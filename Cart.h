#ifndef STUDENT_EXTENSION
#include "Student.h"
#endif 
#ifndef OC_EXTENSION
#include "OnlineCourse.h"
#endif
#ifndef CART_EXTENSION
#define CART_EXTENSION
//cart Class
class Cart
{
public:
//public functions

	//Constructor
	Cart();
        //Function to check cart members if they exist Parameter Course Object Pointer
	bool detectDuplicate(OnlineCourse* InputCourse);
	//Function to get Cart Status
	int CartStatus();
	//Function to get Final Price(Total Discounted)
	double PayPrice();
	//Function to Add to Cart Parameter Course Object Pointer
	//Return True==Success!
	bool CartInsert(OnlineCourse* InputCourse);
	//Function to remove from cart Parameter : index to remove
	void RemoveCart(int index);
	//void RemoveCart_bak(int index); BACKUP FUNCTION

	//function to view cart contents
	void ViewCart();
	//function to register items to the user data 
	//Parameter User Data Object Adress
	//Return TRUE==SUCCESS
	bool RegisterItems(Student& User);
private:
	//private variables
	int inCart;
	OnlineCourse* CartList[MAX_CART];
};
#endif 
