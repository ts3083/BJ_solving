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
	cout << "행렬의 개수 : ";
	cin >> n;
	
	vector<int> d(n + 1);
	cout << "각 행렬의 행과 열의 값을 입력 : \n";
	cin >> d[0] >> d[1];
	for (int i = 1; i < n; i++) {
		cin >> a >> b;
		d[i + 1] = b;
	}

	cout << "곱셈의 최소 횟수 : " << minmult(n, d) << '\n';
	cout << "M행렬 출력\n";
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << M[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << "\np행렬 출력\n";
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << p[i][j] << ' ';
		}
		cout << '\n';
	}

	cout << "최적의 해를 주는 순서의 출력 : ";
	order(1, n);

	return 0;
}