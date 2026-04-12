#pragma once
#include "person.h"
#include "member.h"
#include <string>

struct activity {
	// attendance data
	int hours_worked;
	int session_duration;
};

using namespace std;

class Trainer_Management : public person
{
private:
	string specailty;
	double salary;
	float comisson;
	string assignedmemberlist[10];
	activity trainer_activity;
public:
	Trainer_Management(string n, int idd, int ag, int con, string spec, double sal, float com, activity ta, member list[10], string g);
	Trainer_Management();
	void printer();
	void setspeciality();
	void setsalary();
	void setassignedmemberlist();
	void setcomisson();
	void setactivity();
	double getsalary();
	float getcomisson();
	member getassignedmemberlist();
	activity getactivity();
	void save_file();\
	void load_file(string filename);
};
