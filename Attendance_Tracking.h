#pragma once
#include <ctime>
#include <string>
#include <vector>
#include <fstream>

class member;

using namespace std;

class Attendance_Tracking
{
protected:
    static int attendanceidcounter;
    int id;
    int attendance_id;
    string date;
    time_t checkin_time;
    time_t checkout_time;
    bool status;
    time_t current_time;

public:
    Attendance_Tracking();

    void recordAttendance(vector<member>& members);
    int getuser(vector<member>& members, int id1);
    void getAttendanceReport(vector<member>& members);

    bool getStatus();
    time_t getCheckinTime();
    time_t getCheckoutTime();

    void load_file(vector<Attendance_Tracking>& records);
    void save_file();
    void rewrite_file(vector<Attendance_Tracking>& records);

    void CheckoutAttendance(vector<member>& members);
    int getMemberId();
    bool isCheckedOut();

    string getTodayDate();
    int findTodayRecord(vector<Attendance_Tracking>& records, int memberId, string today);
};