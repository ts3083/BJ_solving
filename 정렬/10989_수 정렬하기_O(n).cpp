#include <iostream>
using namespace std;

/*
입력되는 수의 개수는 천만개이다.
만약 sort함수를 활용한다면 O(nlogn)이 걸리기 때문에 제한시간 5초를 초과하게 될 것이다.
따라서 O(n)이 될 수 있도록 작성한다.

입력되는 수는 10,000보다 작거나 같은 자연수이므로 1부터 1만개의 bucket을 만든다.
*/
//그냥 cin cout을 이용하면 시간초과가 발생한다. printf를 쓰면 되지만 c++ 입출력을 그대로 쓴다면 장치가 필요하다.

int main()
{
	ios_base::sync_with_stdio(false); // c 표존 stream과 c++ 표준 stream의 동기화를 끊는다(2가지 섞어서 사용불가)
	cin.tie(NULL); // cin을 cout으로부터 untie
	cout.tie(NULL); // cout을 cin으로부터 untie

	int bucket[10001] = { 0 };
	int N, num;
	cin >> N; // 최대 천만개의 수의 개수 입력받음
	for (int i = 0; i < N; i++) {
		cin >> num;
		bucket[num]++; // 입력된 num의 원소를 1증가시키기
	}
	for (int i = 1; i <= 10000; i++) { // bucket 원소값만큼 반복하여 i를 출력
		if (bucket[i] != 0) {
			for (int j = 0; j < bucket[i]; j++)
				cout << i << '\n';
		}
	}

	return 0;
}
