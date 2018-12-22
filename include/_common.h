#ifndef _COMMON_H
#define _COMMON_H

#include <iostream>
#include <fstream>
#include <array>

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
T getMax(const std::array<T, size> &numbers)
{
    T max { numbers[0] };

    for (const auto &elem : numbers)
    {
        if ( elem > max )
            max = elem;
    }

    return max;
}


#endif // _COMMON_H
