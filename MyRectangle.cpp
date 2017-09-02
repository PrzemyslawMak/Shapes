#include "MyRectangle.h"

namespace Shapes
{

MyRectangle::MyRectangle():
	IShape()
{
}

MyRectangle::MyRectangle(double a_dWidth, double a_dHeight):
	IShape(a_dWidth,a_dHeight)
{
}

MyRectangle::~MyRectangle()
{
}

double MyRectangle::getArea()
{
	return IShape::getWidth()*IShape::getHeight();
}

void MyRectangle::setWidth (double a_dWidth)
{
	IShape::setWidth(a_dWidth);
	return;
}

void MyRectangle::setHeight (double a_dHeight)
{
	IShape::setHeight(a_dHeight);
	return;
}

double MyRectangle::getWidth ()
{
	return IShape::getWidth();
}

double MyRectangle::getHeight ()
{
	return IShape::getHeight();
}

}//namespace Shapes