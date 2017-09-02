#pragma once
#include <string>
#include <vector>

namespace Shapes
{

class IShape;

//Singleton function used to create shape objects
class ShapeFactory
{
public:
	enum ShapeEnum 
	{
		POINT,
		LINE_SEGMENT,
		TRIANGLE,
		RECTANGLE,
		SQUARE,
		CIRCLE,
		UNDEFINED
	};

	static ShapeFactory& getInstance();
	IShape* CreateShapeInstance(ShapeEnum  a_eShape);
	void Destroy();
	bool IsFactoryChildren(IShape* a_oShapeObj);
	//translate shape enum value to a string
	static std::string ShapeEnumName(ShapeEnum a_eShape);
private:
	ShapeFactory(){}
	~ShapeFactory();
	ShapeFactory(const ShapeFactory&); //do not implement
	ShapeFactory& operator=(const ShapeFactory&); //do not implement
	//in C++ 11 use = delete for copy constructor and assignment operator

	//Vector that is used to register all created objects
	std::vector<IShape*> mObjectRegister;
};

}//namespace Shapes
