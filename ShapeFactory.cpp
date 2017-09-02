#include "ShapeFactory.h"
#include "Shapes.h"
#include "ShapeException.h"

namespace Shapes
{

ShapeFactory::~ShapeFactory(void)
{
	Destroy();
}

ShapeFactory& ShapeFactory::getInstance()
{
	static ShapeFactory instance;
	return instance;
}

void ShapeFactory::Destroy()
{
	for ( std::vector<IShape*>::iterator i = mObjectRegister.begin(); i != mObjectRegister.end(); ++i )
	{
		//This should work, but if somewhere outside the factory object created by factory will be destroyed the it will lead double delete and it will break
		if (*i)
		{
			delete *i;
			*i = NULL;
		}
	}
	mObjectRegister.clear();
}

bool ShapeFactory::IsFactoryChildren(IShape* a_oShapeObj)
{
	bool result = false;
	for ( std::vector<IShape*>::iterator i = mObjectRegister.begin(); i != mObjectRegister.end(); ++i )
	{
		if (*i == a_oShapeObj)
		{
			result = true;
			break;
		}
	}
	return result;
}

IShape* ShapeFactory::CreateShapeInstance(ShapeEnum  a_eShape)
{
	IShape* result = NULL;
	switch (a_eShape){
	case POINT:
		result = new MyPoint;
		break;
	case LINE_SEGMENT:
		result = new LineSegment;
		break;
	case TRIANGLE:
		result = new Triangle;
		break;
	case RECTANGLE:
		result = new MyRectangle;
		break;
	case SQUARE:
		result = new Square;
		break;
	case CIRCLE:
		result = new Circle;
		break;
	default:
		throw(ShapeException("Unknown shape was used in ShapeFactory::CreateShapeInstance"));
		break;
	}
	if(result)
	{
		mObjectRegister.push_back(result);
	}
	return result;
}

std::string ShapeFactory::ShapeEnumName(ShapeEnum a_eShape)
{
	switch (a_eShape){
	case POINT:
		return "Point";
	case LINE_SEGMENT:
		return "LineSegment";
	case TRIANGLE:
		return "Triangle";
	case RECTANGLE:
		return "Rectangle";
	case SQUARE:
		return "Square";
	case CIRCLE:
		return "Circle";
	default:
		return "Undefined";
	}
}

}//namespace Shapes
