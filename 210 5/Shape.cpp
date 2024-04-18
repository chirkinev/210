//#include "Shape.h"
//#include <ostream>
//#include"Rect.h"
////#include"Circle.h"
//
//
//
//std::ostream& operator<<(std::ostream& os, const Shape& li)
//{
//	Shape& tmp = const_cast<Shape&>(li);
//
//	if (typeid(li) == typeid(Rect))
//	{
//		Rect& rr = dynamic_cast<Rect&>(tmp);
//		os << "Rect   m_l= " << rr.m_left <<
//			"; m_r= " << rr.m_right <<
//			"; m_t= " << rr.m_top <<
//			"' m_b= " << rr.m_bottom <<
//			"; color =" << col[static_cast<int>(rr.Scol)] <<
//			";  S= " << rr.S(); 
//	 };
//
//	/*if (typeid(li) == typeid(Circle))
//	{
//		Circle& rr = dynamic_cast<Circle&>(tmp);
//		os << "Circle c_x= " << rr.c_x <<
//			"; c_y= " << rr.c_y <<
//			"; c_r= " << rr.c_r  <<
//			";          color =" << col[static_cast<int>(rr.Scol)] <<
//			";  S= " << rr.S();
//	};*/
//	
//		return os;
//
//	
//}
//
//
//
////bool Shape::operator==(const Shape& s)
////{
////	//if (typeid(Shape) != typeid(s)) return(false);
////
////	if (Scol ==s.Scol) return true;
////
////	return false;
////}
//
//

