#include "Trainer_Management.h"
#include <iostream>
#include<fstream>

using namespace std;

Trainer_Management::Trainer_Management()
{
    // Initialize defaults
    specailty = "";
    salary = 0.0;
    comisson = 0.0f;
    for (int i = 0; i < 10; ++i) assignedmemberlist[i] = "";
    trainer_activity.hours_worked = 0;
    trainer_activity.session_duration = 0;
}
void Trainer_Management::createnewtrainer()
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
void Trainer_Management::load_file(vector<Trainer_Management>& trainers) {
    ifstream tfile("trainerfile.txt");

    if (!tfile.is_open()) {
        cout << "Could not open trainer file.\n";
        return;
    }

    trainers.clear();

    while (true) {
        Trainer_Management temp;

        if (!(tfile >> temp.name
            >> temp.age
            >> temp.specailty
            >> temp.id
            >> temp.gender
            >> temp.salary
            >> temp.comisson
            >> temp.contactinfo
            >> temp.trainer_activity.hours_worked
            >> temp.trainer_activity.session_duration)) {
            break;
        }

        for (int i = 0; i < 10; i++) {
            tfile >> temp.assignedmemberlist[i];
        }

        trainers.push_back(temp);
    }

    tfile.close();
}
void Trainer_Management::save_file()
{
    ofstream tfile;
    tfile.open("trainerfile.txt", ios::app);
    if (tfile.is_open()) {
        tfile << name << " " << age << " " << specailty << " " << id << " " << gender << " " << salary << " " << comisson << " " << contactinfo << " " << trainer_activity.hours_worked << " " << trainer_activity.session_duration << " ";
        for (int i = 0; i < 10; i++)
            tfile << assignedmemberlist[i] << " ";
        tfile << "\n";
    }
    tfile.close();
}
int Trainer_Management::getTrainerIndex(vector<Trainer_Management>& trainers, int id) {
    for (int i = 0; i < trainers.size(); i++) {
        if (trainers[i].getid() == id) {
            return i;
        }
    }
    return -1;
}
void Trainer_Management::getTrainerIndex1(vector<Trainer_Management>& trainers) {
    int id1;
    cout << "Enter Trainer ID: ";
    cin >> id1;

    int index = getTrainerIndex(trainers, id1);

    if (index != -1) {
        trainers[index].printer();
    }
    else {
        cout << "Trainer not found." << endl;
    }
}
void Trainer_Management::saveAllTrainersToFile(const vector<Trainer_Management>& trainers)
{
    ofstream tfile("trainerfile.txt", ios::trunc);

    if (!tfile.is_open()) {
        cout << "Could not open trainer file.\n";
        return;
    }

    for (int i = 0; i < trainers.size(); i++) {
        tfile << trainers[i].name << " "
            << trainers[i].age << " "
            << trainers[i].specailty << " "
            << trainers[i].id << " "
            << trainers[i].gender << " "
            << trainers[i].salary << " "
            << trainers[i].comisson << " "
            << trainers[i].contactinfo << " "
            << trainers[i].trainer_activity.hours_worked << " "
            << trainers[i].trainer_activity.session_duration << " ";

        for (int j = 0; j < 10; j++) {
            tfile << trainers[i].assignedmemberlist[j] << " ";
        }

        tfile << "\n";
    }

    tfile.close();
}
void Trainer_Management::deleteTrainer(vector<Trainer_Management>& trainers)
{
    int id1;
    cout << "Enter trainer ID to delete: ";
    cin >> id1;

    int index = getTrainerIndex(trainers, id1);

    if (index == -1) {
        cout << "Trainer not found.\n";
        return;
    }

    trainers.erase(trainers.begin() + index);
    saveAllTrainersToFile(trainers);

    cout << "Trainer deleted successfully!\n";
}
void Trainer_Management::updateTrainer(vector<Trainer_Management>& trainers)
{
    int id1;
    cout << "Enter trainer ID to update: ";
    cin >> id1;

    int index = getTrainerIndex(trainers, id1);

    if (index == -1) {
        cout << "Trainer not found.\n";
        return;
    }

    int choice;
    cout << "\n===== Update Trainer Menu =====\n";
    cout << "1. Update Name\n";
    cout << "2. Update Age\n";
    cout << "3. Update Gender\n";
    cout << "4. Update Contact Info\n";
    cout << "5. Update Specialty\n";
    cout << "6. Update Salary\n";
    cout << "7. Update Commission\n";
    cout << "8. Update Activity\n";
    cout << "9. Update Assigned Members\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
    case 1:
        cout << "Enter new name: ";
        cin >> trainers[index].name;
        break;

    case 2:
        cout << "Enter new age: ";
        cin >> trainers[index].age;
        break;

    case 3:
        cout << "Enter new gender: ";
        cin >> trainers[index].gender;
        break;

    case 4:
        cout << "Enter new contact info: ";
        cin >> trainers[index].contactinfo;
        break;

    case 5:
        cout << "Enter new specialty: ";
        cin >> trainers[index].specailty;
        break;

    case 6:
        cout << "Enter new salary: ";
        cin >> trainers[index].salary;
        break;

    case 7:
        cout << "Enter new commission: ";
        cin >> trainers[index].comisson;
        break;

    case 8:
        cout << "Enter new hours worked: ";
        cin >> trainers[index].trainer_activity.hours_worked;
        cout << "Enter new session duration: ";
        cin >> trainers[index].trainer_activity.session_duration;
        break;

    case 9:
        cout << "Enter 10 assigned members:\n";
        for (int i = 0; i < 10; i++) {
            cout << "Member " << i + 1 << ": ";
            cin >> trainers[index].assignedmemberlist[i];
        }
        break;

    default:
        cout << "Invalid choice.\n";
        return;
    }

    saveAllTrainersToFile(trainers);
    cout << "Trainer updated successfully!\n";
}
