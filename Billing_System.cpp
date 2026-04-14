#include "Billing_System.h"
#include<iostream>
using namespace std;

void Billing_System::addpayment()
{
	cout << "enter payment method" << endl;
	cin >> payment_methods;
	cout << "please enter the paymrnt amount" << endl;
	cin >> amount;
	cout << "enter payment date" << endl;
	cin >> date;
	payment_State = true;
	payment_id++;
}

