#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#include "Shell_Sort.h"
int Arraysize[5] = { 100000, 500000, 1000000, 5000000, 10000000 };

void solve(int num) {
	if (num == 1) {
		for (int i = 0; i < 5; i++) {
			print_shell_1(Arraysize[i]);
		}
	}
	else if (num == 2) {
		for (int i = 0; i < 5; i++) {
			print_shell_2(Arraysize[i]);
		}
	}
	else if (num == 3) {
		for (int i = 0; i < 5; i++) {
			print_shell_3(Arraysize[i]);
		}
	}
	else {
		cout << "잘못된 입력\n";
	}
}

int main()
{
	srand(time(NULL));
	int num;
	cout << "1. 증가식1: h = 3*h+1\n2. 증가식2: h = 3*h\n3. 증가식3: h = 5*h+1\n";
	cin >> num;

	solve(num);

	return 0;
}