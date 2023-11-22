#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"
#include <iostream>
#include "math.h"

class Point{
	private:
		Fixed const x;
		Fixed const y;
	public:
		Point();
		Point(const float f_x, const float f_y);
		Point(const Point &source);
		Point &operator = (const Point &rhs);
		~Point();

		float getX( void ) const;
		float getY( void ) const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif