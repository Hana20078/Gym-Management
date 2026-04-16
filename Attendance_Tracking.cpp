#define _CRT_SECURE_NO_WARNINGS
#include "Attendance_Tracking.h"
#include "member.h"
#include <iostream>
#include <fstream>

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
int Attendance_Tracking::getuser(vector<member>& members, int id1) {
	for (int i = 0; i < members.size; i++) {
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


	checkin_time = time(0);
	cout << "Member " << members[userindex].getName() << " checked in successfully." << endl;
	cout << "Check in Time: " << ctime(&checkin_time) << endl;

	save_file();
}
	void Attendance_Tracking::CheckoutAttendance() {
		if (!status) {
			cout << "This attendance record is already checked out." << endl;
			return;
		}

		checkout_time = time(0);
		status = false;

		cout << "Check out recorded successfully." << endl;
		cout << "Check out Time: " << ctime(&checkout_time) << endl;

		save_file();
	}
	void Attendance_Tracking::getAttendanceReport(vector<member>& members) {
		if (members.size() <= 0) {
			cout << "No members loaded.\n";
			return;
		}

		int userindex = getuser(members, id);

		if (userindex == -1) {
			cout << "Member not found for this attendance record.\n";
			return;
		}

		cout << "Member Name: " << members[userindex].getName() << endl;
		cout << "Member ID: " << members[userindex].getid() << endl;
		cout << "Membership Plan: " << members[userindex].getstatus() << endl;
		cout << "Attendance Status: " << (status ? "Checked In" : "Checked Out") << endl;

		if (checkin_time != 0)
			cout << "Check-in Time: " << ctime(&checkin_time);
		else
			cout << "Check-in Time: Not recorded\n";

		if (checkout_time != 0)
			cout << "Check-out Time: " << ctime(&checkout_time);
		else
			cout << "Check-out Time: Not recorded\n";

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
bool Attendance_Tracking::getStatus() {
	return status;
}

time_t Attendance_Tracking::getCheckinTime() {
	return checkin_time;
}

time_t Attendance_Tracking::getCheckoutTime() {
	return checkout_time;
}

int Attendance_Tracking::getMemberId() {
	return id;
}

bool Attendance_Tracking::isCheckedOut() {
	return !status;
}

