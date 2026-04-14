#include <iostream>
#include <ctime>
#include "member.h"
#include "person.h"
#include <fstream>
using namespace std;

member::member() : person() {
}
void member::chooseplan() {
	int choice;
	cout << "enter your plan name : ";
	cout << "Choose a membership plan from the following options: " << endl;
	cout << "1. Monthly Plan : price $50" << endl;
	cout << "2. 3 Months Plan : price $140" << endl;
	cout << "3. 6 Months Plan : price $270" << endl;
	cout << "4. 12 Months Plan : price $500" << endl;
	cin >> choice;
	time_t now = time(0);
	tm current_time;
	localtime_s(&current_time, &now);

	switch (choice)
	{
		
			case 1:
				membership_plan = "Monthly Plan";
				current_time.tm_mon += 1;
				break;
			case 2:
				membership_plan = "3 Months Plan";
				current_time.tm_mon += 3;

				break;
			case 3:
				membership_plan = "6 Months Plan";
				current_time.tm_mon += 6;
				break;
			case 4:
				membership_plan = "12 Months Plan";
				current_time.tm_year += 1;
				break;

		default:
			cout << "Invalid choice" << endl;
			break;
	}
	
	expiration_date = mktime(&current_time);
}
void member::activesubscription() {
	time_t now = time(0);
	registration_date = now;
	if (registration_date <= expiration_date) {
		active_subscription = "Active";
	}
	else {
		active_subscription = "Inactive";
	}
}
void member::assignedtrainer() {
	int choice;
	cout << "Choose a trainer from the following options: " << endl;
	cout << "1. Trainer A" << endl;
	cout << "2. Trainer B" << endl;
	cout << "3. Trainer C" << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:
		assigned_trainer = "Trainer A";
		break;
	case 2:
		assigned_trainer = "Trainer B";
		break;
	case 3:
		assigned_trainer = "Trainer C";
		break;
	default:
		cout << "Invalid choice" << endl;
		break;
	}
}
void member::Membershipstatus() {
	cout << "Membership Plan: " << membership_plan << endl;
	cout << "Active Subscription: " << active_subscription << endl;
}
void member::printmemberinfo() {
	assignedtrainer();
	printer();
	cout << "Assigned Trainer: " << assigned_trainer << endl;
	Membershipstatus();
}
void member::createnewclient() {
	person::createnewclient();
	chooseplan();
	assignedtrainer();
	activesubscription();
}
void member::save_file() {
	ofstream mfile("member_info.txt");
	if (mfile.is_open()) {
		mfile << name << " " << id << " " << contactinfo << " " << age << " " << membership_plan << " " << assigned_trainer << " " << active_subscription << " " << gender << " " << payment_status << " " << attendance_record << " " << registration_date << " " << expiration_date;
		mfile.close();
	}
}
	void member::load_file() {
		ifstream mfile("member_info.txt");
		if (mfile.is_open()) {
			mfile >> name >> id >> contactinfo >> age >> membership_plan >> assigned_trainer >> active_subscription >> gender >> payment_status >> attendance_record >> registration_date >> expiration_date;
		}
	}