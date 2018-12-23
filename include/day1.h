#ifndef DAY1_H
#define DAY1_H

// include libraries

#include <iostream>
#include <array>
#include <vector>

#include "_common.h"

// global variables / data types
const unsigned int GL_SIZE {1025};

// function prototypes
void solveDay1();

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
    return 0;
}


#endif // DAY1_H
