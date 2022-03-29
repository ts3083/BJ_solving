#include <iostream>
#include <vector>
using namespace std;

void swap(int& a, int& b) {
	int temp = a; // 정수를 저장하기 위한 temp 선언
	a = b; // a에 b 저장
	b = temp; // b에 a 저장
}

void print_array(vector<int>& arr, int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << ' ';
	}
	cout << '\n';
}

void OddEvenTransition_Sort(vector<int>& arr, int n) {
	bool isSorted = false; // swap이 한번도 일어나지 않으면 반복문을 종료하기 위한 변수 선언
	if (n % 2 == 0) { // n이 짝수라면
		while (!isSorted) {
			isSorted = true; // swap이 일어나지 않으면 isSorted가 true를 유지하고 반복문을 탈출한다
			for (int i = 0; i <= n - 2; i = i + 2) {
				if (arr[i] > arr[i + 1]) { // 오름차순 정렬
					swap(arr[i], arr[i + 1]);
					isSorted = false;
				}
			}

			for (int i = 1; i <= n - 3; i = i + 2) {
				if (arr[i] > arr[i + 1]) { // 오름차순 정렬
					swap(arr[i], arr[i + 1]);
					isSorted = false;
				}
			}
		}
	}
	else { // n이 홀수라면
		while (!isSorted) {
			isSorted = true; // swap이 일어나지 않으면 isSorted가 true를 유지하고 반복문을 탈출한다
			for (int i = 0; i <= n - 3; i = i + 2) {
				if (arr[i] > arr[i + 1]) { // 오름차순 정렬
					swap(arr[i], arr[i + 1]);
					isSorted = false;
				}
			}

			for (int i = 1; i <= n - 2; i = i + 2) {
				if (arr[i] > arr[i + 1]) { // 오름차순 정렬
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