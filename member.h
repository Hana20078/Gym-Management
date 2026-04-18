#pragma once
#include "person.h"
#include <iostream>
#include <ctime>
#include <string> 
#include <fstream>
#include "Billing_System.h"
#include <vector>
#include "Workout_Program_Management.h"

using namespace std;

class Attendance_Tracking;

class member : public person, public Billing_System
{
private:

	string membership_plan;
	time_t registration_date;
	time_t expiration_date;
	string assigned_trainer;
	string attendance_record;
	string payment_status;
	string active_subscription;
	string assigned_workout;

public:
	member();
	void chooseplan();
	void activesubscription();
	void assignedtrainer();
	void Membershipstatus();
	void printmemberinfo();
	void createnewclient();
    void save_file();
	void load_file(vector<member>& members);
	string getstatus();
	int activecount(member arr[], int size);
	string getName();
	int getid();
	string getActiveSubscription()const;
	string getPlan()const;
	string getTrainer()const;
	string getPaymentStatus()const;
	int getAttendance()const;
	int getuser(vector<member>& members, int id1);
	void getuser1(vector<member>& members);
	void deleteMember(vector<member>& members);
	void saveAllMembersToFile(vector<member>& members);
	void updateMember(vector<member>& members);
	string getAssignedWorkout() const;
	void assignWorkoutToMember(vector<member>& members, vector<workout_programs>& programs);
};