#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool inspect(vector<int>& vec, int key) { // 리스트안에 key가 존재하는지 확인하는 함수
	int left = upper_bound(vec.begin(), vec.end(), key) - vec.begin();
	int right = lower_bound(vec.begin(), vec.end(), key) - vec.begin();
	int result = right - left; // 리스트에 key가 존재하지 않으면 0이 됨
	if (result)
		return true;
	else
		return false;
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int n, m, num, key;
	vector<int> vec;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> num;
		vec.push_back(num);
	}
	sort(vec.begin(), vec.end()); // 오름차순 정렬

	cin >> m;
	for (int j = 0; j < m; j++) {
		cin >> key;
		if (inspect(vec, key))
			cout << 1 << '\n';
		else
			cout << 0 << '\n';
	}

	return 0;
}