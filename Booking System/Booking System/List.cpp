#include "List.h"  // header file
// constructor
List::List() { size = 0; }

// add an item to the back of the list (append)
bool List::add(ItemType item)
{
	bool success = size < MAX_SIZE;
	if (success)
	{
		items[size] = item;    // add to the end of the list
		size++;                // increase the size by 1
	}
	return success;
}

// remove an item at a specified position in the list
void List::remove(int index)
{
	bool success = (index >= 0) && (index < size);
	if (success)
	{  // delete item by shifting all items at positions >
	   // index toward the beginning of the list
	   // (no shift if index == size)
		for (int pos = index; pos < size; pos++)
			items[pos] = items[pos + 1];
		size--;  // decrease the size by 1
	}

}

// get an item at a specified position of the list (retrieve)
ItemType List::get(int index)
{

	bool success = (index >= 0) && (index < size);
	if (success)
		return items[index];
	else {
		ItemType nothing;
		return nothing;
	}
}

// check the size of the list
int List::getLength() { return size; }

// display the items in the list
void List::print()
{

}

