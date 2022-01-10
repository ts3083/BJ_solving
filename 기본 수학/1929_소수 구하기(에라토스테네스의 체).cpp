#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int m, n, j;
	cin >> m >> n;

	bool* arr = new bool[n + 1]; // heap공간에 동적할당
	for (int i = 2; i <= n; i++) {
		arr[i] = true;
	}
	arr[0] = false; 
	arr[1] = false; // 소수가 아님

	for (int i = 2; i <= sqrt(n); i++) {
		if (arr[i] == true) {
			j = 2;
			while (i * j <= n) { // i의 배수들을 모두 제외
				if (arr[i * j] == true) {
					arr[i * j] = false;
				}
				j++;
			}
		}
	}

	for (int i = m; i <= n; i++) { // m부터 n까지 true인 인덱스만을 출력
		if (arr[i])
			cout << i << '\n';
	}

	delete[] arr; // 메모리 삭제
	
	return 0;
}