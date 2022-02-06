#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> v(n + 1);
	v[1] = 1;
	if (n > 1) {
		v[2] = 2;
	}
	int result = 0;

	if (n > 2) {
		for (int i = 3; i <= n; i++) {
			result = v[i - 2] + v[i - 1];
			v[i] = result % 15746;
		}
	}

	cout << v[n] << '\n';

	return 0;
}