#include <iostream>
using namespace std;

int binary_search(int arr[], int target, int start, int end) {
	if (start > end)
		return NULL;
	int mid = (start + end) / 2;
	if (arr[mid] == target)
		return mid;
	else if (arr[mid] > target)
		return binary_search(arr, target, start, mid - 1);
	else
		return binary_search(arr, target, mid + 1, end);
}

int mylower_bound(int arr[], int target, int n) { // target이상인 첫번째 원소의 인덱스
	int start = 0, end = n - 1, mid;
	while (start < end) {
		mid = (start + end) / 2;
		if (arr[mid] < target)
			start = mid + 1;
		else
			end = mid;
	}
	return start;
}

int myupper_bound(int arr[], int target, int n) { // target초과하는 첫번째 원소의 인덱스
	int start = 0, end = n - 1, mid;
	while (start < end) {
		mid = (start + end) / 2;
		if (arr[mid] <= target)
			start = mid + 1;
		else
			end = mid;
	}
	return start;
}

int count_sameElem(int arr[], int target, int n) { // 배열안에 원소가 target인 중복된 원소의 개수
	int left = mylower_bound(arr, target, n);
	int right = myupper_bound(arr, target, n);
	return right - left;
}

int main()
{
	int* arr = new int[10]{ 1,2,3,4,5,6,6,6,9,10 };
	int index = myupper_bound(arr, 4, 10);
	
	cout << index << '\n';

	delete[] arr;
	return 0;
}
