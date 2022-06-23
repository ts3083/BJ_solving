#include <iostream>
using namespace std;

void swap(int& S1, int& S2) { // 원소값을 swap하기 위한 함수
	int temp = S1; // 정수를 저장하기 위한 temp 선언
	S1 = S2; // S1에 S2 저장
	S2 = temp; // S2에 temp 저장
}

void QuickSort_increase(int s[], int a, int b) { // 배열 + 첫번째 첨자 + 마지막 첨자를 인자로 전달
	if (a >= b) // S의 크기가 1이면 종료
		return;
	int pivot = 0; // pivot 선언(초기값 0 설정)
	int l, r; // 첨자로 사용하기 위해 l, r 선언
	// Median of Three QuickSort
	if (s[a] >= s[b / 2] && s[a] >= s[b]) { // S[a]가 max
		if (s[b / 2] >= s[b]) 
			pivot = b / 2; 
		else 
			pivot = b; 
	}
	if (s[b / 2] >= s[a] && s[b / 2] >= s[b]) { // S[b / 2]이 max
		if (s[a] >= s[b]) 
			pivot = a; 
		else 
			pivot = b; 
	}
	if (s[b] >= s[b / 2] && s[b] >= s[a]) { // S[b]이 max
		if (s[b / 2] >= s[a]) 
			pivot = b / 2; 
		else 
			pivot = a; 
	}
	swap(s[pivot], s[b]); // 설정한 pivot값을 맨끝 원소값과 swap
	l = a; // l은 맨 처음
	r = b - 1; // r은 맨 뒤

	while (l <= r) { // l이 r보다 커질 때까지 반복
		while (l <= r && s[l] <= s[b]) // S[l].key가 pivot보다 클때까지 실행
			l++; // i 하나 증가
		while (l <= r && s[r] >= s[b]) // S[r].key보다 pivot보다 작을때까지 실행
			r--; // r 하나 증가
		if (l < r) // r이 l보다 작으면 실행
			swap(s[l], s[r]); // S[l]와 S[r]을 바꾸기
	}
	swap(s[l], s[b]); // S[l]와 S[b]을 바꾸기
	QuickSort_increase(s, a, l - 1); // 재귀호출
	QuickSort_increase(s, l + 1, b); // 재귀호출
}

void QuickSort_decrease(int s[], int a, int b) { // 배열 + 첫번째 첨자 + 마지막 첨자를 인자로 전달
	if (a >= b) // S의 크기가 1이면 종료
		return;
	int pivot = 0; // pivot 선언(초기값 0 설정)
	int l, r; // 첨자로 사용하기 위해 l, r 선언
	// Median of Three QuickSort
	if (s[a] >= s[b / 2] && s[a] >= s[b]) { // S[a]가 max
		if (s[b / 2] >= s[b])
			pivot = b / 2;
		else
			pivot = b;
	}
	if (s[b / 2] >= s[a] && s[b / 2] >= s[b]) { // S[b / 2]이 max
		if (s[a] >= s[b])
			pivot = a;
		else
			pivot = b;
	}
	if (s[b] >= s[b / 2] && s[b] >= s[a]) { // S[b]이 max
		if (s[b / 2] >= s[a])
			pivot = b / 2;
		else
			pivot = a;
	}
	swap(s[pivot], s[b]); // 설정한 pivot값을 맨끝 원소값과 swap
	l = a; // l은 맨 처음
	r = b - 1; // r은 맨 뒤

	while (l <= r) { // l이 r보다 커질 때까지 반복
		while (l <= r && s[l] >= s[b]) 
			l++; // i 하나 증가
		while (l <= r && s[r] <= s[b]) 
			r--; // r 하나 증가
		if (l < r) // r이 l보다 작으면 실행
			swap(s[l], s[r]); // S[l]와 S[r]을 바꾸기
	}
	swap(s[l], s[b]); // S[l]와 S[b]을 바꾸기
	QuickSort_decrease(s, a, l - 1); // 재귀호출
	QuickSort_decrease(s, l + 1, b); // 재귀호출
}

int main()
{
	int n = 10;
	int* arr = new int[10]{ 2,6,1,8,7,4,9,10,3,5 };
	QuickSort_decrease(arr, 0, 9);
	for (int i = 0; i < n; i++)
		cout << arr[i] << ' ';
	cout << '\n';

	delete[] arr;
	return 0;
}
