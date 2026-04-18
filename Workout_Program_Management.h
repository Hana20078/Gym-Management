#pragma once
#include <string>

using namespace std;

class workout_programs {
public:
	int num, duration;
	string name, target_goal, exercise_list, assigned_trainer, trainer_performance;
	float start_date, expiration_date, price;
	bool payment;
    workout_programs(int nu, int d, string n, string tg, string el, string at ,float sd,float ed,float p,bool pay,string tp);
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
	void workoutprogrammanagement();
	void setprice();
	float getprice();
	void setpayment();
	bool getpayment();
	void save_file();
	void load_file();
	void settrainerperformance();
	string gettrainerperformance();

};

class Exercise
{
private:
	string exercise_name, target_goal, assigned_trainer, exercise_list;
	int sets, reps, rest_time, id, duration;
public:
	Exercise(string en, int s, int r, int rt, string tg, string el, string at, int i, int d);
	Exercise(std::string en, int s, int r, int rt);
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
	void display();
	void save_file();
	void load_file();
	void Exercisesystem();
};

