#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <ctime>
#include "member.h"
#include "person.h"
#include "Attendance_Tracking.h"
#include <fstream>
#include <string>   
#include <vector>
using namespace std;

member::member() : person(), Billing_System() {
	registration_date = 0;
	expiration_date = 0;

	active_subscription = "Inactive";
	payment_status = "Unpaid";
	attendance_record = "0";
}
string member::getstatus() {
    // Determine active subscription based on expiration_date
	Attendance_Tracking at;
	if (at.getStatus() == true) {
		active_subscription = "Active";
	}
	else {
		active_subscription = "Inactive";
	}
	return active_subscription;
}

int member::activecount(member arr[], int size) {
	int count = 0;
	for (int i = 0; i < size; i++) {
		if (arr[i].active_subscription == "Active") {
			count++;
		}
	}
	return count; 
}

void member::chooseplan() {
	int choice;
	cout << "Choose a membership plan from the following options: " << endl; // fixed
	cout << "1. Monthly Plan : price $50" << endl;
	cout << "2. 3 Months Plan : price $140" << endl;
	cout << "3. 6 Months Plan : price $270" << endl;
	cout << "4. 12 Months Plan : price $500" << endl;
	cout << "Enter your choice: "; // fixed
	cin >> choice;

	registration_date = time(0); // fixed
	tm current_time; // fixed
	localtime_s(&current_time, &registration_date); // fixed

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
		membership_plan = "No Plan"; // fixed
		expiration_date = registration_date; // fixed
		return; // fixed
	}

	expiration_date = mktime(&current_time);
}

void member::activesubscription() {
	Attendance_Tracking at;

	if (at.getStatus() == true) { // fixed
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
	cout << "Enter your choice: "; // fixed
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
		assigned_trainer = "No Trainer"; // fixed
		break;
	}
}

void member::Membershipstatus() {
	cout << "Membership Plan: " << membership_plan << endl;
	cout << "Active Subscription: " << active_subscription << endl;
}

void member::printmemberinfo() {
	printer(); // fixed
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
	ofstream mfile("member_info.txt", ios::app);
	if (mfile.is_open()) {
		mfile << name << "|" << id << "|" << contactinfo << "|" << age << "|" << membership_plan << "|" << assigned_trainer << "|" << active_subscription << "|" << gender << "|" << payment_status << "|" << attendance_record << "|" << registration_date << "|" << expiration_date << "\n";
		mfile.close();
	}
}

void member::load_file(vector<member>& members) {
	ifstream mfile("member_info.txt");

	if (!mfile.is_open()) {
		cout << "Could not open file.\n";
		return;
	}

	members.clear();
	string temp;

	while (true) {
		member one;

		if (!getline(mfile, one.name, '|'))
			break;

		getline(mfile, temp, '|');
		one.id = stoi(temp);

		getline(mfile, temp, '|');
		one.contactinfo = stoi(temp);

		getline(mfile, temp, '|');
		one.age = stoi(temp);

		getline(mfile, one.membership_plan, '|');
		getline(mfile, one.assigned_trainer, '|');
		getline(mfile, one.active_subscription, '|');
		getline(mfile, one.gender, '|');
		getline(mfile, one.payment_status, '|');
		getline(mfile, one.attendance_record, '|');

		getline(mfile, temp, '|');
		one.registration_date = stoll(temp);

		getline(mfile, temp);
		one.expiration_date = stoll(temp);

		members.push_back(one);
	}

	mfile.close();

	int maxId = 999;
	for (int i = 0; i < (int)members.size(); i++) {
		if (members[i].id > maxId) {
			maxId = members[i].id;
		}
	}

	if (!members.empty()) {
		members[0].setCounter(maxId + 1);
	}
}
//void member::load_file(member members[], int &memberCount) {
//	ifstream mfile("member_info.txt");
//	if (mfile.is_open()) {
//		memberCount = 0;
//		while (mfile >> members[memberCount].name >> members[memberCount].id >> members[memberCount].contactinfo >> members[memberCount].age >> members[memberCount].membership_plan >> members[memberCount].assigned_trainer >> members[memberCount].active_subscription >> members[memberCount].gender >> members[memberCount].payment_status >> members[memberCount].attendance_record >> members[memberCount].registration_date >> members[memberCount].expiration_date) {
//			memberCount++;
//			if (memberCount >= 1000) break;
//		}
//		mfile.close();
//	}
//}

string member::getName() {
	return name;
}
int member::getid() {
	return id;
}
string member::getActiveSubscription()const {
	return active_subscription;
}

string member::getPlan()const {
	return membership_plan;
}

string member::getTrainer()const {
	return assigned_trainer;
}

string member::getPaymentStatus()const {
	return payment_status;
}

int member::getAttendance()const {
	return stoi(attendance_record); // لو مخزنة كـ string
}
