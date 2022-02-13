#include <iostream>
#include <vector>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);

	int n, m, num; // 나무의 수 / 가져가고자 하는 나무 길이
	cin >> n >> m;
	
	vector<int> namu;
	int max = 0;
	for (int i = 0; i < n; i++) {
		cin >> num;
		namu.push_back(num);
		if (num > max)
			max = num;
	}

	int sang;
	int start = 1;
	int end = max;
	int result = 0;
	while (start <= end) {
		long long height = (start + end) / 2; // 중간 길이를 높이로 설정
		long long sum = 0;
		for (int i = 0; i < n; i++) {
			sang = namu[i] - height;
			if (sang > 0) {
				sum += sang; // sum은 상근이 가져가는 나무의 길이 합
			}
		}

		if (sum >= m) { // 지금 높이로 자른 나무의 길이가 가져가고자하는 나무길이보다 더 길다
			start = height + 1;
			result = height;
		}
		else { // sum < m / 지금 높이로 자르면 원하는 길이 보다 더 작은 길이를 가져간다 = 길이 줄이기
			end = height - 1;
		}
	}

	cout << result << '\n';

	return 0;
}