#include "SoftwareCourses.h"
void SoftwareCourses::giverating(int ratei) {
		cout << (static_cast<float>(rate) / static_cast<float>(ratedppl)) << "->";
		rate += ratei;
		ratedppl++;
		cout << (static_cast<float>(rate) / static_cast<float>(ratedppl));
	}
void SoftwareCourses::changeRate(int ratei) {
		cout << (static_cast<float>(rate) / static_cast<float>(ratedppl)) << "->";
		rate += ratei;
		cout << (static_cast<float>(rate) / static_cast<float>(ratedppl));
	}
bool SoftwareCourses::checkPrefixID(string checkprefix, int checkid) {
		if (prefix != checkprefix)
			return false;
		if (id != checkid)
			return false;
		return true;
	}
SoftwareCourses::SoftwareCourses():OnlineCourse() {
		Language = "undefinedL", Environment = "undefinedE", prefix = "undefinedp";
	}
SoftwareCourses::SoftwareCourses(int capacityi, int capacityii, int ratei, int ratedppli, int durationi, int leveli, int idi, string namei, string instructori, string prereqsi, double pricei, float discounti, string languagei, string prefixi, string environmenti) :OnlineCourse(capacityi, capacityii, ratei, ratedppli, durationi, leveli, idi, namei, instructori, prereqsi, pricei, discounti) {
		Language = languagei, Environment = environmenti, prefix = prefixi;
	}
void SoftwareCourses::displayInfo() 
	{
		cout << "Course Code: " << prefix << id << "\nCourse Name:\t" << CourseName << "\nInstructor:\t" << Instructor << "\nPrerequisites:\t" << Prerequisities << "\nCapacity =\t[" << capacity[1] << "/" << capacity[0] << "]\nRate =\t\t" << (static_cast<float>(rate) / static_cast<float>(ratedppl)) << "\nDuration =\t" << duration << "\nPrice =\t" << price << "\tDiscount Rate =\t" << discount << "%\nLevel:\t\t" << level << "\nLanugage:\t" << Language << "\nEnvironment:\t" << Environment << endl;

		if (checkCapacity() <= 0)
			cout << "\nCourse Full!!\n\n";
	}

bool SoftwareCourses::addStudent() 
	{
		if (checkCapacity() <= 0) {
			cout << "\n\aCourse Full!\nCan not add student to the course \"" << CourseName << "\"\nPlease contact the administrator or \"" << Instructor << "\"\n";
			return false;
		}
		else
			capacity[1]++;
		return true;
	}

int SoftwareCourses::checkCapacity() 
	{
		return capacity[0] - capacity[1];
	};
int SoftwareCourses::getCalculatedID() 
	{
		return id + 10000;
	}
