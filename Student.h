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
        //Constructors
        Student();
	Student(string name, string surname, string mail);
        //destructor(logout)
        ~Student();
	//operator overladings
	//extraction operator overload Parameters input stream, student object
	friend istream& operator>> (istream& input, Student& stu);
	//insertion operator overload Parameters output stream, student object
	friend ostream& operator<< (ostream& output, Student& stu);
        //Function to rate Courses Registered Parameter:Index of Course
	void rateCourse(int index);
        //Function to check Registration Status
	int RegisterStatus();
	//Function to Enter Information, Parameters: ID, string Information
	//ID table: 1 - Name , 2 - Surname 3 - Mail
	void EnterInfo(int id, string infoIn);
	//Function for accesing information
	//returns name ,surname ,mail,if payment is entered
	//Paramter String , Return type String
	string getInfo(string infotype);
	//Functions for accesing information
	//Returns if the index of registered courses is rated
	//Paramter Index of Register
	bool getInfo(int index);
	//function to list registered courses
	void ListRegistered();
	//function to register course parameter pointer to an course object
	void RegisterCourse(OnlineCourse* InputCourse);
	//function to check duplicate of a course parameter pointer to an course object
	bool detectDuplicate(OnlineCourse* InputCourse);
private:
	//private variables

	//Information variable
	//[0]=Name,[1]=Surname,[2]=Mail Adress
	string info[3];
	//Registration information
	struct RegisterInfo {
		int count = 0;
		struct Course{
			int rategiven;
			bool isRated;
			OnlineCourse* info;
		}Courses[MAX_REGISTER]{};
	}Registered;
	//Payment Information 
	struct BillingInfo {
		//card numbers
		int four[4]{};
		//security code
		int cvv{};
		//[0]=Month,[1]=Year
		int date[2]{};
		string cardholderfullname;
	}card;
};
#endif