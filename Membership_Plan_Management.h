#pragma once
class Membership_Plan_Management
{
private:
	int id;
	string name;
public:
	Membership_Plan_Management(int i,string n);
	void setid();
	void setname();
	int getid();
	string getname();
	void displaymembershipPlan();

};
class plan {
private:
	int plan_id, duration, Access_level;
	float price;
	string Allowed_services, Discount_rules;
public:
	plan(int pi, int d, int al, float p, string a, string dr);
	void displayPlan();
};
