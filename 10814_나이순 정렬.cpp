#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <string>
using namespace std;

bool compare(pair<int, string> c1, pair<int, string> c2) {
	return c1.first < c2.first;
}

int main()
{
	pair<int, string> p;
	int n;
	cin >> n;
	vector<pair<int, string>> v;

	for (int i = 0; i < n; i++) {
		cin >> p.first >> p.second;
		v.push_back(p);
	}
	stable_sort(v.begin(), v.end(), compare);

	for (int i = 0; i < n; i++) {
		cout << v[i].first << ' ' << v[i].second << '\n';
	}

	return 0;
}