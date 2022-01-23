#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	queue<int> q;
	string str;
	int n, num;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> str;
		if (str == "push") {
			cin >> num;
			q.push(num);
		}
		else if (str == "pop") {
			if (q.empty())
				cout << -1 << '\n';
			else {
				cout << q.front() << '\n';
				q.pop();
			}
		}
		else if (str == "size")
			cout << q.size() << '\n';
		else if (str == "empty") {
			if (q.empty())
				cout << 1 << '\n';
			else {
				cout << 0 << '\n';
			}
		}
		else if (str == "front") {
			if (q.empty())
				cout << -1 << '\n';
			else {
				cout << q.front() << '\n';
			}
		}
		else {
			if (q.empty())
				cout << -1 << '\n';
			else {
				cout << q.back() << '\n';
			}
		}		
	}

	return 0;
}