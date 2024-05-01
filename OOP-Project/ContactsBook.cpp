//#include "ContactsBook.h"
//#include <fstream>
//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//void ContactsBook::add_contact(const Contact &contact)
//{
//	if (contacts_count < size_of_contacts)
//	{
//		contacts_list[contacts_count] = contact;
//		contacts_count++;
//	}
//	else
//		resize_list();
//	/*
//	- Check if the list is full, if it is full call the resize function
//	- If list is not full add the contact to the end of the array
//	- (end means the place where last contact was inserted)
//	- At start it will be 0th index as no contact has been inserted before so
//	- count is zero (contacts_count member)
//	- Increment the count
//	- As inserted successfully, return 1
//	*/
//}
//
//int ContactsBook::total_contacts()
//{
//	/*
//	*	Return the total contacts currently stored
//	*/
//	return contacts_count;
//}
//
//bool ContactsBook::full()
//{
//	/*
//	* Return true if list is full, false otherwise
//	*/
//	if (contacts_count == size_of_contacts)
//	{
//		return true;
//	}
//	/*
//	*	Remove this return false; before writing your code
//	*/
//	return false;
//}
//
//void ContactsBook::resize_list()
//{
//	Contact *temp = new Contact[size_of_contacts * 2];
//	for (int i = 0; i < size_of_contacts; i++)
//	{
//		temp[i] = *contacts_list[i].copy_contact();
//	}
//	delete[] contacts_list;
//	contacts_list = temp;
//	this->size_of_contacts = size_of_contacts * 2;
//
//	/*
//	*	Here you will resize the contact list, see example code given in lab manual to see how to resize arrays
//	*	You will allocate a temporary new array of double the current size and copy the contacts from
//	*       previous array to this array one by one, get the copy of each contact using copy_contact
//	*       function of Contact class
//	*	Delete the previous array
//	*	Assign the new temporary array to the contacts_list pointer
//	*	Updated the this->size_of_contacts with new size
//	*/
//}
//
//Contact *ContactsBook::search_contact(string first_name, string last_name)
//{
//	for (int i = 0; i < size_of_contacts; i++)
//	{
//		if (contacts_list[i].GetFirstName() == first_name && contacts_list[i].GetLastName() == last_name)
//		{
//			return contacts_list[i].copy_contact();
//		}
//	}
//	return nullptr;
//
//	/*
//	*	In all search functions perform the searching according the given parameter and return a copy of the contact using copy func
//	*	Remove this return nullptr; before writing your code
//	*/
//}
//
//Contact *ContactsBook::search_contact(string phone)
//{
//	for (int i = 0; i < size_of_contacts; i++)
//	{
//		if (contacts_list[i].GetMobileNumber() == phone)
//		{
//			return contacts_list[i].copy_contact();
//		}
//	}
//
//	/*
//	*	Remove this return nullptr; before writing your code
//	*/
//	return nullptr;
//}
//
//Contact *ContactsBook::search_contact(const Address &address)
//{
//	for (int i = 0; i < size_of_contacts; i++)
//	{
//		if (contacts_list[i].GetAddress() == &address)
//		{
//			/* code */
//		}
//	}
//
//	/*
//	*	Remove this return nullptr; before writing your code
//	*/
//	return nullptr;
//}
//
//ContactsBook::ContactsBook(int size_of_list)
//{
//	size_of_contacts = size_of_list;
//	contacts_count = 0;
//	contacts_list = new Contact[size_of_contacts];
//}
//
//Contact* ContactsBook::copy_contacts_list() const {
//	Contact* copiedList = new Contact[contacts_count];
//	for (int i = 0; i < contacts_count; ++i) {
//		copiedList[i] = *contacts_list[i].copy_contact();
//	}
//	return copiedList;
//}
//void ContactsBook::print_contacts_sorted(string choice)
//{
//	sort_contacts_list(copy_contacts_list(), choice);
//	for (int i = 0; i < contacts_count; ++i)
//	{
//		contacts_list[i].print_contact();
//		contacts_list[i].print_address();
//
//	}
//
//	/*
//	*	Create a copy of this->contacts_list array here (do it by creating a new function that returns copy)
//	*	Call the sort function sort_contacts_list to sort the newly created copy
//	*	This copy is created to avoid changing the original insertion order of contact list
//	*	Then print the contacts in following format:
//	*	[First Name] [Last Name] [Mobile] [Email]
//	*	Call the address print function to print address on next line
//	*/
//}
//
//void ContactsBook::sort_contacts_list(Contact *contacts_list, string choice) {
//	if (choice == "First Name")
//	{
//		sort(contacts_list, total_contacts());
//	}
//	else
//	{
//		sort(contacts_list->GetLastName(), total_contacts);
//	}
//}
//	/*
//	You should not duplicate the code to sort based on choices
//	Follow the strategy provided in manual/tutorial to avoid duplicating the code (Section B & E only)
//	Sort by the fist letter of first name or last name as given in choice
//	*/
//
//void ContactsBook::merge_duplicates()
//{
//	int mergedCount = 0; // Counter for merged duplicates
//	for (int i = 0; i < size_of_contacts; ++i)
//	{
//		for (int j = i + 1; j < size_of_contacts; ++j)
//		{
//			if (contacts_list[i].GetFirstName() == contacts_list[j].GetFirstName() && contacts_list[i].GetLastName() == contacts_list[j].GetLastName() && contacts_list[i].GetEmailAddress() == contacts_list[j].GetEmailAddress() && contacts_list[i].GetAddress() == contacts_list[j].GetAddress() && contacts_list[i].GetMobileNumber() == contacts_list[j].GetMobileNumber())
//			{
//				cout << "Merged contact:" << contacts_list[i].GetFirstName() << " " << contacts_list[i].GetLastName() << " " << contacts_list[i].GetMobileNumber() << " " << contacts_list[i].GetEmailAddress() << " " << endl;
//				for (int k = j; k < size_of_contacts - 1; ++k)
//				{
//					contacts_list[k] = contacts_list[k + 1];
//				}
//				--size_of_contacts;
//				contacts_count--;
//				--j;
//				++mergedCount; // Increment mergedCount
//			}
//		}
//		cout << "Merged count: " << mergedCount << endl;
//	}
//
//	// Implement this function that finds and merges all the duplicates
//	// Duplicate means exact equal
//	// If there are three copies of a Contact, then only one should remain
//	// For example: If total contact are 10, and 2 contacts are same, after removing duplicates
//	// 9 contacts will be left; and the this->contacts_count of list will 9
//	// At the end display contacts merged, and count of merged contacts
//}
//
//void ContactsBook::load_from_file(string file_name)
//{
//
//	/*
//	*	Read contacts back from file in the same format
//	*	Read the contacts_count, and run a loop for this contacts_count and read the
//	*	contacts in the same format as you stored
//	*	Add them to contact book (this.add_contact function can be used)
//	*	Finally, close the file
//	*/
//}
//
//void ContactsBook::save_to_file(string file_name)
//{
//	ofstream file(file_name);
//
//	if (!file.is_open()) {
//		cout << "Error opening file: " << file_name << endl;
//		return;
//	}
//
//	// Write contacts count on the first line
//	file << contacts_count << "\n";
//
//	// Write each contact and address to the file
//	for (int i = 0; i < contacts_count; ++i) {
//		// Write contact attributes to the file
//		file << contacts_list[i].GetFirstName() << ","
//			<< contacts_list[i].GetLastName() << ","
//			<< contacts_list[i].GetMobileNumber() << ","
//			<< contacts_list[i].GetEmailAddress() << "\n";
//
//		// Write address attributes to the file
//		// file << contacts_list[i].house << ","
//		//      << contacts_list[i].street << ","
//		//      << contacts_list[i].city << ","
//		//      << contacts_list[i].country << "\n";
//	}
//
//	// Close the file
//	file.close();
//	/*
//	*	In this function you will store all the contacts to a file
//	*	On first line store contacts_count
//	*	On next lines store contacts in the following format:
//	*       2 lines for each contact
//	*       On oneline write contact attributes(except address) in comma separated format. On second line
//	*	store address atributes in the same format
//	*	first_name,last_name,mobile_number,email_address
//	*	house,street,city,country
//	*	Close the file
//	*/
//}
