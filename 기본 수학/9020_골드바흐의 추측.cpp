#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

vector<bool> arr(10001, true); // 모든 원소를 true로 초기화

int main()
{
	int j = 0;
	for (int i = 2; i <= sqrt(10000); i++) { // 10000까지 모든 소수찾기
		if (arr[i]) {
			j = 2;
			while (i * j <= 10000) {
				if (arr[i * j]) {
					arr[i * j] = false;
				}
				j++;
			}
		}
	}

	int t, n;
	cin >> t; // 테스트 케이스의 개수
	for (int i = 0; i < t; i++) {
		int first, second;
		cin >> n;
		first = n / 2;
		second = n - first;

		while ((arr[first] == false) || (arr[second] == false)) { //  두 수중 하나라도 소수가 아니면 실행
			first--;
			second = n - first;
		}
		cout << first << ' ' << second << '\n';
	}

	return 0;
}