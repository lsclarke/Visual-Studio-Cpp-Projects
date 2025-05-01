#include "Student.h"

Student::Student()
{
}

Student::Student(int grade_level_input, double gpa_input, double weighted_gpa_input, bool hasDisability, 
	bool hasFoodAllergies, unsigned long student_ID_input, int credit_count)
	: grade_level_selection{ grade_level_input }, gpa{ gpa_input }, weighted_gpa{ weighted_gpa_input }, has_disability{hasDisability}
	, has_food_allergies{ hasFoodAllergies }, student_ID{ student_ID_input }, school_credits{credit_count}
{
    setGradeLevel(rank, grade_level_input);
    HasDisabilityCheck(hasDisability);
    HasFoodAllergiesCheck(hasFoodAllergies);
}

Student::~Student()
{
}

Student& Student::operator=(Student&& rhs)
{
	if (this == &rhs) return *this;
}

std::ostream& operator<<(std::ostream& os, const Student& rhs)
{
    os << "Grade Level: " << rhs.grade_level_output << std::endl;
    os << "GPA: " << rhs.gpa << std::endl;
    os << "Weighted GPA: " << rhs.weighted_gpa << std::endl;
    os << "Has Disability: " << rhs.disability_output << std::endl;
    os << "Has Food Allergies: " << rhs.food_allergies_output << std::endl;
    os << "Student ID: #" << rhs.student_ID << std::endl;
    os << "School Credits: " << rhs.school_credits << "/120" << std::endl;
    os << "--------------------------------------------" << std::endl;
    return os;
}
