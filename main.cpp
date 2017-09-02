#include <iostream>
#include "ShapeException.h"
#include "ShapeFactory.h"
#include "Shapes.h"
#include "ShapeUtils.h"

//This simple demo program create some Shape objects using two methods: a ShapeFactory and new
//Then modifies this objects (using setWidth, setHeight functions)
//Then the objects are destroyed (using Destroy function for objects created with ShapeFactory and delete for the ones created with new)
//Changes in the object state are printed on the console (using shapeInfo function).
int main(int argc, char* argv[])
{
	using std::cout;
	using std::cin;
	using std::endl;
	using namespace Shapes;
	const size_t SHAPE_OBJECTS_COUNT=9;
	IShape* shapeObjects[SHAPE_OBJECTS_COUNT];
	try{
		//Creating some shape objects
		shapeObjects[0] = new MyPoint();
		ShapeFactory& f = ShapeFactory::getInstance();
		shapeObjects[1] = f.CreateShapeInstance(ShapeFactory::POINT);
		shapeObjects[2] = f.CreateShapeInstance(ShapeFactory::LINE_SEGMENT);
		shapeObjects[3] = f.CreateShapeInstance(ShapeFactory::TRIANGLE);
		shapeObjects[4] = new Triangle(2.0,3.5);
		shapeObjects[5] = f.CreateShapeInstance(ShapeFactory::RECTANGLE);
		shapeObjects[6] = f.CreateShapeInstance(ShapeFactory::SQUARE);
		shapeObjects[7] = f.CreateShapeInstance(ShapeFactory::CIRCLE);
		shapeObjects[8] = new Circle(3.33);
	} catch (const ShapeException& e){
		//Crating some had coded Shape object. This should never happen when executing this code.
		cout << e.what() << endl;
		cout << "This should never happen. Something is very wrong. Exiting." << endl;
		return -1;
	} catch (const std::bad_alloc& e){ 
		cout << "Memory allocation failed. " << e.what() << endl;
		cout << "Exiting." << endl;
		return -1;
	}

	cout << "Initial state of shape objects in application is:" << endl;
	for(size_t i=0; i<SHAPE_OBJECTS_COUNT; i++)
		shapeInfo(shapeObjects[i]);

	cout << "Setting width and height of objects to index, index+1" << endl;
	for(size_t i=0; i<SHAPE_OBJECTS_COUNT; i++)
	{
		//Using virtual interface to manipulate Shape objects.
		//Set functions can throw exceptions i negative value is used
		//since "i" is always positive exceptions are not catch here
		shapeObjects[i]->setWidth(i);
		shapeObjects[i]->setHeight(i+1);
	}

	cout << "State of shape objects after setting width and height:" << endl;
	for(size_t i=0; i<SHAPE_OBJECTS_COUNT; i++)
		shapeInfo(shapeObjects[i]);

	cout << "Increasing width by factor of 2 and height by factor of 1.7:" << endl;
	for(size_t i=0; i<SHAPE_OBJECTS_COUNT; i++)
	{
		//Using virtual interface to manipulate Shape objects.
		//Set functions can throw exceptions i negative value is used
		//since "i" is always positive exceptions are not catch here
		shapeObjects[i]->setWidth(shapeObjects[i]->getWidth()*2.0);
		shapeObjects[i]->setHeight(shapeObjects[i]->getHeight()*1.7);
	}

	cout << "State of shape objects after modifying width and height:" << endl;
	for(size_t i=0; i<SHAPE_OBJECTS_COUNT; i++)
		shapeInfo(shapeObjects[i]);

	cout << "Destroying all objects created by shape factory" << endl;
	for(size_t i=0; i<SHAPE_OBJECTS_COUNT; i++)
	{
		//Setting all pointers that was obtained from shape factory to null
		//After calling Destroy function there would point to memory that was already deleted
		//This would lead to undefined behavior. To prevent that this pointers will be set to point to NULL
		//Other functions check if the pointer is valid (not equal NULL) before trying to dereference it.
		if(ShapeFactory::getInstance().IsFactoryChildren(shapeObjects[i]))
			shapeObjects[i]=NULL;	
	}
	ShapeFactory::getInstance().Destroy();

	cout << "State of shape objects after object created by factory had been destroyed:" << endl;
	for(size_t i=0; i<SHAPE_OBJECTS_COUNT; i++)
		shapeInfo(shapeObjects[i]);

	cout << "Deleting shape object that had been created using new (not using shape factory)" <<endl;
	for(size_t i=0; i<SHAPE_OBJECTS_COUNT; i+=4)
	{
		delete shapeObjects[i];
		shapeObjects[i] = NULL;
	}

	return 0;
}

