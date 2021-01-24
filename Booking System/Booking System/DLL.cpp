#include "DLL.h"
#include <iostream>

DLL::DLL() {
	size = 0;
	firstNode = NULL;
	lastNode = NULL;
}
DLL::~DLL()
{
}

bool DLL::add(ItemType data) {
	Node* newNode = new Node;
	newNode->item = data;

	if (firstNode != NULL) {
		Node* tempNode = firstNode;	//Temp node for old 
		newNode->next = tempNode;	//Make next of new node the previous first node
		newNode->prev = NULL;
		tempNode->prev = newNode;	//Set previous node of the old node to the new node
		firstNode = newNode;		//Set the new firstnode
	}
	else {
		firstNode = newNode;
		lastNode = newNode;
		newNode->next = NULL;
		newNode->prev = NULL;
	}
	size++;
	return true;
}

bool DLL::add(ItemType data, int index) {
	Node* newNode = new Node;
	newNode->item = data;
	newNode->next = NULL;
	newNode->prev = NULL;
	if (index == 0) {
		Node* oldNode = firstNode;
		newNode->next = oldNode;				//newnode.next is old first node
		oldNode->prev = newNode;
		firstNode = newNode;					//Created node becomes first node
	}
	else {
		Node* currNode = firstNode;
		for (int i = 1; i < index; i++)			//Traverse to node before index to be inserted
		{
			currNode = currNode->next;
		}
		Node* nextNode = currNode->next;		//Obtain the node at index
		currNode->next = newNode;				//Set current index node next to point to new node
		newNode->prev = currNode;				//Set new node prev to point to curr node
		newNode->next = nextNode;				//Set new node to point to next node
		nextNode->prev = newNode;				//Set next node prev to point to new node
	}
	size++;
	return true;
}

bool DLL::append(ItemType data) {
	Node* newNode = new Node;
	newNode->item = data;
	newNode->next = NULL;
	if (lastNode != NULL) {
		Node* tempNode = lastNode;
		tempNode->next = newNode;
		newNode->prev = tempNode;
		lastNode = newNode;
	}
	else {
		newNode->prev = NULL;
		firstNode = newNode;
		lastNode = newNode;
	}
	size++;
	return true;
}
void DLL::remove(int index){
	Node* currNode = firstNode;
	if (index == 0) {
		firstNode = firstNode->next;
		delete currNode;
	}
	else {
		Node* prevNode = new Node;
		for (int i = 0; i < index; i++)			//Traverse to node before index to be inserted
		{
			prevNode = currNode;
			currNode = currNode->next;
		}
		Node* nextNode = currNode->next;		//Obtain the node that current index node is pointing to
		delete currNode;						//Deletes the node.
		prevNode->next = nextNode;				//Sets the node behind the deleted item to have a next of the node after
		nextNode->prev = prevNode;
	}
	size--;
}

bool DLL::isEmpty() { if (size == 0) { return true; } else { return false; } }

void DLL::print() {
	cout << "Traversal in forward direction" << endl;
	Node* curr = firstNode;
	while (curr != NULL) {
		cout << curr->item << ", ";
		curr = curr->next;
	}

	cout << "Traversal in reverse direction" << endl;
	curr = lastNode;
	while (curr != NULL) {
		cout << curr->item << ", ";
		curr = curr->prev;
	}
}
