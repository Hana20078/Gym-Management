#include <iostream>
#include "member.h" 
#include "Trainer_Management.h" 
#include "Membership_Plan_Management.h" 
#include "Workout_Program_Management.h" 
#include "Billing_System.h"  
#include "Attendance_Tracking.h" 
#include "Reports.h"


using namespace std;
int main() {
	int choice;
	do {
		cout << "************************GYM_SYSTEM_MENU***********************" << endl;
		cout << "1.Register new member" << endl;
		cout << "2.update member information" << endl;
		cout << "3.Delete member (if allowed)" << endl;
		cout << "4.search members details" << endl;
		cout << "5.Display members details" << endl;
		cout << "6.Track membership status" << endl;
		cout << "7.exist" << endl;
		cin >> choice;
		//switch (choice) {
		//case1:
		//	register_member();
		//case 2:
		//	update_member();
		//case 3:
		//	delete_member();
		//case 4:
		//	search_member();
		//case 5:
		//	display_member();
		//case 6:
		//	track_memberships();
		//case 7:
		//	cout << "existing...........";
	}while (choice != 7);
}