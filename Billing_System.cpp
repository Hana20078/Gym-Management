#include "Billing_System.h"
#include<iostream>
using namespace std;
int Billing_System::payment_id = 0;

void Billing_System::receipt()
{
}

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

void Billing_System::setamount()
{
}

void Billing_System::setpayment_methods()
{
}

void Billing_System::setdate()
{
}

int Billing_System::getpayment_id()
{
	return 0;
}

int Billing_System::getdate()
{
	return 0;
}

string Billing_System::getpayment_methods()
{
	return string();
}

bool Billing_System::getpayment_State()
{
	return false;
}

double Billing_System::getamount()
{
	return 0.0;
}

