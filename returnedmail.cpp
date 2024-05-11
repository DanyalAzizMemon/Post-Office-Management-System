//Danyal Memon
//20i-1811 BSCS F
//Project
#include <iostream>
#include <fstream>
using namespace std;

//-------------------------------------------------------------------------------------------------------------------------

class ReturnedMail	:public Mail
{
	void display();
};

void ReturnedMail::display()
{
	string details;
	ifstream file;
		file.open("returnedmails.txt",ios::in);

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


