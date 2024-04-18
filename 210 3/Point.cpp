#include "Point.h"

std::ostream& operator<<(std::ostream& os, const MyPoint& p)
{
    os << "x= " << p.x << " y=" << p.y ;
    return os;
}
std::ostream& operator<<(std::ostream& os, const MyPoint* p)// ������ const MyPoint*& p �� �����?
{
    os << "x= " << (*p).x << " y=" << (*p).y ;
    return os;
}
