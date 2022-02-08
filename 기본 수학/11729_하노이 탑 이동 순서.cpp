#include <iostream>
using namespace std;

int h(int n) {
	if (n == 1)
		return 1;
	return 1 + (h(n - 1) * 2);
}

void honoi(int n, int start, int end, int mid) {
	if (n == 1) {
		cout << start << ' ' << end << '\n';
	}
	else {
		honoi(n - 1, start, mid, end);
		cout << start << ' ' << end << '\n';
		honoi(n - 1, mid, end, start);
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);

	int n;
	cin >> n;
	
	cout << h(n) << '\n';
	honoi(n, 1, 3, 2);

	return 0;
}