//=====================================================================
//Group: P05
//ID (Name): Harvinder Arjun Singh (S10196189D), Wayne Lee (S10177125E)
//=====================================================================

#pragma once
#pragma once

#include<string>
#include<iostream>
using namespace std;
struct NodeC
{
	string key; // search key
	Node* item;	// data item
};

const int MAX_SIZE = 5;


class Dictionary
{
private:
	NodeC* items[MAX_SIZE];
	int  size;			// number of items in the Dictionary

public:

	// constructor
	Dictionary();

	// destructor
	~Dictionary();

	int hash(string key);

	// add a new item with the specified key to the Dictionary
	// pre : none
	// post: new item is added to the Dictionary
	//       size of Dictionary is increased by 1
	bool add(string newKey, Node* newItem);

	// remove an item with the specified key in the Dictionary
	// pre : key must exist in the Dictionary
	// post: item is removed from the Dictionary
	//       size of Dictionary is decreased by 1
	void remove(string key);


	// get an item with the specified key in the Dictionary (retrieve)
	// pre : key must exist in the dictionary
	// post: none
	// return the item with the specified key from the Dictionary
	Node* get(string key);

	// check if the Dictionary is empty
	// pre : none
	// post: none
	// return true if the Dictionary is empty; otherwise returns false
	bool isEmpty();

	// check the size of the Dictionary
	// pre : none
	// post: none
	// return the number of items in the Dictionary
	int getLength();

	//------------------- Other useful functions -----------------

	// display the items in the Dictionary
	void print();

	// void replace(KeyType key, ItemType item);
	// bool contains(KeyType key);
};
