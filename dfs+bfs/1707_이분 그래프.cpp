#include <iostream>
#include <vector>
using namespace std;

vector<int> visited(20001, 0);

void visit(vector<vector<int>>& graph, int node, int color) {
	if (color == 0) {
		visited[node] = 1; // 1�� ������ ĥ�ϱ�
	}
	else if (color == 1) {
		visited[node] = -1; // -1�� ������ ĥ�ϱ�
	}
	else {
		visited[node] = 1; // 1�� ������ ĥ�ϱ�
	}

	for (int i = 0; i < graph[node].size(); i++) {
		int now_node = graph[node][i];
		if (visited[now_node] == 0) {
			visit(graph, now_node, visited[node]);
		}
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int k;
	cin >> k; // �׽�Ʈ ���̽� ����
	for (int h = 0; h < k; h++) {
		int v, e; // ������ ���� / ������ ����
		cin >> v >> e;
		vector<vector<int>> graph(v + 1);
		int a, b;
		for (int i = 0; i < e; i++) {
			cin >> a >> b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}

		for (int i = 1; i <= v; i++) {
			if (visited[i] == 0) { // �湮���� �ʾҴٸ� ����
				visit(graph, i, 0);
			}
		}

		int cnt = 0;
		for (int i = 1; i <= v; i++) {
			int c = visited[i];
			for (int j = 0; j < graph[i].size(); j++) {
				if (c == visited[graph[i][j]]) {
					cnt++;
				}
			}
		}
		if (cnt == 0)
			cout << "YES\n";
		else
			cout << "NO\n";

		for (int i = 0; i <= v; i++)
			visited[i] = 0;
	}
	return 0;
}