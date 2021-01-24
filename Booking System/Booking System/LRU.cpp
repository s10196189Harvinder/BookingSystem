#include "DLL.h"
#include "Dictionary.h"
class LRU {
private:
	DLL items = DLL();
	Dictionary keyTable = Dictionary();
	int cacheSize;

public:
	LRU(int size) {
		if (size < 1) {
			cacheSize = 10;
		}
		else {
			cacheSize = size;
		}
	}
	string get(string key) {
		Node* node = keyTable.get(key);
		if (node==nullptr) {
			return "";
		}
		string value = node->item;
		items.pushToHead(node);
		return value;
	}

	void set(string key, string item) {
		Node* value = keyTable.get(key);	//Check if item exists in key table
		if (value!=nullptr) {
			value->item = item;
			items.pushToHead(value);
			return;
		}
		if (items.getLength() == cacheSize) {
			//remove rear
			string key = items.getLastKey();
			keyTable.remove(key);
			items.removeLast();
		}
		Node* newitem = items.add(item,key);
		keyTable.add(key,newitem);
		
	}
	void print() {
		items.print();
	}


};