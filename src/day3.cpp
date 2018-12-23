#include "day3.h"

void solveDay3()
{
    std::cout << "Day3 has started!" << '\n';

    std::vector<Claim> claims = readFile<Claim>("day3.txt");

    printVector<Claim>(claims);

    Rectangle gridArea = day3::getGridArea(claims);
    std::cout << gridArea;

    day3::Grid grid(gridArea);

    grid.mapOverlap(claims);
    // grid.drawOverlap();

    std::cout << '\n';
    std::cout << "CROSS AREA SIZE: " << getCrossAreaSize(grid) << std::endl;
}

std::ostream& operator<<(std::ostream &out, const Claim &c)
{
    out << '#' << c.ID << " @ " << c.offset_x << ',' << c.offset_y << ": " << c.width << 'x' << c.height;

    return out;
}

std::istream& operator>>(std::istream &in, Claim &c)
{
    std::string skip; // used to ignore unnecessary characters

    std::getline(in, skip, '#');
    in >> c.ID;
    std::getline(in, skip, '@');
    in >> c.offset_x;
    std::getline(in, skip, ',');
    in >> c.offset_y;
    std::getline(in, skip, ':');
    in >> c.width;
    std::getline(in, skip, 'x');
    in >> c.height;

    return in;
}

bool operator==(const Claim &c1, const Claim &c2)
{
    return c1.ID == c2.ID;
}

namespace day3 {


void Grid::initGrid()
{
    for (unsigned idx {0}; idx < size(); ++idx)
    {
        points[idx].x = offset_x + (idx % width);
        points[idx].y = offset_y + static_cast<int>(idx / width);
    }
}

void Grid::mapOverlap(const std::vector<Claim> &claims)
{
    int count {0};
    for (unsigned i {0}; i < claims.size(); ++i)
    {
        std::cout << "CLAIM1: " << claims[i] << '\n';
        for (unsigned j {i}; j < claims.size(); ++j)
        {
            if (i == j) continue;

            std::vector<Point> crossPoints = getCrossPoints(claims[i], claims[j]);

            if (crossPoints.empty()) continue;

            for (const auto &point : crossPoints)
                for (unsigned idx {0}; idx < size(); ++idx)
                    if (points[idx] == point) { points[idx].overlap = true; }
        }
    }
}


std::vector<Point> getCrossPoints(const Rectangle &r1, const Rectangle &r2)
{
    std::vector<Point> crossPoints;

    // check if there is cross section
    if (r2.offset_x > r1.offset_x + r1.width || r2.offset_x + r2.width < r1.offset_x ||
        r2.offset_y > r1.offset_y + r1.height || r2.offset_y + r2.height < r1.offset_y )
        return crossPoints;

    // calculate cross section boundaries
    int x_min = r2.offset_x >= r1.offset_x ? r2.offset_x : r1.offset_x;
    int x_max = r2.offset_x >= r1.offset_x ? (r1.offset_x + r1.width) : (r2.offset_x + r2.width);

    int y_min = r2.offset_y >= r1.offset_y ? r2.offset_y : r1.offset_y;
    int y_max = r2.offset_y >= r1.offset_y ? (r1.offset_y + r1.height) : (r2.offset_y + r2.height);

    // push the cross points to a vector
    for (int x {x_min + 1}; x < (x_max + 1); ++x)
        for (int y {y_min + 1}; y < (y_max + 1); ++y)
            crossPoints.push_back(Point(x, y));

    return crossPoints;
}


void Grid::drawOverlap() const
{
    for (unsigned idx {0}; idx < size(); ++idx)
    {
        if ( points[idx].overlap )
            std::cout << 'X';
        else
            std::cout << '.';

        if ( (idx + 1) % width == 0)
            std::cout << '\n';
    }
}

Rectangle getGridArea(const std::vector<Claim> &claims)
{
    Point p1 = Point(claims[0].offset_x, claims[0].offset_y);
    Point p2 = p1;

    for (const auto &claim : claims)
    {
        // find the most left/up corner
        if ( claim.offset_x < p1.x ) { p1.x = claim.offset_x; }
        if ( claim.offset_y < p1.y ) { p1.y = claim.offset_y; }

        // find the most right/down corner
        if ( (claim.offset_x + claim.width) > p2.x ) { p2.x = claim.offset_x + claim.width; }
        if ( (claim.offset_y + claim.height) > p2.y ) { p2.y = claim.offset_y + claim.height; }
    }

    return Rectangle(p1, p2);
}

}

int getCrossAreaSize(const day3::Grid &grid)
{
    int crossAreaSize {0};

    for (unsigned idx {0}; idx < grid.size(); ++idx)
        if (grid[idx].overlap)
            ++crossAreaSize;

    return crossAreaSize;
}
