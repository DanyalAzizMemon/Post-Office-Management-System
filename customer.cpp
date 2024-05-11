//Danyal Memon
//20i-1811 BSCS F
//Project

#include <iostream>
#include <fstream>

//files created

using namespace std;


struct CDetails
{
    string first_name;
    string last_name;
    string cnic;
    string phone_number;

};

//association with class address
class Customer		//this class contains all the details related to Customer
{

    string username;
    string password;
    CDetails CustomerDetails;		//structure of CDetails
    Address CustomerAddress;

public:
    void setCustomer();
    void display();
    friend class Order;
    void login();
    void signup();

};

void Customer::setCustomer()
{
	cout<<"Enter your first name : ";
	cin>>this->CustomerDetails.first_name;

	cout<<"Enter your last name : ";
	cin>>this->CustomerDetails.last_name;

	cout<<"Enter your CNIC name : ";
	cin>>this->CustomerDetails.cnic;

	cout<<"Enter your Phone number : ";
	cin>>this->CustomerDetails.phone_number;

	CustomerAddress.setAddress();

	cout<<"Enter Username for your account : ";
	cin>>this->username;

	cout<<"Enter Password for your account : ";
	cin>>this->password;


	//the contents are written in file

	ofstream C;
	C.open("Customer.txt",ios::app);	//append mode

	if(!C)//if file not created
		cout<<"File not created";

	else
	{
		C << CustomerDetails.first_name << " ";
		C << this->CustomerDetails.last_name << " ";
		C << this->CustomerDetails.cnic << " ";
		C << this->CustomerDetails.phone_number <<endl;//to go to the next line for next customer address

		C << this->CustomerAddress.city << " ";
		C << this->CustomerAddress.sector << " ";
		C << this->CustomerAddress.street << " ";
		C << this->CustomerAddress.house <<endl;
	}
	C.close();


	ofstream s;
	s.open("Customerlogin.txt",ios::app);	//append mode

	if(!s)//if file not created
		cout<<"File not created";

	else
	{
		s << this->username << " " << this->password << endl;
	}
	s.close();

}

void Customer::display()
{
	cout<<"\nCustomer Details:";
	cout<<"\nFirst Name : "<<this->CustomerDetails.first_name;
	cout<<"\nLast Name : "<<this->CustomerDetails.last_name;
	cout<<"\nCNIC : "<<this->CustomerDetails.cnic;
	cout<<"\nPhone Number : "<<this->CustomerDetails.phone_number;

	CustomerAddress.Addressdisplay();

	cout << "\nUser Name : "<<this->username;
	cout << "\nPassword : "<<this->password;
	cout << endl;
}

void Customer::login()
{

	string u[20],p[20];			//username and password;
	string username,password;
	bool success=0;

	ifstream file;
	file.open("Customerlogin.txt",ios::in);

	for(int i=0;(!file.eof()); i++)
	{
		file >> u[i] >> p[i];
	}

	int arrsize = sizeof(u)/sizeof(u[0]);	//to check in for loop

	customerreenter:

	cout << "\nEnter your Username : ";
	cin >> username;

	cout << "Enter your Password : ";
	cin >> password;

	for (int i = 0; i < arrsize; i++)
	{
		if (username == u[i] && password == p[i])
		{
			cout << "Login successful ";
			success = 1;
		}
	}

	if (success == 0)
	{
		cout<< "\nLogin not sucessful : ";
		goto customerreenter;
	}

}

void Customer::signup()
{
	setCustomer();
	display();
	login();
}

