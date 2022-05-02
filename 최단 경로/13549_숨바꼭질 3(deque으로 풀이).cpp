#include <iostream>
#include <queue>
using namespace std;

int graph[100001];
bool visited[100001];

int solve(int n, int k) {
	deque<int> dq;
	int now, nx;
	dq.push_back(n);
	graph[n] = 0;
	while (!dq.empty()) {
		now = dq.front();
		dq.pop_front();
		if (now == k)
			break;

		// �����̵��� �� front�� ����
		if (now * 2 <= 100000 && visited[now * 2] == false) { // �������� �ʾ��� ���� ����
			dq.push_front(now * 2);
			graph[now * 2] = graph[now];
			visited[now * 2] = true;
		}

		// +1 �ȴ��̵��� ���� back�� ����
		if (now + 1 <= 100000 && visited[now + 1] == false) {
			dq.push_back(now + 1);
			graph[now + 1] = graph[now] + 1;
			visited[now + 1] = true;
		}

		// -1 �ȴ��̵��� ���� back�� ����
		if (now - 1 >= 0 && visited[now - 1] == false) {
			dq.push_back(now - 1);
			graph[now - 1] = graph[now] + 1;
			visited[now - 1] = true;
		}
	}
	return graph[k];
}

int main()
{
	int n, k; // ������ ��ġ, ������ ��ġ
	cin >> n >> k;

	cout << solve(n, k) << '\n';

	return 0;
}