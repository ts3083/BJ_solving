#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int n;
	queue<int> q;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}

	if (q.size() > 1)
		q.pop();

	while (q.size() != 1) {
		int num = q.front();
		q.pop();
		q.push(num);
		q.pop();
	}

	cout << q.front() << '\n';

	return 0;
}