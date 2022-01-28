#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() 
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int n, m;
	cin >> n;
	vector<int> sg(n);
	
	for (int i = 0; i < n; i++) {
		cin >> sg[i];
	}
	sort(sg.begin(), sg.end());

	cin >> m;
	vector<int> key(m);
	for (int j = 0; j < m; j++) {
		cin >> key[j];
	}
	
	for (int i = 0; i < m; i++) {
		int right = upper_bound(sg.begin(), sg.end(), key[i]) - sg.begin();
		int left = lower_bound(sg.begin(), sg.end(), key[i]) - sg.begin();
		cout << right - left << ' ';
	}



	return 0;
}