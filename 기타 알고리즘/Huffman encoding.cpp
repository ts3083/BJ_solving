#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <stack>
using namespace std;

class Node { // ��� Ŭ����
public:
	string symbol; // ���ڿ�
	int frequency; // �󵵼�
	Node* left; // left ���
	Node* right; // right ���

	Node() : left(NULL), right(NULL), frequency(0), symbol("") {} // ������
	Node(string symbol, int frequency) : left(NULL), right(NULL), frequency(frequency), symbol(symbol) {}
};

void traversal(Node* r) { // ��� �Լ�
	stack<pair<Node*, string>> str; // ������ ���� ����ϱ� ���� stack ���
	str.push({ r, "" }); // ��Ʈ ����  r����̰� �ڵ�� blank�̴�
	while (!str.empty()) { // stack�� ��������
		Node* cur = str.top().first; // cur�� ������ ���
		string tmp1 = str.top().second; 
		string tmp2 = str.top().second;
		str.pop(); // stack�� pop����
		if (cur->symbol != "") // ���ڿ��� ������ ������ ���
			cout << cur->symbol << ' ' << tmp1 << '\n';

		if (cur->left != NULL) {
			str.push({ cur->left, tmp1.append("0") }); // 0 ����
		}
		if (cur->right != NULL) {
			str.push({ cur->right, tmp2.append("1") }); // 1 ����
		}
	}
}

struct cmp { // �񱳸� ���� ����ü 
	bool operator()(Node* a, Node* b) {
		return (a->frequency > b->frequency); // ���� ���� �켱������ ����
	}
};

void Huffman_encoding(string* k, int count[]) { // Huffman encoding
	priority_queue<Node*, vector<Node*>, cmp> pq;
	for (int i = 0; i < 7; i++) { // ��� ������ + �󵵼� ��带 insert
			pq.push(new Node(k[i], count[i]));
	}

	Node* r = NULL; // r��� �ʱ�ȭ
	while (pq.size() > 1) { // size�� 1�̸� ����
		Node* left = pq.top(); // ���� pq�߿��� ���� ���� Node*
		pq.pop(); // ����
		Node* right = pq.top(); // ���� pq�߿��� ���� ���� Node*
		pq.pop(); // ����
		r = new Node(); // ���ο� ��� ����
		r->left = left; // left ����
		r->right = right; // right ����
		r->frequency = left->frequency + right->frequency; // �󵵼��� left�� right�� �󵵼��� ��
		pq.push(r); // pq�� ����
	}
	traversal(r); // encoding�� ��� ����ϴ� �Լ�
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