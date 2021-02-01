// Booking System.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include "LRU.cpp"
#include "Dictionary.h"
#include "Flight.h"
using namespace std;


int main()
{
    //Initialization of Database:



    bool valid = true;
    string val = "0";
    while (true){
        cout << ("==========") << endl;
        cout << ("Booking System") << endl;
        cout << "1. Reserve Seat" << endl;
        cout << "2. User Ticket" << endl;
        cout << "3. Flight Schedule" << endl;
        cout << "4. Passenger Details" << endl;
        cout << "5. Flight Details" << endl;
        cout << "0. Exit Program" << endl;
        cout << ("==========") << endl;
        cout << ("Enter your option: ");
        cin >> val;
        if (val == "1") {
            //Booking system function
        }
        else if (val == "2") {
            //View user ticket function
        }
        else if (val == "3") {
            //View flight schedules
            cout << "Flight Number" << setw(21) << "Status" << setw(21) << "Seats" << endl;
            cout << "============================" << endl;

            cout << "============================" << endl;
        }
        else if (val == "4") {
            //View passenger details
        }
        else if (val == "5") {
            //View flight details
        }
        else if (val == "0") {
            cout << "Goodbye!";
            return 0;
        }
        else {
            cout << "Invalid input.." << endl;
        }
    } 


    //LRU cache = LRU(5);         //Init cache with max size of 5
    //cache.set("first", "1"); 
    //cache.set("second", "2");
    //cache.set("three", "3");
    //cache.set("four", "4");
    //cache.set("five", "5");     //Add 5 items to cache
    //cache.print();
    //cache.set("six", "1");      //Add 6th item, causing cache to evict the least recently used item (first/1)
    //cache.print();
    //cout << cache.get("three") << endl;     //Get the value of the item with key "three"
    //cache.set("three", "Changed Value");    //Change value of item with key "three" to "Changed value"
    //cout << cache.get("three") << endl;     //Get value of key "three"
    //cache.print();              //As "three" has been edited, it will be in the front of the cache.
}
