#include <iostream>
#include <stack>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int k, n;
	int sum = 0;
	cin >> k;
	stack<int> s;

	for (int i = 0; i < k; i++) {
		cin >> n;
		if (n == 0)
			s.pop();
		else
			s.push(n);
	}

	while (!s.empty()) {
		sum += s.top();
		s.pop();
	}

	cout << sum << '\n';

	return 0;
}