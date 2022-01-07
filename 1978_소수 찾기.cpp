#include <iostream>
#include <cmath>
using namespace std;

bool is_prime_number(int x) {
	// 2���� x-1���� ��� ���� Ȯ��
	if (x == 1)
		return false;
	for (int i = 2; i <= sqrt(x); i++) {
		if (x % i == 0)
			return false; // i�� ����������� �� �ϳ��� ������ �Ҽ� �ƴ�
	}
	return true; // ������ �������� �ʴ´ٸ� �Ҽ�
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
		if (is_prime_number(m)) // �Ҽ����
			count++; // ī��Ʈ�ϱ�
	}
	cout << count << '\n';

	return 0;
}