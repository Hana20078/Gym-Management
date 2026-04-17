#include <iostream>
#include <vector>
#include "member.h"
#include "Trainer_Management.h"
#include "Membership_Plan_Management.h"
#include "Workout_Program_Management.h"
#include "Billing_System.h"
#include "person.h"
#include "Attendance_Tracking.h"
#include "Reports.h"

using namespace std;

void displayMenu() {
    cout << "\nWelcome to the Potatos Management System!" << endl;
    cout << "1. Create User" << endl;
    cout << "2. Print Attendance Report" << endl;
    cout << "3. Membership plan system" << endl;
    cout << "4. Attendance tracking system" << endl;
    cout << "5. Load Trainers/Clients" << endl;
    cout << "0. Exit" << endl;
    cout << "Enter your choice: ";
}

void createMember(vector<member>& members) {
    member newMember;
    newMember.createnewclient();
    members.push_back(newMember);
    cout << "Member created successfully!" << endl;
}

void createTrainer(vector<Trainer_Management>& trainers) {
    Trainer_Management newTrainer;
    newTrainer.createnewtrainer();
    trainers.push_back(newTrainer);
    cout << "Trainer created successfully!" << endl;
}
void loadTrainers(vector<Trainer_Management>& trainers) {
    Trainer_Management temp;
    temp.load_file(trainers);
}

void loadMembers(vector<member>& members) {
    member temp;
    temp.load_file(members);
}
void loadAttendance(vector<Attendance_Tracking>& attendance) {
    Attendance_Tracking temp;
    temp.load_file(attendance);
}
int main() {
    int choice;
    vector<member> m;
    vector<Trainer_Management> t;
    vector<Attendance_Tracking> attendance;
    Membership_Plan_Management mp( "");
    workout_programs wp(0, 0, "", "", "", "", 0, 0, 0, false);
    Reports r;

    do {
        displayMenu();
        cin >> choice;

        switch (choice)
        {
        case 1:
            int choise;
			cout << "1. Create a new member" << endl;
			cout << "2. Create a new trainer" << endl;

            cin >> choise;
            switch (choise) {
            case 1:
                createMember(m);
                m.back().save_file();
                break;
            case 2:
                createTrainer(t);
                t.back().save_file();
                break;
            }

        case 2:
        {
            loadMembers(m);
            loadAttendance(attendance);

            if (attendance.empty()) {
                cout << "No attendance records found." << endl;
            }
            else {
                for (int i = 0; i < (int)attendance.size(); i++) {
                    attendance[i].getAttendanceReport(m);
                }
            }
            break;
        }
        case 3:
            mp.membershipplansystem();
            break;

        case 4:
        {
            int attendanceChoice;
            Attendance_Tracking at;

            cout << "Attendance Tracking System" << endl;
            cout << "1. Record Attendance (Check-in)" << endl;
            cout << "2. Record Attendance (Check-out)" << endl;
            cout << "Enter your choice: ";
            cin >> attendanceChoice;

            switch (attendanceChoice)
            {
            case 1:
                at.recordAttendance(m);
                break;

            case 2:
                at.CheckoutAttendance(m);
                break;

            default:
                cout << "Invalid choice" << endl;
                break;
            }
            break;
        }
        case 5:
            loadMembers(m);
            loadTrainers(t);
            cout << "Loaded " << m.size() << " members and " << t.size() << " trainers." << endl;

            break;

        case 6:
            r.reports;
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