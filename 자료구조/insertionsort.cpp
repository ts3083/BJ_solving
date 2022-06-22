#include <iostream>

using namespace std;

void insertion_ascending(int n, int s[]) { // n은 배열의 크기
	int i, j, x;
	for (i = 1; i < n; i++) {
		x = s[i];
		j = i - 1;
		while (j >= 0 && s[j] > x) { // 기준 x보다 왼쪽으로 돌면서 더 큰 수를 발견하면
			s[j + 1] = s[j]; // 왼쪽 숫자를 오른쪽으로 이동
			j--;
		}
		s[j + 1] = x;
	}
}

void insertion_descending(int n, int s[]) { // n은 배열의 크기
	int i, j, x;
	for (i = 1; i < n; i++) {
		x = s[i];
		j = i - 1;
		while (j >= 0 && s[j] < x) {
			s[j + 1] = s[j]; 
			j--;
		}
		s[j + 1] = x;
	}
}

void insertion_ascending(vector<int>& v) { // n은 배열의 크기
	int i, j, x;
	int size = v.size();
	for (i = 1; i < size; i++) {
		x = v[i];
		j = i - 1;
		while (j >= 0 && v[j] > x) { // 기준 x보다 왼쪽으로 돌면서 더 큰 수를 발견하면
			v[j + 1] = v[j]; // 왼쪽 숫자를 오른쪽으로 이동
			j--;
		}
		v[j + 1] = x;
	}
}

void insertion_descending(vector<int>& v) { // n은 배열의 크기
	int i, j, x;
	int size = v.size();
	for (i = 1; i < size; i++) {
		x = v[i];
		j = i - 1;
		while (j >= 0 && v[j] < x) {
			v[j + 1] = v[j];
			j--;
		}
		v[j + 1] = x;
	}
}

int main()
{
	int* arr = new int[10]{ 5,6,2,4,7,1,9,8,10,3 };
	vector<int> v = { 5,6,2,4,7,1,9,8,10,3 };
	insertion_descending(10, arr);

	cout << "\nInsertion Sort 연산 후 :\n";
	for (int i = 0; i < 10; i++) { // n까지 반복
		cout << arr[i] << " "; // sort 후 배열 출력
	}
	cout << '\n';

	delete[] arr;
	return 0;
}
