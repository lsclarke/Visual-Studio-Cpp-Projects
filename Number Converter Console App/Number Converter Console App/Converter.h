#pragma once
#ifndef _CONVERTER_HPP_
#define _CONVERTER_HPP_

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

static int Count{};

class Converter
{
    unsigned long long input;
public:
    Converter();
    Converter(unsigned long long& input);
    ~Converter();

    Converter& operator=(Converter&& rhs);        // Move operator assignment
    friend std::ostream& operator<<(std::ostream& os, const Converter& rhs); // Insertion operator assignment
    friend std::istream& operator>>(std::istream& in, Converter& rhs); // Exstraction operator assignment

    void Display() const;
};

#endif
