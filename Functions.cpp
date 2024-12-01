#include "Functions.h"
double ApplyDiscount(OnlineCourse& ClassName) {
	return ClassName.price * ((100 - ClassName.discount) / 100);
}
int powof10(int i) {
	int val = 1;
	for (int j = 0; j < i; j++)
	{
		val *= 10;
	}
	return val;

}
void fixChoice(char* input) {
	if (*input >= 'A' && *input <= 'Z')
		*input = *input - 'A' + 'a';
}
OnlineCourse* findCourse(string Prefix, int id) {
	for (int i = 0; i < MAX_SOFT; i++)
		if (Software[i].checkPrefixID(Prefix, id) == true)
			return &Software[i];
		else {}
	for (int i = 0; i < MAX_ELEC; i++)
		if (Elective[i].checkPrefixID(Prefix, id) == true)
			return &Elective[i];
		else {}
	for (int i = 0; i < MAX_PROF; i++)
		if (Professional[i].checkPrefixID(Prefix, id) == true)
			return &Professional[i];
		else {}
	for (int i = 0; i < MAX_ELEC; i++)
		if (Language[i].checkPrefixID(Prefix, id) == true)
			return &Language[i];
		else {}
	return nullptr;
}