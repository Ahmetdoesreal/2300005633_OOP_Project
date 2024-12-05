#ifndef STUDENT_EXTENSION
#include "Student.h"
void Student::rateCourse(int index) {
	if (!(index <= Registered.count && index > 0))
		return;
	int rate = 0;
	do {
		cout << "Enter Your Rating 0-5 (-1 to cancel) :"; cin >> rate; cin.ignore();
		if (rate == -1)
			return;
	} while ((rate < 0) || (rate > 5));
	if (getInfo(index) == true)
		Registered.Courses[index - 1].info->changeRate(rate - Registered.Courses[index - 1].rategiven);
	else
		Registered.Courses[index - 1].info->giverating(rate);
	cout << "\nRate Updated\nThank You For Rating";
	Registered.Courses[index - 1].isRated = true;
	Registered.Courses[index - 1].rategiven = rate;
	};
int Student::RegisterStatus() {
		switch (Registered.count)
		{
		case 0:return 0;
		case 99:return -1;
		default:return Registered.count;
		}
	}
Student::Student() {
		info[0] = "undefinedName", info[1] = "undefinedSurname", info[2] = "undefinedAdress", card.cardholderfullname = "undefinedCardHolder", card.cvv = 0, card.date[0] = 01, card.date[1] = 25;
		Registered.count = 0;
		for (int i = 0; i < 99; i++)
		{
			Registered.Courses[i].info = nullptr;
			Registered.Courses[i].rategiven = -1;
			Registered.Courses[i].isRated = false;

		}
		for (int i = 0; i < 4; i++)
			card.four[i] = 0;
	}
Student::Student(string name, string surname, string mail) {
		info[0] = name, info[1] = surname, info[2] = mail, card.cardholderfullname = "undefinedCardHolder", card.cvv = 0, card.date[0] = 01, card.date[1] = 25;
		Registered.count = 0;
		for (int i = 0; i < 99; i++)
			Registered.Courses[i].info = nullptr;
		for (int i = 0; i < 4; i++)
			card.four[i] = 0;
	}
Student::~Student() {
		cout << "\nLogged Out!";
	}
void Student::EnterInfo(int id, string infoIn) {
		switch (id)
		{
		case 1:case 2:case 3:
			info[id - 1] = infoIn; break;
		default:
			cout << "User Login Failed\n\a";
			break;
		}
	}
string Student::getInfo(string infotype) {
		if (infotype == "name") {
			return info[0];
		}
		else if (infotype == "surname") {
			return info[1];
		}
		else if (infotype == "mail") {
			return info[2];
		}if (infotype == "enteredpayment") {
			if (card.cardholderfullname != "undefinedCardHolder")
				return "y";
			else return "n";
		}
		else
			cout << "\nRequested information not found\a\nCould not find \"" << infotype << "\"\n";
		return "Unknown";
	}
bool Student::getInfo(int index) {
		return Registered.Courses[index - 1].isRated;
	}
void Student::ListRegistered() {
		if (Registered.count <= 0)
		{
			cout << "The user has not registered to any courses.\n";
			return;
		}
		cout << "Registered Courses : \n";
		for (int i = 0; i < Registered.count; i++)
		{
			cout << "Course " << i + 1 << endl;
			Registered.Courses[i].info->displayInfo();
		}
	}
void Student::RegisterCourse(OnlineCourse* InputCourse) {
		if (Registered.count >= 99) {
			cout << "Maximum Registered Courses Reached\nCan not Register anymore!" << endl;
			return;
		}
		if (InputCourse->addStudent() != true)
		{
			cout << "Can't register course!";
			return;
		}
		Registered.Courses[Registered.count].info = InputCourse;
		cout << "\nSuccesfully Registered Course in Register Slot " << ++Registered.count << " of 99" << endl;
	}
bool Student::detectDuplicate(OnlineCourse* InputCourse) {
		for (int i = 0; i < Registered.count; i++)
		{
			if (Registered.Courses[i].info == InputCourse)
				return true;
		}
		return false;
	}
istream& operator>> (istream& input, Student& stu)
{
	stu.card = { {0,0,0,0},0,{0,0},"" };


	string text = "";
	cout << "Enter Billing Information";
	while (1) {
		int numcount = 0;
		cout << "\nCard Number\tXXXX_XXXX_XXXX_XXXX\n\t\t";
		getline(cin, text);
		for (int i = 0; i < text.size(); i++)
		{//This whole part can be avoided if i divided the selection system. again :(
			if (numcount == 16) {
				text = text.substr(0, i);
				break;
			}
			if (text[i] >= '0' && text[i] <= '9') {
				numcount++;
			}
		}
		if (numcount != 16) {
			cout << "Please Enter A Valid Card Number!\n";
		}
		else
			break;
	}
	int index = 0, nums = 0;
	for (int i = 0; i < text.size(); i++)
	{//This whole part is part of the section above still sadface but it works like miracle?
		if (text[i] >= '0' && text[i] <= '9') {
			if (nums == 4)
				nums = 0, index++;
			stu.card.four[index] += (text[i] - '0') * powof10(3 - nums++);
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
	while (1) {
		cout << "Expiration Date MM/YY =";
		input >> stu.card.date[0]; cin.ignore(); input >> stu.card.date[1];
		if (stu.card.date[0] >= 1 && stu.card.date[0] <= 12) {
			if ((stu.card.date[1] == 24 && stu.card.date[0] == 12) || stu.card.date[1] >= 25)
				break;
			else
				cout << "Expired Card!\n";
		}
		else
		{
			cout << "Incorrect Date Format\n";
		}
	}
	if (stu.card.date[1] >= 100)
		stu.card.date[1] %= 100;
	cout << "CVV ="; input >> stu.card.cvv;
	cout << "Full Name Of Card Holder :";
	cin.ignore();
	getline(cin, stu.card.cardholderfullname);

	return input;
}
ostream& operator<< (ostream& output, Student& stu)
{
	printf("Billing Information\nCard Number = %.4d %.4d %.4d %.4d\nCVV = %.3d\nExpiration Date = %.2d/%.2d\nCard Holder Name : ", stu.card.four[0], stu.card.four[1], stu.card.four[2], stu.card.four[3], stu.card.cvv, stu.card.date[0], stu.card.date[1]);
	cout << stu.card.cardholderfullname;
	return output;
}
#endif