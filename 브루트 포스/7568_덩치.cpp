#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<pair<int, int>> vec;
	pair<int, int> p;
	
	for (int i = 0; i < n; i++) {
		cin >> p.first >> p.second;
		vec.push_back(p);
	}
	
	// ���� Ž���Ͽ� �ڽź��� ū �����Կ� Ű�� ���� ����� ���� ��� ����� 1� �о���� ����
	int rank = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (vec[i].first < vec[j].first && vec[i].second < vec[j].second) {
				rank++;
			}
		}
		cout << rank << ' ';
		rank = 1;
	}
	
	return 0;
}