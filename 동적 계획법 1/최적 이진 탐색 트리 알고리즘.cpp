#include <iostream>
#include <vector>
#include <string>
using namespace std;

void OptimalBST(double p[], int n) { // 최적 이진 탐색 트리 알고리즘
	int i, j, h, k, k_result = 0;
	double p_sum;
	vector<vector<double>> A(n + 2, vector<double>(n + 2, 0)); // n행 n열 2차원배열 선언
	vector<vector<int>> r(n + 2, vector<int>(n + 2, 0)); // 최소값을 갖는 k를 저장하는 2차원 배열 선언
	for (i = 1; i <= n; i++) {
		A[i][i] = p[i];
		r[i][i] = i;
	}
	for (h = 1; h < n; h++) {
		for (i = 1; i <= n - h; i++) {
			j = i + h;
			p_sum = 0;
			for (k = i; k <= j; k++) {
				p_sum += p[k];
			}
			A[i][j] = 10000.0;
			for (k = i; k <= j; k++) {
				double temp = A[i][k - 1] + A[k + 1][j] + p_sum;
				if (A[i][j] > temp) {
					A[i][j] = temp;
					k_result = k;
				}
			}
			r[i][j] = k_result;
		}
	}

	cout << "최소 탐색 비용 : " << A[1][n] << '\n';
	cout << "A배열 : \n";
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			cout << A[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << "r배열 : \n";
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			cout << r[i][j] << ' ';
		}
		cout << '\n';
	}
}

int main()
{
	int n;
	double p[101];
	double d;
	string str;
	cin >> n; // 노드 개수 입력받기
	for (int i = 1; i <= n; i++) {
		cin >> str; // 각 노드 탐색비용 입력받기
		d = stod(str);
		p[i] = d;
	}

	OptimalBST(p, n);

	return 0;
}