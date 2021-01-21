// Flight.cpp - Implementation of Flight class
#include "Flight.h"

Flight::Flight() {}

Flight::Flight(string n, string st, int s)
{
	number = n;
	status = st;
	seats = s;
}

void Flight::setNumber(string n) { number = n; }
string Flight::getNumber() { return number; }

void Flight::setStatus(string st) { status = st; }
string Flight::getStatus() { return status; }

void Flight::setSeats(int s) { seats = s; }
int Flight::getSeats() { return seats; }