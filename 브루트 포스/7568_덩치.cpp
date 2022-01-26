#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<pair<int, int>> vec;
	pair<int, int> p;
	
	for (int i = 0; i < n; i++) {
		cin >> p.first >> p.second;
		vec.push_back(p);
	}
	
	// 완전 탐색하여 자신보다 큰 몸무게와 키를 가진 사람이 있을 경우 등수를 1등씩 밀어나가는 형식
	int rank = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (vec[i].first < vec[j].first && vec[i].second < vec[j].second) {
				rank++;
			}
		}
		cout << rank << ' ';
		rank = 1;
	}
	
	return 0;
}