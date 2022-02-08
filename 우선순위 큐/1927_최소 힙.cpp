#include <iostream>
#include <queue>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int n, num;
	priority_queue<int> q;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		if (num == 0) {
			if (q.empty())
				cout << 0 << '\n';
			else {
				cout << -q.top() << '\n';
				q.pop();
			}
		}
		else
			q.push(-num);
	}

	return 0;
}