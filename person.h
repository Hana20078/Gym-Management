
#include<string>
using namespace std;
class person{

private :
	static int counter; //static to be affected by each object created
	string name;
	int id;
	int contactinfo;
	int age;//to check if member/trainer age is valid
	string gender;
public:
	person();
	person(string n, int id, int ag, int contactinfo,string g);
	void printer();
	void setname();
	void setcontactinfo();
	void setage();
	string getname();
	int getid();
	int getage();
	int getcontactinfo();
	





};

