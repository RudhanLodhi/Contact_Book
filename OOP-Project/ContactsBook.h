#pragma once
#ifndef CONTACTBOOK_H
#define CONTACTBOOK_H

#include "Contact.h"

class ContactsBook {
private:
	Contact *contacts_list;
	int size_of_contacts;
	int contacts_count;
public:

	//          Constructor / Destructor
	ContactsBook(int size_of_list);

	//          Search Meathords
	Contact* search_contact(string first_name, string last_name);
	Contact* search_contact(string phone);
	Contact* search_contact(const Address& address);

	//          Getter
	int total_contacts();

	//          Meathords
	void add_contact(const Contact& contact);
	void merge_duplicates();
	void print_contact();
	void print_contacts_sorted(string choice); // Only two choices first_name or last_name
	Contact* copy_contacts_list() const;

	//          File  Handelling
	void load_from_file(string file_name);
	void save_to_file(string file_name);

private:
	bool full();
	void resize_list();
	void sort_contacts_list(Contact *contacts_list, string choice);
};
#endif CONTACTBOOK_H