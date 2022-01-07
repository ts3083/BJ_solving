#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2) { // ������ �ð� ���� ��������, ������ ���� �ð� ���� �������� ����
	if (p1.second != p2.second) // ������ �ð��� �ٸ���
		return p1.second < p2.second; // ������ �ð� ��������
	else // ������ �ð��� ���ٸ�
		return p1.first < p2.first; // ���� �ð����� �츧���� ����
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);

	int n;
	int count = 0; // ȸ���� ������ ī��Ʈ
	int end = -1;
	pair<int, int> p; // ȸ�� ���� �ð� / ȸ�� ������ �ð�
	cin >> n; // ȸ�� ����
	vector<pair<int, int>> v; // ��ü ȸ��
	for (int i = 0; i < n; i++) {
		cin >> p.first >> p.second;
		v.push_back(p);
	}

	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < v.size(); i++) {
		if (v[i].first >= end) {
			end = v[i].second;
			count++;
		}
	}
	cout << count << '\n';

	return 0;
}