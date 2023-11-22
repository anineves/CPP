#include "Point.hpp"

Point::Point(): x(0), y(0) {

}

Point::Point(const float f_x, const float f_y): x(f_x), y(f_y) {
    
}

Point::Point(const Point &source): x(source.x), y(source.y) {

}

Point &Point::operator=(const Point &rhs)
{
	if (this != &rhs) {
    (Fixed)this->x = rhs.getX();
    (Fixed)this->y = rhs.getY();
  	}
	return (*this);
}

Point::~Point() {}

float Point::getX( void ) const
{
	return(this->x.toFloat());
}

float Point::getY( void ) const
{
	return(this->y.toFloat());
}



