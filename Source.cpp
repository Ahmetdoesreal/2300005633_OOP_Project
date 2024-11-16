#include <iostream>
#include <string>
using namespace std;
class OnlineCourse{
private:
    /* data */
public:

    OnlineCourse(/* args */);
    ~OnlineCourse();
};

class SoftwareCourses:public OnlineCourse{
private:
    /* data */
public:
    SoftwareCourses(/* args */);
    ~SoftwareCourses();
};
class LanguageCourses:public OnlineCourse{
private:
    /* data */
public:
    LanguageCourses(/* args */);
    ~LanguageCourses();
};
class ProfessionalDevelopmentCourses:public OnlineCourse
{
private:
    /* data */
public:
    ProfessionalDevelopmentCourses(/* args */);
    ~ProfessionalDevelopmentCourses();
};
class Electives:public OnlineCourse
{
private:
    /* data */
public:
    Electives(/* args */);
    ~Electives();
};