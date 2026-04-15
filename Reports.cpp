#include "Reports.h"
#include "Workout_Program_Management.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// ====== Total workouts ======
void Reports::total_workouts()
{
    ifstream file("workout_programs.txt");

    if (!file)
    {
        cout << "No data found!\n";
        return;
    }

    string line;
    cout << "===== ALL WORKOUTS =====\n";

    while (getline(file, line))
    {
        cout << line << endl;
    }

    file.close();
}

// ====== Count workouts ======
void Reports::count_workouts()
{
    ifstream file("workout_programs.txt");

    string line;
    int count = 0;

    while (getline(file, line))
    {
        count++;
    }

    cout << "Total Workouts: " << count << endl;
}

// ====== Welcome message ======
void showReportsHeader()
{
    cout << "Welcome to the Reports Section" << endl;
}
void Reports::expired_memberships()
{
    cout << "Not implemented yet\n";
}

void Reports::monthly_revenue()
{
    cout << "Not implemented yet\n";
}

void Reports::display_performance()
{
    cout << "Not implemented yet\n";
}