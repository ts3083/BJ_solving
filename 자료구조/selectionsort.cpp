#include <iostream>

using namespace std;

void selection_ascending(int n, int s[]) { // n은 배열의 크기, 오름차순
	int i, j, smallest, temp;
	for (i = 0; i < n - 1; i++) {
		smallest = i; // 확인하는 맨 앞의 숫자 인덱스를 smallest로 가정
		for (j = i + 1; j < n; j++) {
			if (s[j] < s[smallest]) { // j번째 숫자가 smallest번째 숫자보다 작다면
				smallest = j; // smallest 갱신
			}
		}
		temp = s[i];
		s[i] = s[smallest];
		s[smallest] = temp;
	}
}

void selection_descending(int n, int s[]) { // n은 배열의 크기, 내림차순
	int i, j, biggest, temp;
	for (i = 0; i < n - 1; i++) {
		biggest = i; 
		for (j = i + 1; j < n; j++) {
			if (s[j] > s[biggest]) { 
				biggest = j; 
			}
		}
		temp = s[i];
		s[i] = s[biggest];
		s[biggest] = temp;
	}
}

int main()
{
	int* arr = new int[10]{ 5,6,2,4,7,1,9,8,10,3 };
	selection_descending(10, arr);

	cout << "\nselection Sort 연산 후 :\n";
	for (int i = 0; i < 10; i++) { // n까지 반복
		cout << arr[i] << " "; // sort 후 배열 출력
	}
	cout << '\n';

	delete[] arr;
	return 0;
}
