#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(int a, int b) {
	return a > b;
}

int main()
{
	string s;
	cin >> s; // ���ڿ��� ó���� ���ڸ� �Է¹ޱ�
	vector<int> v(s.length());
	for (int i = 0; i < s.length(); i++) {
		v[i] = s[i] - '0';
	}
	sort(v.begin(), v.end(), compare); // �������� ����

	for (int i = 0; i < v.size(); i++) {
		cout << v[i];
	}

	return 0;
}