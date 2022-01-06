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
	vector<long> dist; // ���� ������ �Ÿ�
	vector<long> cost; // ������ ���ʹ� ����
	cin >> n; // ���� ���� �Է¹ޱ�
	for (int i = 0; i < n - 1; i++) {
		cin >> m;
		dist.push_back(m);
	}
	for (int i = 0; i < n; i++) {
		cin >> m;
		cost.push_back(m);
	}
	// �Ÿ��� ������ ������ ������ ����

	min_liter = cost[0];
	for (int i = 1; i <= n - 1; i++) { 
		if (min_liter > cost[i]) { // ���� ������ �������� �� �δٸ� �ּ��� ���� �ְ� 
			sum += min_liter * dist[i - 1];
			min_liter = cost[i]; // �ּ� ������ ��ü
		}
		else { // ���� �������� �� ��δٸ� �ּ� �������� ����
			sum += min_liter * dist[i - 1];
		}
	}
	cout << sum << '\n';

	return 0;
}