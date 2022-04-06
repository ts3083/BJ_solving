#include <iostream>
using namespace std;

int dp[10][101];

int main()
{
	int n;
	cin >> n; // 계단 수의 길이
	for (int i = 1; i < 10; i++) {
		dp[i][1] = 1;
	} // n이 1일 때 개수 초기화

	int result;
	if (n >= 2) {
		for (int j = 2; j <= n; j++) {
			for (int i = 0; i < 10; i++) {
				if (i == 0) {
					result = dp[i + 1][j - 1];
				}
				else if (i == 9) {
					result = dp[i - 1][j - 1];
				}
				else {
					result = dp[i - 1][j - 1] + dp[i + 1][j - 1];
				}
				dp[i][j] = result % 1000000000;
			}
		}
	}

	long long sum = 0;
	for (int i = 0; i< 10; i++) {
		sum += dp[i][n];
	}
	sum = sum % 1000000000;
	
	cout << sum << '\n';

	return 0;
}