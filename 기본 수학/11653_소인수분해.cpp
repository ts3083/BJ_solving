#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int n;
	cin >> n;

	if (n == 1)
		return 0;

	for (;;) {
		for (int i = 2; i <= sqrt(n); i++) {
			if (n % i == 0) { // ¼Ò¼ö°¡ ¾Æ´Ô
				n /= i;
				cout << i << '\n';
				i = 1;
				continue;
			}
		}
		break;
	}
	cout << n << '\n';

	return 0;
}