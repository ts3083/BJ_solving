#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> n(1000001);

void InitNext(string& p, int M) { // next 배열을 찾기위한 함수
	int i = 1, j = 0;
	n[0] = 0;
	for (i; i < M; i++) {
		while (p[i] != p[j]) { // 불일치가 일어나면
			if (j == 0) { // j가 0이면 n[i]에 0을 저장하고 탈출
				n[i] = j;
				break;
			}
			j = n[j - 1]; // j-1번째까지 접미패턴과 겹치는 정보를 활용해서 비교할 j를 다시 설정
		}
		if (p[i] == p[j])
			n[i] = ++j;
	}
}

int KMP(string& p, string& t, int M, int N) { // KMP 알고리즘
	int j = 0, i = 0;
	InitNext(p, M); // next배열 만들기
	for (i; i < N; i++) { // text끝까지 반복
		while (t[i] != p[j]) { // 불일치가 일어나면
			if (j == 0) // 패턴의 첫번째 문자와 불일치가 일어나면 j는 그대로, i는 하나 증가해서 다음 문자열 비교
				break;
			j = n[j - 1];
		}
		if (t[i] == p[j]) { // 일치가 일어나면
			j++;
			if (j == M) // j가 M까지 커지면 패턴이 모두 일치했다는 뜻
				return 1;
		}
	}
	return 0;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	string text, pattern;
	cin >> text >> pattern;
	
	int N = text.length();
	int M = pattern.length();
	
	int result = KMP(pattern, text, M, N);
	cout << result << '\n';

	return 0;
}

