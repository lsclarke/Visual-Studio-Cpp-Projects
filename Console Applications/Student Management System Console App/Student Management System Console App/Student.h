#pragma once

#ifndef _STUDENT_HPP_
#define _STUDENT_HPP_

#include "Person.h"

class Student : public Person 
{

public:

    enum GradeLevel {
        PRE_K = 1, KINDERGARDEN, FIRST_GRADE, SECOND_GRADE,
        THIRD_GRADE = 5, FOURTH_GRADE, FIFTH_GRADE, SIXTH_GRADE,
        SEVENTH_GRADE, EIGHTH_GRADE, NINTH_GRADE, TENTH_GRADE,
        ELEVENTH_GRADE, TWELFTH_GRADE = 14
    };

	Student();
    Student(int grade_level_input, double gpa_input, double weighted_gpa_input, bool hasDisability,
        bool hasFoodAllergies, unsigned long student_ID_input, int credit_count );
	~Student();

    GradeLevel rank;
    int grade_level_selection;
    double gpa;
    double weighted_gpa;
    bool has_disability;
    bool has_food_allergies;
    unsigned long student_ID;
    int school_credits;
    std::string grade_level_output{};

    std::string disability_output{};
    std::string food_allergies_output{};

    void setGradeLevel(GradeLevel grade_lvl, int selection) {
        switch (selection) {
        case PRE_K:
            grade_level_output = "PRE_K";
            break;
        case KINDERGARDEN:
            grade_level_output = "KINDERGARDEN";
            break;
        case FIRST_GRADE:
            grade_level_output = "FIRST_GRADE";
            break;
        case SECOND_GRADE:
            grade_level_output = "SECOND_GRADE";
            break;
        case THIRD_GRADE:
            grade_level_output = "THIRD_GRADE";
            break;
        case FOURTH_GRADE:
            grade_level_output = "FOURTH_GRADE";
            break;
        case FIFTH_GRADE:
            grade_level_output = "FIFTH_GRADE";
            break;
        case SIXTH_GRADE:
            grade_level_output = "SIXTH_GRADE";
            break;
        case SEVENTH_GRADE:
            grade_level_output = "SEVENTH_GRADE";
            break;
        case EIGHTH_GRADE:
            grade_level_output = "EIGHTH_GRADE";
            break;
        case NINTH_GRADE:
            grade_level_output = "NINTH_GRADE";
            break;
        case TENTH_GRADE:
            grade_level_output = "TENTH_GRADE";
            break;
        case ELEVENTH_GRADE:
            grade_level_output = "ELEVENTH_GRADE";
            break;
        case TWELFTH_GRADE:
            grade_level_output = "TWELFTH_GRADE";
            break;
        }
    }

    bool HasDisabilityCheck(bool check) {
        if (check) {
            disability_output = "YES";
        }
        else {
            disability_output = "NO";
        }

        return check;
    }

    bool HasFoodAllergiesCheck(bool check) {
        if (check) {
            food_allergies_output = "YES";
        }
        else {
            food_allergies_output = "NO";
        }

        return check;
    }

    Student& operator=(Student&& rhs);
    friend std::ostream& operator<<(std::ostream& os, const Student& rhs);
};
#endif // !_STUDENT_HPP_
