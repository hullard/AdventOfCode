#include "day3.h"

void solveDay3()
{
    std::cout << "Day3 has started!" << '\n';

    std::vector<Claim> claims = readFile<Claim>("day3.txt");

    printVector<Claim>(claims);
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



