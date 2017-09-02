#ifndef __TRIANGLE__
#define __TRIANGLE__

#include "IShape.h"

namespace Shapes
{

//Shape specification class
class Triangle :
	public IShape
{
public:
	Triangle();
	Triangle(double a_dWidth, double a_dHeight);
	~Triangle();

	virtual double getArea();
	virtual void setWidth (double a_dWidth);
	virtual void setHeight (double a_dHeight);               
	virtual double getWidth ();
	virtual double getHeight ();
};

}//namespace Shapes
#endif //__TRIANGLE__