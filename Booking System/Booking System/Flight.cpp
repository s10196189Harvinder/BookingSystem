// Flight.cpp - Implementation of Flight class
#include "Flight.h"
#include <iomanip>

Flight::Flight(){}
Flight::Flight(string departure, string destination, int departuredate, string departuretime, string number, string status, int seats) {
	Departure = departure;
	Destination = destination;
	DepartureDate = departuredate;
	DepartureTime = departuretime;
	Number = number;
	Status = status;
	Seats = seats;
}

void Flight::setNumber(string n) { Number = n; }
string Flight::getNumber() { return Number; }

string Flight::getStatus() { return Status; }

string Flight::toString() {
	string text = Departure + "    " + Destination + "    " + to_string(DepartureDate) + "    " + DepartureTime + "    " + Number + "    " + Status + "    " + to_string(Seats);
	cout << Departure << setw(11) << Destination << setw(15) << to_string(DepartureDate) << setw(15) << DepartureTime << setw(15) << Number << setw(15) << Status << setw(15) << to_string(Seats) << endl;
	return text;
}

string Flight::getDepartureTime() { return DepartureTime;}
string Flight::getDepartureDate() { return to_string(DepartureDate); }
string Flight::getDeparture() { return Departure; }
string Flight::getDestination() { return Destination; }