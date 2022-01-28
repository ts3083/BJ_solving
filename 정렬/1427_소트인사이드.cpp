#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(int a, int b) {
	return a > b;
}

int main()
{
	string s;
	cin >> s; // 문자열로 처음에 숫자를 입력받기
	vector<int> v(s.length());
	for (int i = 0; i < s.length(); i++) {
		v[i] = s[i] - '0';
	}
	sort(v.begin(), v.end(), compare); // 내림차순 정렬

	for (int i = 0; i < v.size(); i++) {
		cout << v[i];
	}

	return 0;
}
