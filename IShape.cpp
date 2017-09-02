#include "IShape.h"
#include "ShapeException.h"

namespace Shapes
{
//Although IShape class is pure virtual class, and all of its functions need to be redefined by derived class
//the default implementation of this functions has been implemented for set/get functions
//since m_dWidth and m_dHeight members are private it would be impossible for derived class to access that data members without those default implementations.
IShape::IShape():
	m_dWidth(0),
	m_dHeight(0)
{
}	

IShape::IShape(double a_dWidth, double a_dHeight):
	m_dWidth(a_dWidth),
	m_dHeight(a_dHeight)
{
}

void IShape::setWidth (double a_dWidth)
{
	if(a_dWidth < 0)
	{
		ShapeException("Setting shape width to negative value is disallowed.");
	}
	m_dWidth = a_dWidth;
}

void IShape::setHeight (double a_dHeight)
{
	if(a_dHeight < 0)
	{
		ShapeException("Setting shape height to negative value is disallowed.");
	}
	m_dHeight = a_dHeight;
}

double IShape::getWidth ()
{
	return m_dWidth;
}

double IShape::getHeight ()
{
	return m_dHeight;
}

}//namespace Shapes
