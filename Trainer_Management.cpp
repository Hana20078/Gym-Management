#include "Trainer_Management.h"
#include <iostream>
#include<fstream>

using namespace std;

Trainer_Management::Trainer_Management(string n, int idd, int ag, int con, string spec, double sal, float com, activity ta, member list[10], string g) : person(n, ag, con, g)
{
    specailty = spec;
    salary = sal;
    comisson = com;
    trainer_activity.hours_worked = ta.hours_worked;
    trainer_activity.session_duration = ta.session_duration;
}
Trainer_Management::Trainer_Management()
{
    person::createnewclient();

    cout << "enter trainer specaility: " << endl;
    cin >> specailty;
    cout << "enter salary:" << endl;
    cin >> salary;
    cout << "enter commison :" << endl;
    cin >> comisson;
    cout << "enter trainer activity (hours worked & ssesion duration) :" << endl;
    cin >> trainer_activity.hours_worked >> trainer_activity.session_duration;
}
void Trainer_Management::printer() {
    person::printer();
    cout << "Trainer specialty : " << specailty << endl;
    cout << "Trainer salary : " << salary << endl;
    cout << "trainer comisson :" << comisson << endl;
    cout << "trainer activty : hours worked ------>" << trainer_activity.hours_worked << " duration of ssesion ------>" << trainer_activity.session_duration << endl;



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
    cout << "enter assigned members (up to 10)" << endl;
    for (int i = 0; i < 10; ++i) {
        cout << "assigned member number " << i << ": ";
        cin >> assignedmemberlist[i];
    }
}
void Trainer_Management::setcomisson()
{
    cout << "enter comisson:";
    cin >> comisson;
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
    // Return first member placeholder; adjust API if you need to return array
    member m;
    return m;
}
activity Trainer_Management::getactivity()
     
 {
     activity a1;
    a1.hours_worked= trainer_activity.hours_worked;
    a1.session_duration = trainer_activity.session_duration;
         return a1;
 }
void Trainer_Management::load_file() {
    ifstream 

 
 }
void Trainer_Management::save_file()
 {
     ofstream tfile;
     tfile.open("trainerfile.txt");
     if (tfile) {
         tfile << name << "   " << age << "  " << specailty << "  " << id << "  " << gender << "  " << salary << "  " << comisson <<"  " << contactinfo;
         for (int i = 0; i < 10; i++) {
             tfile << assignedmemberlist[i]<<"  ";
             
             
   }
     }
     tfile.close();
 }
 
 
 