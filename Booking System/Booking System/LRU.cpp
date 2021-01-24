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
	void set(ItemType item) {
		ItemType value = keyTable.get(item);	//Check if item exists in key table
		if (value.empty()) {					//If it does not exist,
			items.add(item);						//add item to front of list
		}
	}


	void checkCache() {
		if (items.getLength() > cacheSize) {
			items.remove(items.getLength());
		}
	}
};