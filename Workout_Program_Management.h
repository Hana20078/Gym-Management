#pragma once
#include <string>

using namespace std;

class workout_programs {
private:
	int num, duration;
    string name, target_goal, exercise_list, assigned_trainer;
	float start_date, expiration_date;
public:
    workout_programs(int nu, int d, string n, string tg, string el, string at ,float sd,float ed);
	void chooseWorkout();
	void displayprogram();
	void setid();
	void setduration();
	void setname();
	void settarget_goal();
	void setexercise_list();
	void setassigned_trainer();
    int getid();
	int getduration();
	string getname();
	string gettarget_goal();
	string getexercise_list();
	string getassigned_trainer();
	void setexpiration_date();
	float getexpiration_date();
	void setstart_date();
	float getstart_date();
	void save_file();
	void load_file();
};

class Exercise
{
private:
	string exercise_name;
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
	string getname();
	string gettarget_goal();
	std::string getexercise_list();
	std::string getassigned_trainer();
	Exercise(std::string en, int s, int r, int rt);
	void display();
	void save_file();
	void load_file();
};

