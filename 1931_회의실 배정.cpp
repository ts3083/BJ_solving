#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2) { // 끝나는 시간 기준 오름차순, 같으면 시작 시간 기준 오름차순 정렬
	if (p1.second != p2.second) // 끝나는 시간이 다르면
		return p1.second < p2.second; // 끝나는 시간 오름차순
	else // 끝나는 시간이 같다면
		return p1.first < p2.first; // 시작 시간으로 우름차순 정렬
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);

	int n;
	int count = 0; // 회의의 개수를 카운트
	int end = -1;
	pair<int, int> p; // 회의 시작 시간 / 회의 끝나는 시간
	cin >> n; // 회의 개수
	vector<pair<int, int>> v; // 전체 회의
	for (int i = 0; i < n; i++) {
		cin >> p.first >> p.second;
		v.push_back(p);
	}

	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < v.size(); i++) {
		if (v[i].first >= end) {
			end = v[i].second;
			count++;
		}
	}
	cout << count << '\n';

	return 0;
}