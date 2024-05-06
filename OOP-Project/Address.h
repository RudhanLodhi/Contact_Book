#pragma once
#ifndef ADDRESS_H
#define ADDRESS_H

#include <iostream>
#include <string>
using namespace std;

class Address {
private:
	string house;
	string street;
	string city;
	string country;

public:
	//Meathords
	bool equals(const Address& address) const;
	void print_address() const;
	Address copy_address() const;

	//getters
	string getHouse() const;
	string getStreet() const;
	string getCity() const;
	string getCountry() const;

	//setters
	void setHouse(string house);
	void setStreet(string street);
	void setCity(string city);
	void setCountry(string country);
	void setAddress(string house, string street, string city, string country);

	//Contructor
	Address(string house = "", string street = "", string city = "", string country = "");
};
#endif ADDRESS_H