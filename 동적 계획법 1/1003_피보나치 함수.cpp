#include <iostream>
#include <vector>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int t, n;
	vector<pair<int, int>> vec(41);
	vec[0] = { 1, 0 };
	vec[1] = { 0, 1 };
	
	for (int i = 2; i < 41; i++) {
		vec[i].first = vec[i - 2].first + vec[i - 1].first;
		vec[i].second = vec[i - 2].second + vec[i - 1].second;
	}

	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		cout << vec[n].first << ' ' << vec[n].second << '\n';
	}

	return 0;
}