//Danyal Memon
//20i-1811 BSCS F
//Project

#include <iostream>
#include <fstream>
using namespace std;

//-----------------------------------------------------------------------------------------------------------
class postman : public PostalWorker
{
public:
	void tracker();
	virtual void display();
	void signature();	//to check if the mail has recieved
};

void postman::tracker()
{
	string location;
	string id;

	cout << "Enter id of the mail :  ";
	cin >> id;

	cout << "Postman current location : ";
	cin >>location;
}

void postman::signature()
{
	string name,filename;
	bool correct;
	bool address;

	ifstream file;
	file.open("Customer.txt",ios::in);

	if(!file)//if file not created
		cout<<"File not created";

	else
	{
		file >> filename;
	}
	file.close();

	cout << "Enter name of the of sender ";
	cin >> name;

	if (name == filename)
	{
		correct =1;
	}

	else
	{
		cout<< "\nRe-enter name of signature ";
		cin >>name;
		if (name == filename)
		{
			correct =1;
		}
	}

	if(correct == 0)
	{
		ifstream file;
		file.open("Customer.txt",ios::in);

		if(!file)//if file not created
			cout<<"File not created";

		else
		{
			getline(file,filename,'\n');
		}
		file.close();

		ofstream f;
		f.open("returnedmails.txt",ios::app);

		if(!f)//if file not created
			cout<<"File not created";

		else
		{
			f << filename << endl;
		}
		f.close();
	}

	//incase the address is not correct the mail would go to bounced mails

	cout << "\n\nIs the address correct 1 or 0 :";
	cin >>address;
	if (address == 0)
	{
		ofstream f;
		f.open("bouncedmails.txt",ios::app);

		if(!f)//if file not created
			cout<<"File not created";

		else
		{
			f << filename << endl;
		}
		f.close();

	}


}


void postman::display()
{
	string details;
	cout << "\nPostman details\n";

	ifstream file;
		file.open("postman",ios::in);

		if(!file)//if file not created
				cout<<"File not created";

			else
			{
				while(!file.eof())
				{
					getline(file,details,'\n');
					cout << details << endl;
				}   //word found
			}
			file.close();
}



