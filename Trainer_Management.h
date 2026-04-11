#pragma once
#include"person.h"
#include "member.h"
struct activity {
	//7t 2l attendance hena ya shafik
	int hours_worked;
	int session_duration;
};
class Trainer_Management:public person
{ private  :
	string specailty;
	double salary;
	float comisson;
	member assignedmemberlist[10];
	activity trainer_activity;
public:
Trainer_Management(string n,int idd,int ag,int cont,string spec,double sal,float com,activity ta,member list[])
};


