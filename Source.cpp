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
		Language = "undefinedL", Native = false, prefix = "LANG";
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
	Student(string name, string surname, string mail) {
		info[0] = name, info[1] = surname, info[2] = mail;
	}
	~Student() {
		cout << "\nLogged Out!";
	}
private:
	string info[3];
	int registered[100] = { 0 };
};
class Cart
{
public:
	Cart() {
		inCart = 0;
		for (int i = 0; i < 3; i++)
		{
			CartList[i] = nullptr;
		}
	}
	void CartInsert(OnlineCourse* InputCourse) {
		if (inCart < 3)
			CartList[inCart - 1] = InputCourse;
		else
			cout << "Cart full!\nPlease try removing some items or contact your Administrator" << endl;
	}
	void RemoveCart(int index) {
		if (index - 1 > inCart) {
			cout << "The Cart does not contain that course\n";
			return;
		}
		switch (index)
		{
		case 1:
			switch (inCart)
			{
			case 1:CartList[index - 1] = nullptr; break;
			case 2:CartList[index - 1] = CartList[index]; CartList[index] = nullptr; break;
			case 3:CartList[index - 1] = CartList[index]; CartList[index] = CartList[index + 1]; CartList[index + 2] = nullptr;
			default:
				cout << "There has been an error occured.Please contact Administrator.\a"; break;
			}
			break;
		case 2:
			switch (inCart)
			{
			case 2:CartList[index - 1] = CartList[index]; CartList[index] = nullptr; break;
			case 3:CartList[index - 1] = CartList[index]; CartList[index] = nullptr; break;
			default:
				cout << "There has been an error occured.Please contact Administrator.\a"; break;
			}
			break;
		case 3:
			switch (inCart)
			{
			case 3:CartList[index] = nullptr;
			default:cout << "There has been an error occured.Please contact Administrator.\a";
				break;
			}
			break;
		}
	}
	void ViewCart() {
		for (int i = 0; i < inCart; i++)
		{
			(*CartList[i]).displayInfo();
		}
	}
private:
	int inCart;
	OnlineCourse* CartList[3];
};
int main() {
	int EXIT_FLAG = -1,LoggedIn=-1;
	string name, surname, mail;
	cout << "Enter Login Information\nName:\t"; cin >> name;
	cin.ignore();
	cout << "Surname:\t"; cin >> surname;
	cin.ignore();
	cout << "Mail Adress:\t"; cin >> mail;
	do
	{
		Student User(name, surname, mail);


	} while (EXIT_FLAG==1);
	cout << " test";
}