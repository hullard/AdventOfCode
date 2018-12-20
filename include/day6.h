#ifndef DAY6_H
#define DAY6_H

// include libraries

#include <iostream>
#include <array>
#include <vector>
#include <cmath>

// global variables / data types

const unsigned int GL_NUM {50};

struct Point
{
    int x, y;
    Point(int x = 0, int y = 0) : x(x), y(y) {}

    friend std::ostream& operator<<(std::ostream &out, const Point &p);
    friend bool operator==(const Point &p1, const Point &p2);
    friend int distance(const Point &p1, const Point &p2);
};

// map the closest coordinate to the point
struct PointMap : public Point
{
    int closestIdx;
    PointMap(int idx = 0) : closestIdx(idx) {}
};

struct Rectangle
{
    Point p1, p2;
    Rectangle(Point &p1, Point &p2) : p1(p1), p2(p2) {}
};

class Grid
{
private:
    int offset_x, offset_y;
    int width, height;

    PointMap *points;
    void initGrid();

public:
    Grid(Point &p1, Point &p2) : offset_x(p1.x), offset_y(p1.y),
        width(p2.x - p1.x + 1), height(p2.y - p1.y + 1)
    {
        points = new PointMap[width * height];

        initGrid();
    }

    void map(const std::array<Point, GL_NUM> &coords);
    void draw(const std::array<Point, GL_NUM> &coords);
    bool isBoundary(int idx) const;

    int size() const { return width * height; }
    PointMap& operator[](int idx) { return points[idx]; }
    const PointMap& operator[](int idx) const { return points[idx]; }

    friend std::ostream& operator<<(std::ostream &out, const Grid &g);
};

// function prototypes

void solveDay6();

std::array<Point, GL_NUM> fillInCoords();

void printCoords(const std::array<Point, GL_NUM> &coords);

Rectangle getSeekArea(const std::array<Point, GL_NUM> &coords);

std::array<int, GL_NUM> calcFiniteAreas(const Grid &grid);

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

#endif
