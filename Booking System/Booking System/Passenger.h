//=====================================================================
//Group: P05
//ID (Name): Harvinder Arjun Singh (S10196189D), Wayne Lee (S10177125E)
//=====================================================================

#pragma once
// Passenger.h - Definition of Passenger class

#include <string>
#include <iostream>
#include "Flight.h"
using namespace std;

class Passenger
{
private:
	string Username;
	string Password;
	Flight pFlight;

public:
	Passenger();
	Passenger(string username, string password, Flight num);

	void setUsername(string username);
	string getUsername();

	void setPassword(string password);
	string getPassword();

	void setFlight(Flight num);
	Flight getFlight();

	string toString();
};