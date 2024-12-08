#ifndef STUDENT_EXTENSION
#include "Student.h"
#endif 
#ifndef OC_EXTENSION
#include "OnlineCourse.h"
#endif
#ifndef CART_EXTENSION
#define CART_EXTENSION
class Cart
{
public:
	bool detectDuplicate(OnlineCourse* InputCourse);
	int CartStatus();
	double PayPrice();
	Cart();
	bool CartInsert(OnlineCourse* InputCourse);
	void RemoveCart(int index);
	//void RemoveCart_bak(int index);
	void ViewCart();
	bool RegisterItems(Student& User);
private:
	int inCart;
	OnlineCourse* CartList[MAX_CART];
};
#endif 
