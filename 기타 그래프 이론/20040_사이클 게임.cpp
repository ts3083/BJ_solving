#include <iostream>
#include <vector>
using namespace std;

int find_parent(vector<int>& nodes, int node_num) {
	while (nodes[node_num] != node_num) { // 자기자신이 부모가 아니라면 
		node_num = nodes[node_num];
	}
	return nodes[node_num];
}

void union_parent(vector<int>& nodes, int a, int b) {
	a = find_parent(nodes, a);
	b = find_parent(nodes, b);
	if (a < b) {
		nodes[b] = a;
	}
	else {
		nodes[a] = b;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, x, y, result = 0;
	cin >> n >> m;
	vector<int> nodes(n); // 0부터 n-1까지 노드번호가 쓰여진 리스트 생성
	for (int j = 0; j < n; j++) {
		nodes[j] = j;
	}

	vector<pair<int, int>> select;
	for (int j = 0; j < m; j++) {
		cin >> x >> y;
		select.push_back({ x, y });
	}

	for (int i = 0; i < m; i++) {
		x = select[i].first;
		y = select[i].second;
		if (find_parent(nodes, x) == find_parent(nodes, y)) { // 같은 부모, 사이클이 생긴 것
			result = i + 1;
			break; // 사이클이 발생하면 종료
		}
		else { // 사이클이 없다면
			union_parent(nodes, x, y);
		}
	}
	
	cout << result << '\n';

	return 0;
}
