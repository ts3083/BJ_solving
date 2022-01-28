#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

bool compare(string a, string b) { // sort의 세 번째 인자 값으로 넣기 위한 compare함수 작성
	if (a.length() != b.length()) // 문자열의 길이가 같지 않다면
		return a.length() < b.length(); // 문자열의 길이가 큰 문자열이 뒤로 가도록 정렬(오름차순)
	else // 문자열의 길이가 같다면
		return a < b; // 사전 순으로 정렬, 사전적으로 뒤로 갈수록 문자열이 더 크도록 설정됨(string 연산자 오버로딩)
}

int main()
{
	int size; 
	cin >> size;
	vector<string> v; // string 배열 동적할당을 위한 vector객체 생성
	string str; // 문자열 변수를 저장하기 위한 string 객체 생성

	for (int i = 0; i < size; i++) {
		cin >> str;
		v.push_back(str); // 입력받은 문자열 vector에 저장
	}
	// 문자열 정보 입력 후 정렬
	sort(v.begin(), v.end(), compare); // compare의 반환값에 맞춰서 정렬이 동작

	for (int i = 0; i < v.size(); i++) {
		if (i != 0 && v[i - 1] == v[i]) // 첫번째 문자열일 결우 재외하고 바로 직전의 문자열과 같은 문자열이라면 출력을 패스
			continue;
		else // 첫번째 문자열의 경우 + (i - 1)과 i번째 문자열이 다를 때 i번째 문자열 출력
			cout << v[i] << '\n';
	}

	return 0;
}
