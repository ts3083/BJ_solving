#include <iostream>
#include <vector>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int k, n;
	cin >> k >> n;
	
	vector<long long> v(n);
	long long max = 0;
	for (int i = 0; i < k; i++) {
		cin >> v[i];
		if (max < v[i])
			max = v[i];
	}

	long long start = 1;
	long long high = max;
	int result = 0;
	while (start <= high) {
		long long mid = (start + high) / 2; // 중간값을 랜선값으로 먼저 확인
		long long sum = 0;
		for (int i = 0; i < k; i++) {
			sum += v[i] / mid;
		}
		if (sum < n) {
			high = mid - 1;
		}
		else { // sum >= n
			result = mid;
			start = mid + 1;
		}
	}
	
	cout << result << '\n';

	return 0;
}