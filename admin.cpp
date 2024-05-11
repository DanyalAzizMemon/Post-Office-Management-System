//Danyal Memon
//20i-1811 BSCS F
//Project

#include <iostream>
#include <fstream>
using namespace std;


//-----------------------------------------------------------------------------------------------------------
class Admin
{
	string username;
	string password;

public:
	void login();
	void signup();
	void addpostalWorker();
	void searchpostalWorker();
};

void Admin::login()
{
cout<<"\n\n\nLogin Page\n";
	string u[20],p[20];			//username and password;
	string username,password;
	bool success=0;

	ifstream file;
	file.open("Adminlogin.txt",ios::in);

	for(int i=0;(!file.eof()); i++)
	{
		file >> u[i] >> p[i];
	}

	int arrsize = sizeof(u)/sizeof(u[0]);	//to check in for loop

	Adminreenter:

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
		goto Adminreenter;
	}

}


void Admin::signup()
{
	string name,id,city,user,pass;

	cout << " Enter your Name : ";
	cin >> name;

	cout << " Enter your ID : ";
	cin >> id;

	cout << " Enter your city : ";
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




	//will prompt login after signup
	login();
}

void Admin::addpostalWorker()
{
	string designation,name,id,city;

	cout << "\nDo you want to add Postman, clerk, account officer : ";
	cin >> designation;

	cout << "Enter name : ";
	cin >> name;

	cout << "Enter id : ";
	cin >> id;

	cout << "Enter city of worker : ";
	cin >> city;

	ofstream file;
	file.open("PostalWorker.txt",ios::app);

	if(!file)//if file not created
			cout<<"File not created";

		else
		{
			file << designation << " "<< name << " "<< id << " " << city << endl;
		}
		file.close();

}

void Admin::searchpostalWorker()
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
	cout << "\n Worker with the given details exists : ";

if (found == 0)
	cout << "\n Worker with the given details does not exists : ";
}

