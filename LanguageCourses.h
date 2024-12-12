#ifndef OC_EXTENSION
#include "OnlineCourse.h"
#endif 
#ifndef LC_EXTENSION
#define LC_EXTENSION
class LanguageCourses :public OnlineCourse {
private:
	string Language, prefix;
	bool Native;
public:
	//constructors
	LanguageCourses();
	//Parameter List
	//Total Capacity,Attending Students,Total Rate,Rated People,Duration,Level,ID,Course Name,Instructor Name,Prerequisites,Price,Discount Rate,Language Of Course,Prefix,If the Teacher is a Native Speaker
	LanguageCourses(int capacityi, int capacityii, int ratei, int ratedppli, int durationi, int leveli, int idi, string namei, string instructori, string prereqsi, double pricei, float discounti, string languagei, string prefixi, bool nativei);

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