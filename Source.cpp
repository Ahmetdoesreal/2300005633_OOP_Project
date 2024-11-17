#include <iostream>
#include <string>
using namespace std;

class OnlineCourse {
protected:
	int capacity[2],rate,ratedppl,duration,level,id;
	string CourseName, Instructor,Prerequisities;
public:
	double price;
	float discount;
	OnlineCourse() {
		CourseName = "undefinedC", Instructor = "undefinedI", Prerequisities = "undefinedP", capacity[0] = 10, capacity[1] = 0, rate = 0, ratedppl = 0, level = 0, id = 0, duration = 14, price = 100000, discount = 12.5;
	}
	virtual void displayInfo() = 0;
	virtual void addStudent() = 0;
	virtual int checkCapacity() = 0;
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
};
class SoftwareCourses :public OnlineCourse {
private:
	string Language,Environment,prefix;
public:
	SoftwareCourses() :OnlineCourse() {
		Language = "undefinedL", Environment = "undefinedE", prefix = "undefinedp";
	}
	// OnlineCourse aracýlýðýyla devralýndý
	void displayInfo() override
	{
		cout << "Course Name:\t" << CourseName << "\nInstructor:\t" << Instructor << "\nPrerequisites:\t" << Prerequisities << "\nCapacity =\t[" << capacity[1] << "/" << capacity[0] <<"\nRate =\t" << static_cast<float>(rate / 20) << "\nDuration =\t" << duration << "\nPrice =\t" << price << "\tDiscount Rate =\t" << discount << "%\nLevel:\t" << level << endl;
	}

	void addStudent() override
	{
		if (checkCapacity() <= 0)
			capacity[1]++;
		else
			cout << "\n\aCourse Full!\nCan not add student to the course \"" << CourseName << "\"\nPlease contact the administrator or \"" << Instructor << "\"\n";
	}

	int checkCapacity() override
	{
		return capacity[0] - capacity[1];
	}

};

class LanguageCourses :public OnlineCourse {
private:
	string Language,prefix;
	bool Native;
public:

	LanguageCourses():OnlineCourse() {
		Language = "undefinedL", Native = false, prefix = "undefinedp";
	}
	// OnlineCourse aracýlýðýyla devralýndý
	void displayInfo() override
	{
		cout << "Course Name:\t" << CourseName << "\nInstructor:\t" << Instructor << "\nPrerequisites:\t" << Prerequisities << "\nCapacity =\t[" << capacity[1] << "/" << capacity[0] << "\nRate =\t" << static_cast<float>(rate / 20) << "\nDuration =\t" << duration << "\nPrice =\t" << price << "\tDiscount Rate =\t" << discount << "%\nLevel:\t" << level << endl;
	}

	void addStudent() override
	{
		if (checkCapacity() <= 0)
			capacity[1]++;
		else
			cout << "\n\aCourse Full!\nCan not add student to the course \"" << CourseName << "\"\nPlease contact the administrator or \"" << Instructor << "\"\n";
	}

	int checkCapacity() override
	{
		return capacity[0] - capacity[1];
	}

};

class ProfessionalDevelopmentCourses :public OnlineCourse {
private:
	string Topics,prefix;
	bool Certification;
public:

	ProfessionalDevelopmentCourses() :OnlineCourse(){
		
		Topics = "undefinedT", Certification = false, prefix = "undefinedp";
	}
	// OnlineCourse aracýlýðýyla devralýndý
	void displayInfo() override
	{
		cout << "Course Name:\t" << CourseName << "\nInstructor:\t" << Instructor << "\nPrerequisites:\t" << Prerequisities << "\nCapacity =\t[" << capacity[1] << "/" << capacity[0] << "\nRate =\t" << static_cast<float>(rate / 20) << "\nDuration =\t" << duration << "\nPrice =\t" << price << "\tDiscount Rate =\t" << discount << "%\nLevel:\t" << level << endl;
	}

	void addStudent() override
	{
		if (checkCapacity() <= 0)
			capacity[1]++;
		else
			cout << "\n\aCourse Full!\nCan not add student to the course \"" << CourseName << "\"\nPlease contact the administrator or \"" << Instructor << "\"\n";
	}

	int checkCapacity() override
	{
		return capacity[0] - capacity[1];
	}

};

class Electives :public OnlineCourse {
private:
	bool Departmental;
	string Origin[2];

public:
	Electives():OnlineCourse() {
		
		Origin[0] = "undefined0", Departmental = false, Origin[1] = "undefined1";
	}
	// OnlineCourse aracýlýðýyla devralýndý
	void displayInfo() override
	{
		cout << "Course Name:\t" << CourseName << "\nInstructor:\t" << Instructor << "\nPrerequisites:\t" << Prerequisities << "\nCapacity =\t[" << capacity[1] << "/" << capacity[0] << "\nRate =\t" << static_cast<float>(rate / 20) << "\nDuration =\t" << duration << "\nPrice =\t" << price << "\tDiscount Rate =\t" << discount << "%\nLevel:\t" << level << endl;
	}

	void addStudent() override
	{
		if (checkCapacity() <= 0)
			capacity[1]++;
		else
			cout << "\n\aCourse Full!\nCan not add student to the course \"" << CourseName << "\"\nPlease contact the administrator or \"" << Instructor << "\"\n";
	}

	int checkCapacity() override
	{
		return capacity[0] - capacity[1];
	}

};

double ApplyDiscount(OnlineCourse& ClassName) {
	return ClassName.price * ((100 - ClassName.discount) / 100);
}
class Student
{
public:
	Student() {
		info[0] = "undefinedName", info[1] = "undefinedSurname", info[2] = "undefinedAdress";
	}

private:
	string info[3];
	int registered[100] = { 0 };
};
class Cart
{
public:
	Cart() {
		LanguageCourses Language[5];
		SoftwareCourses Software[20];
		ProfessionalDevelopmentCourses Professional[10];
		Electives Elective[40];
	}
	void ViewCart() {
		for (int i = 0; i < inCart; i++)
		{
		}
	}
private:
	int inCart=0, Items[3][2] = { {0} };
};
int main() {
}