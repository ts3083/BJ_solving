#include <iostream>
#include <cmath>
using namespace std;

bool is_prime_number(int x) {
	// 2부터 x-1까지 모든 수를 확인
	if (x == 1)
		return false;
	for (int i = 2; i <= sqrt(x); i++) {
		if (x % i == 0)
			return false; // i로 나누어떨어지는 게 하나라도 있으면 소수 아님
	}
	return true; // 나누어 떨어지지 않는다면 소수
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int n, m;
	int count = 0;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> m;
		if (is_prime_number(m)) // 소수라면
			count++; // 카운트하기
	}
	cout << count << '\n';

	return 0;
}
