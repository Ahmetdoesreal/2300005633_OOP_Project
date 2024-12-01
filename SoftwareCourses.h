#ifndef OC_EXTENSION
#include "OnlineCourse.h"
#endif 
#ifndef SC_EXTENSION
#define SC_EXTENSION
class SoftwareCourses :public OnlineCourse {
private:
	string Language, Environment, prefix;
public:
	void giverating(int ratei)override;
	void changeRate(int ratei)override;
	bool checkPrefixID(string checkprefix, int checkid);
	SoftwareCourses();
	SoftwareCourses(int capacityi, int capacityii, int ratei, int ratedppli, int durationi, int leveli, int idi, string namei, string instructori, string prereqsi, double pricei, float discounti, string languagei, string prefixi, string environmenti);
	void displayInfo() override;
	bool addStudent() override;
	int checkCapacity() override;
	int getCalculatedID() override;
};
#endif