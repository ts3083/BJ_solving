#include <iostream>
using namespace std;

class Node {
private:
	int elem;
	Node* prev;
	Node* next;
	friend class Deque;
};

class Deque {
private:
	Node* header;
	Node* trailer;
	int n;

protected:
	void add(Node* v, int& e) {
		Node* temp = new Node; // 노드 생성
		temp->elem = e; // temp가 가리키는 elem는 e
		temp->next = v; // temp의 다음 노드는 v
		temp->prev = v->prev; // temp의 prev노드는 이전 v가 가리키고 있던 prev노드
		v->prev->next = temp; // v의 prev의 next가 가리키는 노드는 temp
		v->prev = temp; //  v의 prev가 가리키는 노드는 temp
		n++;
	}
	void remove(Node* v) {
		if (n == 0)
			return;
		Node* f = v->prev;
		Node* b = v->next;
		f->next = b;
		b->prev = f;
		n--;
		delete v;
	}

public:
	Deque() : n(0) {
		header = new Node;
		trailer = new Node;
		header->next = trailer;
		trailer->prev = header;
	}
	~Deque() {
		while (!empty()) {
			removeFront();
		}
		delete header;
		delete trailer;
	}
	bool empty() const {
		return header->next == trailer;
	}
	int front() const {
		if (n == 0)
			return 123456;
		return header->next->elem;
	}
	int back() const {
		if (n == 0)
			return 123456;
		return trailer->prev->elem;
	}
	int size() const {
		return n;
	}
	void insertFront(int e) {
		add(header->next, e);
	}
	void insertBack(int e) {
		add(trailer, e);
	}
	void removeFront() {
		remove(header->next);
	}
	void removeBack() {
		remove(trailer->prev);
	}
};

int main()
{
	Deque q;
	cout << q.size() << '\n';
	cout << q.front() << '\n';
	q.insertBack(1);
	q.insertBack(2);
	cout << q.size() << '\n';
	cout << q.front() << '\n';
	q.removeFront();
	cout << q.size() << '\n';
	cout << q.front() << '\n';

	return 0;
}
