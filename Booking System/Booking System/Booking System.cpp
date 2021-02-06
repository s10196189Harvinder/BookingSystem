// Booking System.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include "LRU.cpp"
#include "Dictionary.h"
#include "Flight.h"
#include "Passenger.h"
#include "List2.h"
#include "List.h"
#include <chrono>
using namespace std;


int main()
{
    //Initialization of Database:
    LRU cache = LRU(3); //Init cache with max size of 4
    List(flightList); //Flight List
    Flight f6 = Flight("USA", "Singapore", 1612022500, "0800", "F06", "Available", 70);
    Flight f1 = Flight("Singapore", "Malaysia", 1611936000, "0800", "F01", "Available", 50);
    Flight f4 = Flight("Australia", "Singapore", 1612022400, "1000", "F04", "Available", 70);
    Flight f3 = Flight("USA", "Malaysia", 1611936000, "0900", "F03", "Cancelled", 50);
    Flight f2 = Flight("Singapore", "Australia", 1611763200, "0800", "F02", "Available", 50);
    Flight f5 = Flight("USA", "Singapore", 1612022400, "0900", "F05", "Cancelled", 40);
    List2(passengerList); //Passenger List
    Passenger p1 = Passenger("John", "k8hxv", f1);
    Passenger p2 = Passenger("Jane", "6eb4g", f4);
    Passenger p3 = Passenger("Ken", "kkahv", f3);
    Passenger p4 = Passenger("Adam", "ks832m", f2);
    Passenger p5 = Passenger("Roger", "oshc8", f1);
    passengerList.add(p1);
    passengerList.add(p2);
    passengerList.add(p3);
    passengerList.add(p4);
    passengerList.add(p5);
    cache.set(f1);
    cache.set(f2);
    cache.set(f3);
    cache.set(f4);
    cache.set(f5);
    cache.set(f6);
    flightList.add(f6);
    flightList.add(f4);
    flightList.add(f3);
    flightList.add(f2);
    flightList.add(f5);
    flightList.add(f1);
    flightList.mergesort();     //Apply merge sort algorithm




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
        //Demonstration of LRU 
        
        cout << "6. Get Flight Route" << endl;
        cout << "7. View LRU Cache" << endl;
        // End
        cout << ("==========") << endl;
        cout << ("Enter your option: ");
        cin >> val;
        if (val == "1") {
            string user;
            string pass;
            string num;
            cout << "Enter username: ";
            cin >> user;
            cout << "Enter password: ";
            cin >> pass;
            cout << "Departure" << setw(11) << "Arrival" << setw(15) << "Departure Date" << setw(15) << "Departure Time" << setw(15) << "Flight Number" << setw(15) << "Status" << setw(15) << "Number of Seats" << endl;
            cout << "============================" << endl;
            flightList.print();
            cout << "============================" << endl;
            cout << "Select a flight: ";
            cin >> num;
            cout << "Username: " << user << endl;
            cout << "Password: " << pass << endl;
            cout << "Selected Flight: " << num << endl;
            Flight* flight = flightList.find(num);
            if (flight == nullptr) {
                cout << "Invalid number inputted !!" << endl;
                continue;
            }
            else {
                cache.set(*flight);
            }
            cout << "You have been added into our database!" << endl;
            Passenger passenger = Passenger(user, pass, *flight);
            passengerList.add(passenger);
        }
        else if (val == "2") {
            string user;
            string pass;
            cout << "Enter username: ";
            cin >> user;
            for (int i = 0; i < passengerList.getLength(); i++)
            {
                if (user == passengerList.get(i).getUsername())
                {
                    cout << "Enter password: ";
                    cin >> pass;
                    if (pass == passengerList.get(i).getPassword())
                    {
                        Flight num = passengerList.get(i).getFlight();
                        cout << "Your booked flight is: " << num.toString() << endl;
                        cache.set(num);
                        break;
                    }
                }
            }
        }
        else if (val == "3") {
            cout << "Departure" << setw(11) << "Arrival" << setw(15) << "Departure Date" << setw(15) << "Departure Time" << setw(15) << "Flight Number" << setw(15) << "Status" << setw(15) << "Number of Seats" << endl;
            cout << "============================" << endl;
            flightList.print();
            cout << "============================" << endl;
        }
        else if (val == "4") {
            //View passenger details
        }
        else if (val == "5") {
            //View flight details
        }
        else if (val == "6") {
            string number;
            cout << "Enter flight number" << endl;
            cin >> number;
            auto start = chrono::steady_clock::now();
            Flight flight;
            flight = cache.get(number);
            if (flight.getNumber() == "") {
                flight = *flightList.find(number);
            }
            auto end = chrono::steady_clock::now();
            cout << flight.toString() << endl;
            cout << "Elapsed Time (ns):" << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << endl;
        }
        else if (val == "7") {
            cache.print();
        }
        else if (val == "0") {
            cout << "Goodbye!";
            return 0;
        }
        else {
            cout << "Invalid input.." << endl;
        }
    } 

}
