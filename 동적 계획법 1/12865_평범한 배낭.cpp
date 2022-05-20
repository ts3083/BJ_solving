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
	cin >> n >> k; // ���� ���� / �賶�� ��Ƽ�� ����
	for (int i = 1; i <= n; i++) {
		cin >> a >> b;
		W[i] = a;
		V[i] = b;
	}

	int first, second;
	for (int j = 1; j <= k; j++) { // limit
		for (int i = 1; i <= n; i++) { // ���� ��ȣ
			// 2���� �߿� ū �� - �ش� ������ �ִ´�, ���� �ʴ´�
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