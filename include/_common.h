#ifndef _COMMON_H
#define _COMMON_H

#include <iostream>
#include <fstream>
#include <array>
#include <vector>

template <typename T, int size>
std::array<T, size> readFile(const std::string &file)
{
    std::ifstream inf(file);

    if (!inf)
    {
        std::cerr << "File could not be opened." << std::endl;
        exit(1);
    }

    std::array<T, size> content;

    int idx {0};
    while (inf)
    {
        inf >> content[idx];
        ++idx;
    }

    return content;
}

// overloading readFile template function to read objects into vector
template <typename T>
std::vector<T> readFile(const std::string &file)
{
    std::ifstream inf(file);

    if (!inf)
    {
        std::cerr << "The file could not be opened." << std::endl;
        exit(1);
    }

    std::vector<T> content;
    T temp;

    while (inf >> temp)
        content.push_back(temp);

    return content;
}


template <typename T, int size>
void printArray(const std::array<T, size> &array)
{
    for (const auto &element : array)
        std::cout << element << '\n';

    std::cout << std::endl;
}

template <typename T>
void printVector(const std::vector<T> &vector)
{
    for (const auto &element : vector)
        std::cout << element << '\n';

    std::cout << std::endl;
}

template <typename T, int size>
T getMax(const std::array<T, size> &numbers)
{
    T max { numbers[0] };

    for (const auto &elem : numbers)
        if ( elem > max )
            max = elem;

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

    Rectangle(Point &p1, Point &p2) :
        offset_x(p1.x), offset_y(p1.y), width(p2.x - p1.x + 1), height(p2.y - p1.y + 1) {}

    Rectangle(int offset_x = 0, int offset_y = 0, int width = 0, int height = 0) :
        offset_x(offset_x), offset_y(offset_y), width(width), height(height) {}

    friend std::ostream& operator<<(std::ostream &out, const Rectangle &r);
};


#endif // _COMMON_H
