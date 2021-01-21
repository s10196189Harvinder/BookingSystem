// Booking System.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
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
        cout << "6. Exit Program" << endl;
        cin >> val;
        if (val == "1") {
            //Booking system function
        }
        else if (val == "2") {
            //View user ticket function
        }
        else if (val == "3") {
            //View flight schedules
        }
        else if (val == "4") {
            //View passenger details
        }
        else if (val == "5") {
            //View flight details
        }
        else if (val == "6") {
            return 0;
        }
        else {
            cout << "Invalid input.." << endl;
        }
    } 
}
