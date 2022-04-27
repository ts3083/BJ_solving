#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> n(1000001);

void InitNext(string& p, int M) { // next �迭�� ã������ �Լ�
	int i = 1, j = 0;
	n[0] = 0;
	for (i; i < M; i++) {
		while (p[i] != p[j]) { // ����ġ�� �Ͼ��
			if (j == 0) { // j�� 0�̸� n[i]�� 0�� �����ϰ� Ż��
				n[i] = j;
				break;
			}
			j = n[j - 1]; // j-1��°���� �������ϰ� ��ġ�� ������ Ȱ���ؼ� ���� j�� �ٽ� ����
		}
		if (p[i] == p[j])
			n[i] = ++j;
	}
}

int KMP(string& p, string& t, int M, int N) { // KMP �˰���
	int j = 0, i = 0;
	InitNext(p, M); // next�迭 �����
	for (i; i < N; i++) { // text������ �ݺ�
		while (t[i] != p[j]) { // ����ġ�� �Ͼ��
			if (j == 0) // ������ ù��° ���ڿ� ����ġ�� �Ͼ�� j�� �״��, i�� �ϳ� �����ؼ� ���� ���ڿ� ��
				break;
			j = n[j - 1];
		}
		if (t[i] == p[j]) { // ��ġ�� �Ͼ��
			j++;
			if (j == M) // j�� M���� Ŀ���� ������ ��� ��ġ�ߴٴ� ��
				return 1;
		}
	}
	return 0;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	string text, pattern;
	cin >> text >> pattern;
	
	int N = text.length();
	int M = pattern.length();
	
	int result = KMP(pattern, text, M, N);
	cout << result << '\n';

	return 0;
}

