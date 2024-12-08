#ifndef SC_EXTENSION
#include "SoftwareCourses.h"

void SoftwareCourses::giverating(int ratei) {
		cout << (static_cast<float>(rate) / static_cast<float>(ratedppl)) << "->";//print old rate
		rate += ratei;//add new rate to existing rate
		ratedppl++;//increase rated people count
		cout << (static_cast<float>(rate) / static_cast<float>(ratedppl));//print new rate
	}
void SoftwareCourses::changeRate(int ratei) {
		cout << (static_cast<float>(rate) / static_cast<float>(ratedppl)) << "->";//print old rate
		rate += ratei;//add updated rate to existing rate
		cout << (static_cast<float>(rate) / static_cast<float>(ratedppl));//print new rate
	}
bool SoftwareCourses::checkPrefixID(string checkprefix, int checkid) {
		if (prefix != checkprefix)//compare prefix values
			return false;//if not same return false
		if (id != checkid)//compare id values
			return false;//if not same return false
		return true;//if function hasn't returned yet return true(the values are same)
	}
SoftwareCourses::SoftwareCourses():OnlineCourse() {
		Language = "undefinedL", Environment = "undefinedE", prefix = "undefinedp";
	}
SoftwareCourses::SoftwareCourses(int capacityi, int capacityii, int ratei, int ratedppli, int durationi, int leveli, int idi, string namei, string instructori, string prereqsi, double pricei, float discounti, string languagei, string prefixi, string environmenti) :OnlineCourse(capacityi, capacityii, ratei, ratedppli, durationi, leveli, idi, namei, instructori, prereqsi, pricei, discounti) {
		Language = languagei, Environment = environmenti, prefix = prefixi;
	}
void SoftwareCourses::displayInfo() 
	{
		cout << "Course Code: " << prefix << id << "\nCourse Name:\t" << CourseName << "\nInstructor:\t" << Instructor << "\nPrerequisites:\t" << Prerequisities << "\nCapacity =\t[" << capacity[1] << "/" << capacity[0] << "]\nRate =\t\t" << (static_cast<float>(rate) / static_cast<float>(ratedppl)) << "("<<ratedppl<<")"<<"\nDuration = \t" << duration << "\nPrice = \t" << price << "\tDiscount Rate = \t" << discount << " % \nLevel:\t\t" << level << "\nLanugage:\t" << Language << "\nEnvironment:\t" << Environment << endl;//print out information about course

		if (checkCapacity() <= 0)//if course is full
			cout << "\nCourse Full!!\n\n";//warn the user
	}

bool SoftwareCourses::addStudent() 
	{
		if (checkCapacity() <= 0) {//if course is full
			cout << "\n\aCourse Full!\nCan not add student to the course \"" << CourseName << "\"\nPlease contact the administrator or \"" << Instructor << "\"\n";
			return false;//warn the user and exit the function
		}
		else//else increase registered user count
			capacity[1]++;
		return true;//successfull execution
	}

int SoftwareCourses::checkCapacity() 
	{
		return capacity[0] - capacity[1];//return capacity
	};
//used to comppute diffrent class types with integers legacy code
// 
//int SoftwareCourses::getCalculatedID() 
//	{
//		return id + 10000;
//	}
#endif