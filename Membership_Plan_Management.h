#pragma once
#include <string>

using namespace std;

class Membership_Plan_Management
{
private:
	int id;
	std::string name;
public:
	Membership_Plan_Management(int i, std::string n);
    void setid();
	void setname();
	int getid();
	std::string getname();
	void displaymembershipPlan();

};

class plan {
private:
	int plan_id, duration, Access_level;
	float price;
	std::string Allowed_services, Discount_rules;
public:
	plan(int pi, int d, int al, float p, std::string a, std::string dr);
	void displayPlan();
};
