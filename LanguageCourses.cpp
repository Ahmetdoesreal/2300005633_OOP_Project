#ifndef LC_EXTENSION
#include "LanguageCourses.h"
void LanguageCourses::giverating(int ratei) {
		cout << (static_cast<float>(rate) / static_cast<float>(ratedppl)) << "->";
		rate += ratei;
		ratedppl++;
		cout << (static_cast<float>(rate) / static_cast<float>(ratedppl));
	}
void LanguageCourses::changeRate(int ratei) {
		cout << (static_cast<float>(rate) / static_cast<float>(ratedppl)) << "->";
		rate += ratei;
		cout << (static_cast<float>(rate) / static_cast<float>(ratedppl));
	}
bool LanguageCourses::checkPrefixID(string checkprefix, int checkid) {
		if (prefix != checkprefix)
			return false;
		if (id != checkid)
			return false;
		return true;
	}
LanguageCourses::LanguageCourses() :OnlineCourse() {
		Language = "undefinedL", Native = false, prefix = "LANG";
	}
LanguageCourses::LanguageCourses(int capacityi, int capacityii, int ratei, int ratedppli, int durationi, int leveli, int idi, string namei, string instructori, string prereqsi, double pricei, float discounti, string languagei, string prefixi, bool nativei) :OnlineCourse(capacityi, capacityii, ratei, ratedppli, durationi, leveli, idi, namei, instructori, prereqsi, pricei, discounti) {
		Language = languagei, Native = nativei, prefix = prefixi;
	}
void LanguageCourses::displayInfo() 
	{
		cout << "Course Code: " << prefix << id << "\nCourse Name:\t" << CourseName << "\nInstructor:\t" << Instructor << "\nPrerequisites:\t" << Prerequisities << "\nCapacity =\t[" << capacity[1] << "/" << capacity[0] << "]\nRate =\t\t" << (static_cast<float>(rate) / static_cast<float>(ratedppl)) << "(" << ratedppl << ")" << "\nDuration =\t" << duration << "\nPrice =\t" << price << "\tDiscount Rate =\t" << discount << "%\nLevel:\t" << level << "\nLanugage:" << Language << "\nNative Teacher=";
		if (Native == true)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;

		if (checkCapacity() <= 0)
			cout << "\nCourse Full!!\n\n";
	}
bool LanguageCourses::addStudent() 
	{
		if (checkCapacity() <= 0) {
			cout << "\n\aCourse Full!\nCan not add student to the course \"" << CourseName << "\"\nPlease contact the administrator or \"" << Instructor << "\"\n";
			return false;
		}
		else
			capacity[1]++;
		return true;
	}
int LanguageCourses::checkCapacity() 
	{
		return capacity[0] - capacity[1];
	}
int LanguageCourses::getCalculatedID() 
	{
		return id + 10000;
	}
#endif