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