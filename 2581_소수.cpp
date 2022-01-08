#include <iostream>
#include <cmath>
using namespace std;

bool is_prime_num(int x) {
	if (x == 1)
		return false;
	for (int i = 2; i <= sqrt(x); i++) {
		if (x % i == 0) {
			return false;
		}
	}
	return true;
}

int main()
{
	int m, n;
	int sum = 0;
	int min = 10001;
	cin >> m >> n;
	
	for (int i = m; i <= n; i++) {
		if (is_prime_num(i)) { // 소수라면 실행
			sum += i;
			if (min > i) // 현재 최솟값보다 i가 작다면
				min = i; // i로 최솟값을 교체
		}
	}

	if (sum == 0)
		cout << -1 << '\n';
	else {
		cout << sum << '\n';
		cout << min << '\n';
	}
	
	return 0;
}