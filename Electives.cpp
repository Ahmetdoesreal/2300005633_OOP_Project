#ifndef E_EXTENSION
#include "Electives.h"
	void Electives::changeRate(int ratei)  {
		cout << (static_cast<float>(rate) / static_cast<float>(ratedppl)) << "->";
		rate += ratei;
		cout << (static_cast<float>(rate) / static_cast<float>(ratedppl));
	}
	void Electives::giverating(int ratei) {
		cout << (static_cast<float>(rate) / static_cast<float>(ratedppl)) << "->";
		rate += ratei;
		ratedppl++;
		cout << (static_cast<float>(rate) / static_cast<float>(ratedppl));
	}
	bool Electives::checkPrefixID(string checkprefix, int checkid) {
		if (Origin[1] != checkprefix)
			return false;
		if (id != checkid)
			return false;
		return true;
	}
	Electives::Electives() :OnlineCourse() {

		Origin[0] = "undefined0", Departmental = false, Origin[1] = "undefined";
	}
	Electives::Electives(int capacityi, int capacityii, int ratei, int ratedppli, int durationi, int leveli, int idi, string namei, string instructori, string prereqsi, double pricei, float discounti, string origini, string prefixi, bool depi) :OnlineCourse(capacityi, capacityii, ratei, ratedppli, durationi, leveli, idi, namei, instructori, prereqsi, pricei, discounti) {
		Origin[0] = origini, Departmental = depi, Origin[1] = prefixi;
	}
	void Electives::displayInfo() 
	{
		cout << "Course Code: " << Origin[1] << id << "\nCourse Name:\t" << CourseName << "\nInstructor:\t" << Instructor << "\nPrerequisites:\t" << Prerequisities << "\nCapacity =\t[" << capacity[1] << "/" << capacity[0] << "]\nRate =\t\t" << (static_cast<float>(rate) / static_cast<float>(ratedppl)) << "(" << ratedppl << ")" << "\nDuration =\t" << duration << "\nPrice =\t" << price << "\tDiscount Rate =\t\t" << discount << "%\nLevel:\t" << level << "\tIs it Departmental= ";
		if (Departmental == true)
			cout << "Yes\n" << "Origin Department" << Origin[0] << endl;
		else
			cout << "No" << endl;

		if (checkCapacity() <= 0)
			cout << "\nCourse Full!!\n\n";
	}
	bool Electives::addStudent() 
	{
		if (checkCapacity() <= 0) {
			cout << "\n\aCourse Full!\nCan not add student to the course \"" << CourseName << "\"\nPlease contact the administrator or \"" << Instructor << "\"\n";
			return false;
		}
		else
			capacity[1]++;
		return true;
	}
	int Electives::checkCapacity()
	{
		return capacity[0] - capacity[1];
	}
	int Electives::getCalculatedID()
	{
		return id + 10000;
	}
#endif