#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class gr {
public:
	int cin_n; // �Է¹��� ����
	int com; // ��ǥ������ ���
	int cin_index; // ó�� �Էµ� ���� �Է� ������ ����
	gr(int a = 0, int b = 0, int c = 0) : cin_n(a), com(b), cin_index(c) {}
};

bool compare_1(gr a, gr b) {
	return a.cin_n < b.cin_n; // �Է¹��� ���ڸ� �������� �������� ����
}

bool compare_2(gr a, gr b) {
	return a.cin_index < b.cin_index; // ó�� �Էµ� ������ ������ ����ߴٰ� ����
}

int main()
{
	int num;
	int number;
	gr group;
	cin >> num;
	vector<gr> v; // num��ŭ ���� ���� �� 0���� �ʱ�ȭ

	for (int i = 0; i < num; i++) {
		cin >> number;
		group.cin_n = number;
		group.cin_index = i;
		v.push_back(group);
	}
	sort(v.begin(), v.end(), compare_1); // �Է¹��� ���ڸ� �������� ����
	
	// ��ǥ���� ���ϱ� + ���� ���´� �Է¹��� ���ڰ� ���� ���� �Ǿ� ū���� �ǵڿ� �ִ� �׷� ����
	int count = 0;
	for (int i = 0; i < num; i++) {
		v[i].com = count;
		if ((i != num - 1) && v[i].cin_n < v[i + 1].cin_n) {
			count++;
		}
	} // ��ǥ���� ��� �Է¿Ϸ�

	// �ٽ� �Է¹��� ������� �����ϰ� ��ǥ���� ���
	sort(v.begin(), v.end(), compare_2); // �Էµ� ������ �������� ����

	for (int i = 0; i < num; i++) {
		cout << v[i].com << " ";
	}

	return 0;
}