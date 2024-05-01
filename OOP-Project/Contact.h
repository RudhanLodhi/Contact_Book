#pragma once
#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
#include <string>
#include "Address.h"
using namespace std;

class Contact {
private:
	string first_name;
	string last_name;
	string mobile_number;
	string email_address;
	Address *address;

public:
	// Meathords
	bool equals(Contact contact);
	Contact* copy_contact();

	// Getters
	string GetFirstName() const;
	string GetLastName() const;
	string GetMobileNumber() const;
	string GetEmailAddress() const;
	Address* GetAddress() const;

	// Setter
	void setFirst_name(string fname);
	void setLast_name(string lname);
	void setMobile_number(string number);
	void setEmail_address(string email);
	void setAddress(Address* address);

	//Print
	void print_contact();

	// Constructor
	Contact();
	Contact(string first_name, string last_name, string mobile_number, string email_address, Address *address);
};

#endif CONTACT_H