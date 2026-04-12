#include "Membership_Plan_Management.h"
#include <iostream>

using namespace std;

Membership_Plan_Management::Membership_Plan_Management(int i, string n) {
	id = i;
	name = n;
}
void Membership_Plan_Management::displaymembershipPlan() {
	cout << "ID:" << id << endl;
	cout << "Name:" << name << endl;
	cout << "======================================================";
}
plan::plan(int pi, int d, int al, float p, string a, string dr) {
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
