#include "_common.h"

std::ostream& operator<<(std::ostream &out, const Point &p)
{
    out << "(" << p.x << ", " << p.y << ")";

    return out;
}

bool operator==(const Point &p1, const Point &p2)
{
    return (p1.x == p2.x && p1.y == p2.y);
}

int distance(const Point &p1, const Point &p2)
{
    // Manhattan-distance
    return abs(p1.x - p2.x) + abs(p1.y - p2.y);
}
