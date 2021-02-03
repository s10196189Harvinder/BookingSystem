#pragma once
#include<string>
#include<iostream>
#include "Passenger.h"
using namespace std;

typedef Passenger ItemType2;

class List2
{
private:
	struct Node
	{
		ItemType2 item;	// data item
		Node* next;	// pointer pointing to next item
	};

	Node* firstNode;	// point to the first item
	int  size;			// number of items in the List2

public:
	List2();			// constructor

	~List2();		// distructor

	// add an item to the back of the List2 (append)
	// pre : size < MAX_SIZE
	// post: item is added to the back of the List2
	//       size of List2 is increased by 1
	bool add(ItemType2 item);

	// add an item at a specified position in the List2 (insert)
	// pre : 0 <= index <= size
	// post: item is added to the specified position in the List2
	//       items after the position are shifted back by 1 position
	//       size of List2 is increased by 1
	bool add(int index, ItemType2 item);

	// remove an item at a specified position in the List2
	// pre : 0 <= index < size
	// post: item is removed the specified position in the List2
	//       items after the position are shifted forward by 1 position
	//       size of List2 is decreased by 1
	void remove(int index);

	// get an item at a specified position of the List2 (retrieve)
	// pre : 0 <= index < size
	// post: none
	// return the item in the specified index of the List2
	ItemType2 get(int index);

	// check if the List2 is empty
	// pre : none
	// post: none
	// return true if the List2 is empty; otherwise returns false
	bool isEmpty();

	// check the size of the List2
	// pre : none
	// post: none
	// return the number of items in the List2
	int getLength();

	//------------------- Other useful functions -----------------

	// display the items in the List2
	void print();

	// void replace(int index, ItemType2 item);
	// int search(ItemType2 item);
};

