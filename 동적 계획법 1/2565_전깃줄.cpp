#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> graph;

bool compare(pair<int, int> p1, pair<int, int> p2) {
	return p1.first < p2.first;
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);

	int n, a, b; // 전깃줄의 개수(100개 이하)
	pair<int, int> p;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		p.first = a;
		p.second = b;
		graph.push_back(p);
	}
	sort(graph.begin(), graph.end(), compare); // a전봇대 오름차순으로 전깃줄 정렬
	vector<int> arr;
	for (int i = 0; i < n; i++) {
		arr.push_back(graph[i].second);
	}
	
	vector<int> dp(n, 1);
	// 가장 긴 증가하는 부분수열 구하기
	for (int i = 0; i < n; i++) {
		for (int j = i - 1; j >= 0; j--) {
			if (arr[i] > arr[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}

	int m = 0;
	for (int i = 0; i < n; i++) {
		m = max(m, dp[i]);
	}
	
	cout << n - m << '\n';
	
	return 0;
}