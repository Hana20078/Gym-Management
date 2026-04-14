#include <iostream>
#include <ctime>
#include "member.h"
#include "person.h"
#include <fstream>
#include <string>   // fixed

using namespace std;

member::member() : person() {
}

string member::getstatus() {
	return active_subscription;
}

int member::activecount(member arr[], int size) {
	int count = 0;
	for (int i = 0; i < size; i++) {
		if (arr[i].active_subscription == "Active") {
			count++;
		}
	}
	return count; // fixed
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
	time_t now = time(0); // fixed
	if (now <= expiration_date) { // fixed
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
	ofstream mfile("member_info.txt"); // fixed
	if (mfile.is_open()) {
		mfile << name << endl; // fixed
		mfile << id << endl; // fixed
		mfile << contactinfo << endl; // fixed
		mfile << age << endl; // fixed
		mfile << membership_plan << endl; // fixed
		mfile << assigned_trainer << endl; // fixed
		mfile << active_subscription << endl; // fixed
		mfile << registration_date << endl; // fixed
		mfile << expiration_date << endl; // fixed
		mfile.close(); // fixed
	}
	else {
		cout << "Error opening file for saving." << endl; // fixed
		mfile << name << " " << id << " " << contactinfo << " " << age << " " << membership_plan << " " << assigned_trainer << " " << active_subscription << " " << gender << " " << payment_status << " " << attendance_record << " " << registration_date << " " << expiration_date;
		mfile.close();
	}
}

//void member::load_file() {
//	ifstream mfile("member_info.txt"); // fixed
//	if (mfile.is_open()) {
//		std::getline(mfile, name); // fixed
//		mfile >> id; // fixed
//		mfile >> contactinfo; // fixed
//		mfile >> age; // fixed
//		mfile.ignore(); // fixed
//		std::getline(mfile, membership_plan); // fixed
//		std::getline(mfile, assigned_trainer); // fixed
//		std::getline(mfile, active_subscription); // fixed
//		mfile >> registration_date; // fixed
//		mfile >> expiration_date; // fixed
//		mfile.close(); // fixed
//	}
//	else {
//		cout << "Error opening file for loading." << endl; // fixed
//	}
//}
void member::load_file() {
	ifstream mfile("member_info.txt");
	if (mfile.is_open()) {
		mfile >> name >> id >> contactinfo >> age >> membership_plan >> assigned_trainer >> active_subscription >> gender >> payment_status >> attendance_record >> registration_date >> expiration_date;
	}
}

string member::getName() {
	return name;
}
int member::getid() {
	return id;
}