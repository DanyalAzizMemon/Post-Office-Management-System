//Danyal Memon
//20i-1811 BSCS F
//Project

#include <iostream>
#include <fstream>


using namespace std;

class accountofficer : public PostalWorker
{
public:
	virtual void display();
};


void accountofficer::display()
{
	string details;
		cout << "\nAccount Officer details\n";

		ifstream file;
			file.open("Accountofficer",ios::in);

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

