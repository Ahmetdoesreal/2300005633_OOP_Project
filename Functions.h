#ifndef FUNCTION_REQ
#define FUNCTION_REQ
#ifndef SC_EXTENSION
#include "SoftwareCourses.h"
#endif 
#ifndef LC_EXTENSION
#include "LanguageCourses.h"
#endif 
#ifndef PDC_EXTENSION
#include "ProfessionalCourses.h"
#endif
#ifndef E_EXTENSION
#include "Electives.h"
#endif
//Apply Discount Function Parameter : Adress Of Object
double ApplyDiscount(OnlineCourse& ClassName);
//Function to Compute Powers of 10 Parameter: Exponent
int powof10(int i);
//Function to make character values fit to a standard Parameter: Pointer To Input Char
void fixChoice(char* input);
//Template Function to Find an Existing Course
template <typename Category>//Telling Compiler that Category Name is a template
//Parameters : Prefix , ID , Object Array ,Array Size
Category* findCourse2(string Prefix, int id, Category* CategoryName, int Max) {
	for (int i = 0; i < Max; i++)//basic loop that goes thorugh the array
		if (CategoryName[i].checkPrefixID(Prefix, id) == true)//checks if the inputted prefix and if are the same
			return &CategoryName[i];//if successfull returns the adress of the object
	return nullptr;//but if not successfull returns null pointer
}
#endif
