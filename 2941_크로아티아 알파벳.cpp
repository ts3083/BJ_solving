#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	vector<string> v = { "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z=" };
	// string �ڷ��� vector ���� + ������ ���Ҵ� string data�̴�.
	string s;
	cin >> s;
	for (int i = 0; i < v.size(); i++) {
		for (;;) {
			if (s.find(v[i]) == string::npos) { // find�Լ��� ���� ���ڿ� ã�� + ���ڿ��� ���ٸ� npos ��ȯ
				break;
			}
			else { // ã�����ϴ� ���ڿ��� ã�´ٸ� ��ü
				s.replace(s.find(v[i]), v[i].length(), "a");
			}
		}
	}
	cout << s.length() << endl;

	return 0;
}