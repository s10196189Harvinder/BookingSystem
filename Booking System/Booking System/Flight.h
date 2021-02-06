#pragma once
// Flight.h - Definition of Flight class

#include <string>
#include <iostream>
using namespace std;

class Flight
{
private:
	string Departure;
	string Destination;
	int DepartureDate; //Epochs
	string DepartureTime; //Epochs
	string Number; // Flight Number
	string Status; // Flight Status (Available, Cancelled)
	int Seats; // Number of seats left on the flight

public:
	Flight();
	Flight(string departure, string destination, int departuredate, string departuretime, string number, string status, int seats);

	void setNumber(string n);
	string getNumber();

	//void setStatus(string st);
	string getStatus();
	string getDepartureDate();
	string getDepartureTime();
	//void setSeats(int s);
	//int getSeats();
	string toString();
	string getDeparture();
	string getDestination();
};