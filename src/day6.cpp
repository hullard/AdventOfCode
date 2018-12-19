#include "day6.h"


void solveDay6()
{
    std::array<Point, GL_NUM> coords = fillInCoordsTest();

    printCoords(coords);

    getLargestArea(coords);
}


int getLargestArea(const std::array<Point, GL_NUM> &coords)
{
    // the coordinates outside of the seek-rectangle are irrelevant because they are sure to have infinite area
    Rectangle seekRect = getSeekRect(coords);

    Grid grid(seekRect.p1, seekRect.p2);

    grid.draw();

    std::cout << seekRect << std::endl;

    return 1;
}

// the seekmap is defined by the four boundary points: get the left/up and right/down corners
Rectangle getSeekRect(const std::array<Point, GL_NUM> &coords)
{
    Point P_start = coords[0];
    Point P_end = P_start;

    for (const auto &coord : coords)
    {
        // find the left/up corner
        if (coord.x < P_start.x)
            P_start.x = coord.x;
        if (coord.y < P_start.y)
            P_start.y = coord.y;

        // find the right/down corner
        if (coord.x > P_end.x)
            P_end.x = coord.x;
        if (coord.y > P_end.y)
            P_end.y = coord.y;
    }

    return Rectangle(P_start, P_end);
}


void printCoords(const std::array<Point, GL_NUM> &coords)
{
    for (const auto &coord : coords)
        std::cout << coord << '\n';

    std::cout << std::endl;
}


std::ostream& operator<<(std::ostream &out, const Point &p)
{
    out << "(" << p.x << ", " << p.y << ")";

    return out;
}


std::ostream& operator<<(std::ostream &out, const Rectangle &r)
{
    out << r.p1 << '\n' << r.p2;

    return out;
}

bool operator==(const Point &p1, const Point &p2)
{
    return (p1.x == p2.x && p1.y == p2.y);
}

/*
std::array<Point, GL_NUM> fillInCoords()
{
    std::array<Point, GL_NUM> coords {{
        {177, 51},
        {350, 132},
        {276, 139},
        {249, 189},
        {225, 137},
        {337, 354},
        {270, 147},
        {182, 329},
        {118, 254},
        {174, 280},
        {42, 349},
        {96, 341},
        {236, 46},
        {84, 253},
        {292, 143},
        {253, 92},
        {224, 137},
        {209, 325},
        {243, 195},
        {208, 337},
        {197, 42},
        {208, 87},
        {45, 96},
        {64, 295},
        {266, 248},
        {248, 298},
        {194, 261},
        {157, 74},
        {52, 248},
        {243, 201},
        {242, 178},
        {140, 319},
        {69, 270},
        {314, 302},
        {209, 212},
        {237, 217},
        {86, 294},
        {295, 144},
        {248, 206},
        {157, 118},
        {155, 146},
        {331, 40},
        {247, 302},
        {250, 95},
        {193, 214},
        {345, 89},
        {183, 206},
        {121, 169},
        {79, 230},
        {88, 155}
    }};

    return coords;
}
*/

std::array<Point, GL_NUM> fillInCoordsTest()
{
    std::array<Point, GL_NUM> coords {{
        {1, 1},
        {1, 6},
        {8, 3},
        {3, 4},
        {5, 5},
        {8, 9}
    }};

    return coords;
}

void Grid::initGrid()
{
    for (int idx {0}; idx < size(); ++idx)
    {
        points[idx].x = offset_x + (idx % width);
        points[idx].y = offset_y + static_cast<int>(idx / width);
    }
}


void Grid::draw()
{
    for (int idx {0}; idx < size(); ++idx)
    {
        std::cout << points[idx] << ' ';

        if ( (idx + 1) % width == 0 && idx > 0)
            std:: cout << '\n';
    }

    std::cout << std::endl;
}
