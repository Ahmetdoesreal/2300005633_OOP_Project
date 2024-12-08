#ifndef OC_EXTENSION
#include "OnlineCourse.h"
#endif
#ifndef FUNCTION_REQ
#include "Functions.h"
#endif 

#ifndef STUDENT_EXTENSION
#define STUDENT_EXTENSION
//student class
class Student
{
public:
	//operator overladings
	//
	friend istream& operator>> (istream& input, Student& stu);
	friend ostream& operator<< (ostream& output, Student& stu);
	void rateCourse(int index);
	int RegisterStatus();
	Student();
	Student(string name, string surname, string mail);
	~Student();
	void EnterInfo(int id, string infoIn);
	string getInfo(string infotype);
	bool getInfo(int index);
	void ListRegistered();

	void RegisterCourse(OnlineCourse* InputCourse);
	bool detectDuplicate(OnlineCourse* InputCourse);
private:
	string info[3];
	struct RegisterInfo {
		int count = 0;
		struct Course{
			int rategiven;
			bool isRated;
			OnlineCourse* info;
		}Courses[MAX_REGISTER]{};
	}Registered;
	struct BillingInfo {
		int four[4]{};
		int cvv{};
		int date[2]{};
		string cardholderfullname;
	}card;
};
istream& operator>> (istream& input, Student& stu);
ostream& operator<< (ostream& output, Student& stu);
#endif