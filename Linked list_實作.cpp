#include <iostream>
using namespace std;

class Chain;

class ChainNode {
	friend class Chain;
public:
	ChainNode(char data = 0, ChainNode* link = nullptr) :
		value(data), next(link) {}
private:
	char value;
	ChainNode* next;
};

class Chain {
public:
	Chain():first(nullptr),n(0){}
	
	bool Empty()const {
		return first == nullptr;
	}
	int Size()const { return n; }

	void Insert(int index, char val) {
		if (index == 0) {
			first = new ChainNode(val, first);
		}
		else {
			ChainNode* before = first;
			for (int i = 0; i < index - 1; i++) {
				before = before->next;
			}
			before->next = new ChainNode(val, before->next);
		}
		n++;
	}

	void Erase(const int index) {
		if (index == 0) {
			ChainNode* deleteNode = first;
			first = first->next;
			delete deleteNode;
		}
		else {
			ChainNode* before = first;
			// Find the node before the target place
			for (int i = 1; i < index; i++) {
				before = before->next;
			}
			ChainNode* deleteNode = before->next;
			before->next = deleteNode->next;
			delete deleteNode;
		}
	}

	void Reverse() {
		ChainNode* current = first;
		ChainNode* previous = nullptr;

		while (current != nullptr) {
			ChainNode* temp = previous;
			previous = current;
			current = current->next;
			previous->next = temp;
		}
		first = previous;
	}

	void Print(const string& tag = "")const {
		if (!tag.empty())cout << tag;
		cout << "[";
		for (ChainNode* p = first; p; p = p->next) {
			cout << p->value;
			if (p->next)cout << "->";
		}
		cout << "](size=" << n << ")\n";
	}
private:
	ChainNode* first;
	int n;
};

int main() {
	Chain L;

	L.Print("初始: ");

	// 1) 在頭插入 'a'
	L.Insert(0, 'a');

	// 2) 在尾端插入 'b'
	L.Insert(L.Size(), 'b');

	// 3) 在中間位置 1 插入 'c'（介於 a 與 b）
	L.Insert(1, 'c');
}
