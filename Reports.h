#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class member;
class workout_programs;
class Reports
{
public:
	 int totalActiveMembers(vector<member>& members);
	 int expiredMemberships(vector<member>& members);
	 float monthlyRevenue(vector<member>& members);
	 void trainerPerformance(vector<workout_programs>& programs);
	 string mostPopularPlan(vector<member>& members);
	 void attendanceStats(vector<member>& members);
	 void display_performance();
	 void reports(vector<member>& members);

};