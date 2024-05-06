#include "ContactsBook.h"
#include <fstream>

//                       Contrsuctor / Destructor
ContactsBook::ContactsBook(int size_of_list)
{
	size_of_contacts = size_of_list;
	contacts_count = 0;
	contacts_list = new Contact[size_of_list];
}

//                         Search Meathords

// Search contact by Name
Contact *ContactsBook::search_contact(string first_name, string last_name)
{
	for (int i = 0; i < size_of_contacts; i++)
	{
		if (contacts_list[i].GetFirstName() == first_name && contacts_list[i].GetLastName() == last_name)
		{
			return contacts_list[i].copy_contact();
		}
	}
	return nullptr;
}

// Search contact by phone
Contact *ContactsBook::search_contact(string phone)
{
	for (int i = 0; i < size_of_contacts; i++)
	{
		if (contacts_list[i].GetMobileNumber() == phone)
		{
			return contacts_list[i].copy_contact();
		}
	}
	return nullptr;
}

// Search contact by Address
Contact *ContactsBook::search_contact(const Address& address)
{
	for (int i = 0; i < size_of_contacts; i++)
	{
		if (contacts_list[i].GetAddress()->equals(address))
		{
			return &contacts_list[i];
		}
	}
	return nullptr;
}

//                         Getter

//  Return number of contacts stored
int ContactsBook::total_contacts()
{
	return contacts_count;
}

//                        Private  Meathords


// Check if Contact_book is full
bool ContactsBook::full()
{
	if (contacts_count == size_of_contacts)
	{
		return true;
	}
	return false;
}

// Resize by making a new D_Array of 2x size and copy contacts in it
void ContactsBook::resize_list()
{
	Contact *temp = new Contact[size_of_contacts * 2];
	for (int i = 0; i < size_of_contacts; i++)
	{
		temp[i] = *contacts_list[i].copy_contact();
	}
	delete[] contacts_list;
	contacts_list = temp;
	this->size_of_contacts = size_of_contacts * 2;
}

// using bubble sort
void ContactsBook::sort_contacts_list(Contact *contacts_list, string choice) {
	if (choice == "First") {
		bool swapped;
		for (int i = 0; i < contacts_count - 1; i++) {
			swapped = false;
			for (int j = 0; j < contacts_count - i - 1; j++) {
				if (contacts_list[j].GetFirstName() > contacts_list[j + 1].GetFirstName()) {
					swap(contacts_list[j], contacts_list[j + 1]);
					swapped = true;
				}
			}
			// If no two elements were swapped by inner loop, then break
			if (swapped == false)
				break;
		}
	}
	else if (choice == "Last") {
		bool swapped;
		for (int i = 0; i < contacts_count - 1; i++) {
			swapped = false;
			for (int j = 0; j < contacts_count - i - 1; j++) {
				if (contacts_list[j].GetLastName() > contacts_list[j + 1].GetLastName()) {
					swap(contacts_list[j], contacts_list[j + 1]);
					swapped = true;
				}
			}
			if (swapped == false)
				break;
		}
	}
}
/*
You should not duplicate the code to sort based on choices
Follow the strategy provided in manual/tutorial to avoid duplicating the code (Section B & E only)
Sort by the fist letter of first name or last name as given in choice
*/


//                             Public  Meathords

// Add contact if full Resize_list
void ContactsBook::add_contact(const Contact &contact)
{
	if (contacts_count < size_of_contacts)
	{
		contacts_list[contacts_count] = contact;
		contacts_count++;
	}
	else
		resize_list();
}

// Merge same contacts
void ContactsBook::merge_duplicates()
{
	int mergedCount = 0; // Counter for merged duplicates
	for (int i = 0; i < size_of_contacts; ++i)
	{
		for (int j = i + 1; j < size_of_contacts; ++j)
		{
			if (contacts_list[i].equals(contacts_list[j]))
			{
				cout << "Merged contact:" << contacts_list[i].GetFirstName() << " " << contacts_list[i].GetLastName() << endl;
				for (int k = j; k < size_of_contacts - 1; ++k)
				{
					contacts_list[k] = contacts_list[k + 1];
				}
				--size_of_contacts;
				contacts_count--;
				--j;
				++mergedCount; // Increment mergedCount
			}
		}
		cout << "Merged count: " << mergedCount << endl;
	}
}

void ContactsBook::print_contact()
{
	for (int i = 0; i < contacts_count; i++)
	{
		cout << "\nContact No." << i + 1 << ": " << endl;
		contacts_list[i].print_contact();
		cout << "Address: \n"; contacts_list[i].GetAddress()->print_address(); cout << endl;
	}
}


// Create a copy of current list
Contact* ContactsBook::copy_contacts_list() const {
	Contact* copiedList = new Contact[contacts_count];
	for (int i = 0; i < contacts_count; ++i) {
		copiedList[i] = *contacts_list[i].copy_contact();
	}
	return copiedList;
}

void ContactsBook::print_contacts_sorted(string choice)
{
	Contact *temp = copy_contacts_list();
	sort_contacts_list(temp, choice);

	for (int i = 0; i < contacts_count; i++)
	{
		cout << temp[i].GetFirstName() << " "
			<< temp[i].GetLastName() << " "
			<< temp[i].GetMobileNumber() << " "
			<< temp[i].GetEmailAddress() << endl;
		temp[i].GetAddress()->print_address();
		cout << endl;
	}
	/*
	*	Create a copy of this->contacts_list array here (do it by creating a new function that returns copy)
	*	Call the sort function sort_contacts_list to sort the newly created copy
	*	This copy is created to avoid changing the original insertion order of contact list
	*	Then print the contacts in following format:
	*	[First Name] [Last Name] [Mobile] [Email]
	*	Call the address print function to print address on next line
	*/
}

//                          File Handelling

void ContactsBook::load_from_file(string file_name)
{
	// Open the file in read mode
	ifstream file(file_name);

	// Check if the file is open
	if (!file) {
		cout << "Unable to open file";
		return;
	}

	// Read the contacts_count from the first line
	int count;
	file >> count;

	// Read the contacts
	for (int i = 0; i < count; i++) {
		string first_name, last_name, mobile_number, email_address;
		string house, street, city, country;

		// Read contact attributes (except address) in comma separated format
		getline(file, first_name, ',');
		getline(file, last_name, ',');
		getline(file, mobile_number, ',');
		getline(file, email_address);

		// Read address attributes in comma separated format
		getline(file, house, ',');
		getline(file, street, ',');
		getline(file, city, ',');
		getline(file, country);

		// Create new Address and Contact objects
		Address* addr = new Address(house, street, city, country);
		Contact* contact = new Contact(first_name, last_name, mobile_number, email_address, addr);

		// Add the new contact to the contact book
		this->add_contact(*contact);
	}

	// Close the file
	file.close();

	/*
	*	Read contacts back from file in the same format
	*	Read the contacts_count, and run a loop for this contacts_count and read the
	*	contacts in the same format as you stored
	*	Add them to contact book (this.add_contact function can be used)
	*	Finally, close the file
	*/
}

void ContactsBook::save_to_file(string file_name)
{
	// Open the file in write mode
	ofstream file(file_name);

	// Check if the file is open
	if (!file) {
		cout << "Unable to open file";
		return;
	}

	// Write the contacts_count on the first line
	file << contacts_count << "\n";

	// Write the contacts
	for (int i = 0; i < contacts_count; i++) {
		// Write contact attributes (except address) in comma separated format
		file << contacts_list[i].GetFirstName() << ","
			<< contacts_list[i].GetLastName() << ","
			<< contacts_list[i].GetMobileNumber() << ","
			<< contacts_list[i].GetEmailAddress() << "\n";

		// Write address attributes in comma separated format
		Address* addr = contacts_list[i].GetAddress();
		file << addr->getHouse() << ","
			<< addr->getStreet() << ","
			<< addr->getCity() << ","
			<< addr->getCountry() << "\n";
	}

	// Close the file
	file.close();
	/*
	*	In this function you will store all the contacts to a file
	*	On first line store contacts_count
	*	On next lines store contacts in the following format:
	*       2 lines for each contact
	*       On oneline write contact attributes(except address) in comma separated format. On second line
	*	store address atributes in the same format
	*	first_name,last_name,mobile_number,email_address
	*	house,street,city,country
	*	Close the file
	*/
}