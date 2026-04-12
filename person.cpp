#include "person.h"
#include<string>
#include<iostream>
int person:: counter = 1000
;
person::person() {
	cout << "please enter name:"<<endl;
	cin >> name;
	cout << "please enter your age : "<<endl;
	cin >> age;
	cout << "please enter your contact info : "<<endl;
	cout << contactinfo;
	id =++ counter;
	cout << "enter your gender : " << endl;
	cin >> gender;

}
person::person(string n, int idd, int ag, int con,string g) {
	name = n;
	age = ag;
	contactinfo = con;
	gender = g;


}


void person::printer() {
	cout << "name  : " << name << endl;
	cout << "id :" << id << endl;
	cout << "contact info :" << contactinfo << endl;
	cout << "age :" << age << endl;

}

void person::setname() 
{
	cout << "enter new name";
	cin >> name;

}

void person::setcontactinfo()
{
	cout << "enter new contact info ";
	cin >> contactinfo;
}

void person::setage() {
	cout << "enter new age";
	cin >> age;
}

string person::getname() {
	return name;
}

int person::getid()
{
	return age;
}

int person::getage() {
	return age;
}


int person::getcontactinfo() {
	return contactinfo;
}




