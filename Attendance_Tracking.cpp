#define _CRT_SECURE_NO_WARNINGS
#include "Attendance_Tracking.h"
#include "member.h"
#include <iostream>
using namespace std;
int Attendance_Tracking::attendanceidcounter = 100;
Attendance_Tracking::Attendance_Tracking() {
	attendance_id = attendanceidcounter++;
	id = 0;
	date = "";
	checkin_time = 0;
	checkout_time = 0;
	status = false;
	current_time = time(0);
}
int Attendance_Tracking::getuser(member members[], int memberCount, int id1) {
	for (int i = 0; i < memberCount; i++) {
		if (id1 == members[i].getid()) {
			return i;
		}
	}
	return -1;
}
void Attendance_Tracking::recordAttendance(vector<member>& members) {
	cout << "Enter member id to check in: ";
	cin >> id;
	int userindex = getuser(members, memberCount, id);

	if (userindex == -1) {
		cout << "Member not found." << endl;
		return;
	}
	else {
		if (status == true) {
			cout << "Member has already checked in Today at " << ctime(&checkin_time) << endl;

		}
		else if (status == false) {
			status = true;
			checkin_time = time(0);
			cout << "Member " << members[userindex].getName() << " checked in successfully." << endl;
			cout << "Check in Time: " << ctime(&checkin_time) << endl;
		}
	}
	save_file();

}
void Attendance_Tracking::CheckoutAttendance(vector<member>& members) {
	cout << "Enter member id to check out: ";
	cin >> id;
	int userindex = getuser(members, memberCount, id);

	if (userindex == -1) {
		cout << "Member not found." << endl;
		return;
	}
	else {
		if (status == true) {
			status = false;
			checkout_time = time(0);
			cout << "Member " << members[userindex].getName() << " checked out successfully." << endl;
			cout << "Check out Time: " << ctime(&checkout_time) << endl;
		}
		else if (status == false) {
			cout << "Member has already checked out Today at " << ctime(&checkout_time) << endl;


		}
	}
	save_file();

}
void Attendance_Tracking:: getAttendanceReport(vector<member>& members) {
	if (memberCount <= 0) {
		cout << "No members loaded.\n";
		return;
	}
	int userindex = getuser(members, memberCount, id);

	cout << "Member Name: " << members[userindex].getName() << endl;
	cout << "Member ID: " << members[userindex].getid() << endl;
	cout << "Membership Plan: " << members[userindex].getstatus() << endl;
	cout << "Attendance Status: " << (status ? "Checked In" : "Not Checked In") << endl;
	cout << "Check-in Time: " << ctime(&checkin_time);
	cout << "Check-out Time: " << ctime(&checkout_time);

	cout << "-----------------------------------" << endl;

}
bool Attendance_Tracking::getStatus() {
	return status;
}
time_t Attendance_Tracking::getCheckinTime() {
	return checkin_time;
}
time_t Attendance_Tracking::getCheckoutTime() {
	return checkout_time;
}
void Attendance_Tracking::save_file() {
	ofstream mfile("Attendance_Tracking.txt", ios::app);

	if (!mfile.is_open()) {
		cout << "Could not open file.\n";
		return;
	}

	mfile << attendance_id << "|"
		<< id << "|"
		<< date << "|"
		<< checkin_time << "|"
		<< checkout_time << "|"
		<< status << "\n";

	mfile.close();
}
void Attendance_Tracking::load_file(Attendance_Tracking records[], int& recordCount) {
	ifstream mfile("Attendance_Tracking.txt");

	if (!mfile.is_open()) {
		cout << "Could not open file.\n";
		return;
	}

	recordCount = 0;
	string temp;

	while (
		getline(mfile, temp, '|') &&
		recordCount < 100
		) {
		records[recordCount].attendance_id = stoi(temp);

		getline(mfile, temp, '|');
		records[recordCount].id = stoi(temp);

		getline(mfile, records[recordCount].date, '|');

		getline(mfile, temp, '|');
		records[recordCount].checkin_time = stoll(temp);

		getline(mfile, temp, '|');
		records[recordCount].checkout_time = stoll(temp);

		getline(mfile, temp);
		records[recordCount].status = stoi(temp);

		recordCount++;
	}

	mfile.close();

	int maxAttendanceId = 99;
	for (int i = 0; i < recordCount; i++) {
		if (records[i].attendance_id > maxAttendanceId) {
			maxAttendanceId = records[i].attendance_id;
		}
	}

	attendanceidcounter = maxAttendanceId + 1;
}

