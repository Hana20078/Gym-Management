#pragma once
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Billing_System
{
private:
	static int counter;
	int payment_id;
	int member_id;
	float amount;
	string payment_method;
	string payment_status;
	string date;
public:
    Billing_System();

    void addpayment();
    void receipt();
    void displayPaymentInfo();

    void save_file();
    void load_file(vector<Billing_System>& payments);

    int searchPayment(vector<Billing_System>& payments, int memberId);
    void viewUnpaidBalances(vector<Billing_System>& payments);

    int getpayment_id();
    int getmember_id();
    float getamount();
    string getdate();
    string getpayment_method();
    string getpayment_status();
};
