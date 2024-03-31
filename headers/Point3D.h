#pragma once
#include "stdafx.h"
class Point3D
{
public:
    Point3D();
    Point3D(double inX, double inY, double inZ);
    ~Point3D();
    double x();
    double y();
    double z();
    void setX(double x);
    void setY(double y);
    void setZ(double z);
    bool operator<(const Point3D& other) const;
    Point3D& operator=(const Point3D& other);
    bool operator==(const Point3D& other) const;


private:
    double mX;
    double mY;
    double mZ;
};