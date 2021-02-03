#pragma once
// Passenger.h - Definition of Passenger class

#include <string>
#include <iostream>
using namespace std;

class Passenger
{
private:
	string Username;
	string Password;
	string Number;

public:
	Passenger();
	Passenger(string username, string password, string num);

	void setUsername(string username);
	string getUsername();

	void setPassword(string password);
	string getPassword();

	void setFlight(string num);
	string getFlight();

	string toString();
};