#include <iostream>
#include <vector>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);

	int n, m, num; // ������ �� / ���������� �ϴ� ���� ����
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
		long long height = (start + end) / 2; // �߰� ���̸� ���̷� ����
		long long sum = 0;
		for (int i = 0; i < n; i++) {
			sang = namu[i] - height;
			if (sang > 0) {
				sum += sang; // sum�� ����� �������� ������ ���� ��
			}
		}

		if (sum >= m) { // ���� ���̷� �ڸ� ������ ���̰� �����������ϴ� �������̺��� �� ���
			start = height + 1;
			result = height;
		}
		else { // sum < m / ���� ���̷� �ڸ��� ���ϴ� ���� ���� �� ���� ���̸� �������� = ���� ���̱�
			end = height - 1;
		}
	}

	cout << result << '\n';

	return 0;
}