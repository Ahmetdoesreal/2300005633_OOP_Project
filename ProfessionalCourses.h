#ifndef OC_EXTENSION
#include "OnlineCourse.h"
#endif 
#ifndef PDC_EXTENSION
#define PDC_EXTENSION

class ProfessionalDevelopmentCourses :public OnlineCourse {
private:
	string Topics, prefix;
	bool Certification;
public:
	ProfessionalDevelopmentCourses();
	// Parameter List
	//Total Capacity,Attending Students,Total Rate,Rated People,Duration,Level,ID,Course Name,Instructor Name,Prerequisites,Price,Discount Rate,Topics Learned,Prefix,If there is a certificate
	ProfessionalDevelopmentCourses(int capacityi, int capacityii, int ratei, int ratedppli, int durationi, int leveli, int idi, string namei, string instructori, string prereqsi, double pricei, float discounti, string topici, string prefixi, bool certi);

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