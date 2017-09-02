#include "Triangle.h"

namespace Shapes
{

Triangle::Triangle():
	IShape(0,0)
{
}

Triangle::Triangle(double a_dWidth, double a_dHeight):
	IShape(a_dWidth,a_dHeight)
{
}

Triangle::~Triangle()
{
}

double Triangle::getArea()
{
	return IShape::getWidth()*IShape::getHeight()*0.5;
}

void Triangle::setWidth (double a_dWidth)
{
	IShape::setWidth(a_dWidth);
	return;
}

void Triangle::setHeight (double a_dHeight)
{
	IShape::setHeight(a_dHeight);
	return;
}

double Triangle::getWidth ()
{
	return IShape::getWidth();
}

double Triangle::getHeight ()
{
	return IShape::getHeight();
}

}//namespace Shapes