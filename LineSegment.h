#ifndef __LINE_SEGMENT__
#define __LINE_SEGMENT__

#include "IShape.h"

namespace Shapes
{

//Shape specification class
class LineSegment :
	public IShape
{
public:
	LineSegment();
	LineSegment(double a_dWidth);
	~LineSegment();

	virtual double getArea();
	virtual void setWidth (double a_dWidth);
	virtual void setHeight (double a_dHeight);               
	virtual double getWidth ();
	virtual double getHeight ();
};

}//namespace Shapes
#endif //__LINE_SEGMENT__