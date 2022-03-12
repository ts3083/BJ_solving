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
	cin >> n >> c; // 집의 개수 / 공유기 개수
	for (int i = 0; i < n; i++) {
		cin >> x; // 집의 좌표
		house.push_back(x);
	}
	sort(house.begin(), house.end()); // 집의 좌표를 오름차순 정렬

	long long left = 1;
	long long right = house[n - 1] - house[0]; // 최대 거리 = 끝집 - 첫집
	long long result = 0;

	while (left <= right) {
		long long mid = (left + right) / 2;
		int prev_house = house[0];
		int count = 1; // 이미 첫집이 선택되어짐
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
