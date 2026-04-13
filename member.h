#pragma once
#include "person.h"
#include <iostream>
#include <ctime>
using namespace std;

class member : public person
{
private:
	time_t now = time(0);
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
<<<<<<< HEAD
=======
	void save_file();
	void load_file();




>>>>>>> 12f264f7b4bb0525f3c77e42427d95bd7418bdd9
};

