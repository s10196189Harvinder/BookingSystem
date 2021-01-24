#include <string>
#pragma once
using namespace std;

typedef string ItemType;

class DLL {
private:
	struct Node
	{
		ItemType item;	// data item
		Node* next;	// pointer pointing to next item
		Node* prev; //Pointer pointing behind
	};
	Node* firstNode;
	Node* lastNode;
	int size;
public:
	DLL();
	~DLL();

	bool add(ItemType);
	bool add(ItemType, int);
	bool append(ItemType);
	void remove(int);
	ItemType get(int);
	bool isEmpty();
	int getLength();
	void print();
};
