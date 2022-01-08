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
		if (is_prime_num(i)) { // �Ҽ���� ����
			sum += i;
			if (min > i) // ���� �ּڰ����� i�� �۴ٸ�
				min = i; // i�� �ּڰ��� ��ü
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