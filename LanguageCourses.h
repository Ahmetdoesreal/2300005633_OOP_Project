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
	void giverating(int ratei)override;
	void changeRate(int ratei)override;
	bool checkPrefixID(string checkprefix, int checkid);
	LanguageCourses();
	LanguageCourses(int capacityi, int capacityii, int ratei, int ratedppli, int durationi, int leveli, int idi, string namei, string instructori, string prereqsi, double pricei, float discounti, string languagei, string prefixi, bool nativei);
	void displayInfo() override;
	bool addStudent() override;
	int checkCapacity() override;
	//int getCalculatedID() override;
};
#endif