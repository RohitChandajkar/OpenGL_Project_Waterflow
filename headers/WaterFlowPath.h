#pragma once

#include "Triangulation.h"
#include "Point3D.h"
#include "ElevationFinder.h"


class WaterFlowPath
{

public:
	vector<Point3D> findWaterFlowPath(Triangulation& terrain);

	Point3D nextPoint(Point3D& currentpoint, Triangulation& terrain);

	vector<Point3D> generatedPath(Point3D& hghestpoint, Triangulation& terrain);
private:
	ElevationFinder ElevationFinder;
};