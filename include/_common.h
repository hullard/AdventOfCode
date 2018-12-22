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

struct Point
{
    int x, y;
    Point(int x = 0, int y = 0) : x(x), y(y) {}

    friend std::ostream& operator<<(std::ostream &out, const Point &p);
    friend bool operator==(const Point &p1, const Point &p2);
    friend int distance(const Point &p1, const Point &p2);
};

struct Rectangle
{
    int offset_x, offset_y;
    int width, height;

    Rectangle(Point &p1, Point &p2) : offset_x(p1.x), offset_y(p1.y),
        width(p2.x - p1.x + 1), height(p2.y - p1.y + 1) {}
};


#endif // _COMMON_H
