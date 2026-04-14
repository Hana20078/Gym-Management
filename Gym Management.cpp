
#include <iostream>
#include "member.h"
#include "Trainer_Management.h"
#include "Membership_Plan_Management.h"
#include "Workout_Program_Management.h"
#include "Billing_System.h"
#include "person.h"
#include "Attendance_Tracking.h"
#include "Reports.h"
#include <vector>

using namespace std;

constexpr int MAX_TRAINERS = 20;

void displayMenu() {
    cout << "\nWelcome to the Potatos Management System!" << endl;
    cout << "1. Create a new member" << endl;
    cout << "2. Create a new trainer" << endl;
	cout << "3. Print Attendance Report" << endl;
    cout << "4. Membership plan system" << endl;
    cout << "5. Attendance tracking system" << endl;
    cout << "6. Load Trainers/Clients" << endl;
    cout << "0. Exit" << endl;
    cout << "Enter your choice: ";
}
void createMember(vector<member>& members) {
	member newMember;
    newMember.createnewclient();
	members.push_back(newMember);
    cout << "Member created successfully!" << endl; 
}
void createTrainer(vector<Trainer_Management>& Trainer) {
	Trainer_Management newTrainer;
    newTrainer.createnewtrainer();
	Trainer.push_back(newTrainer);
    cout << "Trainer created successfully!" << endl;

}
void loadTrainers(Trainer_Management Trainer[], int &TrainerCount) {
    Trainer[0].load_file(Trainer, TrainerCount);
}
void loadMembers(member members[], int &memberCount) {
    members[0].load_file(members, memberCount);
}


int main() {
    int choice;
    //member m[30];
    vector<member> m;
    //Trainer_Management t[MAX_TRAINERS];
    vector<Trainer_Management> t;
    //Attendance_Tracking attendance[10];
	vector<Attendance_Tracking> attendance;
    //int TrainerCount = 0;
    //int memberCount = 0;
	Trainer_Management t1;
	Membership_Plan_Management mp(0, "");
	//int attendanceCount = 0;

    do {
		displayMenu();
        cin >> choice;

        switch (choice)
        {
        
        case 1:
			//createMember(m, memberCount);
			//m[memberCount - 1].save_file();
			createMember(m);
			m.back().save_file();
            break;
        case 2:
			createTrainer(t);
			t.back().save_file();
            break;
        case 3:
            for (int i = 0; i < attendance.size; i++) {
                attendance[i].getAttendanceReport(m, memberCount);
            }
            break;
        case 4:
            mp.membershipplansystem();
            break;
        case 5:
			int attendanceChoice;
			cout << "Attendance Tracking System" << endl;
			cout << "1. Record Attendance (Check-in)" << endl;
			cout << "2. Record Attendance (Check-out)" << endl;
			cout << "Enter your choice: ";
			cin >> attendanceChoice;
            switch (attendanceChoice)
            {
            case 1:
                if (attendanceCount < 100) {
                    attendance[attendanceCount].recordAttendance(m, memberCount);
                    attendanceCount++;
                }
                else {
                    cout << "Attendance limit reached.\n";
                }
                break;
            case 2:
                if (attendanceCount < 100) {
                    attendance[attendanceCount].CheckoutAttendance(m, memberCount);
                    attendanceCount++;
                }
                else {
                    cout << "Attendance limit reached.\n";
                }
                break;
            }
            break;

        case 6:
            loadMembers(m, memberCount);
            loadTrainers(t, TrainerCount);
            cout << "Loaded " << memberCount << " members and " << TrainerCount << " trainers." << endl;
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