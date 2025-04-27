#include "Converter.h"

Converter::Converter()
{
    Count++;
    std::cout << "Constructer activated:: " << std::hex << Count << std::endl;
}

Converter::Converter(unsigned long long& input) : input{ input }
{
    Count++;
   // std::cout << "Constructer active:: " << std::hex << Count << std::endl;
}

Converter::~Converter()
{
    Count--;
   // std::cout << "Deconstructers deactivated:: " << std::hex << Count << std::endl;
}


std::ostream& operator<<(std::ostream& os, const Converter& rhs) {
    os << "--------------------------------------------" << std::endl;
    os << "Binary Format: " << std::bitset<8>{rhs.input} << std::endl;
    os << "Decimal Format: " << std::dec << rhs.input << std::endl;
    os << "Octal Format: " << std::oct << rhs.input << std::endl;
    os << "Hexadecimal Format: " << std::hex << rhs.input << std::endl;
    return os;
}

Converter& Converter::operator=(Converter&& rhs)
{
    if (this == &rhs) return *this;
}

std::istream& operator>>(std::istream& in, Converter& rhs) {
    unsigned long long newValue{};
    in >> newValue;
    rhs = Converter{ newValue };
    return in;
}

void Converter::Display() const {
    std::cout << "Number Entry: " << std::dec << input << std::endl;
}