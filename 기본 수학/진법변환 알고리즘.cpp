#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

void to_10_solution(string& n, int b) { // b진법을 10진법으로 바꾸는 알고리즘
	int size = n.length();
	int count = 0;
	long long result = 0;

	for (int i = size - 1; i >= 0; i--) {
		if (n[i] >= 'A' && n[i] <= 'Z') {
			result += (n[i] - 55) * pow(b, count);
		}
		else {
			result += (n[i] - '0') * pow(b, count);
		}
		count++; // 자리수
	}
	cout << result << '\n';
}

void to_b_solution(int n, int b) { // 10진법을 b진법으로 바꾸는 알고리즘
	string answer = "";
	int rest;
	while (n > 0) {
		rest = n % b;
		if (rest < 10) {
			answer += (rest + '0');
		}
		else { // 알파벳으로 저장
			answer += (rest + 55);
		}
		n /= b;
	}
	reverse(answer.begin(), answer.end());
	cout << answer << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, b;
	cin >> n >> b; // 10진수 n을 b진법

	to_b_solution(n, b);

	return 0;
}
