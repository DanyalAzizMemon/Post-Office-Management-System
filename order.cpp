//Danyal Memon
//20i-1811 BSCS F
//Project
#include <iostream>
#include <fstream>

using namespace std;


//-------------------------------------------------------------------------------------------------------------------------
//inheriting class mailservice and composition with class customer and order
class Order:public MailService
{
Customer customer;
Invoice invoice;
MailService mail;
//members related to parcel
float weight;			//in grams
string dimension;		//123x456x789
int charges = 0;
int servicecharge = 0;
int weightcharges;		//charges due to weight


public:
void setOrder();
void displayOrder();
};

void Order::setOrder()
{
		ifstream c;
		c.open("Temp.txt",ios::in);
		if(!c)//if file not created
			cout<<"File not opened";
		else
		{
			c >> this->citytocity >>  this->services >> this->cityreciever;
		c.close();
		}


	cout << "\nEnter the weight of the Parcel in grams : ";
	cin >> this->weight;
	cout << "Enter Dimension of the parcel in the format 123x456x789 : ";
	cin >> this->dimension;

	//rates of service based on local delivery (in city)
	if ((this->weight < 250) && (citytocity==0))
		this->servicecharge = 51;

	if ((this->weight < 500 && this->weight > 250) && (citytocity == 0))
		this->servicecharge = 64;

	if ((this->weight > 500) && (citytocity==0))
	{
		int temp = this->weight - 500;
		int quotient;
		int charge =64;
		this->servicecharge = 0;

		 quotient = temp / 500;
		 if (quotient != 0)
		 {
			 this->servicecharge = charge + quotient * 26;	//rate for every additional 500 grams is multiplied
		 }
	}

	//city to city charges with varying weights

	if ((this->weight < 250) && (citytocity==1))
		this->servicecharge = 86;

	if ((this->weight < 500 && this->weight > 250) && (citytocity == 1))
		this->servicecharge = 132;

	if ((this->weight > 500) && (citytocity==1))
	{
		int temp = this->weight - 500;
		int quotient;
		int charge = 132;
		this->servicecharge = 0;

		 quotient = temp / 500;
		 if (quotient != 0)
		 {
			 this->servicecharge =charge + quotient * 43;	//rate for every additional 500 grams is multiplied
		 }
	}

//rates coupled due to weight only

	if (this->weight < 1000)
		this->weightcharges = 100;

	if (this->weight < 3000)
		this->weightcharges = 175;

	if (this->weight < 5000)
		this->weightcharges = 250;

	if (this->weight < 10000)
		this->weightcharges = 375;

	if (this->weight < 15000)
		this->weightcharges = 500;

	if (this->weight < 20000)
		this->weightcharges = 625;

	if (this->weight < 25000)
		this->weightcharges = 750;

	if (this->weight < 30000)
		this->weightcharges = 875;

	this->servicecharge += this-> weight +  75;	//75 is registration fee


	ofstream C;
	C.open("Order.txt",ios::app);	//append mode

	if(!C)//if file not created
		cout<<"File not created";

	else
	{
		C << invoice.invoice_id << " ";
		C << MailService::cityreciever<< " ";
		C << this->servicecharge<< " ";
		C << MailService::services <<endl;
	}
	C.close();

//sorting of mails with respect to cities.
	//new txt file is created for each new order
		ofstream i;
		i.open(MailService::cityreciever,ios::app);

		if(!i)//if file not created
			cout<<"File not created";

		else
		{
			i << invoice.invoice_id << " ";
			i << MailService::cityreciever<< " ";
			i << this->servicecharge<< " ";
			i << MailService::services <<endl;
		}
		i.close();


	displayOrder();
}

void Order::displayOrder()
{
int charges;

	cout << "\nOrder Details";
	cout << "\nService type : "<< MailService::services;
	cout << "\nWeight of parcel : "<<this->weight;
	cout << "\nDimension of parcel : "<<this->dimension;
	cout << "\nCost of parcel delivery : "<<this->servicecharge;

	while(charges != this->servicecharge)
	{
		cout<< "\n\n\n Enter amount for payment : ";
		cin >> charges;
	}

	cout << "\n\n\nPayment Successful\n\n";
}

