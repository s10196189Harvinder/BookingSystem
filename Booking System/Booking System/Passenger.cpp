#include "Passenger.h"

Passenger::Passenger() {}
Passenger::Passenger(string username, string password) {
	Username = username;
	Password = password;
}

void Passenger::setUsername(string username) { Username = username; }
string Passenger::getUsername() { return Username; }

void Passenger::setPassword(string password) { Password = password; }
string Passenger::getPassword() { return Password; }

string Passenger::toString() {
	string text = Username + "    " + Password;
	return text;
}