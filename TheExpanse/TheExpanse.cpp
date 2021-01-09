// TheExpanse.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "ExpanseController.h"
#undef main

int main()
{
	ExpanseController controller;
	controller.initWorld();
	controller.programLoop();

	return 0;
}