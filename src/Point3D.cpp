#include "stdafx.h"
#include "Point3D.h"

Point3D::Point3D()
{
    mX = 0.0;
    mY = 0.0;
    mZ = 0.0;
}
Point3D::Point3D(double inX, double inY, double inZ)
{
    mX = inX;
    mY = inY;
    mZ = inZ;
}
Point3D ::~Point3D()
{
}
double Point3D::x()
{
    return mX;
}
double Point3D::y()
{
    return mY;
}
double Point3D::z()
{
    return mZ;
}

void Point3D::setX(double x)
{
    mX = x;
}
void Point3D::setY(double y)
{
    mY = y;
}
void Point3D::setZ(double z)
{
    mZ = z;
}
//operator Overloading
bool Point3D::operator<(const Point3D& other) const
{
    if (mX < other.mX)
        return true;
    if (mX > other.mX)
        return false;

    if (mY < other.mY)
        return true;
    if (mY > other.mY)
        return false;

    return mZ < other.mZ;
}

Point3D& Point3D:: operator=(const Point3D& other) {
    if (this != &other) {
        mX = other.mX;
        mY = other.mY;
        mZ = other.mZ;
    }
    return *this;
}

bool  Point3D::operator==(const Point3D& other) const
{

    if (mX == other.mX and mY == other.mY and mZ == other.mZ)
        return true;
    return false;
}