#include "Preprocessor.h"//preprocessor header file inclusion.
#ifndef OC_EXTENSION //online course check
#define OC_EXTENSION//flag
//OnlineCourse Class itself
class OnlineCourse {
protected:
	//stored values that are only avalible to main class and derived classes
	int capacity[2], rate, ratedppl, duration, level, id;
	string CourseName, Instructor, Prerequisities;
public:
	//stored values that are accessible from everywhere
	double price;
	float discount;
	//constructors
	OnlineCourse(int capacityavalible, int capacityoccupied, int ratei, int ratedppli, int durationi, int leveli, int idi, string namei, string instructori, string prereqsi, double pricei, float discounti);
	OnlineCourse();
	//functions
	//Displays Information About Course
	virtual void displayInfo() = 0;
	//Adds a Student to Course
	virtual bool addStudent() = 0;
	//Checks Course Capacity
	virtual int checkCapacity() = 0;
	//virtual int getCalculatedID() = 0; unused
	
	//Checks Courses ID with Prefix, Parameters : Prefix, ID
	virtual bool checkPrefixID(string checkprefix, int checkid) = 0;
	//Adds a new rate Parameters: Rate
	virtual void giverating(int ratei) = 0;
	//Updates a rate Parameters: Rate
	virtual void changeRate(int ratei) = 0;
};

#endif//end condition