#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);

	int n, num;
	cin >> n;
	vector<int> v;
	vector<char> result;
	stack<int> s;
	for (int i = 0; i < n; i++) {
		cin >> num;
		v.push_back(num);
	}

	int cnt = 1;
	int i = 0;
	for (int j = 0; j < 2 * n; j++) {
		if (!s.empty()) {
			if (v[i] != s.top()) {
				s.push(cnt);
				result.push_back('+');
				cnt++;
			}
			else {
				s.pop();
				result.push_back('-');
				i++;
			}
		}
		else {
			s.push(cnt);
			result.push_back('+');
			cnt++;
		}
	}

	if (s.empty()) {
		for (int i = 0; i < result.size(); i++) {
			cout << result[i] << '\n';
		}
	}
	else {
		cout << "NO" << '\n';
	}

	return 0;
}