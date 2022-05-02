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

		// 순간이동은 덱 front에 삽입
		if (now * 2 <= 100000 && visited[now * 2] == false) { // 지나가지 않았을 때만 갱신
			dq.push_front(now * 2);
			graph[now * 2] = graph[now];
			visited[now * 2] = true;
		}

		// +1 걷는이동은 덱의 back에 삽입
		if (now + 1 <= 100000 && visited[now + 1] == false) {
			dq.push_back(now + 1);
			graph[now + 1] = graph[now] + 1;
			visited[now + 1] = true;
		}

		// -1 걷는이동은 덱의 back에 삽입
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
	int n, k; // 수빈의 위치, 동생의 위치
	cin >> n >> k;

	cout << solve(n, k) << '\n';

	return 0;
}