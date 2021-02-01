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
			NodeC* current = items[i];
			NodeC* previous = NULL;
			while (current != NULL) {
				previous = current;
				current = current->next;
				delete previous;
			}

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
	if (items[index] == NULL) {
		NodeC* newNode = new NodeC();
		newNode->item = newItem;
		newNode->next = NULL;
		newNode->key = newKey;
		items[index] = newNode;
	}
	else {
		NodeC* currentptr = new NodeC();
		currentptr = items[index];
		if (currentptr->key == newKey) {
			return false;
		}
		while (currentptr->next != NULL) {
			currentptr = currentptr->next;
			if (currentptr->key == newKey) {
				return false;
			}
		}
		NodeC* newNode = new NodeC();
		newNode->key = newKey;
		newNode->item = newItem;
		newNode->next = NULL;
		currentptr->next = newNode;
	}
	size += 1;
	return true;
}

void Dictionary::remove(string key) {
	int index = hash(key);
	if (items[index] != NULL) {
		if (items[index]->key == key) {
			items[index] = items[index]->next;
			size--;
		}
		else {
			NodeC* current = items[index];
			NodeC* previous = items[index];
			while (current != NULL) {
				if (current->key == key) {
					previous->next = current->next;
					size--;
					break;
				}
				else {
					previous = current;
					current = current->next;
				}
			}
		}
	}
}

void Dictionary::print() {
	for (int i = 0; i < MAX_SIZE; i++) {
		cout << "[" << i << "]";
		if (items[i] != NULL) {
			NodeC* current = items[i];
			while (current) {
				cout << current->key << ": " << current->item->item.toString() << " -> ";		//CHECK THIS IDK
				current = current->next;
			}
		}
		cout << "NULL" << endl;
	}
}

Node* Dictionary::get(string key) {
	int index = hash(key);
	if (items[index] != NULL) {
		if (items[index]->key == key) {
			return items[index]->item;
		}
		else {
			NodeC* current = items[index];
			NodeC* previous = items[index];
			while (current != NULL) {
				if (current->key == key) {
					return items[index]->item;
					break;
				}
				else {
					previous = current;
					current = current->next;
				}
			}
		}
	}
	return nullptr;
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