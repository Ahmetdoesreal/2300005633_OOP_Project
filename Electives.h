#ifndef OC_EXTENSION
#include "OnlineCourse.h"
#endif 
#ifndef E_EXTENSION
#define E_EXTENSION
//child class electives with public inheritance
class Electives :public OnlineCourse {
private:
	//private values

	bool Departmental;//if the course is departmental
	string Origin[2];//index 0 which dep. index 1=prefix

public:
	//constructors
	Electives();
	//Parameter List
	//Total Capacity,Attending Students,Total Rate,Rated People,Duration,Level,ID,Course Name,Instructor Name,Prerequisites,Price,Discount Rate,Origin Department,Prefix Of Course,Departmental Check
	Electives(int capacityi, int capacityii, int ratei, int ratedppli, int durationi, int leveli, int idi, string namei, string instructori, string prereqsi, double pricei, float discounti, string origini, string prefixi, bool depi);

	//Updates a rate Parameters: Rate
	void changeRate(int ratei)override;
	//Adds a new rate Parameters: Rate
	void giverating(int ratei)override;
	//Checks Courses ID with Prefix, Parameters : Prefix, ID
	bool checkPrefixID(string checkprefix, int checkid);
	//Displays Information About Course
	void displayInfo() override;
	//Adds a Student to Course
	bool addStudent() override;
	//Checks Course Capacity
	int checkCapacity() override;
};

#endif 