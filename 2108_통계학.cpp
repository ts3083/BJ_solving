#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath> // floor함수를 사용하기 위해 포함
using namespace std;

int main()
{
	vector<int> v;
	int num[8001] = { 0 }; // 숫자의 범위가 -4000 ~ 4000
	int n;
	double avg, sum = 0;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
		sum += x;
		num[x + 4000]++;
	}

	// 산술평균
	avg = floor(sum / n + 0.5); 
	cout << avg << '\n';

	// 중앙값
	sort(v.begin(), v.end()); // sort함수를 통해 정렬
	int m = (n / 2);
	cout << v[m] << '\n';

	// 최빈값
	int index = -1;
	int cnt_max = 0; // 입력된 숫자의 가장 큰 빈도 수 저장
	for (int i = 0; i < 8001; i++) {
		if (num[i] > cnt_max) {
			cnt_max = num[i]; // dnt_max는 제일 큰 원소값이 되고 그때의 i - 4000은 최빈값
			index = i; // index에 최빈값을 저장
		}
	}
	for (int i = 0; i < 8001; i++) { // 최빈값이 2개 이상일 경우 두 번째로 작은 값을 찾기
		if (num[i] == cnt_max && i != index) { // 제일 큰 빈도 수를 갖는 원소 중에 위의 결과로 나온 최빈값이 아닌 숫자 찾기
			index = i; // 최빈값 변경
			break; // 최빈값이 3개 이상일 경우 더 이상 변경되지 않도록 반복문 강제종료
		}
	}
	cout << index - 4000 << '\n';

	// 범위
	cout << v.back() - v.front() << '\n';
	

	return 0;
}