#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> n(1000000);

void InitNext(string p) {
	int m = p.length();
	int i, j;
	n[0] = -1;
	for (i = 0, j = -1; i < m; i++, j++) {
		n[i] = j;
		while ((j >= 0) && p[i] != p[j])
			j = n[j];
	}
}

bool KMP(string p, string t) {
	int i, j;
	int M = p.length();
	int N = t.length();
	InitNext(p);
	for (i = 0, j = 0; j < M && i < N; i++, j++) {
		while ((j >= 0) && t[i] != p[j])
			j = n[j];
	}
	if (j == M)
		return true;
	else
		return false;
}

int main()
{
	string text, pattern;
	cin >> text >> pattern;

	bool result = KMP(pattern, text);
	cout << result << '\n';

	return 0;
}