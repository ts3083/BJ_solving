#include <iostream>
using namespace std;

int graph[50][50] = { };
int dx[] = { -1, 1, 0, 0 }; // �����¿�
int dy[] = { 0, 0, -1, 1 };

void dfs(int r, int c, int m, int n) {
	graph[r][c] = 0; // 1�� 0���� ��ȯ
	// ��ȭ�¿� Ȯ���ϸ鼭 ������ ���߸� ��������� dfs����
	for (int i = 0; i < 4; i++) {
		int nx = r + dx[i];
		int ny = c + dy[i];
		if (nx < 0 || ny < 0 || nx >= m || ny >= n)
			continue;
		if (graph[nx][ny] == 1)
			dfs(nx, ny, m, n);
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int t;
	cin >> t; // �׽�Ʈ ���̽� �Է¹���

	for (int i = 0; i < t; i++) { // t�� ����
		int m, n, total; // ����, ����, ���� �� ����
		int x, y;
		int count = 0;
		cin >> m >> n >> total;
		for (int j = 0; j < total; j++) {
			cin >> x >> y;
			graph[x][y] = 1;
		} // ���߰� �ɾ����ִ� �� ���� �ϼ�

		// ������ ������ ������ �� ���� ī��Ʈ
		for (int row = 0; row < m; row++) {
			for (int col = 0; col < n; col++) {
				if (graph[row][col] == 1) {
					dfs(row, col, m, n);
					count++;
				}
			}
		}
		cout << count << '\n';
	}

	return 0;
}