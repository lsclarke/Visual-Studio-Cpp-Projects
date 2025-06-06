#include "Commands.h"
#include "OperatingSystem.h"

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
#include <windows.h>

Commands::Commands() {}

Commands::Commands(int& command) {}

Commands::~Commands() {}

void Commands::Display_Data(std::string& filename)
{
    /*The Display_Data() function will prompt the user for a inventory file name, once the user has entered it in
    the copy inventory file will open. The in file variable will read through the file line by line, but as
    it is do so it is going to find the position of a comma(','). Then it is going to set a string variable
    to be all characters before the comma(','). After it stores the data in a string var, it will discard
    that portion of data from the main line being read. This process will continue to the last line until
    all characters are printed out.
    */
    const int total_width{ 82 };

    std::string line{};
    char input{};

    std::ifstream in_File{}; std::ofstream out_File{};
    in_File.open("..\\..\\..\\..\\Documents\\" + filename, std::ios::app);
    out_File.open("..\\..\\..\\..\\Documents\\CopyInventoryData.csv", std::ios::app | std::ios::out | std::ios::in);

    if (in_File.is_open()) {

        system("CLS");
        std::string manufacturer;
        std::string model;
        std::string weapon_type;
        std::string serialnumber;
        std::string quantity;
        int position{};
        int rows{};

        std::cout << std::setw(total_width) << std::setfill('-') << "" << std::endl;
        std::cout << std::setfill(' ');

        while (getline(in_File, line)) {

            position = line.find(',');

            //Records the data from the first character to the end position which is ','*
            manufacturer = line.substr(0, position);

            //Discards the comma and everything to the right of it*
            line = line.substr(position + 1, line.length());

            position = line.find(',');
            model = line.substr(0, position);
            line = line.substr(position + 1, line.length());


            position = line.find(',');
            weapon_type = line.substr(0, position);
            line = line.substr(position + 1, line.length());

            std::string temp{};
            position = line.find(',');
            temp = line.substr(0, position);
            serialnumber = (temp);

            line = line.substr(position + 1, line.length());
            quantity = (line);

            if (rows >= 0) {

                std::cout << "Row:" << rows << "|  " << manufacturer
                    << "  |  " << model << "  |  "
                    << weapon_type << "  |  " << serialnumber
                    << "  |  " << quantity << "  |  " << std::endl;
            }
            rows++;
            std::cout << std::setw(total_width) << std::setfill('-') << "" << std::endl;
            std::cout << std::setfill(' ');
        }
    }
    else
    {
        std::cerr << "File had a problem opening" << std::endl;
        std::cin.get();
    }
    in_File.close();
    std::cin.get();
}

void Commands::AddNewData(std::string& filename)
{
    /*The AddNewData() function prompts the user to add a new weapon into the inventory system.
    * the system will ask for the manufacturer, model, weapon type, serial number, and the quantity of this specific item.
    * Once the user has completed entering the new data. The system will open the copy file and enter the new data there
    * on a brand new line for the user to review. In order to see the updates to the non copy file, the user must use the
    * Transfer_Data() function.
    */
    std::string manufacturer;
    std::string model{};
    std::string weapon_type{};
    int type{};
    char serial_number[50]{};
    int quantity{};
    char input;
    Weapon status{};

    std::cout << "Enter the [MANUFACTURER] name: "; std::cin >> manufacturer;
    std::cout << "Enter the [MODEL] name: "; std::cin >> model;

    std::cin.ignore();
    std::cout << "1 - [Hand_Gun]\n2 - [Assualt_Rifle]\n3 - [Sniper_Rifle]" << std::endl;
    std::cout << "Enter a number to select the [WEAPON TYPE]: "; std::cin >> type;

    if (type > 0 && type << 8) {

        set_WeaponType(status, type);
        weapon_type = get_WeaponType();

        std::cout << "[Weapon_Type]: " << weapon_type << std::endl;
        std::cin.ignore();
        std::cin.clear();
        std::cout << "Enter the [SERIAL NUMBER]: "; std::cin >> serial_number;
        std::cin.ignore();
        std::cin.clear();
        std::cout << "Enter [QUANTITY]: "; std::cin >> quantity;
    }
    else {
        do {
            std::cerr << "[SYSTEM FAILURE :: UNAUTHORIZED INPUT DETECTED]" << std::endl;
            std::cin.ignore();
            std::cout << "1 - [Hand_Gun]\n2 - [Assualt_Rifle]\n3 - [Sniper_Rifle]" << std::endl;
            std::cout << "Enter a number to select the [WEAPON TYPE]: "; std::cin >> type;
        } while (!isdigit(type));
    }

    std::string quantity_STR = std::to_string(quantity);
    std::string newdata_Str{ manufacturer + "," + model + "," + weapon_type + "," + serial_number + "," + quantity_STR };

    std::ifstream in_File{}; std::ofstream out_File{}; std::fstream f_File{};
    in_File.open("..\\..\\..\\..\\Documents\\" + filename, std::ios::app | std::ios::out | std::ios::in);
    f_File.open("..\\..\\..\\..\\Documents\\CopyInventoryData.csv", std::ios::app | std::ios::out | std::ios::in);
    std::string updateFile;
    if (f_File.is_open()) {
        std::cout << "**NEW ITEM ADDED**";
        std::transform(newdata_Str.begin(), newdata_Str.end(), newdata_Str.begin(), ::toupper);
        std::cout << newdata_Str << std::endl;
        f_File << newdata_Str << std::endl;

        char digit{};
        std::cout << "Enter any digit to return to Add Menu: ";
        std::cin >> digit;
        if (isdigit(digit))
        {
            std::cout << "[SYSTEM COMPLETE :: AUTHORIZED INPUT DETECTED]" << std::endl;
        }
        else {
            do {

                std::cout << "[SYSTEM FAILURE :: UNAUTHORIZED INPUT DETECTED]" << std::endl;
                std::cout << "Enter any digit to return to Main Menu: ";
                std::cin.clear();
                std::cin.ignore();
                std::cin >> digit;
            } while (!isdigit(digit));
        }
        std::string displa_file = "CopyInventoryData.csv";
        Display_Data(displa_file);
    }
    else
    {
        std::cerr << "File had a problem opening" << std::endl;
    }
    f_File.close();
    in_File.close();
}

void Commands::Remove_Data(std::string& filename)
{
    /*The Remove_Data() function prompts the user to remove data from the inventory system.
     the system will run through every line in the file and add it to a vector. the system will then ask
     for the row the user wants to remove from the file. Once the user has entered the row number, the system
     will open the copy inventory file and rewrite it with every line in the vector excluding the the line
     associated with the row number.
    */
    std::ifstream in_File{}; std::ofstream out_File{};
    in_File.open("..\\..\\..\\..\\Documents\\" + filename, std::ios::app | std::ios::out | std::ios::in);

    int rows{};
    int input{};
    std::string line{};
    int position{};

    std::vector<std::string> vec{};

    Display_Data(filename);

    if (in_File.is_open()) {

        while (getline(in_File, line)) {
            vec.push_back(line);
        }

        std::cout << "Enter the row number you want to remove: ";
        std::cin >> input;
        out_File.open("..\\..\\..\\..\\Documents\\CopyInventoryData.csv");
        position = input;
        for (std::string a : vec) {
            std::cout << a;
            rows++;
            if (position != rows) {
                std::cout << a << std::endl;

                out_File << a << std::endl;
            }
        }

        vec.erase(vec.begin(), vec.end());
    }
    else
    {
        std::cerr << "File had a problem opening" << std::endl;
        std::cin.get();
    }
    in_File.close();
    out_File.close();
    std::cin.get();
}

void Commands::Transfer_Data(std::string& filename)
{

    /*The Transfer_Data() function prompts the user for a file they want to update with the copy inventory data.
    the system will run through every line in the file and add it to a vector. then system will go into the file the user entered.
    The file will then be cleared and updated with the lines within the vector from the copy inventory.
    */
    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
    //read in data from file, write data out to file
    std::ifstream in_File{}; std::ofstream out_File{};
    in_File.open("..\\..\\..\\..\\Documents\\CopyInventoryData.csv", std::ios::app | std::ios::out | std::ios::in);

    int rows{};
    std::string line{};
    int position{};

    std::vector<std::string> vec{};

    Display_Data(filename);

    char choice{};
    std::cout << std::endl;
    std::cout << "Would you like to continue (Y or N): "; std::cin >> choice;
    if (choice == 'y' || choice == 'Y') {

        OperatingSystem* os = new OperatingSystem();
        std::cin.ignore();
        std::cin.clear();

        if (in_File.is_open()) {
            while (getline(in_File, line)) {
                vec.push_back(line);
            }

            out_File.open("..\\..\\..\\..\\Documents\\" + filename);

            for (std::string a : vec) {
                out_File << a << std::endl;
            }

            Display_Data(filename);
            std::cout << "[ FILE :: UPDATE COMPLETE]" << std::endl;
            vec.erase(vec.begin(), vec.end());
            std::cin.get();
        }
        else
        {
            std::cerr << "File had a problem opening" << std::endl;
            std::cin.get();
        }
        in_File.close();
        out_File.close();
    }
    else if (choice == 'n' || choice == 'N') {
        std::cout << "[SYSTEM SHUTDOWN :: COMPLETE]" << std::endl;

    }
    else
    {
        std::cerr << "[SYSTEM FAILURE :: UNAUTHORIZED INPUT DETECTED]" << std::endl;
    }

}
