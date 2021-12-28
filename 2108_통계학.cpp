#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath> // floor�Լ��� ����ϱ� ���� ����
using namespace std;

int main()
{
	vector<int> v;
	int num[8001] = { 0 }; // ������ ������ -4000 ~ 4000
	int n;
	double avg, sum = 0;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
		sum += x;
		num[x + 4000]++;
	}

	// ������
	avg = floor(sum / n + 0.5); 
	cout << avg << '\n';

	// �߾Ӱ�
	sort(v.begin(), v.end()); // sort�Լ��� ���� ����
	int m = (n / 2);
	cout << v[m] << '\n';

	// �ֺ�
	int index = -1;
	int cnt_max = 0; // �Էµ� ������ ���� ū �� �� ����
	for (int i = 0; i < 8001; i++) {
		if (num[i] > cnt_max) {
			cnt_max = num[i]; // dnt_max�� ���� ū ���Ұ��� �ǰ� �׶��� i - 4000�� �ֺ�
			index = i; // index�� �ֺ��� ����
		}
	}
	for (int i = 0; i < 8001; i++) { // �ֺ��� 2�� �̻��� ��� �� ��°�� ���� ���� ã��
		if (num[i] == cnt_max && i != index) { // ���� ū �� ���� ���� ���� �߿� ���� ����� ���� �ֺ��� �ƴ� ���� ã��
			index = i; // �ֺ� ����
			break; // �ֺ��� 3�� �̻��� ��� �� �̻� ������� �ʵ��� �ݺ��� ��������
		}
	}
	cout << index - 4000 << '\n';

	// ����
	cout << v.back() - v.front() << '\n';
	

	return 0;
}