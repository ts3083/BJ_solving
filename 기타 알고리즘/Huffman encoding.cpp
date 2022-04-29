#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <stack>
using namespace std;

class Node { // 노드 클래스
public:
	string symbol; // 문자열
	int frequency; // 빈도수
	Node* left; // left 노드
	Node* right; // right 노드

	Node() : left(NULL), right(NULL), frequency(0), symbol("") {} // 생성자
	Node(string symbol, int frequency) : left(NULL), right(NULL), frequency(frequency), symbol(symbol) {}
};

void traversal(Node* r) { // 출력 함수
	stack<pair<Node*, string>> str; // 지나온 곳을 기억하기 위해 stack 사용
	str.push({ r, "" }); // 루트 노드는  r노드이고 코드는 blank이다
	while (!str.empty()) { // stack이 빌때까지
		Node* cur = str.top().first; // cur은 현재의 노드
		string tmp1 = str.top().second; 
		string tmp2 = str.top().second;
		str.pop(); // stack의 pop연산
		if (cur->symbol != "") // 문자열이 존재할 때에만 출력
			cout << cur->symbol << ' ' << tmp1 << '\n';

		if (cur->left != NULL) {
			str.push({ cur->left, tmp1.append("0") }); // 0 삽입
		}
		if (cur->right != NULL) {
			str.push({ cur->right, tmp2.append("1") }); // 1 삽입
		}
	}
}

struct cmp { // 비교를 위한 구조체 
	bool operator()(Node* a, Node* b) {
		return (a->frequency > b->frequency); // 작은 것이 우선순위가 높다
	}
};

void Huffman_encoding(string* k, int count[]) { // Huffman encoding
	priority_queue<Node*, vector<Node*>, cmp> pq;
	for (int i = 0; i < 7; i++) { // 모든 데이터 + 빈도수 노드를 insert
			pq.push(new Node(k[i], count[i]));
	}

	Node* r = NULL; // r노드 초기화
	while (pq.size() > 1) { // size가 1이면 종료
		Node* left = pq.top(); // 현재 pq중에서 가장 작은 Node*
		pq.pop(); // 삭제
		Node* right = pq.top(); // 현재 pq중에서 가장 작은 Node*
		pq.pop(); // 삭제
		r = new Node(); // 새로운 노드 생성
		r->left = left; // left 연결
		r->right = right; // right 연결
		r->frequency = left->frequency + right->frequency; // 빈도수는 left와 right의 빈도수의 합
		pq.push(r); // pq에 삽입
	}
	traversal(r); // encoding한 결과 출력하는 함수
}

int main()
{
	string k1[7] = { "r", "A", "B", "C", "D", "E", "F"};
	string k2[7] = { "ROOT", "ABC", "ABCC", "AB", "A", "B", "BABA"};
	int count1[7] = { 27,15,12,9,5,10,11 };
	int count2[7] = { 27,12,7,19,35,40,15 };

	Huffman_encoding(k1, count1);
	cout << '\n';
	Huffman_encoding(k2, count2);

	return 0;
}