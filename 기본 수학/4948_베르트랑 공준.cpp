#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main()
{
	int n, num, j;
	int cnt;

	for (;;) {
		cnt = 0;
		cin >> n;
		if (n == 0) {
			break;
		}

		num = 2 * n;
		vector<bool> arr(num + 1, true);

		for (int i = 2; i <= sqrt(num); i++) { // 소수를 모두 구하기
			if (arr[i] == true) {
				j = 2;
				while (i * j <= num) {
					if (arr[i * j] == true) {
						arr[i * j] = false;
					}
					j++; // true가 아니어도 j는 계속 증가되어야 함
				}
			}
		}
		for (int i = n + 1; i <= num; i++) {
			if (arr[i]) {
				cnt++;
			}
		}
		cout << cnt << '\n';
	}
	
	return 0;
}