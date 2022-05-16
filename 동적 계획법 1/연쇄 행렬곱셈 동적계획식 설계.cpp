#include <iostream>
#include <vector>
#define INTMAX 1e9
using namespace std;

int p[100][100];
int M[100][100];
int minmult(int n, vector<int>& d) {
	int i, j, k, diagonal, temp, result = 0;
	int min = INTMAX;
	for (i = 1; i <= n; i++)
		M[i][i] = 0;
	for (diagonal = 1; diagonal <= n - 1; diagonal++) {
		for (i = 1; i <= n - diagonal; i++) {
			j = i + diagonal;
			M[i][j] = min;
			for (k = i; k < j; k++) {
				temp = M[i][k] + M[k + 1][j] + d[i - 1] * d[k] * d[j];
				if (temp < M[i][j]) {
					M[i][j] = temp;
					result = k;
				}
			}
			p[i][j] = result;
		}
	}
	return M[1][n];
}

void order(int i, int j) {
	int k;
	if (i == j)
		cout << 'A' << i;
	else {
		k = p[i][j];
		cout << '(';
		order(i, k);
		order(k + 1, j);
		cout << ')';
	}
}

int main()
{
	int n, a, b;
	cout << "����� ���� : ";
	cin >> n;
	
	vector<int> d(n + 1);
	cout << "�� ����� ��� ���� ���� �Է� : \n";
	cin >> d[0] >> d[1];
	for (int i = 1; i < n; i++) {
		cin >> a >> b;
		d[i + 1] = b;
	}

	cout << "������ �ּ� Ƚ�� : " << minmult(n, d) << '\n';
	cout << "M��� ���\n";
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << M[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << "\np��� ���\n";
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << p[i][j] << ' ';
		}
		cout << '\n';
	}

	cout << "������ �ظ� �ִ� ������ ��� : ";
	order(1, n);

	return 0;
}