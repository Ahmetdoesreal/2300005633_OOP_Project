#ifndef FUNCTION_REQ
#include "Functions.h"
double ApplyDiscount(OnlineCourse& ClassName) {
	return ClassName.price * ((100 - ClassName.discount) / 100);//gets values from the classes and returns the discounted price
}
int powof10(int i) {
	int val = 1;//value variable
	for (int j = 0; j < i; j++)//basic loop 
		val *= 10;//multiply value with itself and 10
	return val;//return value when done
}
void fixChoice(char* input) {
	if (*input >= 'A' && *input <= 'Z')//check if the input is a uppercase letter
		*input = *input - 'A' + 'a';//convert to lovercase letter
}
#endif