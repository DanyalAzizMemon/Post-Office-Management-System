//Danyal Memon
//20i-1811 BSCS F
//Project

#include <iostream>
#include <fstream>



using namespace std;


class PostalWorker
{
protected:
	string name;
	string designation;
	string id;
	string city;

public:
	void setPostalWorker();
	virtual void display();	//for polymorphism
};


void PostalWorker::setPostalWorker()
{
	cout<<"Enter first name : ";
	cin>>this->name;

	cout<<"Enter ID : ";
	cin>>this->id;

	cout<<"Enter designation name : ";
	cin>>this->designation;

	cout<<"Enter City : ";
	cin>>this->city;

	ofstream C;
	C.open("PostalWorker.txt",ios::app);	//append mode

	if(!C)//if file not created
		cout<<"File not created";

	else
	{
		C << this->designation << " ";
		C << this->name<< " ";
		C << this->id<< " ";
		C << this->city<<endl;
	}
	C.close();


	ofstream file;
	file.open(this->designation,ios::app);
	if(!file)//if file not created
		cout<<"File not created";

	else
	{
		file << this->designation << " ";
		file << this->name<< " ";
		file << this->id<< " ";
		file << this->city<<endl;
	}
	file.close();

}

void PostalWorker::display()
{
	cout << "\nPostal Worker details\n";
	cout << "\nName : " << this->name;
	cout << "\nID : "<<this->id;
	cout << "\nDesignation : " << this->designation;
	cout << "\nCity : "<<this->city;
}

