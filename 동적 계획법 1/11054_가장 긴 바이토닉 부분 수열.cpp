#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;

vector<int> dp_left(1000, 1);
vector<int> dp_right(1000, 1);

int main()
{
	std::ios::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);

	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = i - 1; j >= 0; j--) {
			if (arr[j] < arr[i]) {
				dp_left[i] = max(dp_left[i], dp_left[j] + 1);
			}
		}
	}

	for (int i = n - 1; i >= 0; i--) {
		for (int j = i + 1; j < n; j++) {
			if (arr[j] < arr[i]) {
				dp_right[i] = max(dp_right[i], dp_right[j] + 1);
			}
		}
	}
	int m = 0;
	for (int i = 0; i < n; i++) {
		m = max(m, dp_left[i] + dp_right[i]);
	}
	cout << m - 1 << '\n';

	return 0;
}