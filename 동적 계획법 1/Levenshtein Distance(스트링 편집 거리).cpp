#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int insert_cost = 1;
int delete_cost = 1;
int swap_cost = 1;

void EditDistance(string& s, string& t, int m, int n) { // Levenshtein Distance 스트링 편집거리
	int i, j, cost, temp;
	vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0)); // n행 m열 2차원배열 선언
	dp[0][0] = 0;
	for (i = 1; i <= n; i++)
		dp[i][0] = dp[i - 1][0] + insert_cost;
	for (j = 1; j <= m; j++)
		dp[0][j] = dp[0][j - 1] + delete_cost;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			cost = swap_cost;
			if (t[i - 1] == s[j - 1])
				cost = 0;
			temp = min(dp[i - 1][j] + insert_cost, dp[i][j - 1] + delete_cost);
			dp[i][j] = min(temp, dp[i - 1][j - 1] + cost);
		}
	}
	
	for (i = 0; i <= n; i++) {
		for (j = 0; j <= m; j++) {
			cout << dp[i][j] << ' ';
		}
		cout << '\n';
	}

	cout << "스트링 편집의 최소 비용 : " << dp[n][m] << '\n';
}

int main()
{
	string source = "GUMBO";
	string target = "GAMBOL";
	int m = source.length();
	int n = target.length();

	EditDistance(source, target, m, n);

	return 0;
}