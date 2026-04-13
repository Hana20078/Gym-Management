#include "Workout_Program_Management.h"
#include<iostream>
#include <string>
using namespace std;

workout_programs::workout_programs(int nu, int d, string n, string tg, string el, string at,float sd, float ed) {
	num = nu;
	duration = d;
	name = n;
	target_goal = tg;
	exercise_list = el;
	assigned_trainer = at;
	start_date = sd;
	expiration_date = ed;
}
void workout_programs::chooseWorkout() {
	int choice;
	cout << "Choose a workout program from the following options: " << endl;
	cout << "1. Weight Loss Program" << endl;
	cout << "2. Muscle Gain Program" << endl;
	cout << "3. Strength Training Program" << endl;
	cout << "4. Cardio Program" << endl;
	cin >> choice;
	if (choice < 1 || choice > 4) {
		cout << "Invalid choice. Please choose a number between 1 and 4." << endl;
		return;
	}
	switch (choice)
	{
	case 1:
		num = 1;
		name = "Weight Loss Program";
		target_goal = "Weight Loss";
		exercise_list = "Cardio, HIIT, Circuit Training";
		assigned_trainer = "Trainer A";
		break;
	case 2:
		num = 2;
		name = "Muscle Gain Program";
		target_goal = "Muscle Gain";
		exercise_list = "Weightlifting, Resistance Training, Compound Exercises";
		assigned_trainer = "Trainer B";
		break;
	case 3:
		num = 3;
		name = "Strength Training Program";
		target_goal = "Strength Building";
		exercise_list = "Powerlifting, Olympic Lifting, Bodyweight Exercises";
		assigned_trainer = "Trainer C";
		break;
	case 4:
		num = 4;
		name = "Cardio Program";
		target_goal = "Cardiovascular Fitness";
		exercise_list = "Running, Cycling, Swimming, Jump Rope";
		assigned_trainer = "Trainer D";
		break;
	default:
		cout << "Invalid choice" << endl;
		break;
	}
}
void workout_programs::displayprogram() {
	cout << "ID:" << num << endl;
	cout << "Duration:" << duration << endl;
	cout << "Name:" << name << endl;
	cout << "Target Goal:" << target_goal << endl;
	cout << "Exercises:" << exercise_list << endl;
	cout << "Trainer:" << assigned_trainer << endl;
	cout << "Start Date:" << start_date << endl;
	cout << "Expiration Date:" << expiration_date << endl;
	cout << "======================================================";
}
Exercise::Exercise(string en, int s, int r, int rt) {
	exercise_name = en;
	sets = s;
	reps = r;
	rest_time = rt;
}
void Exercise::display() {
	cout << "Exercise Name:" << exercise_name << endl;
	cout << "Sets:" << sets << endl;
	cout << "Reps:" << reps << endl;
	cout << "Rest time:" << rest_time << endl;
	cout << "======================================================";
}

void workout_programs::setid()
{
    cout << "write workout's id  " << num;
	cin >> num;
}
void workout_programs::setstart_date()
{
	cout << "write workout's start date  " << start_date;
	cin >> start_date;
}

void workout_programs::setduration()
{
	cout << "write workout's duration  " << duration;
	cin >> duration;
}

void workout_programs::setname()
{
	cout << "write workout's name " << name;
	cin >> name;
}

void workout_programs::settarget_goal()
{
	cout << "write workout's target goal " << target_goal;
	cin >> target_goal;
}

void workout_programs::setexercise_list()
{
	cout << "write workout's exercise list " << exercise_list;
	cin >> exercise_list;
}

void workout_programs::setassigned_trainer()
{
	cout << "write workout's assigned trainer" << assigned_trainer;
	cin >> assigned_trainer;
}

int workout_programs::getid()
{
	cout << "workout's id is " ;
    return num;
}

int workout_programs::getduration()
{
	cout << "workout's duration is " ;
    return duration;
}

float workout_programs::getstart_date()
{
	return start_date;
}

string workout_programs::getname()
{
	cout << "workout's name is " ;
    return name;
}

string workout_programs::gettarget_goal()
{
	cout << "workout's target goal is " ;
    return target_goal;
}

string workout_programs::getexercise_list()
{
	cout << "workout's exercise list is " ;
    return exercise_list;
}

string workout_programs::getassigned_trainer()
{
	cout << "workout's assigned trainer is " ;
    return assigned_trainer;
}

float workout_programs::getexpiration_date()
{
	return start_date + duration;
}


