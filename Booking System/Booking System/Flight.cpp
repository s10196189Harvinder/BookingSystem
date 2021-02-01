// Flight.cpp - Implementation of Flight class
#include "Flight.h"

Flight::Flight(){}
Flight::Flight(string departure, string destination, int departuredate, int departuretime, string number, string status, int seats) {
	Departure = departure;
	Destination = destination;
	DepartureDate = departuredate;
	DepartureTime = departuretime;
	Number = number;
	Status = status;
	Seats = seats;
}




void Flight::setNumber(string n) {
	Number = n;
}
string Flight::getNumber() { return Number; }
string Flight::toString() {
	string text = Departure + Destination + to_string(DepartureDate) + to_string(DepartureTime) + Number + Status + to_string(Seats);
	return text;
}
int Flight::getDepartureTime() {
	return DepartureTime;
}
