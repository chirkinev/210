#include "Point.h"

std::ostream& operator<<(std::ostream& os, const MyPoint& p)
{
    os << "x= " << p.x << " y=" << p.y ;
    return os;
}
std::ostream& operator<<(std::ostream& os, const MyPoint* p)// почему const MyPoint*& p не катит?
{
    os << "x= " << (*p).x << " y=" << (*p).y ;
    return os;
}
