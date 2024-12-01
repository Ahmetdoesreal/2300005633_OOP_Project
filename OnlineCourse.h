#include "Preprocessor.h"
#ifndef OC_EXTENSION
#define OC_EXTENSION
class OnlineCourse {
protected:
	int capacity[2], rate, ratedppl, duration, level, id;
	string CourseName, Instructor, Prerequisities;
public:
	double price;
	float discount;

	OnlineCourse(int capacityavalible, int capacityoccupied, int ratei, int ratedppli, int durationi, int leveli, int idi, string namei, string instructori, string prereqsi, double pricei, float discounti);
	OnlineCourse();
	virtual void displayInfo() = 0;
	virtual bool addStudent() = 0;
	virtual int checkCapacity() = 0;
	virtual int getCalculatedID() = 0;
	virtual bool checkPrefixID(string checkprefix, int checkid) = 0;
	virtual void giverating(int ratei) = 0;
	virtual void changeRate(int ratei) = 0;
};

#endif