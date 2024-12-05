#ifndef CART_EXTENSION
#include "Cart.h"
bool Cart::detectDuplicate(OnlineCourse* InputCourse) {
		for (int i = 0; i < inCart; i++)
		{
			if (CartList[i] == InputCourse)
				return true;
		}
		return false;
	}
int Cart::CartStatus() {
		switch (inCart)
		{
		case 3:return -1;
		default:return inCart;
		}
	}
double Cart::PayPrice() {
		double pr = 0;
		for (int i = 0; i < inCart; i++)
		{
			pr += ApplyDiscount(*CartList[i]);
		}
		return pr;
	}
Cart::Cart() {
		inCart = 0;
		for (int i = 0; i < 3; i++)
		{
			CartList[i] = nullptr;
		}
	}
bool Cart::CartInsert(OnlineCourse* InputCourse) {
		if (CartStatus() != -1) {
			if (InputCourse->checkCapacity() >= 1)
			{
				if (detectDuplicate(InputCourse) != false) {
					cout << "\nItem Exists In Cart\n";
					return false;
				}
				CartList[inCart] = InputCourse;
				inCart++;
			}
			else return false;
		}
		else
		{
			cout << "Cart full!\nPlease try removing some items or contact your Administrator" << endl;
			return false;
		}
		cout << "\nOperation Successfull\n";
		return true;
	}
void Cart::RemoveCart(int index) {
		if (index - 1 > inCart) {
			cout << "The Cart does not contain that item\n";
			return;
		}
		switch (index)
		{
		case 1:
			switch (inCart)
			{
			case 1:CartList[index - 1] = nullptr; inCart--; break;
			case 2:CartList[index - 1] = CartList[index]; CartList[index] = nullptr; inCart--; break;
			case 3:CartList[index - 1] = CartList[index]; CartList[index] = CartList[index + 1]; CartList[index + 1] = nullptr; inCart--; break;
			default:
				cout << "There has been an error occured.Please contact Administrator.\a"; break;
			}
			break;
		case 2:
			switch (inCart)
			{
			case 2:CartList[index] = nullptr; inCart--; break;
			case 3:CartList[index - 1] = CartList[index]; CartList[index] = nullptr; inCart--; break;
			default:
				cout << "There has been an error occured.Please contact Administrator.\a"; break;
			}
			break;
		case 3:
			switch (inCart)
			{
			case 3:CartList[index - 1] = nullptr; inCart--; break;
			default:cout << "There has been an error occured.Please contact Administrator.\a";
				break;
			}
			break;
		}
	}
void Cart::ViewCart() {
		if (CartStatus() == 0)
		{
			cout << "Cart Is Empty\n";
			return;
		}
		double totalprice[2] = { 0 };
		cout << "In Cart" << endl;
		for (int i = 0; i < inCart; i++)
		{
			cout << "Item " << i << endl;
			(*CartList[i]).displayInfo();
			totalprice[0] += CartList[i]->price;
			totalprice[1] += ApplyDiscount(*CartList[i]);
		}
		cout << "\nTotal Price Of Cart:\t" << totalprice[0] << "\nAfter Discount:\t" << totalprice[1] << "\nAverage Discount Ratio:" << 100 - (totalprice[1] / totalprice[0] * 100) << "%" << endl;
	}
bool Cart::RegisterItems(Student& User) {
		for (int i = 0; i < inCart; i++)
		{
			if (User.detectDuplicate(CartList[i]) != false) {
				cout << "Item " << i + 1 << " in Cart is already registered, Please Remove it and try again.\n";
				return false;
			}
		}
		for (int i = 0; i < inCart; i++)
		{
			User.RegisterCourse(CartList[i]);
			CartList[i] = nullptr;
		}
		inCart = 0;
		return true;
	}
#endif