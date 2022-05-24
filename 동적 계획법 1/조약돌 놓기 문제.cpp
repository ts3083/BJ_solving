#include <iostream>
#include <algorithm>
using namespace std;

int graph[3][8] = {
	{6,7,12,-5,5,3,11,3},
	{-8,10,14,9,7,13,8,5},
	{11,12,7,4,8,-2,9,4}
};
int dp[4][8]; // 패턴이 4개 존재하고 각각의 결과일 때 최적의 값을 저장해야 함

void stone() {
	for (int i = 0; i < 4; i++) {
		if (i == 3) {
			dp[i][0] = graph[0][0] + graph[2][0];
		}
		else {
			dp[i][0] = graph[i][0];
		}
	}

	// 패턴: 1 -> 이전의 패턴 2, 3중에 큰 거
	// 패턴: 2 -> 이전의 패턴 1, 3, 4중에 큰 거
	// 패턴: 3 -> 이전의 패턴 1, 2중에 큰 거
	// 패턴: 4 -> 이전의 패턴 2

	int temp, now, pattern = 0;
	for (int j = 1; j < 8; j++) {
		for (int i = 0; i < 4; i++) {
			now = graph[i][j];
			if (i == 0) { // 패턴 1
				temp = max(dp[1][j - 1], dp[2][j - 1]);
			}
			else if (i == 1) { // 패턴 2
				int temp0 = max(dp[0][j - 1], dp[2][j - 1]);
				temp = max(temp0, dp[3][j - 1]);
			}
			else if (i == 2) { // 패턴 3
				temp = max(dp[0][j - 1], dp[1][j - 1]);
			}
			else { // i == 3 -> 패턴 4
				temp = dp[1][j - 1];
				now = graph[0][j] + graph[2][j];
			}
			dp[i][j] = now + temp;
		}
	}

	int m = 0;
	for (int i = 0; i < 4; i++) {
		m = max(m, dp[i][7]);
	}

	cout << "돌이 놓인 자리에 있는 수의 합이 최대가 되는 값 : " << m << '\n';
	cout << "dp 배열 : \n";
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 8; j++) {
			cout << dp[i][j] << ' ';
		}
		cout << '\n';
	}
}

int main()
{
	stone();

	return 0;
}