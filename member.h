#pragma once
#include "person.h"
#include <iostream>
#include <ctime>
#include <string> // fixed

using namespace std;

class member : public person
{
private:
	string membership_plan; // fixed
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
	void load_file();
	string getstatus();
	int activecount(member arr[], int size); // fixed
};