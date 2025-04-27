#include "Converter.h"

int main() {

    std::cout << "Enter a number into the conversion system: ";
    unsigned long long num{};

    while (!(std::cin >> num)) {
        std::cout << "[SYSTEM_ERROR::INVLAID ENTRY]" << std::endl;
        std::cin.clear();
        std::cin.ignore(123, '\n');
        std::cout << "Please Enter a number into the conversion system: "; 
        std::cin >> num;
    }
    system("CLS");


    Converter amount{ num };
    amount.Display();
    std::cout << amount << std::endl;


    return 0;
}

