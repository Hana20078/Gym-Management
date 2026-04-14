#pragma once
#include<string>
using namespace std;
#include"member.h"
int Billing_System::payment_id=0;
class Billing_System: public member
{
private:
	static int payment_id;
	int date;
	string payment_method;
	bool payment_State;
	double amount;

public:

	
};
void addpayment();
