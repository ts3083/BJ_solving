#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	vector<string> v = { "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z=" };
	// string 자료형 vector 생성 + 각각의 원소는 string data이다.
	string s;
	cin >> s;
	for (int i = 0; i < v.size(); i++) {
		for (;;) {
			if (s.find(v[i]) == string::npos) { // find함수를 통해 문자열 찾기 + 문자열이 없다면 npos 반환
				break;
			}
			else { // 찾고자하는 문자열을 찾는다면 교체
				s.replace(s.find(v[i]), v[i].length(), "a");
			}
		}
	}
	cout << s.length() << endl;

	return 0;
}
