#include "Address.h"

//                                       Constructors
Address::Address(string house, string street, string city, string country) :
	house(house), street(street), city(city), country(country) {}

//                                          getters
string Address::getHouse() const { return house; }
string Address::getStreet() const { return street; }
string Address::getCity() const { return city; }
string Address::getCountry() const { return country; }

//                                          setters
void Address::setHouse(string house) { this->house = house; }
void Address::setStreet(string street) { this->street = street; }
void Address::setCity(string city) { this->city = city; }
void Address::setCountry(string country) { this->country = country; }
void Address::setAddress(string house, string street, string city, string country) {
	this->house = house;
	this->street = street;
	this->city = city;
	this->country = country;
}
//                                            Meathods

//Two addresses are equal if all the attributes of addresses are equal
bool Address::equals(const Address& address) const
{
	if (house == address.house && city == address.city && street == address.street && country == address.country)
	{
		return true;
	}
	return false;
}

//Print address on one line as House, Street, City, Country
void Address::print_address() const
{
	cout << "Address: " << house << ", " << street << ", " << city << ", " << country << endl;
}

// return a copy of current address
Address Address::copy_address() const
{
	return Address(this->house, this->street, this->city, this->country);

}