//Danyal Memon
//20i-1811 BSCS F
//Project

#include <iostream>
#include <fstream>

//files created

using namespace std;


//-------------------------------------------------------------------------------------------------------------------------

class MailService
{
protected:
	string services;
	bool citytocity;
	string cityreciever;

public:
	void setMail();

};

void MailService::setMail()
{
	string city,citysender;
	string temp;
	int choice;

	cout << "In which city do you want to send your mail to : ";
	cin >> city;

	this->cityreciever = city;


	ofstream c;
	c.open("Customer.txt",ios::app);

	if(!c)//if file not created
		cout<<"File not opened";
	else
		c << city << endl;

	c.close();

	ifstream R;
	R.open("Customer.txt",ios::in);		//first line is ignored as city is stored in next line

	getline(R,temp,'\n');
	R >> citysender;

	R.close();

	if (citysender == city)
	{
		this->citytocity = 0;
		reenter:		//incase user enters a wrong value
		cout<<"Which service would you like to choose\nSame Day press 1\nOne Day press 2\nUrgent Press 3\n Regular press 4\nEnter your choice : ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			this->services = "sameday";
			break;

		case 2:
			this->services = "oneday";
			break;

		case 3:
			this->services = "urgent";
			break;

		case 4:
			this->services = "regular";
			break;

		default:
			cout<<"\nWrong choice selected Re-enter\n";
			goto reenter;
			break;
		}
	}

	if (city == "lahore" || city == "pindi" || city == "sargodha"|| city == "faisalabad")	// the neighbouring cities to Islamabad reachable in one day
	{
		this->citytocity = 1;
		reenter1:		//incase user enters a wrong value
		cout<<"Which service would you like to choose\nOne Day press 1\nUrgent Press 2\n Regular press 3\nEnter your choice : ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			this->services = "oneday";
			goto continue1;
			break;

		case 2:
			this->services = "urgent";
			goto continue1;
			break;

		case 3:
			this->services = "regular";
			goto continue1;
			break;

		default:
			cout<<"\nWrong choice selected Re-enter\n";
			goto reenter1;
			break;
		}
	}

	if((city != citysender) && (city != "lahore" || city != "pindi" || city != "sargodha"|| city != "faisalabad"))
	{
		reenter2:		//incase user enters a wrong value
		cout<<"Which service would you like to choose\nUrgent Press 1\n Regular press 2\nEnter your choice : ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			this->services = "urgent";
			break;

		case 2:
			this->services = "regular";
			break;

		default:
			cout<<"\nWrong choice selected Re-enter\n";
			goto reenter2;
			break;
		}
	}

	continue1:
	//as the parent class members are losing there values in child class i will create a temp txt to store data
	ofstream d;
		d.open("Temp.txt",ios::trunc);
		if(!d)//if file not created
			cout<<"File not opened";
		else
		{
			d << this->citytocity << " " << this->services << " " <<this->cityreciever;
		d.close();
		}

}


