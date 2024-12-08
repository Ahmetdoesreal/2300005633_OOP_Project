#ifndef OC_EXTENSION//check
#include "OnlineCourse.h"//inclusion
#endif //endofcheck
#ifndef SC_EXTENSION//check
#define SC_EXTENSION//flag
//creating a class with public inheritance from the main class OnlineCourse
class SoftwareCourses :public OnlineCourse {
private:
	//private variables
	string Language, Environment, prefix;
public:
	//constructors
	SoftwareCourses();
	SoftwareCourses(int capacityi, int capacityii, int ratei, int ratedppli, int durationi, int leveli, int idi, string namei, string instructori, string prereqsi, double pricei, float discounti, string languagei, string prefixi, string environmenti);
	//Public and functions
	//Adds a new rate Parameters: Rate
	void giverating(int ratei)override;
	//Updates a rate Parameters: Rate
	void changeRate(int ratei)override;
	//Checks Courses ID with Prefix, Parameters : Prefix, ID
	bool checkPrefixID(string checkprefix, int checkid);
	//Displays Information About Course
	void displayInfo() override;
	//Adds a Student to Course
	bool addStudent() override;
	//Checks Course Capacity
	int checkCapacity() override;
	//int getCalculatedID() override; unused
};
#endif