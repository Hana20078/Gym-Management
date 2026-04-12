#include "person.h"
#include "Trainer_Management.h"
class member:public person
{
private:
	int regsetion_date;
	int expiration_date;
	Trainer_Management Assigned_trainer;
	bool status_active;


	member() {
		cout << "enter member regestriation : " << endl;
		cin >> regsetion_date;
		cout << "enter expiration date : " << endl;
		cin>>expiration_date;
		cout << "enter your assigned trianer : " << endl;
		cin >> Assigned_trainer;

	}



	




};

