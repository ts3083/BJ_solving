#include <iostream>
#include <algorithm>
using namespace std;

// ���� �Ʒ����� ����ؼ� ������ ���� �����ϴ� �˰��� [n-1][0] -> [0][m-1]
// ���� ������ ����ؼ� ������ �Ʒ��� �����ϴ� �˰��� [0][0] -> [n-1][m-1]
// �㵣�� ��ġ���� -1�� ����
int graph1[9][9] = {
	{0,0,1,0,0,0,0,0,0},
	{0,0,0,0,0,1,0,-1,0},
	{1,0,-1,0,0,0,0,1,0},
	{0,0,0,0,1,-1,0,0,0},
	{0,1,0,1,0,0,0,0,0},
	{0,0,0,0,0,-1,1,-1,0},
	{0,1,0,0,1,0,0,0,0},
	{0,0,0,0,0,1,0,0,0},
	{0,0,0,0,0,0,0,0,0}
};
int graph2[9][9] = {
	{0,0,1,0,0,0,0,0,0},
	{0,0,0,0,0,1,0,-1,0},
	{1,0,-1,0,0,0,0,1,0},
	{0,0,0,0,1,-1,0,0,0},
	{0,1,0,1,0,0,0,0,0},
	{0,0,0,0,0,-1,1,-1,0},
	{0,1,0,0,1,0,0,0,0},
	{0,0,0,0,0,1,0,0,0},
	{0,0,0,0,0,0,0,0,0}
};

int main()
{
	int n = 9, m = 9;
	// �ʱⰪ ����
	for (int i = 1; i < n; i++) {
		if (graph1[i][0] == -1 || graph1[i - 1][0] == - 1)
			continue;
		graph1[i][0] = graph1[i][0] + graph1[i - 1][0];
	}
	for (int j = 1; j < m; j++) {
		if (graph1[0][j] == -1 || graph1[0][j - 1] == -1)
			continue;
		graph1[0][j] = graph1[0][j] + graph1[0][j - 1];
	}

	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			if (graph1[i][j] == -1)
				continue;
			
			int left = graph1[i][j - 1];
			int up = graph1[i - 1][j];
			if (left == -1)
				left = 0;
			if (up == -1)
				up = 0;
			graph1[i][j] = max(left, up) + graph1[i][j];
		}
	}

	for (int i = n - 2; i >= 0; i--) {
		if (graph2[i][0] == -1 || graph2[i + 1][0] == -1)
			continue;
		graph2[i][0] = graph2[i][0] + graph2[i + 1][0];
	}
	for (int j = 1; j < m; j++) {
		if (graph2[n - 1][j] == -1 || graph2[n - 1][j - 1] == -1)
			continue;
		graph2[n - 1][j] = graph2[n - 1][j] + graph2[n - 1][j - 1];
	}

	for (int i = n - 2; i >= 0; i--) {
		for (int j = 1; j < m; j++) {
			if (graph2[i][j] == -1)
				continue;

			int left = graph2[i][j - 1];
			int down = graph2[i + 1][j];
			if (left == -1)
				left = 0;
			if (down == -1)
				down = 0;
			graph2[i][j] = max(left, down) + graph2[i][j];
		}
	}

	cout << "������ �Ʒ��� �ⱸ�� ��� ġ���� �ִ밪 : " << graph1[n - 1][m - 1] << '\n';
	cout << "������ ���� �ⱸ�� ��� ġ���� �ִ밪 : " << graph2[0][m - 1] << '\n';

	return 0;
}