#ifndef STUDENT_EXTENSION
#include "Student.h"

void Student::rateCourse(int index) {
	if (!(index <= Registered.count && index > 0))//check if the index is out of range
		return;//return if out of range
	int rate = 0;
	do {
		cout << "Enter Your Rating 0-5 (-1 to cancel) :"; cin >> rate; cin.ignore();//prompt user and get input
		if (rate == -1)//if rate is -1 (cancel value) 
			return;//return
	} while ((rate < 0) || (rate > 5));//continue asking for rate until user provides valid input
	if (getInfo(index) == true)//get info about course's rate status(rated or not)
		Registered.Courses[index - 1].info->changeRate(rate - Registered.Courses[index - 1].rategiven);//call changerate function with the difference between the new rating and old one as a parameter
	else
		Registered.Courses[index - 1].info->giverating(rate);//setting rate
	cout << "\nRate Updated\nThank You For Rating";
        //update rate values
	Registered.Courses[index - 1].isRated = true;
	Registered.Courses[index - 1].rategiven = rate;
	};
int Student::RegisterStatus() {
	switch (Registered.count)//check registered count
	{
		case MAX_REGISTER:return -1;//if it is at the maxmium return negative value
		default:return Registered.count;//if it is not maximum return the amount
	}
}
    //default Constructor
Student::Student() {
	info[0] = "undefinedName", info[1] = "undefinedSurname", info[2] = "undefinedAdress", card.cardholderfullname = "undefinedCardHolder", card.cvv = 0, card.date[0] = 01, card.date[1] = 25;
	Registered.count = 0;
	for (int i = 0; i < MAX_REGISTER; i++)
	{       
                //set up registered courses array values
		Registered.Courses[i].info = nullptr;
		Registered.Courses[i].rategiven = -1;
		Registered.Courses[i].isRated = false;
	}
        //setup card num
	for (int i = 0; i < 4; i++)
		card.four[i] = 0;
}
Student::Student(string name, string surname, string mail) {
	info[0] = name, info[1] = surname, info[2] = mail, card.cardholderfullname = "undefinedCardHolder", card.cvv = 0, card.date[0] = 01, card.date[1] = 25;
	Registered.count = 0;
	//set up registered courses array values
	for (int i = 0; i < MAX_REGISTER; i++)
		Registered.Courses[i].info = nullptr;
	//setup card num
	for (int i = 0; i < 4; i++)
		card.four[i] = 0;
}
Student::~Student() {
		cout << "\nLogged Out!\n";//logout message
	}
void Student::EnterInfo(int id, string infoIn) {
	switch (id){//choose the category to be entered
	case 1:case 2:case 3:
		info[id - 1] = infoIn; break;//sets name,surname,mail respectively
	default://
		cout << "User Login Failed\n\a";//tells user that the function call was wrong
		break;
	}
}
string Student::getInfo(string infotype) {
	if (infotype == "name") {//if the parameter is name
		return info[0];	//return name
	}
	else if (infotype == "surname") {//if the parameter is surname
		return info[1];		//return surname
	}
	else if (infotype == "mail") {//if the parameter is mail
		return info[2];		//return mail
	}if (infotype == "enteredpayment") {//if the parameter is entered payment
		if (card.cardholderfullname != "undefinedCardHolder")//check for the payment info value that is the most likely to be diffrent
			return "y";//if not the default value return "y" for yes
		else return "n";//if the default value return "n" for no
	}
	else//the case where it cant find the requested info
		cout << "\nRequested information not found\a\nCould not find \"" << infotype << "\"\n";
	return "Unknown";
}
bool Student::getInfo(int index) {
	return Registered.Courses[index - 1].isRated;//return the israted value
}
void Student::ListRegistered() {
	if (Registered.count <= 0){//if registered count 0 or less tell user that they havent registered
		cout << "The user has not registered to any courses.\n";
		return;
	}
	cout << "Registered Courses : \n";
	//loop that calls registered courses display function
	for (int i = 0; i < Registered.count; i++){
		cout << "Course " << i + 1 << endl;
		Registered.Courses[i].info->displayInfo();
	}
}
void Student::RegisterCourse(OnlineCourse* InputCourse) {
		if (RegisterStatus()==-1) {//if the register slots are full
			cout << "Maximum Registered Courses Reached\nCan not Register anymore!" << endl;
			return;//warn user and return
		}
		if (InputCourse->addStudent() != true)//if the add student function returned not true(success value)
		{
			cout << "Can't register course!";
			return;//warn user and return
		}
		Registered.Courses[Registered.count].info = InputCourse;//copy the pointer
		cout << "\nSuccesfully Registered Course in Register Slot " << ++Registered.count << " of "<<MAX_REGISTER << endl;//inform user the action was a success
	}
bool Student::detectDuplicate(OnlineCourse* InputCourse) {
	for (int i = 0; i < Registered.count; i++){//loop that checks the registered courses array for duplicates
		if (Registered.Courses[i].info == InputCourse)
			return true;//if same return true
	}
	return false;//if not detected any same value return false
}
istream& operator>> (istream& input, Student& stu)
{
	stu.card = { {0,0,0,0},0,{0,0},"" };//set values to zeroes
	string text = "";
	cout << "Enter Billing Information";//prompt user
	while (1) {
		int numcount = 0;
		cout << "\nCard Number\tXXXX_XXXX_XXXX_XXXX\n\t\t";
		getline(cin, text);
		for (int i = 0; i < text.size(); i++)
		{//This whole part can be avoided if i divided the selection system. again :(
			if (numcount == 16) {//if there are at least 16 numbers in input
				text = text.substr(0, i);//make sub string 
				break;//return
			}
			if (text[i] >= '0' && text[i] <= '9')//if the string member is a number
				numcount++;//increase number count
		}
		if (numcount != 16) {//if the number count is not 16 warn user
			cout << "Please Enter A Valid Card Number!\n";
		}
		else//if the number count is 16(successfull getting info)
			break;
	}
	int index = 0, nums = 0;
	for (int i = 0; i < text.size(); i++)
	{//This whole part is part of the section above still sadface but it works like miracle?
		if (text[i] >= '0' && text[i] <= '9') {//check string members value for numbers
			if (nums == 4)//if numbers are 4 increase index
				nums = 0, index++;
			stu.card.four[index] += (text[i] - '0') * powof10(3 - nums++);//increase string value with string member*10^(3-nums)
		}
	}
	//cout << "Enter Billing Information\nCard Number\tXXXX_XXXX_XXXX_XXXX\n\t\t";
	/*static_cast<void>(scanf("%4d%4d%4d%4d", &stu.card.four[0], &stu.card.four[1], &stu.card.four[2], &stu.card.four[3]));
	cin.ignore();
	cin.clear();*/
	/*BACKUP
		cout << "Enter Billing Information\nCard Number\tXXXX-XXXX-XXXX-XXXX\n\t\t";
		input >> stu.card.four[0]>> stu.card.four[1]>> stu.card.four[2] >> stu.card.four[3];
		*/
	while (1) {//get expiration date values
		cout << "Expiration Date MM/YY =";
		input >> stu.card.date[0]; cin.ignore(); input >> stu.card.date[1];//get input
		if (stu.card.date[0] >= 1 && stu.card.date[0] <= 12) {//check the month values
			if ((stu.card.date[1] == 24 && stu.card.date[0] == 12) || stu.card.date[1] >= 25)//check the year values
				break;
			else
				cout << "Expired Card!\n";//warn user
		}
		else
			cout << "Incorrect Date Format\n";//warn user
	}
	//keep the last 2 digits
	if (stu.card.date[1] >= 100)
		stu.card.date[1] %= 100;
	//get security code
	cout << "CVV ="; input >> stu.card.cvv;
	cout << "Full Name Of Card Holder :";
	cin.ignore();
	getline(cin, stu.card.cardholderfullname);//get card holder name

	return input;//return input stream
}
ostream& operator<< (ostream& output, Student& stu)
{
	printf("Billing Information\nCard Number = %.4d %.4d %.4d %.4d\nCVV = %.3d\nExpiration Date = %.2d/%.2d\nCard Holder Name : ", stu.card.four[0], stu.card.four[1], stu.card.four[2], stu.card.four[3], stu.card.cvv, stu.card.date[0], stu.card.date[1]);//print out info
	cout << stu.card.cardholderfullname;//print info
	return output;//return output stream
}
#endif