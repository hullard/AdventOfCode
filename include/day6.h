#ifndef DAY6_H
#define DAY6_H

// include libraries

#include <iostream>
#include <array>

// global variables/types

const unsigned int GL_NUM {50};

struct Point
{
    int x, y;
};

// function prototypes

void solveDay6();

std::array<Point, GL_NUM> fillInCoords();

int getLargestArea(std::array<Point, GL_NUM> &coords);

void printCoords(std::array<Point, GL_NUM> &coords);

#endif DAY6_H
