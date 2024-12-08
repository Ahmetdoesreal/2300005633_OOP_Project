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

double ApplyDiscount(OnlineCourse& ClassName);
int powof10(int i);
void fixChoice(char* input);
template <typename Category>Category* findCourse2(string Prefix, int id, Category* CategoryName, int Max) {
	for (int i = 0; i < Max; i++)
		if (CategoryName[i].checkPrefixID(Prefix, id) == true)
			return &CategoryName[i];
	return nullptr;
}
#endif
