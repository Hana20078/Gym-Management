#include "Membership_Plan_Management.h"
#include <iostream>

using namespace std;

Membership_Plan_Management::Membership_Plan_Management(int i, string n) {
	id = i;
	name = n;
}
void Membership_Plan_Management::setid()
{
	cout << "write membership plan's id  " << id;
	cin >> id;
}
void Membership_Plan_Management::setname()
{
	cout << "write membership plan's name " << name;
	cin >> name;
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
plan::plan(int pi, int d, float p, string a, string dr, Access_level al) {
	plan_id = pi;
	duration = d;
	Access_level = al;
	price = p;
	Allowed_services = a;
	Discount_rules = dr;
}
void plan::displayPlan() {
	cout << "Plan ID:" << plan_id << endl;
	cout << "Duration:" << duration << endl;
	cout << "Access level:" << Access_level << endl;
	cout << "Price:" << price << endl;
	cout << "Allowed services:" << Allowed_services << endl;
	cout << "Discount rules:" << Discount_rules << endl;
	cout << "======================================================";
}
