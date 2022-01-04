#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	int index_start = 0;
	int result = 0;
	int index_end = 0;
	string s;
	vector<int> v;
	cin >> s;
	
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '+') { // + 라면
			index_end = i;
			result += stoi(s.substr(index_start, index_end - index_start));
			index_start = i + 1;
		}
		else if(s[i] == '-') { // - 라면
			index_end = i;
			result += stoi(s.substr(index_start, index_end - index_start));
			v.push_back(result);
			result = 0;
			index_start = i + 1;
		}

		if (i == s.length() - 1) {
			result += stoi(s.substr(index_start));
			v.push_back(result);
		}
	}

	int sum = v[0];
	if (v.size() == 1) {
		cout << sum << '\n';
	}
	else {
		for (int i = 1; i < v.size(); i++) {
			sum -= v[i];
		}
		cout << sum << '\n';
	}

	return 0;
}