
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

constexpr int MAX_TRAINERS = 30;

void displayMenu() {
    cout << "\nWelcome to the Potatos Management System!" << endl;
    cout << "1. Create a new member" << endl;
    cout << "2. Create a new trainer" << endl;
	cout << "3. Load member" << endl;
    cout << "4. Membership plan system" << endl;
    cout << "5. Attendance tracking system" << endl;

    cout << "0. Exit" << endl;
    cout << "Enter your choice: ";
}
void createMember(member members[], int& memberCount) {
    if (memberCount < 1000) {
        members[memberCount].createnewclient();
        memberCount++;
        cout << "Member created successfully!" << endl;
    }
    else {
        cout << "Member limit reached. Cannot create more members." << endl;
	}
     
}
void createTrainer(Trainer_Management Trainer[], int& TrainerCount) {
    if (TrainerCount < MAX_TRAINERS) {
        Trainer[TrainerCount].createnewtrainer();
        TrainerCount++;
        cout << "Trainer created successfully!" << endl;
    }
    else {
        cout << "Trainer limit reached. Cannot create more trainers." << endl;
    }

}


int main() {
    int choice;
    member m[1000];
    Trainer_Management t[MAX_TRAINERS];
    int TrainerCount = 0;
    int memberCount = 0;
	Trainer_Management t1;
	Membership_Plan_Management mp(0, "");
    Attendance_Tracking at;

    do {
		displayMenu();
        cin >> choice;

        switch (choice)
        {
        
        case 1:
			createMember(m, memberCount);
            break;
        case 2:
			//cout << "Creating a new trainer is under construction. Please check back later." << endl;
			createTrainer(t, TrainerCount);
			t[TrainerCount - 1].save_file();
            break;
        case 3:
			t1.load_file(); 
			t1.printer();
            break;
        case 4:
            mp.membershipplansystem();
            break;
        case 5:
            at.recordAttendance(m, memberCount);
			break;
        case 0:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
        }
    } while (choice != 0);
    return 0;
}