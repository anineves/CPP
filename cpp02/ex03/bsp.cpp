#include "Point.hpp"

Fixed abs(Fixed x)
{
	 if (x < 0)
        return x * -1;
    return x;
}

Fixed   area( Point const a, Point const b, Point const c ) 
{
    Fixed aux = ((( a.getX() * (b.getY() - c.getY())) +
                (b.getX() * (c.getY() - a.getY())) +
                (c.getX() * ( a.getY() - b.getY())))/2);

        return(abs(aux));
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed abc = area(a, b, c);
    Fixed pab = area(a, b, point);
    Fixed pac = area(a, c, point);
    Fixed pbc = area(b, c, point);
    if(pab == 0 || pac == 0 || pbc == 0)
        return (0);
    return(abc == (pab + pac + pbc));
}