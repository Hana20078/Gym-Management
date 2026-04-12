
#ifndef PERSON_H
#define PERSON_H

#include <string>

using namespace std;

class person {

private:
	static int counter; // static to be affected by each object created
	std::string name;
	int id;
	int contactinfo;
	int age; // to check if member/trainer age is valid
	std::string gender;
public:
	person();
	person(std::string n, int ag, int con, std::string g);
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
