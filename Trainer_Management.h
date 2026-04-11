#pragma once
#include"person.h"
#include "member.h"
#include<string>

struct activity {
	//7t 2l attendance hena ya shafik
	int hours_worked;
	int session_duration;
};
class Trainer_Management :public person
{
private:
	string specailty;
	double salary;
	float comisson;
	member assignedmemberlist[10];
	activity trainer_activity;
public:
	Trainer_Management(string n, int idd, int ag, int con, string spec, double sal, float com, activity ta, member list[10]) :person(n, ag, idd, con) {};
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



};
