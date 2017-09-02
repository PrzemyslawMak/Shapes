#include "LineSegment.h"

namespace Shapes
{

LineSegment::LineSegment():
	IShape()
{
}

LineSegment::LineSegment(double a_dWidth):
	IShape(a_dWidth,0)
{
}

LineSegment::~LineSegment()
{
}

double LineSegment::getArea()
{
	//The area of line segment is always 0
	return 0.0;
}

void LineSegment::setWidth (double a_dWidth)
{
	IShape::setWidth(a_dWidth);
	return;
}

void LineSegment::setHeight (double a_dHeight)
{
	//Line segment Height is always 0, it can not be changed to any other value
	return;
}

double LineSegment::getWidth ()
{
	return IShape::getWidth();
}

double LineSegment::getHeight ()
{
	//Line segment has always height = 0
	return 0.0;
}

}//namespace Shapes
