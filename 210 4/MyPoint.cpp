#include "MyPoint.h"

std::ostream& operator<<(std::ostream& os, const MyPoint& p)
{
    os << "x= " << p.x << " y=" << p.y;
    return os;
}
std::ostream& operator<<(std::ostream& os, const MyPoint* p)// почему const MyPoint*& p не катит?
{   if(p)
     os << "x= " << (*p).x << " y=" << (*p).y; 
    else
     os << "nulpoint" ;
    return os;
}

