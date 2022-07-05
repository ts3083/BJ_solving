#include <iostream>
#include <algorithm>
using namespace std;

long long Calculate_under(long long mid, long long n) { // mid 이하의 숫자의 개수 구하기
	long long sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += min(n, mid / i);
	}
	return sum;
}

int main()
{
	long long n, k;
	cin >> n >> k;
	k = min((long long)1000000000, k);

	long long start = 1;
	long long end = n * n;
	while (start <= end) {
		long long mid = (start + end) / 2;
		long long sum = Calculate_under(mid, n);
		if (sum < k) {
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}

	cout << start << '\n';

	return 0;
}
