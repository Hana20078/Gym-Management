#include <iostream>
#include "member.h"
#include "Trainer_Management.h"
#include "Membership_Plan_Management.h"
#include "Workout_Program_Management.h"
#include "Billing_System.h"
#include "person.h"
#include "Attendance_Tracking.h"
#include "Reports.h"

using namespace std;

int main() {
    int choice;
    member m1;
	cout << "Welcome to the Potatos Management System!" << endl;
	cout << "1. Create a new member" << endl;
    cin >> choice;
	switch (choice)
    {
        case 1:
            m1.createnewclient();
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
    }

    return 0;
}