#ifndef DAY6_H
#define DAY6_H

// include libraries

#include <iostream>
#include <array>

// global variables/types

const unsigned int GL_NUM {6};

struct Point
{
    int x, y;
    Point(int x = 0, int y = 0) : x(x), y(y) {}

    friend std::ostream& operator<<(std::ostream &out, const Point &p);
    friend bool operator==(const Point &p1, const Point &p2);
};

struct Rectangle
{
    Point p1, p2;
    Rectangle(Point &p1, Point &p2) : p1(p1), p2(p2) {}

    friend std::ostream& operator<<(std::ostream &out, const Rectangle &r);
};

class Grid
{
private:
    int offset_x, offset_y;
    int width, height;

    Point *points;
    void initGrid();

public:
    Grid(Point &p1, Point &p2) : offset_x(p1.x), offset_y(p1.y),
        width(p2.x - p1.x + 1), height(p2.y - p1.y + 1)
    {
        points = new Point[width * height];

        initGrid();
    }

    int size() { return width * height; }
    Point& operator[](int idx) { return points[idx]; }

    void draw();
};

// function prototypes

void solveDay6();

//std::array<Point, GL_NUM> fillInCoords();

std::array<Point, GL_NUM> fillInCoordsTest();

int getLargestArea(const std::array<Point, GL_NUM> &coords);

Rectangle getSeekRect(const std::array<Point, GL_NUM> &coords);

void printCoords(const std::array<Point, GL_NUM> &coords);

#endif DAY6_H
