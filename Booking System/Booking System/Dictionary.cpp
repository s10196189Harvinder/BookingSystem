#include "DLL.h"
#include "Dictionary.h"
Dictionary::Dictionary() {
	size = 0;
	for (int i = 0;i < MAX_SIZE;i++) {
		items[i] = NULL;
	}
}
Dictionary::~Dictionary() {
	for (int i = 0; i < MAX_SIZE; i++) {
		if (items[i] != NULL) {
			delete items[i];

		}
	}

}

int charvalue(char c)
{
	if (isalpha(c))
	{
		if (isupper(c))
			return (int)c - (int)'A';
		else
			return (int)c - (int)'a' + 26;
	}
	else
		return -1;
}


int Dictionary::hash(string key) {
	int h = 0;
	for (int i = 0; i < key.size();i++) {
		h += (charvalue(key[i]));
	}
	return (h % MAX_SIZE);
}

bool Dictionary::add(string newKey, Node* newItem) {
	int index = hash(newKey);
	while (items[index] != NULL) {		//Linear probing
		index = ((index)+1) % MAX_SIZE;
	}
	NodeC* newNode = new NodeC();
	newNode->item = newItem;
	newNode->key = newKey;
	items[index] = newNode;
	size ++;
	return true;
}

void Dictionary::remove(string key) {
	int index = hash(key);
	int temp = index;
	while (true) {
		if (items[index] == NULL) {
			index = (index + 1) % MAX_SIZE;
		}
		else if (items[index]->key!=key) {
			index = (index + 1) % MAX_SIZE;
		}
		else {
			break;
		}
		if (index == temp) {	//If it goes around the dict and cannot find the item
			return;
		}
	}
	delete items[index];
	items[index] = NULL;
	size--;
}

void Dictionary::print() {
	for (int i = 0; i < MAX_SIZE; i++) {
		cout << "[" << i << "]";
		if (items[i] != NULL) {
			NodeC* current = items[i];
			cout << current->key << ": " << current->item->item.toString() << endl;
		}
		cout << "NULL" << endl;
	}
}

Node* Dictionary::get(string key) {
	int index = hash(key);
	int temp = index;
	while (true) {
		if (items[index] == NULL) {
			index = (index + 1) % MAX_SIZE;
		}
		else if (items[index]->key != key) {
			index = (index + 1) % MAX_SIZE;
		}
		else {
			break;
		}
		if (index == temp) {
			return NULL;
		}
	}
	return(items[index]->item);
}

bool Dictionary::isEmpty() {
	if (size == 0) {
		return true;
	}
	return false;
}

int Dictionary::getLength() {
	return size;
}