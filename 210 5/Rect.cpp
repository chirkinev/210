#include "Rect.h"

bool Rect::operator==(const Rect& r)
{
    if (this->m_left == r.m_left &&
        this->m_right == r.m_right &&
        this->m_top == r.m_top &&
        this->m_bottom == r.m_bottom &&

        /*(static_cast<Shape>(*this)) ==
        (static_cast<Shape>(r)))*/

        Shape::operator==(r))
        // *(static_cast<Shape*>(const_cast<Rect*>(&r)))
        
        //&&
       // this->Scol==r.Scol)  
        return true;
    return false;
}

bool Rect::operator==(const Shape& s)
{
    if (typeid(Rect) != typeid(s)) return(false);

    if (*(this) ==
        static_cast<Rect&>(const_cast<Shape&>(s))) return true;

    return false;
}
Shape* Rect::clone() const
{
    Shape* tmp = new Rect(*this);

    return tmp;
}

Rect& Rect::operator=(const Rect& r)
{
    m_left = r.m_left;
    m_right = r.m_right;
    m_top = r.m_top;
    m_bottom = r.m_bottom;
    Shape::operator=(r);
    return *this;
}

Shape& Rect::operator=(const Shape& c)
{
    // TODO: вставьте здесь оператор return
   

    *this = static_cast<Rect&>(const_cast<Shape&>(c));
    return *this;

}

std::ostream& operator<<(std::ostream& os, const Rect& p)
{
    os << "L= " << p.m_left << " R= " << p.m_right << " T= " << p.m_top << " B= " << p.m_bottom << " L from 0.0= "<< p.distFromCentre()<<"  \n";
    return os;
}
//bool cmpRect(Rect a, Rect b)
//{
//    return false;
//}
//std::ostream& operator<<(std::ostream& os, const Rect* p)// почему const MyPoint*& p не катит?
//{
//    if (p)
//        os << "L= " << (*p).m_left << " R= " << p.m_right << "T= " << p.m_top << " B= " << p.m_bottom << "  \n";
//    else
//        os << "nulpoint";
//    return os;
//}

bool cmpRect(Rect a, Rect b) {
    return (a.distFromCentre() < b.distFromCentre());
}

