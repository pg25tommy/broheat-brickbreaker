//
// * ENGINE-X
//
// + Types.h
// representations of: 2D vector with floats, 2D vector with integers and RBGA color as four bytes
//

#pragma once

//-----------------------------------------------------------------
//-----------------------------------------------------------------

struct exVector2
{
    float x, y;

    // Constructor to initialize x and y. Default values are 0.0f
    exVector2(float xVal = 0.0f, float yVal = 0.0f) : x(xVal), y(yVal) {}

    // Overload the + operator
    exVector2 operator+(const exVector2& rhs) const {
        return exVector2(x + rhs.x, y + rhs.y);
    }

    // Overload the - operator
    exVector2 operator-(const exVector2& rhs) const {
        return exVector2(x - rhs.x, y - rhs.y);
    }
};

//-----------------------------------------------------------------
//-----------------------------------------------------------------

struct exIntegerVector2
{
    int x, y;
};

//-----------------------------------------------------------------
//-----------------------------------------------------------------

struct exColor
{
    unsigned char mColor[4];
};
