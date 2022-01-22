#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool inspect(vector<int>& vec, int key) { // ����Ʈ�ȿ� key�� �����ϴ��� Ȯ���ϴ� �Լ�
	int left = upper_bound(vec.begin(), vec.end(), key) - vec.begin();
	int right = lower_bound(vec.begin(), vec.end(), key) - vec.begin();
	int result = right - left; // ����Ʈ�� key�� �������� ������ 0�� ��
	if (result)
		return true;
	else
		return false;
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int n, m, num, key;
	vector<int> vec;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> num;
		vec.push_back(num);
	}
	sort(vec.begin(), vec.end()); // �������� ����

	cin >> m;
	for (int j = 0; j < m; j++) {
		cin >> key;
		if (inspect(vec, key))
			cout << 1 << '\n';
		else
			cout << 0 << '\n';
	}

	return 0;
}