#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> house;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int n, c, x;
	cin >> n >> c; // ���� ���� / ������ ����
	for (int i = 0; i < n; i++) {
		cin >> x; // ���� ��ǥ
		house.push_back(x);
	}
	sort(house.begin(), house.end()); // ���� ��ǥ�� �������� ����

	long long left = 1;
	long long right = house[n - 1] - house[0]; // �ִ� �Ÿ� = ���� - ù��
	long long result = 0;

	while (left <= right) {
		long long mid = (left + right) / 2;
		int prev_house = house[0];
		int count = 1; // �̹� ù���� ���õǾ���
		for (int i = 1; i < n; i++) {
			int h = house[i] - prev_house;
			if (h >= mid) {
				count++;
				prev_house = house[i];
			}
		}

		if (count >= c) {
			left = mid + 1;
			result = max(mid, result);
		}
		else {
			right = mid - 1;
		}
	}
	cout << result << '\n';

	return 0;
}
