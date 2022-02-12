#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int n, num;
	vector<int> vec;
	stack<int> s;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		vec.push_back(num);
	}

	vector<int> oge(n, -1);

	for (int i = 0; i < n; i++) {
		while (!s.empty() && vec[s.top()] < vec[i]) {
			oge[s.top()] = vec[i]; // oge¸¦ °»½Å
			s.pop();
		}
		s.push(i);
	}

	for (int i = 0; i < n; i++) {
		cout << oge[i] << ' ';
	}

	return 0;
}