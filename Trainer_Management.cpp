#include "Trainer_Management.h"
#include<iostream>
#include "person.h"
#include<string>
using namespace std;

Trainer_Management::Trainer_Management(string n, int idd, int ag, int con, string spec, double sal, float com, activity ta, member list[10])
{
	specailty = spec;
	comisson = com;
	trainer_activity.hours_worked = ta.hours_worked;
	trainer_activity.session_duration = ta.session_duration;

}

Trainer_Management::Trainer_Management()
{
	cout << "enter trainer specaility: "<<endl;
	cin >> specailty;
	cout << "enter salary:"<<endl;
	cin >> salary;
	cout << "enter commison :" << endl;
	cin >> comisson;
	cout << "enter trainer activity (hours worked & ssesion duration) :" << endl;
	cin >> trainer_activity.hours_worked >> trainer_activity.session_duration;
		


}
 void Trainer_Management::printer() {
	 person::printer();
	 cout << "Trainer specialty : " << specailty;
		cout << "Trainer salary : " << salary << endl;
	 cout << "trainer comisson :" << comisson << endl;
	 cout << "trainer activty : hours worked ------>" << trainer_activity.hours_worked << "duration of ssesion ------>"<< trainer_activity.session_duration;



}

 void Trainer_Management::setspeciality() {
	 cout << "enter speciality : ";
		 cin >> specailty;
 }

 void Trainer_Management::setsalary()
 {
	 cout << "enter salary :";
	 cin >> salary;
 }

 void Trainer_Management::setassignedmemberlist() {

 }
 void Trainer_Management::setcomisson()
 {
 }
 void Trainer_Management::setactivity() {
	 cout << "enter trainer activity (hours worked & ssesion duration) :" << endl;
	 cin >> trainer_activity.hours_worked >> trainer_activity.session_duration;
 }

 double Trainer_Management::getsalary()
 {
	 return salary;
 }

 float Trainer_Management::getcomisson()
 {
	 return comisson;
 }

 member Trainer_Management::getassignedmemberlist()
 {
	 return ;
 }

 activity Trainer_Management::getactivity()
	 
 {
	 activity a1;
	a1.hours_worked= trainer_activity.hours_worked;
	a1.session_duration = trainer_activity.session_duration;
		return a1;
 }
 
 
 