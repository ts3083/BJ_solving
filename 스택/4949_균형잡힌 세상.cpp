#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);

	while (1) {
		string str;
		stack<char> s;
		getline(cin, str);
		if (str == ".")
			break;
		
		for (int i = 0; i < str.length(); i++) {
			char c = str[i];
			if (c == '(' || c == '[') {
				s.push(c);
			}
			else if (c == ')') {
				if (!s.empty()) {
					if (s.top() == '(')
						s.pop();
					else
						s.push(c);
				}
				else
					s.push(c);
			}
			else if (c == ']') {
				if (!s.empty()) {
					if (s.top() == '[')
						s.pop();
					else
						s.push(c);
				}
				else
					s.push(c);
			}
		}

		if (s.empty())
			cout << "yes" << '\n';
		else
			cout << "no" << '\n';

	}
	return 0;
}