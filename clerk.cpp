//Danyal Memon
//20i-1811 BSCS F
//Project

#include <iostream>
#include <fstream>
using namespace std;

//-----------------------------------------------------------------------------------------------------------

class clerk : public PostalWorker
{
public:
	void setclerk();
	virtual void display();
};

void clerk::display()
{
	string details;
		cout << "\nClerk details\n";

		ifstream file;
			file.open("clerk",ios::in);

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

