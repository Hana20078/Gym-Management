
#ifndef PERSON_H
#define PERSON_H

#include <string>

using namespace std;

class person {

protected:
	static int counter; // static to be affected by each object created
	string name;
	int id;
	int contactinfo;
	int age; // to check if member/trainer age is valid
	string gender;
public:
	person();
	person(string n, int ag, int con,string g);
	void printer();
	void setname();
	void setcontactinfo();
	void setage();
	std::string getname();
	int getid();
	int getage();
	int getcontactinfo();
};

#endif // PERSON_H
