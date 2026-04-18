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

void showMainMenu() {
    cout << "\n========== GYM MANAGEMENT SYSTEM ==========\n";
    cout << "1. Member Management\n";
    cout << "2. Trainer Management\n";
    cout << "3. Membership Plans\n";
    cout << "4. Workout Programs\n";
    cout << "5. Attendance Tracking\n";
    cout << "6. Payment / Billing\n";
    cout << "7. Reports\n";
    cout << "0. Exit\n";
    cout << "Enter your choice: ";
}

void showMemberMenu() {
    cout << "\n========== MEMBER MANAGEMENT ==========\n";
    cout << "1. Add Member\n";
    cout << "2. Update Member\n";
    cout << "3. Delete Member\n";
    cout << "4. Search Member\n";
    cout << "5. Display All Members\n";
    cout << "0. Back\n";
    cout << "Enter your choice: ";
}

void showTrainerMenu() {
    cout << "\n========== TRAINER MANAGEMENT ==========\n";
    cout << "1. Add Trainer\n";
    cout << "2. Update Trainer\n";
    cout << "3. Delete Trainer\n";
    cout << "4. Search Trainer\n";
    cout << "5. Display All Trainers\n";
    cout << "0. Back\n";
    cout << "Enter your choice: ";
}

void showPlanMenu() {
    cout << "\n========== MEMBERSHIP PLANS ==========\n";
    cout << "1. Add Plan\n";
    cout << "2. Update Plan\n";
    cout << "3. Delete Plan\n";
    cout << "4. Display All Plans\n";
    cout << "0. Back\n";
    cout << "Enter your choice: ";
}

void showWorkoutMenu() {
    cout << "\n========== WORKOUT PROGRAMS ==========\n";
    cout << "1. Add Workout Program\n";
    cout << "2. Assign Workout to Member\n";
    cout << "3. Display Workout Programs\n";
    cout << "0. Back\n";
    cout << "Enter your choice: ";
}

void showAttendanceMenu() {
    cout << "\n========== ATTENDANCE TRACKING ==========\n";
    cout << "1. Check In\n";
    cout << "2. Check Out\n";
    cout << "3. View Attendance Report\n";
    cout << "0. Back\n";
    cout << "Enter your choice: ";
}

void showBillingMenu() {
    cout << "\n========== PAYMENT / BILLING ==========\n";
    cout << "1. Record Payment\n";
    cout << "2. Generate Receipt\n";
    cout << "3. View Unpaid Balances\n";
    cout << "0. Back\n";
    cout << "Enter your choice: ";
}

void showReportsMenu() {
    cout << "\n========== REPORTS ==========\n";
    cout << "1. Member Report\n";
    cout << "2. Trainer Report\n";
    cout << "3. Payment Report\n";
    cout << "4. Attendance Report\n";
    cout << "0. Back\n";
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
void createWorkoutProgram(vector<workout_programs>& programs) {
    workout_programs newProgram(0, 0, "", "", "", "", 0, 0, 0, false,"");
    newProgram.chooseWorkout();
    programs.push_back(newProgram);
    newProgram.save_file();
    cout << "Workout program created successfully!" << endl;
}
void loadWorkoutPrograms(vector<workout_programs>& programs) {
    ifstream file("workout_programs.txt");
    if (!file.is_open()) return;
     workout_programs temp(0, 0, "", "", "", "", 0, 0, 0, false, "");
     while (true) {
         if (!(file >> temp.num)) break;
         file.ignore(); // skip |

         file >> temp.duration;
         file.ignore();

         getline(file, temp.name, '|');
         getline(file, temp.target_goal, '|');
         getline(file, temp.exercise_list, '|');
         getline(file, temp.assigned_trainer, '|');

         file >> temp.start_date;
         file.ignore();

         file >> temp.expiration_date;

         programs.push_back(temp);
     }
     file.close();
}

void createMembershipPlan(vector<Membership_Plan_Management>& plans) {
    Membership_Plan_Management newPlan("");
    newPlan.createnewclient();
    plans.push_back(newPlan);
    newPlan.save_file();
    cout << "Membership plan created successfully!" << endl;
}

void loadMembershipPlans(vector<Membership_Plan_Management>& plans) {
    Membership_Plan_Management temp("");
    temp.load_file(plans);
}
void updateMembershipPlan(vector<Membership_Plan_Management>& plans) {
    Membership_Plan_Management temp("");
    temp.updateMembershipPlan(plans);
}
void deleteMembershipPlan(vector<Membership_Plan_Management>& plans) {
    Membership_Plan_Management temp("");
    temp.deleteMembershipPlan(plans);
}
void displayMembershipPlans(const vector<Membership_Plan_Management>& plans) {
    for (const auto& plan : plans) {
        plan.displayPlan();
        cout << "-----------------------------\n";
    }
}

int main() {
    int choice;
    vector<member> m;
    vector<Trainer_Management> t;
    vector<Attendance_Tracking> attendance;
    Membership_Plan_Management mp( "");
    workout_programs wp(0, 0, "", "", "", "", 0, 0, 0, false,"");
    Reports r;
    member temp;
    vector<Membership_Plan_Management> memberships;
    vector<Billing_System> payments;
    //mp.save_file();

    do {
        showMainMenu();
        cin >> choice;

        switch (choice)
        {
        case 1:
            int choice1;
            do{
                showMemberMenu();
                cin >> choice1;
                switch (choice1) {
                case 1:
                    cout << "Add Member selected\n";
                    createMember(m);
                    m.back().save_file();
                    break;
                case 2:
                    cout << "Update Member selected\n";
					temp.updateMember(m);
                    break;
                case 3:
                    cout << "Delete Member selected\n";
                    temp.deleteMember(m);
                    break;
                case 4: {
                    cout << "Search Member selected\n";
                    int memberId;
                    cout << "Enter member ID: ";
                    cin >> memberId;
                    
                    int index = temp.getuser(m, memberId);
                    if (index != -1) {
                        m[index].printmemberinfo();
                    }
                    else {
                        cout << "Member not found.\n";
                    }

                    break;
                }
                case 5:
                    cout << "Display All Members selected\n";
					loadMembers(m);
					for (member& x : m) {
                        x.printmemberinfo();
                        cout << "-----------------------------\n";
                    }
                    break;
                case 0:
                    break;
                default:
                    cout << "Invalid choice\n";
                }
            } while (choice1 != 0);
            break;
        case 2:
        {
            int choice2;
			do {
                showTrainerMenu();
                cin >> choice2;
                switch (choice2) {
                case 1:
                    cout << "Add Trainer selected\n";
					createTrainer(t);
                    break;
                case 2: {
                    cout << "Update Trainer selected\n";
                    Trainer_Management tempTrainer;
                    tempTrainer.updateTrainer(t);
                    break;

                }
                case 3: {
                    cout << "Delete Trainer selected\n";
                    Trainer_Management tempTrainer;
                    tempTrainer.deleteTrainer(t);
                    break;
                }
                case 4: {
                    cout << "Search Trainer selected\n";
                    Trainer_Management tempTrainer;
                    tempTrainer.getTrainerIndex1(t);
                    break;
                }
                case 5:
                    cout << "Display All Trainers selected\n";
                    for (Trainer_Management& x : t) {
                        x.printer();
                        cout << "-----------------------------\n";
                    }
                    break;
                case 0:
                    break;
                default:
                    cout << "Invalid choice\n";
                }
            
            } while (choice2 != 0);
            break;
            //loadMembers(m);
            //loadAttendance(attendance);

            //if (attendance.empty()) {
            //    cout << "No attendance records found." << endl;
            //}
            //else {
            //    for (int i = 0; i < (int)attendance.size(); i++) {
            //        attendance[i].getAttendanceReport(m);
            //    }
            //}
            //break;
        }
        case 3:
            int choice3;
            do {
                showPlanMenu();
                cin >> choice3;

                switch (choice3) {
                case 1:
                    cout << "Add Plan selected\n";
                    break;
                case 2:
                    cout << "Update Plan selected\n";
                    break;
                case 3:
                    cout << "Delete Plan selected\n";
                    break;
                case 4:
                    cout << "Display All Plans selected\n";
                    break;
                case 0:
                    break;
                default:
                    cout << "Invalid choice\n";
                }
            } while (choice3 != 0);
            break;
        case 4:
        {
            int choice4;
            do {
                showWorkoutMenu();
                cin >> choice4;

                switch (choice4) {
                case 1:
                    cout << "Add Workout Program selected\n";
                    break;
                case 2:
                    cout << "Assign Workout to Member selected\n";
                    break;
                case 3:
                    cout << "Display Workout Programs selected\n";
                    break;
                case 0:
                    break;
                default:
                    cout << "Invalid choice\n";
                }
            } while (choice != 0);
            break;
            //int attendanceChoice;
            //Attendance_Tracking at;

            //cout << "Attendance Tracking System" << endl;
            //cout << "1. Record Attendance (Check-in)" << endl;
            //cout << "2. Record Attendance (Check-out)" << endl;
            //cout << "Enter your choice: ";
            //cin >> attendanceChoice;

            //switch (attendanceChoice)
            //{
            //case 1:
            //    at.recordAttendance(m);
            //    break;

            //case 2:
            //    at.CheckoutAttendance(m);
            //    break;

            //default:
            //    cout << "Invalid choice" << endl;
            //    break;
            //}
            //break;
        }
        case 5:
            int choice5;
            do {
                showAttendanceMenu();
                cin >> choice5;

                switch (choice5) {
                case 1:
                    cout << "Check In selected\n";
                    break;
                case 2:
                    cout << "Check Out selected\n";
                    break;
                case 3:
                    cout << "View Attendance Report selected\n";
                    break;
                case 0:
                    break;
                default:
                    cout << "Invalid choice\n";
                }
            } while (choice5 != 0);
            break;
            //loadMembers(m);
            //loadTrainers(t);
            //cout << "Loaded " << m.size() << " members and " << t.size() << " trainers." << endl;

            //break;

        case 6:
            int choice6;
            do {
                showBillingMenu();
                cin >> choice6;

                switch (choice6) {
                case 1: {
                    cout << "Record Payment selected\n";
                    Billing_System bill;
					bill.addpayment();
					bill.save_file();
					payments.push_back(bill);
                    break;
                }
                case 2: {
                    cout << "Generate Receipt selected\n";
                    Billing_System tempBill;
					tempBill.load_file(payments);

					for (int i = 0; i < (int)payments.size(); i++) {
                        cout << "Payment " << (i + 1) << ":\n";
                        payments[i].receipt();
                    }
                    break;
                }
                case 3: {
                    cout << "View Unpaid Balances selected\n";
                    Billing_System temp;
                    temp.load_file(payments);
                    temp.viewUnpaidBalances(payments);
                    break;
                }
                case 0:
                    break;
                default:
                    cout << "Invalid choice\n";
                }
            } while (choice6 != 0);
            break;
        case 7:{
            int choice7;
            do {
                showReportsMenu();
                cin >> choice7;

                switch (choice7) {
                case 1:{
                    cout << "Member Report selected\n";
					Reports r;
                    
                    r.reports(m); 
                    r.expiredMemberships(m);
                    }
                    break;
                case 2:
                    cout << "Trainer Report selected\n";
                    r.trainerPerformance(wp);
                    break;
                case 3:
                    cout << "Payment Report selected\n";
                    r.mostPopularPlan(m);
                    r.monthlyRevenue(m);
                    break;
                case 4:
                    cout << "Attendance Report selected\n";
                    r.attendanceStats(m);
                    break;
                case 0:
                    break;
                default:
                    cout << "Invalid choice\n";
                }
            } while (choice7 != 0);
            break;
        }

        case 0:
            cout << "Exiting..." << endl;
            break;

        default:
            cout << "Invalid choice" << endl;
        }

    } while (choice != 0);
	