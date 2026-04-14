#pragma once
#include "person.h"
#include <iostream>
#include <ctime>
#include <string> 
#include <fstream>
#include "Billing_System.h"
using namespace std;

class Attendance_Tracking;

class member : public person, public Billing_System
{
private:
	string membership_plan;
	time_t registration_date;
	time_t expiration_date;
	string assigned_trainer;
	string attendance_record;
	string payment_status;
	string active_subscription;

public:
	member();
	void chooseplan();
	void activesubscription();
	void assignedtrainer();
	void Membershipstatus();
	void printmemberinfo();
	void createnewclient();
    void save_file();
	void load_file(member members[], int &memberCount);
	string getstatus();
	int activecount(member arr[], int size);
	string getName();
	int getid();
};