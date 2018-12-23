#include "day3.h"

void solveDay3()
{
    std::cout << "Day3 has started!" << '\n';

    std::vector<day3::Claim> claims = readFile<day3::Claim>("day3.txt");

    printVector<day3::Claim>(claims);
}

namespace day3 {

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

void Grid::initGrid()
{
    for (unsigned idx {0}; idx < size(); ++idx)
    {
        points[idx].x = offset_x + (idx % width);
        points[idx].y = offset_y + static_cast<int>(idx / width);
    }
}

void Grid::drawOverlap() const
{
    for (unsigned idx {0}; idx < size(); ++idx)
    {
        if ( points[idx].overlap )
            std::cout << 'X';
        else
            std::cout << ' ';

        if ( (idx + 1) % width == 0)
            std::cout << '\n';
    }
}

}
