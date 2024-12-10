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
	void changeRate(int ratei)override;
	void giverating(int ratei)override;
	bool checkPrefixID(string checkprefix, int checkid);
	ProfessionalDevelopmentCourses();

	ProfessionalDevelopmentCourses(int capacityi, int capacityii, int ratei, int ratedppli, int durationi, int leveli, int idi, string namei, string instructori, string prereqsi, double pricei, float discounti, string topici, string prefixi, bool certi);
	void displayInfo() override;
	bool addStudent() override;
	int checkCapacity() override;
	//int getCalculatedID() override;
};
#endif 