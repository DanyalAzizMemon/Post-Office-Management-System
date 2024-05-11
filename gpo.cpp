//Danyal Memon
//20i-1811 BSCS F
//Project

#include <iostream>
#include <fstream>
using namespace std;


//---------------------------------------------------------------------------------------------------
class GPO
{
public:
	void login();
	void addAdmin();		//includes admin,postman,clerk,account-officer
	void searchAdmin();
	void deleteAdmin();
	void addGPO();
	void addPostOffice();
};

void GPO::login()
{
string username,password,file1,file2;

//as GPO has all the control so we cannot sign up a new GPO head

	ofstream f;
	f.open("GPO.txt",ios::trunc);

	if(!f)//if file not created
			cout<<"File not created";

		else
		{
			f << "GPO" << " " <<"123" <<endl;	//a password and username is assigned to GPO
		}
		f.close();

//Password and username are

	ifstream i;
	i.open("GPO.txt",ios::in);
	if(!i)//if file not created
			cout<<"File not opened";
		else
		{
			i >> file1 >> file2;
		}
		i.close();

		GPOagain:

		cout << "\nEnter username : ";
		cin >> username;

		cout << "Enter Password : ";
		cin >> password;

		if(username != file1 || password !=file2)
		{
			cout <<"Password incorrect\n Reenter : ";
			goto GPOagain;
		}

		cout << "Login Successful ";

}
void GPO::addAdmin()
{
	string name,id,city,user,pass;
	cout<<"\nEnter records for admin";
	cout << "\nEnter Name : ";
	cin >> name;

	cout << " Enter ID : ";
	cin >> id;

	cout << " Enter city : ";
	cin >> city;

	cout << " Enter Username : ";
	cin >> user;

	cout << " Enter Password : ";
	cin >> pass;


		ofstream file;
		file.open("PostalWorker.txt",ios::app);

		if(!file)//if file not created
				cout<<"File not created";

			else
			{
				file << "admin" << " "<< name << " "<< id <<endl;
			}
			file.close();


	//for login and password info of admin

			ofstream f;
			f.open("Adminlogin.txt",ios::app);

			if(!f)//if file not created
					cout<<"File not created";

				else
				{
					f<< user << " "<< pass << endl;
				}
				f.close();
}

void GPO::searchAdmin()
{
	bool found = 0;

	string search,word;
	cout << "\nTo search enter one of the following\nID, Name\nEnter the desired entry : ";
	cin >> search;

	ifstream file;
	file.open("PostalWorker.txt",ios::app);

	if(!file)//if file not created
			cout<<"File not created";

		else
		{
			while(!file.eof())
			{
				file >> word;
				if(word == search)
				{
					found=1;
					break;
				}   //word found

			}
		}
		file.close();

if (found == 1)
	cout << "\n Admin with the given details exists : ";

if (found == 0)
	cout << "\n Admin with the given details does not exists : ";

}

void GPO::addPostOffice()
{
	string id,city;
	cout<<"Adding a Post office ";

	cout <<"\nEnter City of Postoffice : ";
	cin >>city;

	cout << "\nEnter unique id for postoffice : ";
	cin >> id;

	ofstream file;
	file.open("Postoffice.txt",ios::app);

	if(!file)//if file not created
			cout<<"File not created";

		else
		{
		file << id << " "<<city;
		}
		file.close();

}

void GPO::addGPO()
{
	string id,city;
	cout<<"Adding a GPO ";

	cout <<"\nEnter City of GPO : ";
	cin >>city;

	cout << "\nEnter unique id of GPO : ";
	cin >> id;

	ofstream file;
	file.open("GPOlocations.txt",ios::app);

	if(!file)//if file not created
			cout<<"File not created";

		else
		{
		file << id << " "<<city;
		}
		file.close();
}

