#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

vector<int> n(1000001);
vector<int> arr;

void InitNext(string& p, int M) { // InitNext함수
	int i = 1, j = 0;
	n[0] = 0;
	for (i; i < M; i++) {
		while (p[i] != p[j]) { // j >= 0 이면서 불일치하면
			if (j == 0) {
				n[i] = j;
				break;
			}
			j = n[j - 1];
		}
		if (p[i] == p[j])
			n[i] = ++j;
	}
}

void KMP(string& p, string& t, int M, int N) { // KMP 알고리즘
	int j = 0, pos;
	InitNext(p, M); // next 배열 만들기
	for (int i = 0; i < N; i++) {
		while (t[i] != p[j]) {
			if (j == 0)
				break;
			j = n[j - 1];
		}
		if (t[i] == p[j]) {
			j++;
			if (j == M) {
				arr.push_back(i - M + 1);
				j = n[j - 1];
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string text;
	string pattern;
	getline(cin, text);
	getline(cin, pattern);
	int M = pattern.length(); // 패턴의 길이
	int N = text.length(); // 텍스트의 길이

	KMP(pattern, text, M, N);

	cout << arr.size() << '\n';
	for (int i = 0; i < arr.size(); i++)
		cout << arr[i] + 1 << ' ';

	return 0;
}
