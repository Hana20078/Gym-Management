#define _CRT_SECURE_NO_WARNINGS
#include "Attendance_Tracking.h"
#include "member.h"
#include <iostream>
#include <fstream>
#include <ctime>
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
    for (int i = 0; i < (int)members.size(); i++) {
        if (id1 == members[i].getid()) {
            return i;
        }
    }
    return -1;
}

string Attendance_Tracking::getTodayDate() {
    time_t now = time(0);
    tm localTime;
    localtime_s(&localTime, &now);

    char buffer[11];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d", &localTime);

    return string(buffer);
}

void Attendance_Tracking::rewrite_file(vector<Attendance_Tracking>& records) {
    ofstream mfile("Attendance_Tracking.txt");

    if (!mfile.is_open()) {
        cout << "Could not open file.\n";
        return;
    }

    for (int i = 0; i < (int)records.size(); i++) {
        mfile << records[i].attendance_id << "|"
            << records[i].id << "|"
            << records[i].date << "|"
            << records[i].checkin_time << "|"
            << records[i].checkout_time << "|"
            << records[i].status << "\n";
    }

    mfile.close();
}

int Attendance_Tracking::findTodayRecord(vector<Attendance_Tracking>& records, int memberId, string today) {
    for (int i = 0; i < (int)records.size(); i++) {
        if (records[i].id == memberId && records[i].date == today) {
            return i;
        }
    }
    return -1;
}

void Attendance_Tracking::recordAttendance(vector<member>& members) {
    cout << "Enter member id to check in: ";
    cin >> id;

    int userindex = getuser(members, id);

    if (userindex == -1) {
        cout << "Member not found." << endl;
        return;
    }

    vector<Attendance_Tracking> records;
    load_file(records);

    string today = getTodayDate();
    int index = findTodayRecord(records, id, today);

    if (index != -1) {
        if (records[index].checkout_time == 0) {
            cout << "Member already checked in today." << endl;
        }
        else {
            cout << "Member already checked out today and cannot check in again." << endl;
        }
        return;
    }

    date = today;
    checkin_time = time(0);
    checkout_time = 0;
    status = true;

    cout << "Member " << members[userindex].getName() << " checked in successfully." << endl;
    cout << "Check in Time: " << ctime(&checkin_time);

    records.push_back(*this);
    rewrite_file(records);
}

void Attendance_Tracking::CheckoutAttendance(vector<member>& members) {
    int memberId;
    cout << "Enter member id to check out: ";
    cin >> memberId;

    int userindex = getuser(members, memberId);

    if (userindex == -1) {
        cout << "Member not found." << endl;
        return;
    }

    vector<Attendance_Tracking> records;
    load_file(records);

    string today = getTodayDate();
    int index = findTodayRecord(records, memberId, today);

    if (index == -1) {
        cout << "This member did not check in today." << endl;
        return;
    }

    if (records[index].checkout_time != 0) {
        cout << "Member already checked out today." << endl;
        return;
    }

    records[index].checkout_time = time(0);
    records[index].status = false;

    cout << "Member " << members[userindex].getName() << " checked out successfully." << endl;
    cout << "Check out Time: " << ctime(&records[index].checkout_time);

    rewrite_file(records);
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
        << ctime(&checkin_time) << "|"
        << ctime(&checkout_time) << "|"
        << status << "\n";

    mfile.close();
}

void Attendance_Tracking::load_file(vector<Attendance_Tracking>& records) {
    ifstream mfile("Attendance_Tracking.txt");

    if (!mfile.is_open()) {
        cout << "Could not open file.\n";
        return;
    }

    records.clear();
    string temp;

    while (getline(mfile, temp, '|')) {
        Attendance_Tracking record;

        if (temp.empty()) break;
        record.attendance_id = stoi(temp);

        getline(mfile, temp, '|');
        if (temp.empty()) break;
        record.id = stoi(temp);

        getline(mfile, record.date, '|');

        getline(mfile, temp, '|');
        if (temp.empty()) temp = "0";
        record.checkin_time = stoll(temp);

        getline(mfile, temp, '|');
        if (temp.empty()) temp = "0";
        record.checkout_time = stoll(temp);

        getline(mfile, temp);
        if (temp.empty()) temp = "0";
        record.status = stoi(temp);

        records.push_back(record);
    }

    mfile.close();

    int maxAttendanceId = 99;
    for (int i = 0; i < (int)records.size(); i++) {
        if (records[i].attendance_id > maxAttendanceId) {
            maxAttendanceId = records[i].attendance_id;
        }
    }

    attendanceidcounter = maxAttendanceId + 1;
}

int Attendance_Tracking::getMemberId() {
    return id;
}

bool Attendance_Tracking::isCheckedOut() {
    return !status;
}

