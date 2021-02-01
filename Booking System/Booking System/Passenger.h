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
	Passenger(string username, string password) {
		Username = username;
		Password = password;
	}
}; 
