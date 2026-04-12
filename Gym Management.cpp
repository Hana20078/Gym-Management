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
	cout << "2. Create a new trainer" << endl;
    cin >> choice;

    //
    Trainer_Management myTrainer;

    cout << "Saving trainer data to file..." << endl;
    myTrainer.save_file();
    cout << "Done! Check your folder for trainerfile.txt" << endl;

    //


	switch (choice)
    {
        case 1:
            m1.createnewclient();
            break;
        case 2:
			break;
        default:
            cout << "Invalid choice" << endl;
            break;
    }

    return 0;
}