#pragma once
#include <ctime>
#include <string>

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
	int check_id;
public:
	Attendance_Tracking();
    void recordAttendance(member members[], int memberCount);
	int getuser(member member[], int memberCount, int id1);
	void getAttendanceReport(member members[], int memberCount);
	bool getStatus();
	time_t getCheckinTime();
};

