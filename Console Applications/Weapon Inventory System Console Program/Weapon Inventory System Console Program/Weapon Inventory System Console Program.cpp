// Weapon Inventory System Console Program.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Commands.h"
#include "OperatingSystem.h"
#include <iostream>

int main()
{
    OperatingSystem* os = new OperatingSystem();
    os->MainMenu();

    delete os;
}
