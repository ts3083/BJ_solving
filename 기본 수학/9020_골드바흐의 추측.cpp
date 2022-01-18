#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

vector<bool> arr(10001, true); // ��� ���Ҹ� true�� �ʱ�ȭ

int main()
{
	int j = 0;
	for (int i = 2; i <= sqrt(10000); i++) { // 10000���� ��� �Ҽ�ã��
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
	cin >> t; // �׽�Ʈ ���̽��� ����
	for (int i = 0; i < t; i++) {
		int first, second;
		cin >> n;
		first = n / 2;
		second = n - first;

		while ((arr[first] == false) || (arr[second] == false)) { //  �� ���� �ϳ��� �Ҽ��� �ƴϸ� ����
			first--;
			second = n - first;
		}
		cout << first << ' ' << second << '\n';
	}

	return 0;
}