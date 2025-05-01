#pragma once
#ifndef _PERSON_HPP_
#define _PERSON_HPP_

#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <sstream>
#include <vector>
#include <bitset>
#include <list>
#include <algorithm>
#include <cctype>
#include <iterator>
#include <cmath>
#include <fstream>
#include <map>
#include <cstdlib>
#include <set>

class Person {

public:
    enum Ethinicity {
        AfricanAmerican = 1, HispanicLatinoAmerican, Caucasian, Hispanic,
        AlaskaNative, NativeHawaiian, NativeAmerican, PacificIslander,
        AsianAmericans, MiddleEastern, SouthAsian = 11
    };

    bool operator<(const Person& rhs) const {
        return this->age < rhs.age;
    }
    

    void setEthinicity(Ethinicity eth, int selection)
    {
        switch (selection)
        {
        case 1:
            eth = AfricanAmerican;
            ethinicity = "African American";
            break;
        case Person::HispanicLatinoAmerican:
            ethinicity = "Hispanic Latino American";
            break;
        case Person::Caucasian:
            ethinicity = "Caucasian";
            break;
        case Person::Hispanic:
            ethinicity = "Hispanic";
            break;
        case Person::AlaskaNative:
            ethinicity = "Alaska Native";
            break;
        case Person::NativeHawaiian:
            ethinicity = "Native Hawaiian";
            break;
        case Person::NativeAmerican:
            ethinicity = "Native American";
            break;
        case Person::PacificIslander:
            ethinicity = "Pacific Islander";
            break;
        case Person::AsianAmericans:
            ethinicity = "Asian Americans";
            break;
        case Person::MiddleEastern:
            ethinicity = "Middle Eastern";
            break; 
        case Person::SouthAsian:
            ethinicity = "South Asian";
                break;
        default:
            std::cout << "[SYSETM ERROR::INVALID ENTRY] \n Please choose from the selction!" << std::endl;
            break;
        }
    }

    std::string first_name;
    std::string last_name;
    int age;
    double height;
    int ethnicity_selection;
    std::string ethinicity;
    Ethinicity group {};  

//    void Name(std::string text);
//    void Age(int num);
    Person();
    Person(std::string firstname, std::string lastname, int age, double height, int ethnicity_choice);
    ~Person();


    Person& operator=( Person&& rhs);
    friend std::ostream& operator<<(std::ostream& os, const Person& rhs); // Insertion operator assignment
    friend std::istream& operator>>(std::istream& in, Person& rhs); // Exstraction operator assignment
};
#endif // !_PERSON_HPP_
