#pragma once
#ifndef COMMANDS_HPP
#define COMMANDS_HPP

#include <iostream>
#include <string>

//Commands class is in charge of all the commands withing the program. The operating system calls on these commands to perform file changes and updates
class Commands
{
private:

	//Manufacturer,Model,Weapon_Type,Serial_Number,Quantity
public:
	//Constructors and Deconstructors
	Commands();
	Commands(int& command);
	~Commands();

	//Public prototype functions++


	//Adds new items to data base or add to existing items quantity to a copy of the main source file(complete)
	void Display_Data(std::string& filename);

	//Adds new items to data base or add to existing items quantity to a copy of the main source file(complete)
	void AddNewData(std::string& filename);

	//Removes a row of data from file
	void Remove_Data(std::string& filename);

	//Transfer/Copies over data that has been added to the copy file
	void Transfer_Data(std::string filename);
	enum Weapon { Hand_Gun, Assualt_Rifle, Sniper_Rifle, Shotgun, Grenade, Motor, Artillery };

	Weapon status{};
	std::string type_label{};

	//Sets the weapon type string based on an integer
	void set_WeaponType(Weapon status, int type) {
		if (type == 1) { status = Hand_Gun; type_label = "Hand_Gun"; }
		if (type == 2) { status = Assualt_Rifle; type_label = "Assualt_Rifle"; }
		if (type == 3) { status = Sniper_Rifle; type_label = "Sniper_Rifle"; }
		if (type == 4) { status = Shotgun; type_label = "Shotgun"; }
		if (type == 5) { status = Grenade; type_label = "Grenade"; }
		if (type == 6) { status = Motor; type_label = "Motor"; }
		if (type == 7) { status = Artillery; type_label = "Artillery"; }
	}

	std::string get_WeaponType() { return type_label; }

};

#endif;

