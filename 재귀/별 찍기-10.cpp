#include <iostream>
using namespace std;

void print(int i, int j, int n) {
	if (i % 3 == 1 && j % 3 == 1)
		cout << " ";
	else if (n == 1)
		cout << "*";
	else
		print(i / 3, j / 3, n / 3);
}

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			print(i, j, n);
		}
		cout << '\n';
	}
	
	return 0;
}