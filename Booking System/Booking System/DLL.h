#include <string>
#include "Flight.h"
#pragma once
using namespace std;
struct Node
{
	Flight item;	// data item
	Node* next;	// pointer pointing to next item
	Node* prev; //Pointer pointing behind
};

class DLL {
private:
	Node* firstNode;
	Node* lastNode;
	int size;
public:
	DLL();
	~DLL();

	Node* add(Flight);
	bool add(Flight, int);
	bool append(Flight);
	void remove(int);
	void removeLast();
	string get(int);
	bool isEmpty();
	int getLength();
	void print();
	string getLastKey();
	void pushToHead(Node*);

	//tbc
	void removeNum(string);
	Flight getNum(string);
};
