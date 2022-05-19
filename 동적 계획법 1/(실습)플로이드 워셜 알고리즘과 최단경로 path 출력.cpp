#include <iostream>
#include <iomanip>
#define INF 1e9
using namespace std;

int W[6][6] = {
	{0,0,0,0,0,0},
	{0,0,1,INF,1,5},
	{0,9,0,3,2,INF},
	{0,INF,INF,0,4,INF},
	{0,INF,INF,2,0,3},
	{0,3,INF,INF,INF,0}
};
int P[6][6];
int D[6][6];

void floyd2(int n) {
	int i, j, k;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			D[i][j] = W[i][j];
		}
	}
	for (k = 1; k <= n; k++) {
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= n; j++) {
				int temp = D[i][k] + D[k][j];
				if (temp < D[i][j]) {
					P[i][j] = k;
					D[i][j] = temp;
				}
			}
		}
	}
	
	cout << "D[i][j] is\n";
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			cout << setw(3) << D[i][j];
		}
		cout << '\n';
	}
	cout << '\n';
	cout << "P[i][j] is\n";
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			cout << setw(3) << P[i][j];
		}
		cout << '\n';
	}
	cout << '\n';
}

void path(int q, int r) {
	if (P[q][r] != 0) {
		path(q, P[q][r]);
		cout << " v" << P[q][r] << "->";
		path(P[q][r], r);
	}
}

void print_path(int q, int r) {
	cout << "The shortest path(" << q << ", " << r << ") is v" << q << "->";
	path(q, r);
	cout << " v" << r << '\n';
}

int main()
{
	int n = 5;
	floyd2(n);
	print_path(5, 3);
	print_path(1, 3);
	print_path(2, 5);

	return 0;
}