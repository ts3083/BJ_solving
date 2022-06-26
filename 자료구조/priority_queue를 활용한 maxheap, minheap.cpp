#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void max_heap() {
	priority_queue<int, vector<int>> pq; // maxheap
	// priority_queue<int, vector<int>, less<int>> pq; 내림차순 정렬 == minheap
	pq.push(4);
	pq.push(9);
	pq.push(1);
	pq.push(7);
	pq.push(10);
	pq.push(2);
	pq.push(3);
	while (!pq.empty()) {
		cout << pq.top() << endl;
		pq.pop();
	}
}

void min_heap() {
	priority_queue<int, vector<int>, greater<int>> pq; // minheap
	pq.push(4);
	pq.push(9);
	pq.push(1);
	pq.push(7);
	pq.push(10);
	pq.push(2);
	pq.push(3);
	while (!pq.empty()) {
		cout << pq.top() << endl;
		pq.pop();
	}
}

int main()
{
  max_heap();
	min_heap();
	
	return 0;
}
