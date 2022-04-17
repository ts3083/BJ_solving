#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> skip(200);

void InitSkip(string p) {
	int i;
	int M = p.length();
	for (i = 97; i < 122; i++) 
		skip[i] = M;
	for (i = 0; i < M; i++)
		skip[p[i]] = M - i - 1;
}

int MisChar(string p, string t) {
	int M = p.length();
	int N = t.length();
	int i, j, k;
	InitSkip(p);
	for (i = M - 1, j = M - 1; j >= 0; i--, j--) {
		while (t[i] != p[j]) {
			k = skip[t[i]];
			if (M - j > k)
				i = i + M - j;
			else
				i = i + k;
			if (i >= N)
				return N;
			j = M - 1;
		}
	}
	return i + 1;
}

int main()
{
	string text, pattern;
	cin >> text >> pattern;

	int pos = MisChar(pattern, text);
	cout << pos << '\n';

	return 0;
}