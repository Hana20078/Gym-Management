#include "Membership_Plan_Management.h"
#include <iostream>
#include<ctime>
#include"Billing_System.h"
#include <fstream>
#include <vector>

int Membership_Plan_Management::counter = 1000;

using namespace std;
Membership_Plan_Management::Membership_Plan_Management(string n) {
	id = counter++;
	name = n;
}

void Membership_Plan_Management::setid()
{
	cout << "write membership plan's id  " << id;
	cin >> id;
}

int Membership_Plan_Management::getid()
{
	cout << "membership plan's id is " << id;
	return id;
}

string Membership_Plan_Management::getname()
{
	cout << "membership plan's name is " << name;
	return name;
}

void Membership_Plan_Management::displaymembershipPlan() {
	cout << "ID:" << id << endl;
	cout << "Name:" << name << endl;
	cout << "======================================================";
}

void Membership_Plan_Management::membershipplansystem() {
	string n;
	cout << "Enter membership plan name: ";
	cin >> n;
	setname(n);
	displaymembershipPlan();
	cout << endl;
	plan p(0, 0, 0, "", "", Access_level::Basic);
	p.setplan_id();
	p.setduration();
	p.setprice();
	p.setAllowed_services();
	p.setDiscount_rules();
	p.setstart_date();
	p.setexpiration_date();
	p.displayPlan();
	p.printstartandenddate();
	billing_system.addpayment();
	billing_system.receipt();
	p.psave_file();
}

void Membership_Plan_Management::setbilling_system(Billing_System b)
{
	billing_system = b;
}

plan::plan()
{
	plan_id = 0;
	duration = 0;
	price = 0;
	Allowed_services = "";
	Discount_rules = "";
	access_level = Basic;
	start_date = time(0);
	expiration_date = time(0);
}

plan::plan(int pi, int d, float p, string a, string dr, Access_level al) {
	plan_id = pi; 
	duration = d;
	start_date = time(0);
	expiration_date = start_date + (duration * 24 * 60 * 60);
	Allowed_services = a;
	Discount_rules = dr;
	access_level = al;
	start_date = time(0);
}

void plan::displayPlan() {
	cout << "Plan ID:" << plan_id << endl;
	cout << "Duration:" << duration << endl;
	cout << "Access level:" << access_level << endl;
	cout << "Price:" << price << endl;
	cout << "Allowed services:" << Allowed_services << endl;
	cout << "Discount rules:" << Discount_rules << endl;
	cout << "======================================================";
}

void Membership_Plan_Management::createMembershipPlan(vector<Membership_Plan_Management>& plans) {
	Membership_Plan_Management newPlan("");
	newPlan.createnewclient();
	plans.push_back(newPlan);
}

void Membership_Plan_Management::createnewclient()
{
	cout << "Enter plan data..." << endl;
}
void plan::setplan_id()
{
	cout << "write plan id ";
	cin >> plan_id;
}	

void plan::setduration()
{
	cout << "write plan duration in days " ;
	cin >> duration;
}

void plan::setprice()
{
	cout << "write plan price " ;
	cin >> price;
}

float plan::getprice()
{
	return price;
}

string plan::getAllowed_services()
{
	return Allowed_services;
}

string plan::getDiscount_rules()
{
	return Discount_rules;
}

void plan::setAllowed_services() {
	cout << "write allowed services for this plan " ;
	cin >> Allowed_services;
}

void plan::setDiscount_rules() {
	cout << "write discount rules for this plan " ;
	cin >> Discount_rules;
}

int plan::getplan_id()
{
	return plan_id;
}

int plan::getduration()
{
	return duration;
}

void plan::setexpiration_date()
{
	start_date = time(0);
	expiration_date = start_date + (duration * 24 * 60 * 60);
}

void plan::setstart_date()
{
	start_date = time(0);
}

time_t plan::getstart_date()
{
	return start_date;
}
time_t plan::getexpiration_date()
{
	return expiration_date;
}
void Membership_Plan_Management::setname(string n)
{
	name = n;
}
void Membership_Plan_Management::updateMembershipPlan(vector<Membership_Plan_Management>& plans)
{
	int id;
	cout << "Enter plan ID to update: ";
	cin >> id;

	for (auto& p : plans) {
		if (p.getid() == id) {
			string newName;
			cout << "Enter new name: ";
			cin >> newName;
			p.setname(newName);
			cout << "Updated successfully!\n";
			return;
		}
	}
	
	cout << "Plan not found.\n";
}
void Membership_Plan_Management::deleteMembershipPlan(vector<Membership_Plan_Management>& plans)
{
	int id;
	cout << "Enter plan ID to delete: ";
	cin >> id;

	for (int i = 0; i < plans.size(); i++) {
		if (plans[i].getid() == id) {
			plans.erase(plans.begin() + i);
			cout << "Deleted successfully!\n";
			return;
		}
	}
	cout << "Plan not found.\n";
}
void plan::printstartandenddate()
{
	char startBuffer[26];
	char endBuffer[26];

	ctime_s(startBuffer, sizeof(startBuffer), &start_date);
	ctime_s(endBuffer, sizeof(endBuffer), &expiration_date);

	cout << "Start Date: " << startBuffer;
	cout << "Expiration Date: " << endBuffer;
}
void Membership_Plan_Management::save_file()
{
	ofstream mfile("membershipplans.txt", ios::app);

	if (mfile.is_open()) {
		mfile << id << "|" << name << "\n";
		mfile.close();
	}
	else {
		cout << "Could not open membership plan file.\n";
	}
}

void Membership_Plan_Management::load_file(vector<Membership_Plan_Management>& plans)
{
	ifstream mfile("membershipplans.txt");

	if (!mfile.is_open()) {
		cout << "Could not open membership plan file.\n";
		return;
	}

	plans.clear();

	while (true) {
		string tempId;
		Membership_Plan_Management temp("");

		if (!getline(mfile, tempId, '|'))
			break;

		getline(mfile, temp.name);

		temp.id = stoi(tempId);

		plans.push_back(temp);
	}

	mfile.close();
}
void plan::psave_file()
{
	ofstream pfile("plans.txt", ios::app);

	if (pfile.is_open()) {
		pfile << plan_id << "|"
			<< duration << "|"
			<< price << "|"
			<< Allowed_services << "|"
			<< Discount_rules << "|"
			<< start_date << "|"
			<< expiration_date << "|"
			<< access_level << "\n";

		pfile.close();
	}
	else {
		cout << "Could not open plan file.\n";
	}
}

void plan::pload_file(vector<plan>& plans)
{
	ifstream pfile("plans.txt");

	if (!pfile.is_open()) {
		cout << "Could not open plan file.\n";
		return;
	}

	plans.clear();

	while (true) {
		string temp1, temp2, temp3, temp4, temp5, temp6, temp7, temp8;

		if (!getline(pfile, temp1, '|'))
			break;

		getline(pfile, temp2, '|');
		getline(pfile, temp3, '|');
		getline(pfile, temp4, '|');
		getline(pfile, temp5, '|');
		getline(pfile, temp6, '|');
		getline(pfile, temp7, '|');
		getline(pfile, temp8);

		plan temp(0, 0, 0, "", "", Basic);

		temp.plan_id = stoi(temp1);
		temp.duration = stoi(temp2);
		temp.price = stof(temp3);
		temp.Allowed_services = temp4;
		temp.Discount_rules = temp5;
		temp.start_date = stoll(temp6);
		temp.expiration_date = stoll(temp7);
		temp.access_level = (Access_level)stoi(temp8);

		plans.push_back(temp);
	}

	pfile.close();
}
