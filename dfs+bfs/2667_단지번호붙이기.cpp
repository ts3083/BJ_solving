#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int h_num = 0;
int graph[25][25] = { 0 };
vector<int> house_num; // ������ ���ϴ� ���� �� ����Ʈ�� ���� ����
int dx[] = {-1, 1, 0, 0}; // �����¿�
int dy[] = {0, 0, -1, 1}; // �����¿�

void visit(int x, int y, int n) { // ����� ���� ��� �湮�ϱ� ���� ����Լ� �ۼ�
	if (x < 0 || y < 0 || x >= n || y >= n) // ������ ����ٸ� �״�� ����
		return;
	graph[x][y] = 0; // �湮�ϸ� 0���� �ٲٱ�
	h_num++; // ������ ���ϴ� ���� �� ���ϱ�
	for (int i = 0; i < 4; i++) { 
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (graph[nx][ny] == 1)
			visit(nx, ny, n);
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);
	int cnt = 0; // �������� �����ϴ� ����
	int n; // ������ ũ�⸦ �����ϴ� ����
	cin >> n;
	vector<string> str(n); // ���� ���ڿ��� �ڷḦ �Է� �ޱ����� ���ڿ� vector ����
	
	for (int i = 0; i < n; i++) {
		cin >> str[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			graph[i][j] = str[i][j] - '0'; // ���ڸ� ������ ����
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (graph[i][j] == 1) {
				visit(i, j, n); // ����� ���� ��� �湮
				cnt++; // ������ ����
				house_num.push_back(h_num);
				h_num = 0; // ������ ���� �� 0���� �ʱ�ȭ
			}
		}
	}

	cout << cnt << '\n'; // �� ������ ���
	sort(house_num.begin(), house_num.end()); // ������ ���� ���� ������ vector�� �������� ����
	for (int i = 0; i < house_num.size(); i++)
		cout << house_num[i] << '\n'; // �� ������ ���� ���� ���

	return 0;
}