//Danyal Memon
//20i-1811 BSCS F
//Project

#include <iostream>
#include <fstream>
using namespace std;


//-------------------------------------------------------------------------------------------------------------------------


class Address
{

	string house;
	string street;
	string sector;
	string city;

public:
	void setAddress();
	void Addressdisplay();
	friend class Customer;		//class will need to access private members of address
	friend class Order;
};

void Address::setAddress()
{
	cout << "\nEnter City : ";
	cin >> this->city;

	cout << "Enter Sector : ";
	cin >> this->sector;

	cout << "Enter Street number : ";
	cin >> this->street;

	cout << "Enter House number : ";
	cin >> this->house;
}

void Address::Addressdisplay()
{
	cout << "\nAddress details";
	cout << "\nCity : "<<this->city;
	cout << "\nSector : "<<this->sector;
	cout << "\nStreet number : "<<this->street;
	cout << "\nHouse number : "<<this->house;

}


