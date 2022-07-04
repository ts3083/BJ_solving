#include <iostream>
#include <vector>
#include <queue>
using namespace std;

priority_queue<pair<int, bool>, vector<pair<int, bool>>, greater<pair<int, bool>>> pq; // minheap

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	bool positive;
	int n, x, temp;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> x;
		if (x == 0) {
			if (pq.empty()) {
				cout << 0 << '\n';
			}
			else {
				if (pq.top().second) {
					temp = pq.top().first;
				}
				else {
					temp = -pq.top().first;
				}
				cout << temp << '\n';
				pq.pop();
			}
		}
		else {
			if (x < 0) {
				positive = false;
			}
			else {
				positive = true;
			}
			x = (x > 0 ? x : -x);
			pq.push({ x, positive });
		}
	}	

	return 0;
}
