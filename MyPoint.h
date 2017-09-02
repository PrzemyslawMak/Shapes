#ifndef __MY_POINT__
#define __MY_POINT__

#include "IShape.h"

namespace Shapes
{

//Shape specification class
class MyPoint :
	public IShape
{
public:
	MyPoint();
	~MyPoint();

	virtual double getArea();
	virtual void setWidth (double a_dWidth);
	virtual void setHeight (double a_dHeight);               
	virtual double getWidth ();
	virtual double getHeight ();
};

}//namespace Shapes
#endif //__MY_POINT__