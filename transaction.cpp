//Danyal Memon
//20i-1811 BSCS F
//Project

#include <iostream>
#include <fstream>

using namespace std;


class Transaction
{
public:
	void display();
};

void Transaction::display()
{
	int option;
	string details;
	cout << "\nTransaction details\n";

	ifstream file;
	file.open("Order.txt",ios::in);

	if(!file)//if file not created
		cout<<"File not created";

	else
	{
		while(!file.eof())
		{
			getline(file,details,'\n');
			cout << details << endl;
		}
	}
	file.close();


	cout << "\n\nDo you want to look for a specific transaction of post office\nPress 1 for yes\nPress 2 for no : ";
	cin >> option;

	if(option==1)
	{
		cout << "Enter City : ";
		cin >> details;

		ifstream file;
		file.open(details,ios::in);

		if(!file)//if file not created
			cout<<"File not created";

		else
		{
			while(!file.eof())
			{
				getline(file,details,'\n');
				cout << details << endl;
			}
		}
		file.close();
	}

}

