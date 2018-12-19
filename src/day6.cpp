#include "day6.h"

void solveDay6()
{
    std::array<Point, GL_NUM> coords = fillInCoords();

    printCoords(coords);
}


int getLargestArea(std::array<Point, GL_NUM> &coords)
{

    return 1;
}



void printCoords(std::array<Point, GL_NUM> &coords)
{
    for (const auto &coord : coords)
        std::cout << coord.x << ", " << coord.y << '\n';
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
