#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	vector<int> dp(n, 0);
	vector<int> dp0(n, 0);
	dp0[0] = arr[0];
	dp[0] = arr[0];
	if (n > 1) {
		for (int i = 1; i < n; i++) {
			dp0[i] = max(arr[i], dp0[i - 1] + arr[i]);
			dp[i] = max(dp[i - 1], dp0[i]);
		}
	}

	cout << dp[n - 1] << '\n';

	return 0;
}
