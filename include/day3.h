#ifndef DAY3_H
#define DAY3_H

// include libraries
#include <iostream>
#include <fstream>
#include <vector>

#include "_common.h"

// global variables / data types

struct Claim : Rectangle
{
    unsigned ID;
    friend std::ostream& operator<<(std::ostream &out, const Claim &c);
    friend std::istream& operator>>(std::istream &in, Claim &c);
};

// function prototypes
void solveDay3();


#endif // DAY3_H
