#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

bool compare(string a, string b) { // sort�� �� ��° ���� ������ �ֱ� ���� compare�Լ� �ۼ�
	if (a.length() != b.length()) // ���ڿ��� ���̰� ���� �ʴٸ�
		return a.length() < b.length(); // ���ڿ��� ���̰� ū ���ڿ��� �ڷ� ������ ����(��������)
	else // ���ڿ��� ���̰� ���ٸ�
		return a < b; // ���� ������ ����, ���������� �ڷ� ������ ���ڿ��� �� ũ���� ������(string ������ �����ε�)
}

int main()
{
	int size; 
	cin >> size;
	vector<string> v; // string �迭 �����Ҵ��� ���� vector��ü ����
	string str; // ���ڿ� ������ �����ϱ� ���� string ��ü ����

	for (int i = 0; i < size; i++) {
		cin >> str;
		v.push_back(str); // �Է¹��� ���ڿ� vector�� ����
	}
	// ���ڿ� ���� �Է� �� ����
	sort(v.begin(), v.end(), compare); // compare�� ��ȯ���� ���缭 ������ ����

	for (int i = 0; i < v.size(); i++) {
		if (i != 0 && v[i - 1] == v[i]) // ù��° ���ڿ��� ��� ����ϰ� �ٷ� ������ ���ڿ��� ���� ���ڿ��̶�� ����� �н�
			continue;
		else // ù��° ���ڿ��� ��� + (i - 1)�� i��° ���ڿ��� �ٸ� �� i��° ���ڿ� ���
			cout << v[i] << '\n';
	}

	return 0;
}