#ifndef CART_EXTENSION
#include "Cart.h"
bool Cart::detectDuplicate(OnlineCourse* InputCourse) {
	for (int i = 0; i < inCart; i++)//check the cart contents 
	{
		if (CartList[i] == InputCourse)//check the pointing adress of pointers 
			return true;//if same return true
	}
	return false;//if the cart contents are not the same with the parameter pointer return false
}
int Cart::CartStatus() {
	switch (inCart){//check incart count
	case MAX_CART:return -1;
	default:return inCart;
	}
}
double Cart::PayPrice() {
	double pr = 0;//price value
	for (int i = 0; i < inCart; i++)
	{
		pr += ApplyDiscount(*CartList[i]);//increase price value with the calulated value
	}
	return pr;//reutrn price value
}

Cart::Cart() {
	inCart = 0;//zero in cart items
	for (int i = 0; i < MAX_CART; i++)//loop to set pointers to null
		CartList[i] = nullptr;
}
bool Cart::CartInsert(OnlineCourse* InputCourse) {
	if (CartStatus() != -1) {//if the cart is not full
		if (InputCourse->checkCapacity() >= 1){//and there is capacity in the course
			if (detectDuplicate(InputCourse) != false) {//and the course already in the registered slots
				cout << "\nItem Exists In Cart\n";//warn user
				return false;//and return with not successfull
			}
			//if the course is not in cart
			CartList[inCart] = InputCourse;//copy the adress of the input to cart
			inCart++;//increase cart items count
		}
		else {
			cout << "\nCourse Full!\n";
			return false;//if the course is full return false
		}
	}
	else//if the cart is full
	{
		cout << "Cart full!\nPlease try removing some items or contact your Administrator" << endl;
		return false;//return false
	}
	cout << "\nOperation Successfull\n";
	return true;
}
void Cart::RemoveCart(int index) {
	if (index <= 0||index-- > inCart) {//if the index is in range (arrays cant have negative index and the index of arrays dont go higher to size of array itself)
		//index-- is to decrease index to work with arrays since they start from 0
		//also the end user typically starts counting from 1 
		cout << "Invalid Index";
		return;
	}
	//if the previous check is successfull
	for (int i = index; i < inCart; i++)//starting from the input every following pointer will get the value from the pointer that is next in the index and continue untill it reaches end of the inCart value (end of used array members)
	{
		CartList[i] = CartList[i + 1];//setting the values
	}
	CartList[--inCart] = nullptr;//the last used member is set to null
}
//void Cart::RemoveCart_bak(int index) {
//	if (index - 1 > inCart) {
//		cout << "The Cart does not contain that item\n";
//		return;
//	}
//	switch (index)
//	{
//	case 1:
//		switch (inCart)
//		{
//		case 1:CartList[index - 1] = nullptr; inCart--; break;
//		case 2:CartList[index - 1] = CartList[index]; CartList[index] = nullptr; inCart--; break;
//		case 3:CartList[index - 1] = CartList[index]; CartList[index] = CartList[index + 1]; CartList[index + 1] = nullptr; inCart--; break;
//		default:
//			cout << "There has been an error occured.Please contact Administrator.\a"; break;
//		}
//		break;
//	case 2:
//		switch (inCart)
//		{
//		case 2:CartList[index] = nullptr; inCart--; break;
//		case 3:CartList[index - 1] = CartList[index]; CartList[index] = nullptr; inCart--; break;
//		default:
//			cout << "There has been an error occured.Please contact Administrator.\a"; break;
//		}
//		break;
//	case 3:
//		switch (inCart)
//		{
//		case 3:CartList[index - 1] = nullptr; inCart--; break;
//		default:cout << "There has been an error occured.Please contact Administrator.\a";
//			break;
//		}
//		break;
//	}
//}
void Cart::ViewCart() {
		//check for empty cart
		if (CartStatus() == 0)
		{
			cout << "Cart Is Empty\n";
			return;
		}
		//initialize variables
		double totalprice[2] = {};
		cout << "In Cart" << endl;
		//prints out each cart item untill the end of the used array members(array size is defined by MAX_CART but actual used space could be less if the user didnt add to their cart)
		for (int i = 0; i < inCart; i++)
		{
			cout << "Item " << i+1 << endl;
			(*CartList[i]).displayInfo();//calling info funciton
			totalprice[0] += CartList[i]->price;//increasing total price
			totalprice[1] += ApplyDiscount(*CartList[i]);//increasing total price after discount
		}
		cout << "\nTotal Price Of Cart:\t" << totalprice[0] << "\nAfter Discount:\t" << totalprice[1] << "\nAverage Discount Ratio:" << 100 - (totalprice[1] / totalprice[0] * 100) << "%" << endl;//informing user
	}
bool Cart::RegisterItems(Student& User) {
	//checking if user can accept any more courses
	if (User.RegisterStatus()==-1)
	{
		cout << "Can't register any more courses! Register is full";
		return false;
	}
		//loop to check both for duplicate courses and if the cart items will exceed the register slots
		for (int i = 0; i < inCart; i++)
		{
			if (User.detectDuplicate(CartList[i]) != false) {
				cout << "Item " << i + 1 << " in Cart is already registered, Please Remove it and try again.\n";
				return false;
			}
			if (User.RegisterStatus()+i>=MAX_REGISTER)
			{
				cout << "Can't register any more courses! Please Make Sure Your Cart Has Less than or Equal to "<<i<<" items";
				return false;
			}
		}
		//actual register process
		for (int i = 0; i < inCart; i++)
		{
			User.RegisterCourse(CartList[i]);//pass the adress to user object
			CartList[i] = nullptr;//reset the adress of cart item to null
		}
		inCart = 0;//reset in cart items to 0
		return true;
	}
#endif