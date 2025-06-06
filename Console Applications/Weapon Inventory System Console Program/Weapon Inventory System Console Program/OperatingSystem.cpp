#include "OperatingSystem.h"
#include "Commands.h"

#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cctype>
#include <cmath>
#include <fstream>

OperatingSystem::OperatingSystem()
{
}

OperatingSystem::OperatingSystem(std::string& filename, int command)
{
}

OperatingSystem::~OperatingSystem()
{
}

void OperatingSystem::MainMenu()
{
    /*The MainMenu() function is the centeral hub for all the different commands available to the user.
    the menu will prompt the user for 5 commands for the user to choose fromand depending on the number input
    the system will run a command and perform a specific function.
    */
    system("CLS");
    MainStruct sMain;
    std::cout << std::setw(sMain.total_width) << std::setfill('-') << "" << std::endl;
    std::cout << std::setfill(' ');
    std::cout << std::setw((sMain.total_width - sMain.Title.length()) / 2) << "" << sMain.Title << std::endl;
    std::cout << std::setw((sMain.total_width - sMain.sub_Title.length()) / 2) << "" << sMain.sub_Title << std::endl;
    std::cout << std::setw(sMain.total_width) << std::setfill('-') << "" << std::endl;
    std::cout << std::setw(sMain.total_width) << std::setfill('-') << "" << std::endl;
    std::cout << std::setfill(' ') << std::endl;

    //Print out all the commands options
    std::vector<std::string> cmd_Array{ sMain.command_STR1 ,sMain.command_STR2 ,sMain.command_STR3 ,sMain.command_STR4, sMain.command_STR5 };
    for (size_t i = 0; i < cmd_Array.size(); i++) {
        std::cout << std::setw((sMain.total_width - sMain.command_STR1.length()) / 2) << std::setfill(' ') << "" << cmd_Array[i] << std::endl;
    }

    std::cout << std::setfill(' ') << std::endl;
    std::cout << sMain.version << std::endl;
    std::cout << std::setw(sMain.total_width) << std::setfill('-') << "" << std::endl;
    std::cout << std::setw(sMain.total_width) << std::setfill('-') << "" << std::endl;
    std::cout << sMain.prompt; std::cin >> sMain.input;

    Commands* cmd = new Commands();
    std::string filename{};

    //Main menu options
switch (sMain.input)
{
case 1:
    std::cout << "Enter a file name: "; std::cin >> filename;
    cmd->Display_Data(filename);
    Restart();
    break;
case 2:
    std::cout << "Enter a file name: "; std::cin >> filename;
    cmd->AddNewData(filename);
    Restart();
    break;
case 3:
    std::cout << "Enter a file name: "; std::cin >> filename;
    cmd->Remove_Data(filename);
    Restart();
    break;
case 4:
    std::cout << "Enter a file name: "; std::cin >> filename;
    cmd->Transfer_Data(filename);
    Restart();
    break;
case 5:
    std::cout << "[SYSTEM SHUTDOWN :: COMPLETE]" << std::endl;
    break;
default:
    std::cout << "[SYSTEM SHUTDOWN :: COMPLETE]" << std::endl;
    break;
}

if (sMain.input < 0 && sMain.input > 4)
{
    std::cin.clear();
    std::cin.ignore();
    MainMenu();
}
}

void OperatingSystem::Restart()
{
    /*The Restart() function is used to help prompt the user if they wish to continue using the application,
        or if they want to end it.
    */
    char choice{};
    std::cout << std::endl;
    std::cout << "Would you like to continue (Y or N): "; std::cin >> choice;
    if (choice == 'y' || choice == 'Y') {
        OperatingSystem* os = new OperatingSystem();
        std::cin.ignore();
        std::cin.clear();
        os->MainMenu();
    }
    else if (choice == 'n' || choice == 'N') {
        std::cout << "[SYSTEM SHUTDOWN :: COMPLETE]" << std::endl;

    }
    else
    {
        std::cerr << "[SYSTEM FAILURE :: UNAUTHORIZED INPUT DETECTED]" << std::endl;
    }
}
