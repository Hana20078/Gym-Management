#pragma once
#include <ctime>
#include "member.h"

using namespace std;	

class Attendance_Tracking : public member
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
	int getuser(member member[], int memberCount);
};

