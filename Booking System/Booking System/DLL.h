#include <string>
#pragma once
using namespace std;
struct Node
{
	string item;	// data item
	string key;
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

	Node* add(string,string);
	bool add(string, int);
	bool append(string);
	void remove(int);
	void removeLast();
	string get(int);
	bool isEmpty();
	int getLength();
	void print();
	string getLastKey();
	void pushToHead(Node*);
};
