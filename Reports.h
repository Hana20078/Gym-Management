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
	static int totalActiveMembers(vector<member>& members);
	static int expiredMemberships(vector<member>& members);
	static float monthlyRevenue(vector<member>& members);
	void trainerPerformance(vector<workout_programs>& programs);
	static string mostPopularPlan(vector<member>& members);
	static void attendanceStats(vector<member>& members);
	void display_performance();
	static void reports(vector<member>& members);

};