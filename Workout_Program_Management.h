using namespace std; 
class workout_programs {
private:
	int id, duration;
	string name, target_goal, exercise_list, assigned_trainer;
public:
	workout_programs(int i, int d, string n, string tg, string el, string at);
	void displayprogram();
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
	string getexercise_list();
	string getassigned_trainer();
	Exercise(string en, int s, int r, int rt);
	void display();
};

