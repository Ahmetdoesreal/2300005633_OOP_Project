//Since There are Multiple Header Files With Same Structure of Checks i will explain in this file since it doesnt include any other user defined header files
//the ifndef stands for if not defined and i gave it a simple check that looks for the definition
//if it cant find it it will then continue to process other lines
//but if it finds the definition it wont process it again
//this is done to prevent multiple inclusions and definitions

#ifndef PREPROCESSOR//Checking Preproccessor directive
#define PREPROCESSOR//definition that acts like a "yes i am already included" flag
#define _CRT_SECURE_NO_WARNINGS//silences microsofts security warnings
#define ChangeExitChar '5'//change user information exit char might change later
#define CURRENT_SOFT 16//maximum software course count
#define CUURENT_LANG 7//maximum language course count
#define CURRENT_PROF 16//maximum proffessional courses count
#define CURRENT_ELEC 16//maximum elective courses count

//max register and cart count is set to 3 due to low demand for registration slots :(

#define MAX_REGISTER 3//maximum amount of courses that user can register to
#define MAX_CART 3//maximum amount of courses that user can add to the cart
#if MAX_CART>MAX_REGISTER//checks if the cart is greater than the register slots (since user cant do anything about it i decided to do not let the compiler compile if the values are nonsense)
#error Maximum Cart Value Cant Be Greater Than The Maximum Register Slots
//error statements ^^^^^^
#endif//end of condition
#include <iostream>//cpp input output library
#include <string>//cpp string library
using namespace std;//cpp standard library
#endif//end of condition