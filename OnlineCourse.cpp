#include "OnlineCourse.h"

	//messed up while making the data swapping here to fix it :)
OnlineCourse::OnlineCourse(int capacityavalible, int capacityoccupied, int ratei, int ratedppli, int durationi, int leveli, int idi, string namei, string instructori, string prereqsi, double pricei, float discounti) {
		capacity[0] = capacityoccupied, capacity[1] = capacityavalible, rate = ratei, ratedppl = ratedppli, duration = durationi, level = leveli, id = idi, CourseName = namei, Instructor = instructori, Prerequisities = prereqsi, price = pricei, discount = discounti;
	}
OnlineCourse::OnlineCourse() {
		CourseName = "undefinedC", Instructor = "undefinedI", Prerequisities = "undefinedP", capacity[0] = 10, capacity[1] = 0, rate = 0, ratedppl = 0, level = 0, id = 0, duration = 14, price = 100000, discount = 12.5;
	}
	//void displayInfo() {
	//	cout << "Course Name:\t" << CourseName << "\nInstructor:\t" << Instructor << "\nPrerequisites:\t" << Prerequisities << "\nCapacity =\t[" << capacity[1] << "/" << capacity[0] << "]\nRate =\t" << static_cast<float>(rate / 20) << "\nDuration =\t" << duration << "\nPrice =\t" << price << "\tDiscount Rate =\t" << discount << "%\nLevel:\t" << level << endl;
	//}
	//void addStudent() {
	//	if (checkCapacity()<=0)
	//		capacity[1]++;
	//	else
	//		cout << "\n\aCourse Full!\nCan not add student to the course \"" << CourseName << "\"\nPlease contact the administrator or \"" << Instructor << "\"\n";
	//}
	//int checkCapacity() {
	//	return capacity[0] - capacity[1];
	//}

