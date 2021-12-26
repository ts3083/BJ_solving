#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int N; // �ԷµǴ� ������ �ִ� ũ��� �ʸ����� O(nlogn)���� ����
	cin >> N;
	int* arr = new int[N];
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	sort(arr, arr + N); // �����Լ��� sort�Լ� Ȱ��, sort�� quick���� ��� �־��� ��쿡�� o(logn)�� ����
	
	for (int i = 0; i < N; i++)
		cout << arr[i] << '\n';	// endl�� �̿��Ͽ� �ٹٲ��� �ϸ� ���۸� ���� �۾��� ���ݵǾ� '\n'���� �ٹٲ��ϴ� ���� �ð��� �����

	delete[] arr;
	return 0;
}