#include "Contact.h"
#include <string>
using namespace std;

/*
*	Implement a constructor that initializes all the Contact parts, including address. Call the setter to set values
*	as they have the logic to check correct input
*	Declaration is given in Contact.h
*/
//                                   Constructors

Contact::Contact() : first_name(""), last_name(""), mobile_number(""), email_address(""), address(NULL) {}
Contact::Contact(string first_name, string last_name, string mobile_number, string email_address, Address *address) :
	first_name(first_name), last_name(last_name), mobile_number(mobile_number), email_address(email_address), address(address) {}

/*
*	Implement getter/setters for all the member variables of Contact. Also declare them in the Contact.h header file
*	In each setter, do not set value if string is empty ("" 0 size).
*   Check in phone number setter, Phone number must be 11 digits
*/

//                                     Getters
string Contact::GetFirstName() const { return first_name; }
string Contact::GetLastName() const { return last_name; }
string Contact::GetMobileNumber() const { return mobile_number; }
string Contact::GetEmailAddress() const { return email_address; }
Address* Contact::GetAddress() const { return address; }

//                                    Setters
void Contact::setFirst_name(string fname) { this->first_name = fname; }
void Contact::setLast_name(string lname) { this->last_name = lname; }
void Contact::setMobile_number(string number) {
	if (size(number) == 11) {
		this->mobile_number = number;
	}
}
void Contact::setEmail_address(string email) { this->email_address = email; }
void Contact::setAddress(Address* address) { this->address = address; }

//                                  Print
void Contact::print_contact() {
	cout << "Contact: " << first_name << "  " << last_name << "  " << mobile_number << " " << email_address;
}

//                                  Meathords
bool Contact::equals(Contact contact) {
	if (first_name == contact.first_name && last_name == contact.last_name && mobile_number == contact.mobile_number &&
		email_address == contact.email_address && contact.address->equals(*address))
	{
		return true;
	}
	return false;
}

Contact* Contact::copy_contact()
{
	Address newaddress = address->copy_address();
	Contact* newContact = new Contact(this->first_name, this->last_name, this->mobile_number, this->email_address, &newaddress);
	return newContact;
}
