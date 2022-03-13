#include <iostream>
#include <algorithm>
using namespace std;

int graph[301];
int dp[301];

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int n;
	cin >> n; // 계단의 개수
	for (int i = 1; i <= n; i++) {
		cin >> graph[i];
	}
	
	dp[1] = graph[1];
	dp[2] = max(graph[2], graph[1] + graph[2]);
	dp[3] = max(graph[1] + graph[3], graph[2] + graph[3]);
	if (n > 3) {
		for (int i = 4; i <= n; i++) {
			dp[i] = max(dp[i - 2] + graph[i], dp[i - 3] + graph[i - 1] + graph[i]);
		}
	}

	cout << dp[n] << '\n';

	return 0;
}