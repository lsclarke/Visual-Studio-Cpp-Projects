// Student Management System Console App.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Student.h"
#include "Person.h"
#include <chrono>
#include <thread>
#include <unordered_map>

using namespace std::chrono_literals;

void RefreshStudentData(std::unordered_map<std::string, std::string> name, std::unordered_map<int, double> traits,
	std::unordered_map<std::string, std::string> traits2, std::unordered_map<double, double> gpa, std::unordered_map<std::string, std::string> disabilities, std::unordered_map<unsigned long, int> credentialsMap)
{
	while (true) {
		system("CLS");
		for (auto& item : name) {
			std::cout << "\nStudent Overview Details" << std::endl;
			std::cout << "--------------------------------------------" << std::endl;
			std::cout << "First Name: " << item.first << "\nLast Name: " << item.second << std::endl;
			for (auto& item : traits) {
				std::cout << "Age: " << item.first << "\nHeight: " << item.second << std::endl;
				for (auto& item : traits2) {
					std::cout << "Ethnic Group: " << item.first << "\nGrade Level: " << item.second << std::endl;
					for (auto& item : gpa) {
						double gpa_cap{4.0};
						std::cout << "Weighted GPA: " << item.first << "\nGPA: " << item.second << std::endl;
						if ((rand() % 3) > gpa_cap || item.second > gpa_cap) {
							
							item.second -= 1.45;
						}
						else {
							item.second+= 0.21;
						}

						for (auto& item : disabilities) {
							std::cout << "Has Disability: " << item.first << "\nHas Food Allergies : " << item.second << std::endl;
							for (auto& item : credentialsMap) {
								std::cout << "Student ID: #" << item.first << "\nSchool Credits : " << item.second << "/120" << std::endl;
								item.second += 3;
							}
							std::cout << "--------------------------------------------" << std::endl;
						}



					}
				}
			}
		}

		std::this_thread::sleep_for(3000ms);
	}
}

int main()
{

	Person p1 { "Isha", "Gibbons", 8, 4.5, 1 };
	Student s1 {3, 2.19, 2.59, false, true, 628792, 45};

	Person p2{ "Alex", "Mims", 10, 5.1, Person::Caucasian };
	Student s2{ 7, 2.5, 2.4, true, true, 83784, 45 };

	Person p3{ "Travis", "Hunter", 9, 4.5, Person::AfricanAmerican };
	Student s3{ 6, 3.1, 3.4, false, false, 95689, 45 };

	Person p4{ "Canyon", "Mcnair", 8, 4.5, Person::PacificIslander };
	Student s4{ 5, 2.3, 2.6, false, false, 23478, 45 };

	Person p5{ "Maddie", "Mallocks", 7, 4.5, Person::NativeAmerican };
	Student s5{ 3, 2.72, 2.8, true, false, 344121, 45 };

	Person p6{ "Ori", "Maddicks", 10, 4.5, Person::SouthAsian };
	Student s6{ 7, 3.0, 3.3, false, true, 356245, 45 };

	Person p7{ "Adam", "Grain", 9, 4.5, Person::AlaskaNative };
	Student s7{ 6, 3.0, 3.3, false, true, 372955, 45 };

	std::unordered_map<std::string, std::string> studentsMap{};
	std::unordered_map<int, double> traitsMap{};
	std::unordered_map<std::string, std::string> traitsMap2{};
	std::unordered_map<double, double> gpaMap{};
	std::unordered_map<std::string, std::string> disabilitiesMap{};
	std::unordered_map<unsigned long, int> credentialsMap{};

	//Student 1: Isha Gibbons
	studentsMap.insert(std::make_pair(p1.first_name,p1.last_name));
	traitsMap.insert(std::make_pair(p1.age,p1.height));
	traitsMap2.insert(std::make_pair(p1.ethinicity, s1.grade_level_output));
	gpaMap.insert(std::make_pair(s1.weighted_gpa, s1.gpa));
	disabilitiesMap.insert(std::make_pair(s1.disability_output,s1.food_allergies_output));
	credentialsMap.insert(std::make_pair(s1.student_ID, s1.school_credits));


	//Student 2: Alex Mims
	//studentsMap.insert(std::make_pair(p2.first_name, p2.last_name));
	//traitsMap.insert(std::make_pair(p2.age, p2.height));
	//traitsMap2.insert(std::make_pair(p2.ethinicity, s2.grade_level_output));
	//gpaMap.insert(std::make_pair(s2.weighted_gpa, s2.gpa));
	//disabilitiesMap.insert(std::make_pair(s2.disability_output, s2.food_allergies_output));
	//credentialsMap.insert(std::make_pair(s2.student_ID,s2.school_credits));

	//Student 3: Travis Hunter
	//studentsMap.insert(std::make_pair(p3.first_name, p3.last_name));
	//traitsMap.insert(std::make_pair(p3.age, p3.height));
	//traitsMap2.insert(std::make_pair(p3.ethinicity, s3.grade_level_output));
	//gpaMap.insert(std::make_pair(s3.weighted_gpa, s3.gpa));
	//disabilitiesMap.insert(std::make_pair(s3.disability_output, s3.food_allergies_output));
	//credentialsMap.insert(std::make_pair(s3.student_ID, s3.school_credits));


	std::thread bgWorker(RefreshStudentData, studentsMap, traitsMap, traitsMap2, gpaMap, disabilitiesMap, credentialsMap);

	system("pause>nul");
}
