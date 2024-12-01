#include "ProfessionalCourses.h"
void ProfessionalDevelopmentCourses::changeRate(int ratei) {
		cout << (static_cast<float>(rate) / static_cast<float>(ratedppl)) << "->";
		rate += ratei;
		cout << (static_cast<float>(rate) / static_cast<float>(ratedppl));
	}
void ProfessionalDevelopmentCourses::giverating(int ratei) {
		cout << (static_cast<float>(rate) / static_cast<float>(ratedppl)) << "->";
		rate += ratei;
		ratedppl++;
		cout << (static_cast<float>(rate) / static_cast<float>(ratedppl));
	}
bool ProfessionalDevelopmentCourses::checkPrefixID(string checkprefix, int checkid) {
		if (prefix != checkprefix)
			return false;
		if (id != checkid)
			return false;
		return true;
	}
ProfessionalDevelopmentCourses::ProfessionalDevelopmentCourses() :OnlineCourse() {

		Topics = "undefinedT", Certification = false, prefix = "undefinedp";
	}
ProfessionalDevelopmentCourses::ProfessionalDevelopmentCourses(int capacityi, int capacityii, int ratei, int ratedppli, int durationi, int leveli, int idi, string namei, string instructori, string prereqsi, double pricei, float discounti, string topici, string prefixi, bool certi) :OnlineCourse(capacityi, capacityii, ratei, ratedppli, durationi, leveli, idi, namei, instructori, prereqsi, pricei, discounti) {
		Topics = topici, Certification = certi, prefix = prefixi;
	}
void ProfessionalDevelopmentCourses::displayInfo() 
	{
		cout << "Course Code: " << prefix << id << "\nCourse Name:\t" << CourseName << "\nInstructor:\t" << Instructor << "\nPrerequisites:\t" << Prerequisities << "\nCapacity =\t[" << capacity[1] << "/" << capacity[0] << "]\nRate =\t\t" << (static_cast<float>(rate) / static_cast<float>(ratedppl)) << "\nDuration =\t" << duration << "\nPrice =\t" << price << "\tDiscount Rate =\t" << discount << "%\nLevel:\t" << level << "\nTopics:" << Topics << "\nCertification=";
		if (Certification == true)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;

		if (checkCapacity() <= 0)
			cout << "\nCourse Full!!\n\n";
	}
bool ProfessionalDevelopmentCourses::addStudent() 
	{
		if (checkCapacity() <= 0) {
			cout << "\n\aCourse Full!\nCan not add student to the course \"" << CourseName << "\"\nPlease contact the administrator or \"" << Instructor << "\"\n";
			return false;
		}
		else
			capacity[1]++;
		return true;
	}
int ProfessionalDevelopmentCourses::checkCapacity() 
	{
		return capacity[0] - capacity[1];
	}
int ProfessionalDevelopmentCourses::getCalculatedID() 
	{
		return id + 10000;
	}