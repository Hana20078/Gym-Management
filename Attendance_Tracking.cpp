#define _CRT_SECURE_NO_WARNINGS
#include "Attendance_Tracking.h"

using namespace std;
int Attendance_Tracking::attendanceidcounter = 1000;


Attendance_Tracking::Attendance_Tracking() : member() {
	attendance_id = attendanceidcounter++;
	id = 0;
	date = "";
	checkin_time ;
	checkout_time ;
	status = false;
	current_time = time(0);
}
int Attendance_Tracking::getuser(member member[], int memberCount) {
	for(int i =0 ; i < memberCount; i++) {
		if (id == member[i].getid()) {
			return i;
		}
	}
		return -1;
}
void Attendance_Tracking::recordAttendance(member members[], int memberCount) {
	member m;
	cout << "Enter member id to check in: ";
	cin >> id;
	int userindex = getuser(members, memberCount);

	if( userindex == -1) {
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
};

