#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	int m = 1e9;
	cin >> n; // ���� �Է¹ޱ�
	vector<int> dp(n + 1, m);
	dp[1] = 0;
	
	// 1 2 3 4 5 6 7 8 9
	//   1 1 2
	for (int i = 1; i <= n; i++) {
		if (i % 3 == 0) { // 3���� ������ �������� 3���� ������
			dp[i] = min(dp[i], dp[i / 3] + 1);
		}
		if (i % 2 == 0) { // 2�� ������ �������� 2�� ������
			dp[i] = min(dp[i], dp[i / 2] + 1); 
		}
		dp[i] = min(dp[i], dp[i - 1] + 1);
	}
	
	cout << dp[n] << '\n';

	return 0;
}