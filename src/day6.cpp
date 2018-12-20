#include "day6.h"


void solveDay6()
{
    // fill in the initial array with the coordinates
    std::array<Point, GL_NUM> coords = fillInCoords();
    printCoords(coords);

    // the coordinates of start and end point
    Point P_start = Point(0, 0);
    Point P_end = getEndPoint(coords);

    // build up the grid covered by the seek area
    Grid grid(P_start, P_end);
    //std::cout << grid << '\n';

    grid.map(coords);
    grid.draw(coords);

    // calculate area sizes and set the area of the boundary points to 0
    std::array<int, GL_NUM> size_area = calcAreas(grid);

    std::vector<int> boundIdx = getBoundPointIdx(coords);

    std::array<int, GL_NUM> size_area_filtered = filterAreas(size_area, boundIdx);

    // select the largest area size
    std::cout << '\n' << "LARGEST AREA: " << getMax<int, GL_NUM>(size_area_filtered) << '\n';
}

std::array<int, GL_NUM> calcAreas(const Grid &grid)
{
    std::array<int, GL_NUM> sum;
    sum.fill(0);

    for ( int point {0}; point < grid.size(); ++point)
    {
        if ( grid[point].closestIdx != -1 )
            sum[grid[point].closestIdx] += 1;
    }
    return sum;
}

std::vector<int> getBoundPointIdx(const std::array<Point, GL_NUM> &coords)
{
    std::vector<int> pointIdx;
    Rectangle bound = getBoundRect(coords);

    for (unsigned idx {0}; idx < coords.size(); ++idx)
    {
        if (    coords[idx].x <= bound.x_min || coords[idx].x >= bound.x_max ||
                coords[idx].y <= bound.y_min || coords[idx].y >= bound.y_max    )
        {
            pointIdx.push_back(idx);
        }
    }
    return pointIdx;
}


Rectangle getBoundRect(const std::array<Point, GL_NUM> &coords)
{
    Rectangle b(coords[0].x, coords[0].y, coords[0].x, coords[0].y);

    for (unsigned idx {0}; idx < coords.size(); ++idx)
    {
        if ( coords[idx].x < b.x_min )
            b.x_min = coords[idx].x;

        if ( coords[idx].x > b.x_max )
            b.x_max = coords[idx].x;

        if ( coords[idx].y < b.y_min )
            b.y_min = coords[idx].y;

        if ( coords[idx].y > b.y_max )
            b.y_max = coords[idx].y;
    }

    return b;
}


std::array<int, GL_NUM>& filterAreas(std::array<int, GL_NUM> &areas, const std::vector<int> &boundIdx)
{
    for (const auto &idx : boundIdx)
        areas[idx] = 0;

    return areas;
}


Point getEndPoint(const std::array<Point, GL_NUM> &coords)
{
    int max_xy {0};

    for (const auto &coord : coords)
    {
        // find the most right/down corner
        if ( coord.x > max_xy || coord.y > max_xy )
            max_xy = coord.x > coord.y ? coord.x : coord.y;
    }

    return Point(max_xy, max_xy);
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
            if ( points[idx] == coords[points[idx].closestIdx] )
                std::cout << static_cast<char>(points[idx].closestIdx + 65) << ' ';
            else
                std::cout << static_cast<char>(points[idx].closestIdx + 97) << ' ';
        }
        else
            std::cout << '.' << ' ';

        if ( (idx + 1) % width == 0 && idx > 0)
            std::cout << '\n';
    }
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

