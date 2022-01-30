#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int graph[1000][1000];
queue<pair<int, int>> q;
int dx[] = { -1, 1, 0, 0 }; // �����¿�
int dy[] = { 0, 0, -1, 1 };
int cnt = 0;

void visit(int i, int j, int m, int n) { // �� �Ϸ縸ŭ �丶�並 �Ͱ��ϴ� �Լ�
	for (int k = 0; k < 4; k++) {
		int nx = i + dx[k];
		int ny = j + dy[k];
		if (nx < 0 || ny < 0 || nx >= n || ny >= m)
			continue;
		if (graph[nx][ny] == 0) {
			q.push({ nx, ny });
			graph[nx][ny] = graph[i][j] + 1;
		}
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);

	int m, n;
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> graph[i][j];
			if (graph[i][j] == 1) {
				q.push({ i, j }); // ���� �丶���� ��ġ�� q�� push
			}
		}
	} // �׷��� �Է¹ޱ� �Ϸ�
	
	while (!q.empty()) { // ���� �� �ִ� �丶�並 ��� �������� ����
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		visit(x, y, m, n);
	}

	int max = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (graph[i][j] == 0)
				max = 1001;
			if (graph[i][j] > max)
				max = graph[i][j];
		}
	}

	if (max == 1001) // �� ���� �丶�䰡 �����Ѵٸ�
		cout << -1 << '\n'; // -1 ���
	else // �׷����� ��� �丶�並 ���� �� �ִٸ�
		cout << max - 1 << '\n'; // ��ĥ�� �ɷȴ��� ���

	return 0;
}