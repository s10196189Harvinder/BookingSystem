//=====================================================================
//Group: P05
//ID (Name): Harvinder Arjun Singh (S10196189D), Wayne Lee (S10177125E)
//=====================================================================

#include <iostream>
#include "List2.h"
#include "Passenger.h"

// constructor
List2::List2()
{
	size = 0;
}
//Destructor
List2::~List2() {
	//remove all Nodes from the linked List2
	Node* temp = firstNode;
	while (temp != NULL)
	{
		firstNode = firstNode->next;
		temp->next = NULL;
		delete temp;
		temp = firstNode;
	}
	size = 0;
}

bool List2::add(ItemType2 item) {
	Node* newNode = new Node; //Creating a new node
	newNode->item = item; //Store the item in the node
	newNode->next = NULL; //Initialize the next pointer to null

	if (size == 0) {
		firstNode = newNode; //Set first node (pointer) to point to new node
	}
	else {
		Node* current = firstNode;
		while (current->next != NULL) {
			current = current->next; //Traverse to the last Node
		}
		current->next = newNode; //set last node to point to the new node
	}
	size += 1; //Increase the size by 1
	return true;
}

bool List2::add(int index, ItemType2 item) {
	if (index < size && index >= 0) {
		Node* newNode = new Node; //Creating a new node
		newNode->item = item; //Store the item in the node
		newNode->next = NULL; //Initialize the next pointer to null
		if (index - 1 == 0) {
			newNode->next = firstNode; // set new node to point to node pointed by first node
			firstNode = newNode; //Set first node (pointer) to point to new node
		}
		else {
			Node* current = firstNode;
			for (int i = 1; i < index - 1; i++)
			{
				current = current->next; //Traverse to the node just before the indexed node
			}
			newNode->next = current->next; //Set new node to point to the indexed node
			current->next = newNode; //Set that node to point to the new node
		}
		size += 1; //Increase size by 1
		return true;
	}
	else {
		return false;
	}

}

void List2::remove(int index) {
	if (index < size && index >= 0) {
		if (index - 1 == 0) {
			firstNode = firstNode->next; //Set first node to print to the second node (or NULL)
		}
		else {
			Node* current = firstNode;
			for (int i = 1; i < index - 1; i++)
			{
				current = current->next; //Traverse to the node just before the node to be removed
			}
			Node* removedNode = current->next;
			current->next = current->next->next; //set that node to the node after the position 

			removedNode->next = NULL; //Deleting node at certain index
			delete removedNode;
		}
		size -= 1; //Decrease size by 1
	}
}

ItemType2 List2::get(int index) {
	if (index < size && index >= 0) {
		Node* current = firstNode;
		for (int i = 0; i < index; i++)
		{
			current = current->next; //Traverse to the node 
		}
		return current->item; //return the item contained in the node
	}
	else {
		ItemType2 nothing;
		return nothing;
	}
}

bool List2::isEmpty() {
	if (size == 0) {
		return true;
	}
	else {
		return false;
	}
}

int List2::getLength() { return size; }

void List2::print() {
	Node* temp = firstNode; //Set a temp pointer to point to the first node of the List2
	while (temp != NULL) {
		ItemType2 item1 = temp->item; //Retrieve the item from the node that pointed by temp
		cout << item1.toString() << endl; //Display the item
		temp = temp->next; //Set temp to point to the next node
	}
}