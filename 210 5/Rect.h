#pragma once
#include"Shape.h"
//#include"List.h"

class Rect :public Shape
{
	int m_left, m_right, m_top, m_bottom;
public:
	//Rect() {};
	Rect(const Rect& r) :m_left(r.m_left), m_right(r.m_right),
		m_top(r.m_top), m_bottom(r.m_bottom), Shape(r.Scol) {};

	Rect(int i_l, int i_r, int i_t, int i_b, Scolor s) :
		m_left(i_l), m_right(i_r), m_top(i_t), m_bottom(i_b), Shape(s) {};
	Rect(int i_l, int i_r, int i_t, int i_b) :
		m_left(i_l), m_right(i_r), m_top(i_t), m_bottom(i_b), Shape(CLEAR) {};
	
	friend std::ostream& operator<<(std::ostream& os, const Shape& li);
	bool operator==(const Rect& r);
	bool operator==(const Shape& s);
	double S() { return fabs((m_right - m_left) * (m_bottom - m_top)); };
	//friend std::ofstream& operator<<(std::ofstream& os, const List& li);
	Shape* clone() const;
	Rect& operator=(const Rect& r);
	virtual Shape& operator=(const Shape& c);
	double distFromCentre() const {
		double cx = (double (m_right) - m_left)/2.0+m_left;
		double cy = (double (m_top) - m_bottom)/2.0+m_bottom;

		return (sqrt(cx * cx + cy * cy));
	}
	friend std::ostream& operator<<(std::ostream& os, const Rect& r);
};

 bool cmpRect(Rect a, Rect b)  ;