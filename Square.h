#ifndef __SQUARE__
#define __SQUARE__

#include "IShape.h"

namespace Shapes
{

//Shape specification class
class Square :
	public IShape
{
public:
	Square(void);
	Square(double a_dWidth);
	~Square(void);

	virtual double getArea();
	virtual void setWidth (double a_dWidth);
	virtual void setHeight (double a_dHeight);               
	virtual double getWidth ();
	virtual double getHeight ();
};

}//namespace Shapes
#endif //__SQUARE__
