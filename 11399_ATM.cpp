#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int n;
	int sum = 0;
	cin >> n;
	vector<int> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i]; // ���� �迭 ����
	}
	sort(v.begin(), v.end()); // �������� ����

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			sum += v[j];
		}
	}
	cout << sum << '\n';

	return 0;
}