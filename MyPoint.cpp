#include "MyPoint.h"

namespace Shapes
{

MyPoint::MyPoint():
	IShape()
{
}

MyPoint::~MyPoint()
{
}

double MyPoint::getArea()
{
	//The area of point is always 0
	return 0.0;
}

void MyPoint::setWidth (double a_dWidth)
{
	//Point has always Width = 0, it can not be changed to any other value
	return;
}

void MyPoint::setHeight (double a_dHeight)
{
	//Point has always Height = 0, it can not be changed to any other value
	return;
}

double MyPoint::getWidth ()
{
	//Point has always width = 0
	return 0.0;
}

double MyPoint::getHeight ()
{
	//Point has always height = 0
	return 0.0;
}

}//namespace Shapes
