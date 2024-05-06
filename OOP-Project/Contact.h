#pragma once
#ifndef CONTACT_H
#define CONTACT_H
#include "Address.h"

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

	// Constructor / Destructor
	Contact(string first_name, string last_name, string mobile_number, string email_address, Address *address);
	Contact();
};
#endif CONTACT_H