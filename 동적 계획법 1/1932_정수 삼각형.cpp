#include <iostream>
#include <algorithm>
using namespace std;

int graph[500][500];
int dp[500][500];

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) { // graph 입력받기
		for (int j = 0; j <= i; j++) {
			cin >> graph[i][j];
		}
	}
	dp[0][0] = graph[0][0];

	for (int i = 1; i < n; i++) { 
		for (int j = 0; j <= i; j++) {
			if (j == 0) {
				dp[i][j] = dp[i - 1][j] + graph[i][j];
			}
			else if (j == i) {
				dp[i][j] = dp[i - 1][j - 1] + graph[i][j];
			}
			else {
				dp[i][j] = max(dp[i - 1][j - 1] + graph[i][j], dp[i - 1][j] + graph[i][j]);
			}
		}
	}

	int max = 0;
	for (int i = 0; i < n; i++) {
		if (max < dp[n - 1][i]) {
			max = dp[n - 1][i];
		}
	}

	cout << max << '\n';

	return 0;
}