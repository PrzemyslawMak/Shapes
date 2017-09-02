#ifndef __ISHAPE__
#define __ISHAPE__

namespace Shapes
{

//Base abstract class for shape objects
class IShape {
public:
	IShape();
	IShape(double a_dWidth, double a_dHeight);
	virtual ~IShape(){}
	virtual double getArea() = 0 ;
	virtual void setWidth (double a_dWidth) = 0 ;
	virtual void setHeight (double a_dHeight) = 0 ;               
	virtual double getWidth () = 0 ;
	virtual double getHeight () = 0 ;               
private:
	double m_dWidth ;
	double m_dHeight ;
};

}// namespace Shapes
#endif //__ISHAPE__