#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int t, temp;
	cin >> t;
	string str;
	char c;

	for (int i = 0; i < t; i++) {
		temp = 0;
		stack<char> s;
		cin >> str;
		for (int j = 0; j < str.length(); j++) {
			c = str[j];
			if (c == '(')
				s.push(c);
			else {
				if (s.empty()) {
					temp++;
					break;
				}
				s.pop();
			}
		}
		if (temp == 0 && s.empty())
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';
	}

	return 0;
}