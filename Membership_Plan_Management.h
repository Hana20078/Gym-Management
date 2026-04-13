#pragma once
#include<iostream>
#include <string>


class Membership_Plan_Management
{
private:
	int id;
	string name;
public:
	Membership_Plan_Management(int i, string n);
    void setid();
	void setname();
	int getid();
	string getname();
	void displaymembershipPlan();

};
enum Access_level{Basic, Premium, VIP};
class plan {
private:
	int plan_id, duration;
	float price;
	string Allowed_services, Discount_rules;
public:
	plan(int pi, int d, float p, string a, string dr, Access_level al);
	void setplan_id();
	void setduration();
	void setprice();
	void setAllowed_services();
	void setDiscount_rules();
	int getplan_id();
	int getduration();
	float getprice();
	string getAllowed_services();
	string getDiscount_rules();
	Access_level Access_level;
	void displayPlan();
};
