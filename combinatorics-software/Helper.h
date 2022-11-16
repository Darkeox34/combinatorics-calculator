#include <iostream>
using namespace std;


int fact(int n) {
	if (n == 1)
		return 1;
	else
		return n * fact(n - 1);
}


template <typename T>
class node {
public:
	T data;
	node<T>* next;

	node() { next = nullptr; }
};

template <typename T>
class linkedlist {
private:
	node<T>* head;
public:

	linkedlist() { head = nullptr; }

	void insert(T data);

	bool findVal(T data);

	int listFact(string s);

	void deleteList();

	void print();
};

linkedlist<int> intL;
linkedlist<char> charL;


void gsnor(string s) {
	int c = 0;
	for (int i = 0; i < s.length(); i++) {
		c = 0;
		if (!charL.findVal(s[i])) {
			for (int j = i; j < s.length(); j++) {
				if (s[j] == s[i]) {
					c++;
				}
			}
		}
		intL.insert(c);
		charL.insert(s[i]);
	}
}


template <typename T>
int linkedlist<T>::listFact(string s) {
	gsnor(s);
	int ret = 1;
	node<T>* iter = head;
	while (iter != nullptr) {
		if (iter->data > 0) {
			ret *= fact(iter->data);
		}
		iter = iter->next;
	}
	return ret;
}

template <typename T>
void linkedlist<T>::print() {
	node<T>* iter = head;
	while (iter != nullptr) {
		cout << iter->data << " -> ";
		iter = iter->next;
	}
	cout << "NULLPTR";
}

template <typename T>
bool linkedlist<T>::findVal(T data) {
	node<T>* iter = head;
	while (iter != nullptr) {
		if (data == iter->data) {
			return true;
		}
		iter = iter->next;
	}
	return false;
}

template <typename T>
void linkedlist<T>::insert(T data) {
	node<T>* newNode = new node<T>;
	newNode->data = data;
	if (head == nullptr) {
		head = newNode;
	}
	else
	{
		node<T>* iter = head;
		while (iter->next != nullptr) {
			iter = iter->next;
		}
		iter->next = newNode;
		newNode->next = nullptr;
	}

}



