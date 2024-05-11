//Danyal Memon
//20i-1811 BSCS F
//Project

#include <iostream>
#include <fstream>

//files created

#include "address.cpp"
#include "customer.cpp"
#include "invoice.cpp"
#include "mailservice.cpp"
#include "order.cpp"
#include "postalworker.cpp"
#include "postman.cpp"
#include "accountofficer.cpp"
#include "clerk.cpp"
#include "admin.cpp"
#include "gpo.cpp"
#include "postoffice.cpp"
#include "transaction.cpp"
#include "mail.cpp"
#include "bouncedmail.cpp"
#include "returnedmail.cpp"

using namespace std;
int main()
{

	int choice;		//will be used for almost all switch options
	Admin a1;
	Customer c1;
	MailService m1;
	Order o1;
	Invoice i1;
	GPO g1;
	Postoffice p1;
	PostalWorker pw1;
	clerk cl1;
	postman pm1;
	accountofficer ao1;
	Transaction t1;

	//for polymorphism
	PostalWorker* postw;
	Mail* mail;


	ReturnedMail returned;
	BouncedMail	 bounced;

	//for sign up and login of Admin and Users

	cout << "_______________________Welcome to Pakistan Post Office digital_______________________\n";
	cout << "\nPress 1 for Admin\nPress 2 for Customer\nPress 3 for GPO Head\nPress 4 to Recieve Mail\nEnter your desired option : ";
	cin>>choice;

	switch (choice)
	{
	case 1:
		cout<< "\nLogin, press 1\nSignup press 2\nEnter your desired option : ";
		cin >> choice;

		if( choice == 1)
		{
			a1.login();
		}

		if(choice == 2)
		{
			a1.signup();
		}

		cout << "\n\nAdd a new employee press 1\nSearch for an employee press 2\nDelete an employee record press 3\nViewing Existing Postoffices press 4\nView Clerks in records press 5\n View Postman in records press 6\nView AccountOfficers in record press 7\nEnter your desired option : ";
		cin >> choice;

		if( choice == 1)
		{
			a1.addpostalWorker();
		}

		if(choice == 2)
		{
			a1.searchpostalWorker();
		}

		if (choice == 4)
		{
			p1.display();
		}

		if( choice == 5)
		{
			postw = &cl1;
			postw->display();
		}

		if(choice == 6)
		{
			postw = &pm1;
			postw->display();
		}

		if (choice == 7)
		{
			postw = &ao1;
			postw->display();
		}

		break;

	case 2:
		cout<< "\nReturning Customer? press 1\nNew Customer? press 2\nEnter your desired option : ";
		cin >> choice;

		if	(choice == 1)
		{
			c1.login();
		}

		if	(choice == 2)
		{
			c1.signup();
		}

		cout<< "\n\nTo place an order press 1\nTo check shipment time press 2\nTo exit press 3\nEnter your desired option : ";
		cin >> choice;

		if	(choice == 1)
		{
			m1.setMail();
			o1.setOrder();
//			o1.displayOrder();
		}

		if	(choice == 2)
		{
			pm1.tracker();
		}
		break;

		if	(choice == 3)
		{
			return 0;
		}
		break;


	case 3:
		cout << "\nTo add GPO press 1\nTo add an admin press 2\n To add a post office press 3\nTo search for an admin press 4\nTo enter a postal worker press 5\nTo view transactions press 6\nTo view bounced mails press 7\nTo view returned mails press 8\nEnter your desired choice : ";
		cin >> choice;

		if	(choice == 1)
		{
			g1.login();
			g1.addGPO();
		}

		if	(choice == 2)
		{
			g1.login();
			g1.addAdmin();
		}

		if	(choice == 3)
		{
			g1.login();
			g1.addPostOffice();
		}

		if	(choice == 4)
		{
			g1.login();
			g1.searchAdmin();
		}

		if	(choice == 5)
		{
			g1.login();
			pw1.setPostalWorker();
		}

		if	(choice == 6)
		{
			g1.login();
			t1.display();
		}

		if	(choice == 7)
		{
			g1.login();
			mail =&bounced;
			mail->display();		//polymorphinsm
		}

		if	(choice == 8)
		{
			mail = &returned;
			mail->display();		//polymorphinsm
		}


		break;


	case 4:
		pm1.signature();
		break;


	default:
		cout << "\nInvalid option selected sequel terminated ";
		return 0;
		break;
	}
    return 0;
}

