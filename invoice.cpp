//Danyal Memon
//20i-1811 BSCS F
//Project

#include <iostream>
#include <fstream>

//files created

//#include "address.cpp"
//#include "customer.cpp"


using namespace std;


//-------------------------------------------------------------------------------------------------------------------------
//this class generates an invoice id for each order sent
class Invoice
{
protected:
	static int invoice_id;

public:
	Invoice();
	void display();
	friend class Order;
};

//default constructor which would increment invoice id
int Invoice::invoice_id = 0;
Invoice::Invoice()	{	invoice_id++;	}
void Invoice::display()	{	cout << "\nInvoice ID : "<<invoice_id;	}

