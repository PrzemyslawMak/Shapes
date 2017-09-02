#include "Square.h"

namespace Shapes
{

Square::Square()
{
}

Square::Square(double a_dWidth):
	IShape(a_dWidth,0)
{
}

Square::~Square()
{
}

double Square::getArea()
{
	//Since in Square shape height must be equal to width, only width is used
	return IShape::getWidth()*IShape::getWidth();
}

void Square::setWidth (double a_dWidth)
{
	IShape::setWidth(a_dWidth);
	return;
}

void Square::setHeight (double a_dHeight)
{
	//Since in Square shape height must be equal to width, only width is used
	IShape::setWidth(a_dHeight);
	return;
}

double Square::getWidth ()
{
	return IShape::getWidth();
}

double Square::getHeight ()
{
	//Since in Square shape height must be equal to width, only width is used
	return IShape::getWidth();
}

}//namespace Shapes
