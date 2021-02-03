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

public:
	Passenger();
	Passenger(string username, string password);

	void setUsername(string username);
	string getUsername();

	void setPassword(string password);
	string getPassword();

	string toString();
};