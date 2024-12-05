#ifndef FUNCTION_REQ
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
#endif