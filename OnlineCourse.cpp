#ifndef OC_EXTENSION//check
#include "OnlineCourse.h"//inclusion

	//messed up while making the data swapping here to fix it :)
	//basically capacity[0] and capacity[1] kinda got swapped
	
OnlineCourse::OnlineCourse(int capacityavalible, int capacityoccupied, int ratei, int ratedppli, int durationi, int leveli, int idi, string namei, string instructori, string prereqsi, double pricei, float discounti) {//parameterized constructor
		capacity[0] = capacityoccupied, capacity[1] = capacityavalible, rate = ratei, ratedppl = ratedppli, duration = durationi, level = leveli, id = idi, CourseName = namei, Instructor = instructori, Prerequisities = prereqsi, price = pricei, discount = discounti;
	}
OnlineCourse::OnlineCourse() {//default constructor
		CourseName = "undefinedC", Instructor = "undefinedI", Prerequisities = "undefinedP", capacity[0] = 10, capacity[1] = 0, rate = 0, ratedppl = 0, level = 0, id = 0, duration = 14, price = 100000, discount = 12.5;
	}
#endif//end of condition