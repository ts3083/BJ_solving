#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<int> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	vector<int> cv(v); // 입력받은 벡터를 복사
	sort(cv.begin(), cv.end()); // 오름차순 정렬

	cv.erase(unique(cv.begin(), cv.end()), cv.end());
	for (int i = 0; i < n; i++) {
		int p = lower_bound(cv.begin(), cv.end(), v[i]) - cv.begin();
		cout << p << ' ';
	}

	return 0;
}