#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int N; // 입력되는 숫자의 최대 크기는 십만개로 O(nlogn)으로 구현
	cin >> N;
	int* arr = new int[N];
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	sort(arr, arr + N); // 내장함수인 sort함수 활용, sort는 quick정렬 기반 최악의 경우에도 o(logn)을 보장
	
	for (int i = 0; i < N; i++)
		cout << arr[i] << '\n';	// endl을 이용하여 줄바꿈을 하면 버퍼를 비우는 작업이 동반되어 '\n'으로 줄바꿈하는 것이 시간이 절약됨

	delete[] arr;
	return 0;
}
