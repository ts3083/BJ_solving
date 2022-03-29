#include <iostream>
#include <vector>
using namespace std;

void swap(int& a, int& b) {
	int temp = a; // ������ �����ϱ� ���� temp ����
	a = b; // a�� b ����
	b = temp; // b�� a ����
}

void print_array(vector<int>& arr, int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << ' ';
	}
	cout << '\n';
}

void OddEvenTransition_Sort(vector<int>& arr, int n) {
	bool isSorted = false; // swap�� �ѹ��� �Ͼ�� ������ �ݺ����� �����ϱ� ���� ���� ����
	if (n % 2 == 0) { // n�� ¦�����
		while (!isSorted) {
			isSorted = true; // swap�� �Ͼ�� ������ isSorted�� true�� �����ϰ� �ݺ����� Ż���Ѵ�
			for (int i = 0; i <= n - 2; i = i + 2) {
				if (arr[i] > arr[i + 1]) { // �������� ����
					swap(arr[i], arr[i + 1]);
					isSorted = false;
				}
			}

			for (int i = 1; i <= n - 3; i = i + 2) {
				if (arr[i] > arr[i + 1]) { // �������� ����
					swap(arr[i], arr[i + 1]);
					isSorted = false;
				}
			}
		}
	}
	else { // n�� Ȧ�����
		while (!isSorted) {
			isSorted = true; // swap�� �Ͼ�� ������ isSorted�� true�� �����ϰ� �ݺ����� Ż���Ѵ�
			for (int i = 0; i <= n - 3; i = i + 2) {
				if (arr[i] > arr[i + 1]) { // �������� ����
					swap(arr[i], arr[i + 1]);
					isSorted = false;
				}
			}

			for (int i = 1; i <= n - 2; i = i + 2) {
				if (arr[i] > arr[i + 1]) { // �������� ����
					swap(arr[i], arr[i + 1]);
					isSorted = false;
				}
			}
		}
	}	
}

int main()
{
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	OddEvenTransition_Sort(arr, n);
	print_array(arr, n);
	
	return 0;
}