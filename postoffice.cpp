//Danyal Memon
//20i-1811 BSCS F
//Project

#include <iostream>
#include <fstream>
using namespace std;

class Postoffice
{
public :
	void display();
};

void Postoffice::display()
{
	string id,city;
	ifstream file;
	file.open("Postoffice.txt",ios::app);

	if(!file)//if file not created
			cout<<"File not created";

		else
		{
			while(!file.eof())
			{
				file >> id >> city;
				cout<< "ID : "<<id <<endl<< "City : "<<city<<endl;
			}
		}
		file.close();

}

