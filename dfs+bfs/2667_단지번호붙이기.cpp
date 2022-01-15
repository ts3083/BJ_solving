#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int h_num = 0;
int graph[25][25] = { 0 };
vector<int> house_num; // 단지에 속하는 집의 수 리스트로 각각 저장
int dx[] = {-1, 1, 0, 0}; // 상하좌우
int dy[] = {0, 0, -1, 1}; // 상하좌우

void visit(int x, int y, int n) { // 연결된 집을 모두 방문하기 위한 재귀함수 작성
	if (x < 0 || y < 0 || x >= n || y >= n) // 범위를 벗어난다면 그대로 종료
		return;
	graph[x][y] = 0; // 방문하면 0으로 바꾸기
	h_num++; // 단지에 속하는 집의 수 셈하기
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
	int cnt = 0; // 단지수를 저장하는 변수
	int n; // 지도의 크기를 저장하는 변수
	cin >> n;
	vector<string> str(n); // 먼저 문자열로 자료를 입력 받기위해 문자열 vector 생성
	
	for (int i = 0; i < n; i++) {
		cin >> str[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			graph[i][j] = str[i][j] - '0'; // 문자를 정수로 변경
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (graph[i][j] == 1) {
				visit(i, j, n); // 연결된 집을 모두 방문
				cnt++; // 단지수 세기
				house_num.push_back(h_num);
				h_num = 0; // 단지내 집의 수 0으로 초기화
			}
		}
	}

	cout << cnt << '\n'; // 총 단지수 출력
	sort(house_num.begin(), house_num.end()); // 단지내 지의 수를 저장한 vector를 오름차순 정렬
	for (int i = 0; i < house_num.size(); i++)
		cout << house_num[i] << '\n'; // 각 단지내 집의 수를 출력

	return 0;
}