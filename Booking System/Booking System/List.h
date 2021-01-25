//List.h -- Specification of List ADT
#pragma once
#include <iostream>
#include "Flight.cpp"
using namespace std;

const int MAX_SIZE = 5;
typedef Flight ItemType;

class List {
private:
	ItemType items[MAX_SIZE];
	int size;

public:
	// constructor
	List();

	// add an item to the back of the list (append)
	// pre : size < MAX_SIZE
	// post: item is added to the back of the list
	//       size of list is increased by 1
	bool add(ItemType item);

	// remove an item at a specified position in the list
	// pre : 0 <= index < size
	// post: item is removed the specified position in the list
	//       size of list is decreased by 1
	void remove(int index);

	// get an item at a specified position of the list (retrieve)
	// pre : 0 <= index < size
	// post: none
	ItemType get(int index);

	// check the size of the list
	// pre : none
	// post: none
	// return the number of items in the list
	int getLength();

	void print();
};