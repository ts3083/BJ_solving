#include <iostream>
#include <string>
using namespace std;

int n[50];

void InitNext(string& p, int M) {
	int i = 1, j = 0;
	n[0] = 0;
	for (i; i < M; i++) {
		while (p[i] != p[j]) {
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

void KMP(string& t, string& p, int N, int M) {
	int i = 0, j = 0;
	InitNext(p, M);
	for (i; i < N; i++) {
		while (t[i] != p[j]) {
			if (j == 0)
				break;
			j = n[j - 1];
		}
		if (t[i] == p[j]) {
			j++;
			if (j == M) {
				cout << "패턴이 발생한 위치 : " << i - M + 1 << '\n';
				j = n[j - 1];
			}
		}
	}
	cout << "스트링 탐색 종료\n";
}

int main()
{
	string ex1 = "ababababcababababcaabbabababcaab";
	string pattern1 = "abababca";
	string ex2 = "This class is an algorithm design class. Therefore, students will have time to learn about algorithms and implement each algorithm themselves.";
	string pattern2 = "algorithm";

	int M1 = pattern1.length();
	int N1 = ex1.length();
	int M2 = pattern2.length();
	int N2 = ex2.length();

	KMP(ex1, pattern1, N1, M1);
	KMP(ex2, pattern2, N2, M2);

	return 0;
}