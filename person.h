

using namespace std;
class person{

private :
	static int counter; //static to be affected by each object created
	string name;
	int id;
	int contactinfo;
	int age;//to check if member/trainer age is valid
public:
	person();
	person(string n, int id, int ag, int contactinfo);
	void printer();
	void setname();
	void setcontactinfo();
	void setage();
	string getname();
	int getid();
	int getage();
	int getcontactinfo();
	





};

