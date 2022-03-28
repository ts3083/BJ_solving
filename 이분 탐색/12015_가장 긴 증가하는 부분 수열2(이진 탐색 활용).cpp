#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void binary_search(vector<int>& dp, int num) {
	int left = 0, right = dp.size() - 1;
	int mid;
	int index = 0;
	// dp에서 처음으로 num보다 같거나 큰 인덱스를 찾아서 swap하기
	while (left <= right) {
		mid = (left + right) / 2;
		if (dp[mid] >= num) {
			right = mid - 1;
			index = mid;
		}
		else {
			left = mid + 1;
		}
	}
	dp[index] = num;
}

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
			binary_search(dp, arr[i]);
		}
	}

	cout << dp.size() << '\n';

	return 0;
}