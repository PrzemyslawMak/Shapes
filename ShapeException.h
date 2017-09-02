#ifndef __SHAPE_EXCEPTION__
#define __SHAPE_EXCEPTION__

#include <exception>
#include <string>

namespace Shapes
{

class ShapeException :
	public std::exception 
{
public:
	ShapeException(): 
	  m_info("ShapeException")
	{
	}
	ShapeException(std::string info):
	 m_info("ShapeException: " + info)
	 {
	 }
	~ShapeException() throw()
	{

	}
	const char* what() const throw() {return m_info.c_str();}
private:
	std::string m_info;
};

}//namespace Shapes
#endif //__SHAPE_EXCEPTION__
