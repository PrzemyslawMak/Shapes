#include "ShapeFactory.h"
#include "Shapes.h"
#include "ShapeUtils.h"
#include <iostream>

namespace Shapes
{

void shapeInfo(IShape* a_oShapeObj)
{
	using std::cout;
	using std::endl;
	if(!a_oShapeObj)
	{
		cout << "ERROR!!!\nThis pointer is no longer valid. There is no info that could be given." <<endl;
		return;
	}
	cout << "Shape Type is: " << ShapeFactory::ShapeEnumName(getShapeType(a_oShapeObj)) << endl;
	cout << "Shape width: " << a_oShapeObj->getWidth() <<", height: " << a_oShapeObj->getHeight() << ", area: " << a_oShapeObj->getArea() <<
		". This object was " << (ShapeFactory::getInstance().IsFactoryChildren(a_oShapeObj)?"":"not ") << "created by shape factory." << endl; 
}

ShapeFactory::ShapeEnum getShapeType(IShape* a_oShapeObj)
{
	if(dynamic_cast<MyPoint*>(a_oShapeObj))
		return ShapeFactory::POINT;
	else if(dynamic_cast<LineSegment*>(a_oShapeObj))
		return ShapeFactory::LINE_SEGMENT;
	else if(dynamic_cast<Triangle*>(a_oShapeObj))
		return ShapeFactory::TRIANGLE;
	else if(dynamic_cast<MyRectangle*>(a_oShapeObj))
		return ShapeFactory::RECTANGLE;
	else if(dynamic_cast<Square*>(a_oShapeObj))
		return ShapeFactory::SQUARE;
	else if(dynamic_cast<Circle*>(a_oShapeObj))
		return ShapeFactory::CIRCLE;
	else
		return ShapeFactory::UNDEFINED;
}

}//namespace Shapes
