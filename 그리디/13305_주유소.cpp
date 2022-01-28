#include <iostream>
#include <vector>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	long long n, m;
	long long min_liter = 0;
	long long sum = 0;
	vector<long> dist; // 도시 사이의 거리
	vector<long> cost; // 도시의 리터당 가격
	cin >> n; // 도시 개수 입력받기
	for (int i = 0; i < n - 1; i++) {
		cin >> m;
		dist.push_back(m);
	}
	for (int i = 0; i < n; i++) {
		cin >> m;
		cost.push_back(m);
	}
	// 거리와 주유소 가격이 결정된 상태

	min_liter = cost[0];
	for (int i = 1; i <= n - 1; i++) { 
		if (min_liter > cost[i]) { // 다음 도시의 주유값이 더 싸다면 최소한 만을 넣고 
			sum += min_liter * dist[i - 1];
			min_liter = cost[i]; // 최소 주유값 교체
		}
		else { // 다음 주유값이 더 비싸다면 최소 주유값을 유지
			sum += min_liter * dist[i - 1];
		}
	}
	cout << sum << '\n';

	return 0;
}
