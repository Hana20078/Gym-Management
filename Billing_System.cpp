#include "Billing_System.h"
#include<iostream>
#include <fstream>
#include <ctime>
using namespace std;
int Billing_System::counter = 1000;
Billing_System::Billing_System() {
	payment_id = counter++;
	member_id = 0;
	amount = 0.0;
	date = "";
	payment_status = "";
	payment_method = "";
}
void Billing_System::addpayment() {
	cout << "Enter member ID: ";
	cin >> member_id;

	cout << "Enter amount: ";
	cin >> amount;
	if (amount <= 0) {
		cout << "Invalid amount. Payment not added.\n";
		return;
	}

	cout << "Enter payment method (Cash / Card / VodafoneCash) : ";
	cin >> payment_method;

	cout << "Enter payment status (Paid / Unpaid / Pending): ";
	cin >> payment_status;

	time_t now = time(0);
	char buffer[26];
	ctime_s(buffer, sizeof(buffer), &now);
	date = buffer;
}
void Billing_System::receipt() {
	cout << "\n========== RECEIPT ==========\n";
	cout << "Payment ID     : " << payment_id << endl;
	cout << "Member ID      : " << member_id << endl;
	cout << "Amount         : " << amount << endl;
	cout << "Date           : " << date;
	cout << "Payment Method : " << payment_method << endl;
	cout << "Payment Status : " << payment_status << endl;
	cout << "=============================\n";
}
void Billing_System::displayPaymentInfo() {
	cout << "Payment ID     : " << payment_id << endl;
	cout << "Member ID      : " << member_id << endl;
	cout << "Amount         : " << amount << endl;
	cout << "Date           : " << date;
	cout << "Payment Method : " << payment_method << endl;
	cout << "Payment Status : " << payment_status << endl;
	cout << "-----------------------------\n";
}
void Billing_System::viewUnpaidBalances(vector<Billing_System>& payments) {
	cout << "\n========== UNPAID BALANCES ==========\n";
	bool found = false;

	for (int i = 0; i < payments.size(); i++) {
		if (payments[i].payment_status == "Unpaid" || payments[i].payment_status == "Pending") {
			payments[i].displayPaymentInfo();
			found = true;
		}
	}
}
int Billing_System::getpayment_id()
{
	return payment_id;
}
int Billing_System::getmember_id()
{
	return member_id;
}
float Billing_System::getamount()
{
	return amount;
}
string Billing_System::getdate()
{
	return date;
}
string Billing_System::getpayment_method()
{
	return payment_method;
}
string Billing_System::getpayment_status()
{
	return payment_status;
}
void Billing_System::save_file()
{
	ofstream file("billing.txt", ios::app);

	if (!file.is_open()) {
		cout << "Could not open billing file.\n";
		return;
	}

	file << payment_id << "|"
		<< member_id << "|"
		<< amount << "|"
		<< date << "|"
		<< payment_method << "|"
		<< payment_status << "\n";

	file.close();
}
void Billing_System::load_file(vector<Billing_System>& payments)
{
	ifstream file("billing.txt");

	if (!file.is_open()) {
		cout << "Could not open billing file.\n";
		return;
	}

	payments.clear();

	while (true) {
		Billing_System temp;
		string s1, s2, s3, s4, s5, s6;

		if (!getline(file, s1, '|'))
			break;

		getline(file, s2, '|');
		getline(file, s3, '|');
		getline(file, s4, '|');
		getline(file, s5, '|');
		getline(file, s6);

		temp.payment_id = stoi(s1);
		temp.member_id = stoi(s2);
		temp.amount = stof(s3);
		temp.date = s4;
		temp.payment_method = s5;
		temp.payment_status = s6;

		payments.push_back(temp);
	}

	file.close();
}