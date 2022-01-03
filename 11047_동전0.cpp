#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, k;
	int count = 0;
	int index = 0;
	cin >> n >> k;
	vector<int> v(n);
	
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	
	for (int j = n - 1; j >= 0; j--) {
		if (k / v[j] != 0) { // �Ѿ� ���� ������ ��ġ�� �� ū ��츦 �Ÿ��� �ڵ�
			index = j;
			break;
		}
	}

	while (k != 0) {
		count += k / v[index]; // ������ ����
		k %= v[index]; // �Ѿ��� �ٽ� ����
		index--;
	}
	cout << count << '\n';

	return 0;
}