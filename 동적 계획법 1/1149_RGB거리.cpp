#include <iostream>
#include <algorithm>
using namespace std;

int dp[1000][3];
int graph[1000][3];

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int n;
	cin >> n; // 집의 개수
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> graph[i][j];
		}
	}

	for (int j = 0; j < 3; j++) {
		dp[0][j] = graph[0][j];
	}

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			int min = 1e9;
			for (int k = 0; k < 3; k++) {
				if (j == k)
					continue;
				if (min > dp[i - 1][k]) {
					min = dp[i - 1][k];
				}
			}
			dp[i][j] = graph[i][j] + min;
		}
	}

	cout << min(dp[n - 1][0], min(dp[n - 1][1], dp[n - 1][2])) << '\n';

	return 0;
}