#include <iostream>
#include <vector>
using namespace std;

void insertion_sort(vector<int>& arr, int n) {
	int i, j, x;
	for (int i = 1; i < n; i++) {
		x = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > x) {
			arr[j + 1] = arr[j]; // ������ �̵�
			j--;
		}
		arr[j + 1] = x;
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int n;
	int sum = 0;
	cin >> n;
	vector<int> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i]; // ���� �迭 ����
	}
	insertion_sort(v, n); // �������� ����

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			sum += v[j];
		}
	}
	cout << sum << '\n';

	return 0;
}
