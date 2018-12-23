#ifndef DAY3_H
#define DAY3_H

// include libraries
#include <iostream>
#include <fstream>
#include <vector>

#include "_common.h"

// global variables / data types

namespace day3 {

struct Claim : Rectangle
{
    unsigned ID;
    friend std::ostream& operator<<(std::ostream &out, const Claim &c);
    friend std::istream& operator>>(std::istream &in, Claim &c);
};

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

}

// function prototypes
void solveDay3();


#endif // DAY3_H
