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
	int DepartureTime; //Epochs
	string Number; // Flight Number
	string Status; // Flight Status (Available, Cancelled)
	int Seats; // Number of seats left on the flight

public:
	Flight();
	Flight(string departure, string destination, int departuredate, int departuretime, string number, string status, int seats) {
		Departure = departure;
		Destination = destination;
		DepartureDate = departuredate;
		DepartureTime = departuretime;
		Number = number;
		Status = status;
		Seats = seats;
	}

	void setNumber(string n);
	string getNumber();

	void setStatus(string st);
	string getStatus();

	void setSeats(int s);
	int getSeats();
};