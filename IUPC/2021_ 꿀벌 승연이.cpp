#include <iostream>
using namespace std;

long long graph[1001][1001];
int dx_even[] = { -1, 0, 1 }; // ��-�Ʒ�, ��-��, ���� �밢�� �Ʒ�
int dy_even[] = { 0, -1, -1 };
int dx_odd[] = { -1, -1, 0 }; // ��-�Ʒ�, ���� �밢�� ��, ��-��
int dy_odd[] = { 0, -1, -1 };

int main()
{
	int n, m, k, x, y; // ��, ��, ���� ĭ�� ����
	cin >> n >> m >> k;
	for (int h = 0; h < k; h++) {
		cin >> x >> y;
		graph[x][y] = -1;
	}
	graph[1][1] = 1;

	long long temp;
	for (int j = 1; j <= m; j++) {
		for (int i = 1; i <= n; i++) {
			if (graph[i][j] == -1)
				continue;
			for (int z = 0; z < 3; z++) {
				int nx, ny;
				if (j % 2 == 0) { // ¦���� �϶�
					nx = i + dx_even[z];
					ny = j + dy_even[z];
				}
				else { // Ȧ���� �϶�
					nx = i + dx_odd[z];
					ny = j + dy_odd[z];
				}
				if (nx < 1 || nx > n || ny < 1 || ny > m)
					continue;
				if (graph[nx][ny] != -1) {
					temp = graph[i][j] + graph[nx][ny];
					graph[i][j] = temp % (1000000000 + 7);
				}
			}
		}
	}

	cout << graph[n][m] << '\n';

	return 0;
}