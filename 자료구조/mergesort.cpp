#include <iostream>
using namespace std;

void merge_increase(int h, int m, int u[], int v[], int s[]) { // merge 함수
	int i, j, k; // 첨자역할을 할 i, j, k 선언
	i = 0, j = 0, k = 0;  // 초기값 0으로 설정
	while (i < h && j < m) { // U와 V에 숫자가 모두 남아있다면 실행
		if (u[i] <= v[j]) { // U에 있는 숫자가 V에 있는 숫자보다 작거나 같으면 실행
			s[k] = u[i]; // S에 복사
			i++; // i하나 증가
		}
		else { // V에 있는 숫자가 더 작다면
			s[k] = v[j]; // S에 복사
			j++; // j하나 증가
		}
		k++; // k하나 증가
	}
	if (i >= h) { // V에 값이 남아있을 경우
		while (j < m) { // V가 빌 때까지 실행
			s[k] = v[j]; // S에 복사
			j++; // j하나 증가
			k++; // k하나 증가
		}
	}
	else { // U에 값이 남아있을 경우
		while (i < h) { // U가 빌 때까지 실행
			s[k] = u[i]; // S에 복사
			i++; // i하나 증가
			k++; // k하나 증가
		}
	}
}

void mergesort_increase(int n, int s[]) { // mergesort 알고리즘
	const int h = n / 2, m = n - h; // h, m 초기값 설정
	int i, j; // i, j 첨자로 사용하기 위해 선언
	int* u = new int[h]; // 크기가 h인 data set 동적할당
	int* v = new int[m]; // 크기가 m인 data set 동적할당
	if (n > 1) { // 크기가 1인 경우는 실행 되지 않음
		for (i = 0; i < h; i++) // h까지 반복
			u[i] = s[i]; // S[0]부터 S[h-1]까지를 U[0]부터 U[h-1]까지 복사
		for (j = 0; j < m; j++) // m까지 반복
			v[j] = s[j + h]; // S[h]부터 S[n-1]까지를 V[0]부터 V[m-1]까지 복사
		mergesort_increase(h, u); // 재귀호출
		mergesort_increase(m, v); // 재귀호출
		merge_increase(h, m, u, v, s); // merge함수 실행
	}
	delete[] u; // u 메모리 삭제
	delete[] v; // v 메모리 삭제
}

void merge_decrease(int h, int m, int u[], int v[], int s[]) { 
	int i, j, k; 
	i = 0, j = 0, k = 0; 
	while (i < h && j < m) { 
		if (u[i] >= v[j]) {
			s[k] = u[i];
			i++; 
		}
		else { 
			s[k] = v[j]; 
			j++; 
		}
		k++; 
	}
	if (i >= h) { 
		while (j < m) { 
			s[k] = v[j]; 
			j++; 
			k++; 
		}
	}
	else { 
		while (i < h) { 
			s[k] = u[i]; 
			i++; 
			k++; 
		}
	}
}

void mergesort_decrease(int n, int s[]) {
	const int h = n / 2, m = n - h; 
	int i, j; 
	int* u = new int[h]; 
	int* v = new int[m]; 
	if (n > 1) { 
		for (i = 0; i < h; i++) 
			u[i] = s[i];
		for (j = 0; j < m; j++) 
			v[j] = s[j + h]; 
		mergesort_decrease(h, u); 
		mergesort_decrease(m, v); 
		merge_decrease(h, m, u, v, s); 
	}
	delete[] u; // u 메모리 삭제
	delete[] v; // v 메모리 삭제
}

int main()
{
	int n = 10;
	int* arr = new int[10]{ 2,6,1,8,7,4,9,10,3,5 };
	mergesort_increase(10, arr);
	for (int i = 0; i < n; i++)
		cout << arr[i] << ' ';
	cout << '\n';

	delete[] arr;
	return 0;
}
