#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, k;
	int count = 0;
	int index = 0;
	cin >> n >> k;
	vector<int> v(n);
	
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	
	for (int j = n - 1; j >= 0; j--) {
		if (k / v[j] != 0) { // 총액 보다 동전의 가치가 더 큰 경우를 거르는 코드
			index = j;
			break;
		}
	}

	while (k != 0) {
		count += k / v[index]; // 동전의 갯수
		k %= v[index]; // 총액을 다시 설정
		index--;
	}
	cout << count << '\n';

	return 0;
}
