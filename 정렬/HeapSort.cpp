#include <iostream>
using namespace std;

void maxheapify(int a[], int h, int m) {
	int v = a[h];
	int j;
	for (j = 2 * h; j <= m; j = 2 * j) {
		if (j < m && a[j] < a[j + 1])
			j = j + 1;
		if (v >= a[j])
			break;
		else
			a[j / 2] = a[j];
	}
	a[j / 2] = v;
}

void minheapify(int a[], int h, int m) {
	int v = a[h];
	int j;
	for (j = 2 * h; j <= m; j = 2 * j) {
		if (j < m && a[j] > a[j + 1])
			j = j + 1;
		if (v <= a[j])
			break;
		else
			a[j / 2] = a[j];
	}
	a[j / 2] = v;
}

void MaxHeapSort(int a[], int length) {
	int n = length - 1;
	for (int i = n / 2; i >= 1; i--)
		maxheapify(a, i, n);

	for (int i = n - 1; i >= 1; i--) {
		int temp = a[1];
		a[1] = a[i + 1];
		a[i + 1] = temp;
		maxheapify(a, 1, i);
	}
}

void MinHeapSort(int a[], int length) {
	int n = length - 1;
	for (int i = n / 2; i >= 1; i--)
		minheapify(a, i, n);

	for (int i = n - 1; i >= 1; i--) {
		int temp = a[1];
		a[1] = a[i + 1];
		a[i + 1] = temp;
		minheapify(a, 1, i);
	}
}

int main()
{
	int arr1[] = { 0,6,2,8,1,3,9,4,5,10,7 };
	int arr2[] = { 0,6,2,8,1,3,9,4,5,10,7 };

	MaxHeapSort(arr1, 11);
	cout << "MaxHeap Sorting\n";
	for (int i = 1; i <= 10; i++)
		cout << arr1[i] << ' ';
	cout << '\n';

	MinHeapSort(arr2, 11);
	cout << "MinHeap Sorting\n";
	for (int i = 1; i <= 10; i++)
		cout << arr2[i] << ' ';

	return 0;
}