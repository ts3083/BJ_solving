#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<string> white{
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW"
};
vector<string> black{
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB"
};

int check(vector<string>& graph, int i, int j) {
	int count1 = 0;
	int count2 = 0;
	// w로 시작하는 체스판
	for (int a = 0; a < 8; a++) {
		for (int b = 0; b < 8; b++) {
			if (graph[i + a][j + b] != white[a][b])
				count1++;
		}
	}
	
	for (int a = 0; a < 8; a++) {
		for (int b = 0; b < 8; b++) {
			if (graph[i + a][j + b] != black[a][b])
				count2++;
		}
	}
	
	return min(count1, count2);
}

int main()
{
	int n, m;
	cin >> n >> m; // m이 가로, n이 세로
	string str;
	vector<string> graph;
	for (int i = 0; i < n; i++) {
		cin >> str;
		graph.push_back(str);
	}

	vector<int> cnt;
	int c;
	for (int i = 0; i <= n - 8; i++) {
		for (int j = 0; j <= m - 8; j++) {
			c = check(graph, i, j);
			cnt.push_back(c);
		}
	}

	int mi = 1e9;
	for (int i = 0; i < cnt.size(); i++) {
		mi = min(cnt[i], mi);
	}

	cout << mi << '\n';	

	return 0;
}