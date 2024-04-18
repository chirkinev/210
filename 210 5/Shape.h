#pragma once
#include <iostream>
static const char* col[5] = { "CLEAR", "WHITE", "RED", "GREEN", "BLUE" };
class Shape
{
public:
enum Scolor { CLEAR, WHITE, RED, GREEN, BLUE };
//static const char* col[5] = {"CLEAR", "WHITE", "RED", "GREEN", "BLUE"};
protected:
	Scolor Scol;
public:
	virtual Shape* clone() const { return new Shape(Scol); };
	Shape(const Scolor c):Scol(c) {};
	virtual double S() { return 0; };
	
	//friend std::ostream& operator<<(std::ostream& os, const Shape& li);
	virtual bool operator==(const Shape& s) 
	{
		if (Scol = s.Scol) return true;
		return false;//чисто для проверки попадания сюда
	};
	virtual Shape& operator=(const Shape& c) 
	{ Scol = c.Scol; return *this; };//просто для проверки попадания сюда
	Scolor col() { return Scol; };
};




