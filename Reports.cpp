#include "Reports.h"
#include "member.h"
#include "Workout_Program_Management.h"
#include <iostream>
#include <map>
using namespace std;

int Reports::totalActiveMembers(vector<member>& members) {
    int count = 0;
    for (auto& m : members) {
        if (m.getActiveSubscription() == "Active")
            count++;
    }
    return count;
}

int Reports::expiredMemberships(vector<member>& members) {
    int count = 0;
    for (auto& m : members) {
        if (m.getActiveSubscription() == "Inactive")
            count++;
    }
    return count;
}

float Reports::monthlyRevenue(vector<member>& members) {
    float total = 0;
    for (auto& m : members) {
        if (m.getPaymentStatus() == "Paid") {
            if (m.getPlan() == "Monthly Plan")
                total += 50;
            else if (m.getPlan() == "3 Months Plan")
                total += 140;
            else if (m.getPlan() == "6 Months Plan")
                total += 270;
            else if (m.getPlan() == "12 Months Plan")
                total += 500;
        }
    }
    return total;
}

void Reports::trainerPerformance(vector<workout_programs>& programs) {
    map<string, int> trainerCount;

    for (auto& w : programs) {
        trainerCount[w.getassigned_trainer()]++;
    }

    cout << "Trainer Performance:\n";
    for (auto& t : trainerCount) {
        cout << t.first << " -> " << t.second << " programs\n";
    }
}

string Reports::mostPopularPlan(vector<member>& members) {
    map<string, int> planCount;
    for (auto& m : members) {
        planCount[m.getPlan()]++;
    }

    string bestPlan;
    int maxCount = 0;
    for (auto& p : planCount) {
        if (p.second > maxCount) {
            maxCount = p.second;
            bestPlan = p.first;
        }
    }

    return bestPlan;
}

void Reports::attendanceStats(vector<member>& members) {
    int total = 0;
    for (auto& m : members) {
        total += m.getAttendance();
    }

    cout << "Total Attendance: " << total << endl;
    if (!members.empty()) {
        double avg = static_cast<double>(total) / members.size();
        cout << "Average Attendance: " << avg << endl;
    }
}

void Reports::reports(vector<member>& members) {
    cout << "Active Members: " << totalActiveMembers(members) << endl;
    cout << "Expired Memberships: " << expiredMemberships(members) << endl;
    cout << "Monthly Revenue: $" << monthlyRevenue(members) << endl;
    cout << "Most Popular Plan: " << mostPopularPlan(members) << endl;
    attendanceStats(members);
}





