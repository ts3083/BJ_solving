#include <iostream>
#include <string>
using namespace std;

/*
그룹단어 : 각 문자가 연속해서만 나타나는 단어
예) ccazzzbb, kin ...
aabbbcca와 같이 떨어져서 나오는 문자가 있으면 그룹단어가 아니다

먼저 문자열을 string 자료형을 사용, 문자열을 입력받는다.
문자는 소문자 알파벳만이 입력됨으로 26개의 int형 배열을 선언하고 0으로 초기화한다. + a가 0이고 z는 26번째 배열
입력받은 문자열의 처음 원소값부터 문자열 길이만큼 이동하며 자신의 원소값과 바로 다음의 원소값이 다르다면 해당 문자열에 해당하는 원소값을 1증가
만약 문자가 그룹단어가 아니라면 떨어져서 입력된 문자열의 원소값이 2이상이다. (다음 원소값과 비교, 다르다면 1증가하는데 떨어져서 나온 문자는 2번 다르기 때문)
*/

bool check_group(int arr[], int size) { // 그룹단어를 체크하는 함수
	int j = 0;
	for (int i = 0; i < size; i++) { // 만약 원소값이 2이상 것이 있다면 j가 0이 아니다
		if (arr[i] >= 2)
			j++;
	}
	if (j > 0)
		return false; // 떨어져서 존재하는 문자가 있다는 의미 => false : 그룹단어가 아니다
	else
		return true; // true : 그룹단어이다.
}

int main()
{
	int num;
	int count = 0;
	cin >> num;
	for (int i = 0; i < num; i++) {
		string s;
		int check[26] = { 0 }; // 알파벳 갯수만큼 배열 생성 + 0으로 초기화
		cin >> s;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] != s[i + 1]) // 바로 다음 원소값과 비교, 다르다면 원소값 1증가
				check[s[i] - 97] += 1;
		}
		if (check_group(check, 26) == true) // 그룹단어이면 count 1증가
			count++;
	}
	cout << count << endl; // 그룹단어의 갯수 출력
	
	return 0;
}
