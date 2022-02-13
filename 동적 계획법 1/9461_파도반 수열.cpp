#include <iostream>
#include <vector>
using namespace std;

vector<long long> dp(101, 1);

int main()
{
	dp[4] = 2;
	dp[5] = 2;
	
	for (int i = 6; i <= 100; i++) {
		dp[i] = dp[i - 1] + dp[i - 5];
	}
	
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;

		cout << dp[n] << '\n';
	}

	return 0;
}