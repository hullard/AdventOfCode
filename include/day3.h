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
    friend bool operator==(const Claim &c1, const Claim &c2);
};

namespace day3 {

class Grid : public Rectangle
{
public:
    // map the closest coordinate & total distance to the point
    struct PointMap : public Point
    {
        bool overlap;
        PointMap(bool overlap = false) : overlap(overlap) {}
    };

private:
    PointMap *points;
    void initGrid();

public:
    Grid(Rectangle &rect) : Rectangle(rect)
    {
        points = new PointMap[width * height];
        initGrid();
    }

    void mapOverlap(const std::vector<Claim> &claims);
    void drawOverlap() const;

    inline unsigned size() const { return width * height; }
    inline PointMap& operator[](int idx) { return points[idx]; }
    inline const PointMap& operator[](int idx) const { return points[idx]; }
};

std::vector<Point> getCrossPoints(const Rectangle &r1, const Rectangle &r2);
Rectangle getGridArea(const std::vector<Claim> &claims);

}

// function prototypes
void solveDay3();

int getCrossAreaSize(const day3::Grid &grid);

#endif // DAY3_H
