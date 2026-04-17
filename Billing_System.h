#pragma once
#include <string>

using namespace std;

class Billing_System
{
private:
	static int payment_id;
	int date;
	bool payment_State;
	double amount;
	string payment_methods;

public:
	Billing_System();
	void receipt();
	void addpayment();
	void setamount();
	void setpayment_methods();
	void setdate();
	int getpayment_id();
	int getdate();
	string getpayment_methods();
	bool getpayment_State();
	double getamount();	
};
