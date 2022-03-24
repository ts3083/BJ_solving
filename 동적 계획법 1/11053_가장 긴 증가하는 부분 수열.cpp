#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int n;
	cin >> n; // 수열의 크기
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	vector<int> dp;
	dp.push_back(arr[0]); // 초기dp는 비어있기 때문에 arr[0]추가
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