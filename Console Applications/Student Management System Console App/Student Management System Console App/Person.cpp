#include "Person.h"

Person::Person(){}

Person::Person(std::string firstname, std::string lastname, int age, double height, int ethnicity_choice)
    : first_name{ firstname }, last_name{ lastname }, age{ age }, height{ height }, ethnicity_selection{ ethnicity_choice }
{
    setEthinicity(group, ethnicity_selection);
}


Person::~Person(){}

Person& Person::operator=(Person&& rhs)
{
    if (this == &rhs) return *this;
}

std::ostream& operator<<(std::ostream& os, const Person& rhs)
{
    os << "Student Overview Details" << std::endl;
    os << "--------------------------------------------" << std::endl;
    os << "First Name: " << rhs.first_name << std::endl;
    os << "Last Name: " << rhs.last_name << std::endl;
    os << "Age: " << rhs.age << std::endl;
    os << "Height: " << rhs.height << "ft" << std::endl;
    os << "Ethnic Group: " << rhs.ethinicity << std::endl;
    return os;
}

std::istream& operator>>(std::istream& in, Person& rhs) {
    std::string newFirstText{}, newLastText{}; int newAge{}; double newHeight{}; Person::Ethinicity newGroup{};
    in >> newFirstText, newLastText, newAge, newHeight, newGroup;
    rhs = Person{ newFirstText, newLastText, newAge, newHeight, newGroup };
    return in;
}
