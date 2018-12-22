#ifndef DAY6_H
#define DAY6_H

// include libraries

#include <iostream>
#include <array>
#include <cmath>

#include "_common.h"

// global variables / data types

const int GL_NUM {50};
const int GL_TOT_DIST {10000};


// map the closest coordinate & total distance to the point
struct PointMap : public Point
{
    int closestIdx;
    int totalDist;
    PointMap(int closestIdx = 0, int totalDist = 0) :
        closestIdx(closestIdx), totalDist(totalDist) {}
};

class Grid : public Rectangle
{
private:
    PointMap *points;
    void initGrid();

public:
    Grid(Rectangle &rect) : Rectangle(rect)
    {
        points = new PointMap[width * height];
        initGrid();
    }

    void mapClosestIdx(const std::array<Point, GL_NUM> &coords);
    void mapTotalDist(const std::array<Point, GL_NUM> &coords);
    void drawClosestIdx() const;
    void drawTotalDist() const;
    bool isBoundaryPoint(int idx) const;

    inline unsigned size() const { return width * height; }
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

int getRegionSize(const Grid &grid);

#endif // DAY6_H
