#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int n;
	cin >> n; // 입력의 크기가 최대 백만 개
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	vector<int> dp;
	dp.push_back(arr[0]);
	for (int i = 1; i < n; i++) {
		if (dp.back() < arr[i]) {
			dp.push_back(arr[i]);
		}
		else {
			int index = lower_bound(dp.begin(), dp.end(), arr[i]) - dp.begin();
			dp[index] = arr[i];
		}
	}

	cout << dp.size() << '\n';

	return 0;
}