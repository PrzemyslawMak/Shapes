#include "Circle.h"

namespace Shapes
{

Circle::Circle(void)
{
}

Circle::Circle(double a_dWidth):
	IShape(a_dWidth,0)
{
}

Circle::~Circle(void)
{
}

double Circle::getArea()
{
	const double PI_4 = 0.785398163397448309616; //Approximated value of Pi divided by 4
	//Since in circle shape height must be equal to width, only width is used
	return PI_4*IShape::getWidth()*IShape::getWidth();
}

void Circle::setWidth (double a_dWidth)
{
	if(a_dWidth<0)

	IShape::setWidth(a_dWidth);
	return;
}

void Circle::setHeight (double a_dHeight)
{
	//Since in circle shape height must be equal to width, only width is used
	IShape::setWidth(a_dHeight);
	return;
}

double Circle::getWidth ()
{
	return IShape::getWidth();
}

double Circle::getHeight ()
{
	//Since in circle shape height must be equal to width, only width is used
	return IShape::getWidth();
}

}//namespace Shapes
