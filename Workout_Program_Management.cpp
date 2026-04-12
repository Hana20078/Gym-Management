#include "Workout_Program_Management.h"
#include<iostream>
#include <string>
using namespace std;

workout_programs::workout_programs(int i, int d, string n, string tg, string el, string at) {
	id = i;
	duration = d;
	name = n;
	target_goal = tg;
	exercise_list = el;
	assigned_trainer = at;
}
void workout_programs::displayprogram() {
	cout << "ID:" << id << endl;
	cout << "Duration:" << duration << endl;
	cout << "Name:" << name << endl;
	cout << "Target Goal:" << target_goal << endl;
	cout << "Exercises:" << exercise_list << endl;
	cout << "Trainer:" << assigned_trainer << endl;
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
    cout << "write workout's id  " << id;
	cin >> id;
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
	cout << "workout's id is " << id;
    return id;
}

int workout_programs::getduration()
{
	cout << "workout's duration is " << duration;
    return duration;
}

string workout_programs::getname()
{
	cout << "workout's name is " << name;
    return name;
}

string workout_programs::gettarget_goal()
{
	cout << "workout's target goal is " << target_goal;
    return target_goal;
}

string workout_programs::getexercise_list()
{
	cout << "workout's exercise list is " << exercise_list;
    return exercise_list;
}

string workout_programs::getassigned_trainer()
{
	cout << "workout's assigned trainer is " << assigned_trainer;
    return assigned_trainer;
}
