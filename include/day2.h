#ifndef DAY2_H
#define DAY2_H

// include libraries
#include <iostream>
#include <string>
#include <iterator>
#include <array>
#include <algorithm>
#include <exception>

#include "_common.h"

// global variables / data types
const int GL_SIZE {250};

// function prototypes
void solveDay2();

int makeCheckSum(const std::array<std::string, GL_SIZE> &strings);

std::array<unsigned, 256> getSpectrumASCII(const std::string &string);

std::string getCommonLetters(const std::array<std::string, GL_SIZE> &strings);

int countDifferentLetters(const std::string &str1, const std::string &str2);

std::string getCommonString(const std::string &str1, const std::string &str2);

#endif // DAY2_H
