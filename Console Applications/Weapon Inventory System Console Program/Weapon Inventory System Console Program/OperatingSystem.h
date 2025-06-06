
#ifndef OPERATINGSYSTEM_HPP
#define OPERATINGSYSTEM_HPP

#include <iostream>

class OperatingSystem
{
private:

    std::string manufacturer;
    char model[50];
    int type;
    std::string weapon_type;
    char serial_number[50];
    int quantity{ 0 };
    std::string filename;
    char input;
    std::string result{};

    struct MainStruct
    {
        std::string Title{ "Inventory System Console" };
        std::string sub_Title{ "Main Menu" };
        std::string version{ "v0.001a" };

        char selection[5]{ '1','2','3','4' };

        std::string command_STR1{ "1 - READ" };
        std::string command_STR2{ "2 - ADD" };
        std::string command_STR3{ "3 - REMOVE" };
        std::string command_STR4{ "4 - UPDATE" };
        std::string command_STR5{ "5 - QUIT" };
        std::string prompt{ "Choice a number to activate a command: " };
        int input;

        const int total_width{ 70 };
        const int field_1{ 75 };
        const int field_2{ 20 };
        const int Field_3{ 20 };
        const int field_4{ 15 };
        const int field_5{ 15 };
    };

public:

    OperatingSystem();
    OperatingSystem(std::string& filename, int command);
    ~OperatingSystem();
    void MainMenu();
    void Restart();

};

#endif
