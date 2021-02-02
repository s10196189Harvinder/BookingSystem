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
	Flight get(string key) {
		Flight flight = Flight();
		Node* node = keyTable.get(key);
		if (node!=nullptr) {
			flight = node->item;
			items.pushToHead(node);
		}
		return flight;
	}

	void set(Flight item) {
		Node* value = keyTable.get(item.getNumber());	//Check if item exists in key table
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
		Node* newitem = items.add(item);
		keyTable.add(item.getNumber(),newitem);
	}
	void print() {
		items.print();
	}


};