#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[10000];

int main()
{
	int n, temp;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	dp[0] = arr[0];
	if (n > 1) {
		dp[1] = arr[1] + arr[0];
	}
	if (n > 2) {
		int temp = max(dp[1], arr[1] + arr[2]);
		dp[2] = max(temp, arr[0] + arr[2]);
	}
	if (n > 3) {
		for (int i = 3; i < n; i++) {
			temp = max(dp[i - 2] + arr[i], dp[i - 3] + arr[i - 1] + arr[i]);
			dp[i] = max(temp, dp[i - 1]);
		}
	}

	cout << dp[n - 1] << '\n';

	return 0;
}