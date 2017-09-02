#ifndef __SHAPE_UTILS__
#define __SHAPE_UTILS__

namespace Shapes
{

//Helper functions
//Display information on console about shape object (type, width, height, area and whether this object was created by ShapeFactory)
void shapeInfo(IShape* a_oShapeObj);
ShapeFactory::ShapeEnum getShapeType(IShape* a_oShapeObj);

}//namespace Shapes
#endif // __SHAPE_UTILS__
