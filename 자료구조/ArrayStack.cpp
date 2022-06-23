#include <iostream>
using namespace std;

class ArrayStack {
private:
	int* s;
	int t; // 배열에서 가장 위쪽에 있는 원소의 인덱스
	int n;

public:
	ArrayStack(int n = 100) : n(n) {
		s = new int[n];
		t = -1; // 스택에 아무것도 없음
	}
	~ArrayStack() {
		delete[] s;
	}
	int size() const {
		return t + 1;
	}
	bool empty() const {
		return t < 0; // top이 -1이면 true
	}
	int& top() {
		if (t == -1)
			cout << "empty";
		else
			return s[t];
	}
	void pop() {
		if (t == -1) {
			return;
		}
		t--;
	}
	bool isFull() {
		if (t == n - 1)
			return true;
		else
			return false;
	}
	void push(int elem) {
		if (isFull())
			cout << "full";
		else
			s[++t] = elem;
	}
	void clear() {
		delete[] s;
		s = new int[n];
		t = -1;
	}
};

int main()
{
	ArrayStack s;
	cout << s.size() << '\n';
	s.push(3);
	s.push(2);
	s.push(1);
	cout << s.size() << '\n';
	cout << s.top() << '\n';
	s.pop();
	cout << s.size() << '\n';
	cout << s.top() << '\n';

	return 0;
}
