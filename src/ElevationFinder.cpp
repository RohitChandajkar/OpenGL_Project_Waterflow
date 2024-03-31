#include"stdafx.h"

#include <cmath>

#include"ElevationFinder.h"

double ElevationFinder::distanceTo(Point3D point1, Point3D point2)
{
	double dx = point2.x() - point1.x();
	double dy = point2.y() - point1.y();
	double dz = point2.z() - point1.z();
	double distance = std::sqrt(dx * dx + dy * dy + dz * dz);
	return std::abs(dz / distance);
}

Point3D ElevationFinder::findHighestPoint(Triangulation& triangulation)
{
	vector<Point3D> points = triangulation.uniquePoints();
	double highestpoint = std::numeric_limits<double>::lowest();
	Point3D answer;
	for (auto point : points)
	{
		double high = point.z();
		if (high > highestpoint)

		{
			highestpoint = high;
			answer = point;
		}
	}

	return answer;

}
//Point3D ElevationFinder::findlowestPoint(Triangulation& triangulation)
//{
//	vector<Point3D> points = triangulation.uniquePoints();
//	double lowestpoint = std::numeric_limits<double>::max();  //put highest value of z
//	Point3D answer;
//	for (auto point : points)
//	{
//		double low = point.y();
//		if (low < lowestpoint)
//
//		{
//			lowestpoint = low;
//			answer = point;
//		}
//	}
//
//	return answer;
//
//}

Point3D ElevationFinder::findlowestPoint(Triangulation& triangulation)
{
    vector<Point3D> points = triangulation.uniquePoints();
    double lowestZ = std::numeric_limits<double>::max(); // Initialize lowest y-coordinate
    double highestX = -std::numeric_limits<double>::max(); // Initialize highest x-coordinate
    Point3D answer;

    // Find the lowest y-coordinate value
    for (auto point : points)
    {
        double z = point.z();
        if (z < lowestZ)
        {
            lowestZ = z;
        }
    }

    // Find the point(s) with the lowest y-coordinate value
    vector<Point3D> lowestYPoints;
    for (auto point : points)
    {
        if (point.z() == lowestZ)
        {
            lowestYPoints.push_back(point);
        }
    }

    // Find the point with the highest x-coordinate among the points with the lowest y-coordinate
    for (auto point : lowestYPoints)
    {
        double y = point.y();
        if (y > highestX)
        {
            highestX = y;
            answer = point;
        }
    }

    return answer;
}
