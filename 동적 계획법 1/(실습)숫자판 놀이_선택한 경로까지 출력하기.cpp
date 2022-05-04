#include <iostream>
#include <algorithm>
using namespace std;

int dy[] = { -1, 0, 1 };

int main()
{
	int arr[8][9] = {
		{3, 4, 9, -2, 2, 51, -23, 2, -1},
		{223, 7, 8, -11, 5, -99, 2, 3, -4},
		{2, 51, -23, -23, 6, 3, 2, 4, 5},
		{5, -99, 2, -1, 32, 2, 5, -99, 2},
		{6, 3, 3, -4, 2, -1, 6, 3, 3},
		{32, 2, 4, 5, 3, -4, 2, -1, 4},
		{4, 4, 23, 6, 2, -1, 3, -4, 34},
		{78, 32, 1, 7, 3, -4, -23, -23, 6},
	};

	int dp[8][9];
	for (int j = 0; j < 9; j++)
		dp[0][j] = arr[0][j];

	for (int i = 1; i < 8; i++) {
		for (int j = 0; j < 9; j++) {
			for (int k = 0; k < 3; k++) {
				int nx = i - 1;
				int ny = j + dy[k];
				if (nx < 0 || nx >= 8 || ny < 0 || ny >= 9)
					continue;
				dp[i][j] = max(dp[nx][ny] + arr[i][j], dp[i][j]);
			}
		}
	}

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 9; j++) {
			cout << dp[i][j] << ' ';
		}
		cout << '\n';
	}

	int result = 0;
	for (int j = 0; j < 9; j++)
		result = max(dp[7][j], result);

	cout << "최댓값 : " <<  result << '\n';
	cout << "각 행에서 선택한 값을 모두 출력\n";
	int i = 7;
	int j = 0;
	int temp;
	cout << arr[i][j] << ' ';
	while(1) {
		temp = dp[i - 1][j];
		i--;
		if (i < 0)
			break;
		for (int k = 0; k < 3; k++) {
			int ny = j + dy[k];
			if (ny < 0 || ny > 8)
				continue;

			if (temp < dp[i][ny]) {
				j = ny;
			}
		}
		cout << arr[i][j] << ' ';
	}

	return 0;
}