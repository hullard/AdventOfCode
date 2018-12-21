#ifndef DAY1_H
#define DAY1_H

// include libraries

#include <iostream>
#include <fstream>
#include <array>
#include <vector>

// global variables / data types
const unsigned int GL_SIZE {1025};

// function prototypes
void solveDay1();

template <typename T, int size>
std::array<T, size> readFile(const std::string &file)
{
    std::ifstream inf(file);

    if (!inf)
    {
        std::cerr << "File could not be opened." << std::endl;
        exit(1);
    }

    std::array<T, size> array;

    int idx {0};
    while (inf)
    {
        inf >> array[idx];
        ++idx;
    }

    return array;
}

template <typename T, int size>
void printArray(const std::array<T, size> &array)
{
    for (const auto &element : array)
        std::cout << element << '\n';

    std::cout << std::endl;
}

template <typename T, int size>
int sumUp(const std::array<T, size> &array)
{
    int sum {0};
    for (const auto &element : array)
        sum += element;

    return sum;
}

template <typename T, int size>
int getFirstDuplFreq(const std::array<T, size> &changes)
{
    std::vector<T> freqs;

    int currFreq {0};
    for (int i {0}; i < size; ++i)
    {
        currFreq += changes[i];

        for (const auto &freq : freqs)
            if (currFreq == freq)
                return currFreq; // return here when duplication found

        freqs.push_back(currFreq);

        // restart to process "changes" array if we reached the end
        if ( i == (size - 1) )
        {
            i = -1;
            std::cout << "Cycle restarted! Current freq: " << currFreq << '\n';
        }
    }
}


#endif // DAY1_H
