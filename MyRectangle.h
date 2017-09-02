#ifndef __MY_RECTANGLE__
#define __MY_RECTANGLE__

#include "IShape.h"

namespace Shapes
{

//Shape specification class
class MyRectangle :
	public IShape
{
public:
	MyRectangle(void);
	MyRectangle(double a_dWidth, double a_dHeight);
	~MyRectangle(void);

	virtual double getArea();
	virtual void setWidth (double a_dWidth);
	virtual void setHeight (double a_dHeight);               
	virtual double getWidth ();
	virtual double getHeight ();
};

}//namespace Shapes
#endif //__MY_RECTANGLE__