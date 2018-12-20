#include "day6.h"


void solveDay6()
{
    // fill in the initial array with the coordinates
    std::array<Point, GL_NUM> coords = fillInCoords();
    printCoords(coords);

    // determine the seek area, which is the covering rectangle
    Rectangle seekArea = getSeekArea(coords);

    // build up the grid covered by the seek area
    Grid grid(seekArea.p1, seekArea.p2);
    //std::cout << grid << '\n';

    grid.map(coords);
    //grid.draw(coords);

    // calculate area sizes and set the area of the boundary points to 0
    std::array<int, GL_NUM> area_sizes = calcFiniteAreas(grid);

    // select the largest area size
    std::cout << '\n' << "LARGEST AREA: " << getMax<int, GL_NUM>(area_sizes) << '\n';
}

std::array<int, GL_NUM> calcFiniteAreas(const Grid &grid)
{
    std::array<int, GL_NUM> area_sizes;
    area_sizes.fill(0);

    // calculate each area size within the grid
    for ( int point {0}; point < grid.size(); ++point)
    {
        if ( grid[point].closestIdx != -1 )
            area_sizes[grid[point].closestIdx] += 1;
    }

    // set the ones, wich are on the boundary to zero
    for ( int point {0}; point < grid.size(); ++point)
    {
        if ( grid.isBoundary(point) )
            area_sizes[grid[point].closestIdx] = 0;
    }

    return area_sizes;
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

void Grid::map(const std::array<Point, GL_NUM> &coords)
{
    for (int i {0}; i < size(); ++i)
    {
        unsigned closestIdx {0};

        for (unsigned j {1}; j < GL_NUM; ++j)
        {
            if ( distance(points[i], coords[j]) < distance(points[i], coords[closestIdx]) )
                closestIdx = j;
        }

        for (unsigned j {0}; j < GL_NUM; ++j)
        {
            if ( j == closestIdx ) continue;

            if ( distance(points[i], coords[j]) == distance(points[i], coords[closestIdx]) )
            {
                closestIdx = -1;
                break;
            }
        }

        points[i].closestIdx = closestIdx;
    }
}


void Grid::draw(const std::array<Point, GL_NUM> &coords)
{
    for (int idx {0}; idx < size(); ++idx)
    {
        if ( points[idx].closestIdx != -1 )
        {
        /*
            if ( points[idx] == coords[points[idx].closestIdx] )
                std::cout << static_cast<char>(points[idx].closestIdx + 65) << ' ';
            else
                std::cout << static_cast<char>(points[idx].closestIdx + 97) << ' ';
        */
            std::cout << points[idx].closestIdx << ' ';
        }
        else
            std::cout << '.' << ' ';

        if ( (idx + 1) % width == 0)
            std::cout << '\n';
    }
}

bool Grid::isBoundary(int idx) const
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
