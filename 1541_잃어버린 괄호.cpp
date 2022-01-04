#include <iostream>
#include <string>
using namespace std;

int main()
{
	int sum = 0;
	int result = 0;
	int index_end = 0;
	string s;
	string temp = "";
	cin >> s;

	for (int i = 0; i <= s.length(); i++) {
		if (s[i] == '+' || s[i] == '-' || s[i] == '\0') {
			if (result) {
				sum -= stoi(temp);
			}
			else {
				sum += stoi(temp);
			}
			if (s[i] == '-') {
				result = 1; // -가 1번만 등장해도 뒤의 모든 숫자들을 빼주면 된다.
			}
			temp = ""; // temp에 저장된 문자열 초기화
			continue;
		}
		temp += s[i];
	}
	cout << sum << '\n';

	return 0;
}