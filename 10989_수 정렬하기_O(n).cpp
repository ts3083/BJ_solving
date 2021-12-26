#include <iostream>
using namespace std;

/*
�ԷµǴ� ���� ������ õ�����̴�.
���� sort�Լ��� Ȱ���Ѵٸ� O(nlogn)�� �ɸ��� ������ ���ѽð� 5�ʸ� �ʰ��ϰ� �� ���̴�.
���� O(n)�� �� �� �ֵ��� �ۼ��Ѵ�.

�ԷµǴ� ���� 10,000���� �۰ų� ���� �ڿ����̹Ƿ� 1���� 1������ bucket�� �����.
*/
//�׳� cin cout�� �̿��ϸ� �ð��ʰ��� �߻��Ѵ�. printf�� ���� ������ c++ ������� �״�� ���ٸ� ��ġ�� �ʿ��ϴ�.

int main()
{
	ios_base::sync_with_stdio(false); // c ǥ�� stream�� c++ ǥ�� stream�� ����ȭ�� ���´�(2���� ��� ���Ұ�)
	cin.tie(NULL); // cin�� cout���κ��� untie
	cout.tie(NULL); // cout�� cin���κ��� untie

	int bucket[10001] = { 0 };
	int N, num;
	cin >> N; // �ִ� õ������ ���� ���� �Է¹���
	for (int i = 0; i < N; i++) {
		cin >> num;
		bucket[num]++; // �Էµ� num�� ���Ҹ� 1������Ű��
	}
	for (int i = 1; i <= 10000; i++) { // bucket ���Ұ���ŭ �ݺ��Ͽ� i�� ���
		if (bucket[i] != 0) {
			for (int j = 0; j < bucket[i]; j++)
				cout << i << '\n';
		}
	}

	return 0;
}