#pragma once
// Flight.h - Definition of Flight class

#include <string>
#include <iostream>
using namespace std;

class Flight
{
private:
	string number; // Flight Number
	string status; // Flight Status (Available, Cancelled)
	int seats; // Number of seats left on the flight

public:
	Flight();
	Flight(string n, string st, int s);

	void setNumber(string n);
	string getNumber();

	void setStatus(string st);
	string getStatus();

	void setSeats(int s);
	int getSeats();
};