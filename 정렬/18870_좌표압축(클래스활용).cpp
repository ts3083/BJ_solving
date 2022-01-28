#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class gr {
public:
	int cin_n; // 입력받은 숫자
	int com; // 좌표압축의 결과
	int cin_index; // 처음 입력될 때의 입력 순서의 저장
	gr(int a = 0, int b = 0, int c = 0) : cin_n(a), com(b), cin_index(c) {}
};

bool compare_1(gr a, gr b) {
	return a.cin_n < b.cin_n; // 입력받은 숫자를 기준으로 오름차순 정렬
}

bool compare_2(gr a, gr b) {
	return a.cin_index < b.cin_index; // 처음 입력된 숫자의 순서를 기억했다가 정렬
}

int main()
{
	int num;
	int number;
	gr group;
	cin >> num;
	vector<gr> v; // num만큼 벡터 생성 후 0으로 초기화

	for (int i = 0; i < num; i++) {
		cin >> number;
		group.cin_n = number;
		group.cin_index = i;
		v.push_back(group);
	}
	sort(v.begin(), v.end(), compare_1); // 입력받은 숫자를 기준으로 정렬
	
	// 좌표압축 구하기 + 지금 상태는 입력받은 숫자가 작은 값이 맨앞 큰값이 맨뒤에 있는 그런 상태
	int count = 0;
	for (int i = 0; i < num; i++) {
		v[i].com = count;
		if ((i != num - 1) && v[i].cin_n < v[i + 1].cin_n) {
			count++;
		}
	} // 좌표압축 결과 입력완료

	// 다시 입력받은 순서대로 정렬하고 좌표압축 출력
	sort(v.begin(), v.end(), compare_2); // 입력된 순서를 기준으로 정렬

	for (int i = 0; i < num; i++) {
		cout << v[i].com << " ";
	}

	return 0;
}
