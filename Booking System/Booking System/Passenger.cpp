#include "Passenger.h"

Passenger::Passenger() {}
Passenger::Passenger(string username, string password, Flight num) {
	Username = username;
	Password = password;
	pFlight = num;
}

void Passenger::setUsername(string username) { Username = username; }
string Passenger::getUsername() { return Username; }

void Passenger::setPassword(string password) { Password = password; }
string Passenger::getPassword() { return Password; }

void Passenger::setFlight(Flight num) { pFlight = num; }
Flight Passenger::getFlight() { return pFlight; }

string Passenger::toString() {
	string text = Username + "    " + Password;
	return text;
}