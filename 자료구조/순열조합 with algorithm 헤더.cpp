#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(int a, int b) {
	return a > b;
}

void permutation_increase(vector<int>& vec) { // 오름차순 컨테이너의 모든 순열 생성
	sort(vec.begin(), vec.end()); // 오름차순
	do {
		for (int i = 0; i < vec.size(); i++) {
			cout << vec[i] << ' ';
		}
		cout << '\n';
	} while (next_permutation(vec.begin(), vec.end()));
}

void permutation_decrease(vector<int>& vec) { // 내림차순 컨테이너의 모든 순열 생성
	sort(vec.begin(), vec.end(), compare); // 내림차순
	do {
		for (int i = 0; i < vec.size(); i++) {
			cout << vec[i] << ' ';
		}
		cout << '\n';
	} while (prev_permutation(vec.begin(), vec.end()));
}

void combination(vector<int>& temp, vector<int>& vec) {
	sort(temp.begin(), temp.end()); // 오름차순
	do {
		for (int i = 0; i < temp.size(); i++) {
			if (temp[i] == 1)
				cout << vec[i] << ' ';
		}
		cout << '\n';
	} while (next_permutation(temp.begin(), temp.end()));
}

int main()
{
	vector<int> vec = { 1, 2, 3, 5 };
	vector<int> temp = { 1, 1, 1, 0 };  // 1의 개수가 nCr에서 r을 결정

	combination(temp, vec);
	
	return 0;
}
