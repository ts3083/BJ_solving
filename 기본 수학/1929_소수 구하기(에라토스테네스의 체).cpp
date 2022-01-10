#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int m, n, j;
	cin >> m >> n;

	bool* arr = new bool[n + 1]; // heap������ �����Ҵ�
	for (int i = 2; i <= n; i++) {
		arr[i] = true;
	}
	arr[0] = false; 
	arr[1] = false; // �Ҽ��� �ƴ�

	for (int i = 2; i <= sqrt(n); i++) {
		if (arr[i] == true) {
			j = 2;
			while (i * j <= n) { // i�� ������� ��� ����
				if (arr[i * j] == true) {
					arr[i * j] = false;
				}
				j++;
			}
		}
	}

	for (int i = m; i <= n; i++) { // m���� n���� true�� �ε������� ���
		if (arr[i])
			cout << i << '\n';
	}

	delete[] arr; // �޸� ����
	
	return 0;
}