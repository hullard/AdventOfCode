#include "day6.h"
#include "_common.h"

void solveDay6()
{
    std::cout << "Day6 has started!" << '\n';
    // fill in the initial array with the coordinates
    std::array<Point, GL_NUM> coords = fillInCoords();
    printCoords(coords);

    // determine the seek area, which is the covering rectangle
    Rectangle seekArea = getSeekArea(coords);

    // build up the grid covered by the seek area
    Grid grid(seekArea.p1, seekArea.p2);
    //std::cout << grid << '\n';

    grid.mapClosestIdx(coords);
    //grid.drawClosestIdx();

    // calculate area sizes and set the area of the boundary points to 0
    std::array<int, GL_NUM> area_sizes = calcFiniteAreas(grid);

    // select the largest area size
    std::cout << '\n';
    std::cout << "LARGEST AREA: " << getMax<int, GL_NUM>(area_sizes) << '\n';

    std::cout << '\n';
    grid.mapTotalDist(coords);
    //grid.drawTotalDist();

    std::cout << '\n';
    std::cout << "REGION SIZE: " << getRegionSize(grid) << '\n';
}


std::array<int, GL_NUM> calcFiniteAreas(const Grid &grid)
{
    std::array<int, GL_NUM> area_sizes;
    area_sizes.fill(0);

    // calculate each area size within the grid
    for ( int idx {0}; idx < grid.size(); ++idx)
        if ( grid[idx].closestIdx != -1 )
            area_sizes[grid[idx].closestIdx] += 1;

    // set the ones, wich are on the boundary to zero
    for ( int idx {0}; idx < grid.size(); ++idx)
        if ( grid.isBoundaryPoint(idx) )
            area_sizes[grid[idx].closestIdx] = 0;

    return area_sizes;
}


int getRegionSize(const Grid &grid)
{
    int regionSize {0};

    for (int idx {0}; idx < grid.size(); ++idx)
        if (grid[idx].totalDist < GL_TOT_DIST)
            ++regionSize;

    return regionSize;
}

Rectangle getSeekArea(const std::array<Point, GL_NUM> &coords)
{
    Point p1 = coords[0];
    Point p2 = p1;

    for (const auto &coord : coords)
    {
        // find the most left/up corner
        if ( coord.x < p1.x ) { p1.x = coord.x; }
        if ( coord.y < p1.y ) { p1.y = coord.y; }

        // find the most right/down corner
        if ( coord.x > p2.x ) { p2.x = coord.x; }
        if ( coord.y > p2.y ) { p2.y = coord.y; }
    }

    return Rectangle(p1, p2);
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

bool operator==(const Point &p1, const Point &p2)
{
    return (p1.x == p2.x && p1.y == p2.y);
}

int distance(const Point &p1, const Point &p2)
{
    // Manhattan-distance
    return abs(p1.x - p2.x) + abs(p1.y - p2.y);
}


void Grid::initGrid()
{
    for (int idx {0}; idx < size(); ++idx)
    {
        points[idx].x = offset_x + (idx % width);
        points[idx].y = offset_y + static_cast<int>(idx / width);
    }
}

void Grid::mapClosestIdx(const std::array<Point, GL_NUM> &coords)
{
    for (int i {0}; i < size(); ++i)
    {
        unsigned closestIdx {0};

        for (unsigned idx {1}; idx < GL_NUM; ++idx)
            if ( distance(points[i], coords[idx]) < distance(points[i], coords[closestIdx]) )
                closestIdx = idx;

        for (unsigned idx {0}; idx < GL_NUM; ++idx)
        {
            if ( idx == closestIdx ) continue;

            if ( distance(points[i], coords[idx]) == distance(points[i], coords[closestIdx]) )
            {
                closestIdx = -1;
                break;
            }
        }

        points[i].closestIdx = closestIdx;
    }
}

void Grid::mapTotalDist(const std::array<Point, GL_NUM> &coords)
{
    for (int i {0}; i < size(); ++i)
        for (unsigned idx {0}; idx < GL_NUM; ++idx)
            points[i].totalDist += distance(points[i], coords[idx]);
}

void Grid::drawClosestIdx() const
{
    for (int idx {0}; idx < size(); ++idx)
    {
        if ( points[idx].closestIdx != -1 )
            std::cout << points[idx].closestIdx << ' ';
        else
            std::cout << '.' << ' ';

        if ( (idx + 1) % width == 0)
            std::cout << '\n';
    }
}

void Grid::drawTotalDist() const
{
    for (int idx {0}; idx < size(); ++idx)
    {
        if ( points[idx].totalDist )
            std::cout << points[idx].totalDist << ' ';
        else
            std::cout << '.' << ' ';

        if ( (idx + 1) % width == 0)
            std::cout << '\n';
    }
}


bool Grid::isBoundaryPoint(int idx) const
{
    if ( idx % width == 0 || (idx + 1) % width == 0 ||
         int(idx / width) == 0 || int(idx / width) == (height - 1) )
        return true;
    else
        return false;
}

std::ostream& operator<<(std::ostream &out, const Grid &g)
{
    for (int idx {0}; idx < g.size(); ++idx)
    {
        out << g[idx] << ' ';

        if ( (idx + 1) % g.width == 0 && idx > 0)
            out << '\n';
    }

    return out;
}


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

/*

std::array<Point, GL_NUM> fillInCoords()
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

*/
