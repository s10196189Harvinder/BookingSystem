#include <iostream>
#include "List.h"
#include "Flight.h"

// constructor
List::List()
{
	size = 0;
}
//Destructor
List::~List() {
	//remove all Nodes from the linked list
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

bool List::add(ItemType item) {
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

bool List::add(int index, ItemType item) {
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

void List::remove(int index) {
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

ItemType List::get(int index) {
	if (index < size && index >= 0) {
		Node* current = firstNode;
		for (int i = 0; i < index; i++)
		{
			current = current->next; //Traverse to the node 
		}
		return current->item; //return the item contained in the node
	}
	else {
		ItemType nothing;
		return nothing;
	}
}

bool List::isEmpty() {
	if (size == 0) {
		return true;
	}
	else {
		return false;
	}
}

int List::getLength() { return size; }

void List::print() {
	Node* temp = firstNode; //Set a temp pointer to point to the first node of the list
	while (temp != NULL) {
		ItemType item1 = temp->item; //Retrieve the item from the node that pointed by temp
		cout << item1.toString() << endl; //Display the item
		temp = temp->next; //Set temp to point to the next node
	}
}

Flight* List::find(string num) {
	Node* current = firstNode;
	while (current != NULL) {
		if (current->item.getNumber() == num) {
			return &(current->item);
		}
		current = current->next;
	}
	Flight* fh;
	fh = nullptr;
	return fh;
}


void List::mergesort() {
	mergesort(&firstNode);
}
void List::mergesort(Node** ref) {
	Node* p = *ref;
	Node* a;
	Node* b;
	if (p==NULL || p->next == NULL) {
		return;
	}
	split(p,&a, &b);
	mergesort(&a);
	mergesort(&b);
	*ref = merge(a, b);
}
void List::split(Node* src,Node **front, Node **back){
	Node* ahead;
	Node* behind;
	ahead = src->next;
	behind = src;
	while (ahead != NULL) {
		ahead = ahead->next;		//Ahead traverses 2x faster than behind
		if (ahead != NULL) {
			behind = behind->next;
			ahead = ahead->next;
		}
	}
	*front = src;
	*back = behind->next;
	behind->next = NULL;
}
List::Node* List::merge(Node* head1, Node* head2) {
	Node* res = NULL;
	if (head1 == NULL) {
		return head2;
	}
	else if (head2 == NULL) {
		return head1;
	}
	int num1 = stoi((head1->item.getNumber()).substr(1, 2));
	int num2 = stoi((head2->item.getNumber()).substr(1, 2));
	if (num1 <= num2) {
		res = head1;
		res->next = merge(head1->next, head2);
	}
	else {
		res = head2;
		res->next = merge(head1, head2->next);
	}
	return res;
}