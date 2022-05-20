#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> W(100001, 0);
vector<int> V(1001, 0);
vector<vector<int>> dp(101, vector<int>(100001, 0));

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int n, k, a, b;
	cin >> n >> k; // 물건 개수 / 배낭이 버티는 무게
	for (int i = 1; i <= n; i++) {
		cin >> a >> b;
		W[i] = a;
		V[i] = b;
	}

	int first, second;
	for (int j = 1; j <= k; j++) { // limit
		for (int i = 1; i <= n; i++) { // 물건 번호
			// 2가지 중에 큰 것 - 해당 물건을 넣는다, 넣지 않는다
			if (W[i] > j) {
				first = 0;
			}
			else {
				first = V[i] + dp[i - 1][j - W[i]];
			}
			second = dp[i - 1][j];
			dp[i][j] = max(first, second);
		}
	}

	cout << dp[n][k] << '\n';

	return 0;
}