#pragma once
#include<string>
#include"member.h"
using namespace std;
int Billing_System::payment_id=0;
class Billing_System: public member
{
private:
	static int payment_id;
	int date;
	bool payment_State;
	double amount;
	int payment_methods;

public:
	void addpayment();
};
