#pragma once
#ifndef CONTACTBOOK_H
#define CONTACTBOOK_H

#include "Contact.h"
#include "Address.h"
#include <iostream>
#include <string>
using namespace std;

class ContactsBook {
private:
	Contact *contacts_list; // array of contacts
	int size_of_contacts;   // storage limit
	int contacts_count;     // total contacts currently stored, next contact will be 
						    // stored at this count plus 1 index
public:
	void add_contact(const Contact& contact);
	int total_contacts();

	Contact* search_contact(string first_name, string last_name);
	Contact* search_contact(string phone);
	Contact* search_contact(const Address& address);

	ContactsBook(int size_of_list);
	void print_contact();
	
	void print_contacts_sorted(string choice); // Only two choices first_name or last_name
	void merge_duplicates(); // Implement this function that finds and merges all the duplicates
							 // Duplicate means exact equal, this means if
	/* 
	*  This function loads contacts from the given file (see details in ContactsBook.cpp)
	*/
	void load_from_file(string file_name);
	void save_to_file(string file_name);
	Contact* copy_contacts_list() const;

private:
	bool full();
	void resize_list();
	void sort_contacts_list(Contact *contacts_list, string choice);
};

#endif CONTACTBOOK_H
