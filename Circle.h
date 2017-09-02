#ifndef __CIRCLE__
#define __CIRCLR__

#include "IShape.h"

namespace Shapes
{

//Shape specification class	
class Circle :
	public IShape
{
public:
	Circle(void);
	Circle(double a_dWidth);
	~Circle(void);

	virtual double getArea();
	virtual void setWidth (double a_dWidth);
	virtual void setHeight (double a_dHeight);               
	virtual double getWidth ();
	virtual double getHeight ();
};

}//namespace Shapes
#endif //__CIRCLE__