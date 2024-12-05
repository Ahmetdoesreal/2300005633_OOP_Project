#ifndef FUNCTION_REQ
#define FUNCTION_REQ
#ifndef CourseData
#include "CourseData.h"
#endif
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
OnlineCourse* findCourse(string Prefix, int id);
#endif
