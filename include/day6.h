#ifndef DAY6_H
#define DAY6_H

// include libraries

#include <iostream>
#include <array>
#include <vector>
#include <cmath>

// global variables / data types

const unsigned int GL_NUM {6};

struct Point
{
    int x, y;
    Point(int x = 0, int y = 0) : x(x), y(y) {}

    friend std::ostream& operator<<(std::ostream &out, const Point &p);
    friend bool operator==(const Point &p1, const Point &p2);
    friend int distance(const Point &p1, const Point &p2);
};

// map the closest coordinate & total distance to the point
struct PointMap : public Point
{
    int closestIdx;
    int totalDist;
    PointMap(int closestIdx = 0, int totalDist = 0) :
        closestIdx(closestIdx), totalDist(totalDist) {}
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

    void mapClosestIdx(const std::array<Point, GL_NUM> &coords);
    void mapTotalDist(const std::array<Point, GL_NUM> &coords);
    void drawClosestIdx() const;
    void drawTotalDist() const;
    bool isBoundary(int idx) const;

    inline int size() const { return width * height; }
    inline PointMap& operator[](int idx) { return points[idx]; }
    inline const PointMap& operator[](int idx) const { return points[idx]; }

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
