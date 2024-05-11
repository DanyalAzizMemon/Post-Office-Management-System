//Danyal Memon
//20i-1811 BSCS F
//Project

#include <iostream>
#include <fstream>

using namespace std;



class Mail
{
public:
	void display();
};

void Mail::display()
{
	string details;
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
}

