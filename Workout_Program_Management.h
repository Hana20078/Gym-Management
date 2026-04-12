#pragma once
#include <string>

using namespace std;

class workout_programs {
private:
	int id, duration;
	std::string name, target_goal, exercise_list, assigned_trainer;
public:
	workout_programs(int i, int d, std::string n, std::string tg, std::string el, std::string at);
	void displayprogram();
};

class Exercise
{
private:
	std::string exercise_name;
	int sets, reps, rest_time;
public:
	void setid();
	void setduration();
	void setname();
	void settarget_goal();
	void setexercise_list();
	void setassigned_trainer();
	int getid();
	int getduration();
	std::string getname();
	std::string gettarget_goal();
	std::string getexercise_list();
	std::string getassigned_trainer();
	Exercise(std::string en, int s, int r, int rt);
	void display();
};

