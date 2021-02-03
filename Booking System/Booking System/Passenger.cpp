#include "Passenger.h"

Passenger::Passenger() {}
Passenger::Passenger(string username, string password, string num) {
	Username = username;
	Password = password;
	Number = num;
}

void Passenger::setUsername(string username) { Username = username; }
string Passenger::getUsername() { return Username; }

void Passenger::setPassword(string password) { Password = password; }
string Passenger::getPassword() { return Password; }

void Passenger::setFlight(string num) { Number = num; }
string Passenger::getFlight() { return Number; }

string Passenger::toString() {
	string text = Username + "    " + Password;
	return text;
}