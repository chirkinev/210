#pragma once
#include <ostream>
class MyPoint
{
	int x;
	int y;
public:
	MyPoint():x(0), y(0) {};
	//~MyPoint();
	MyPoint(const int x,const int y):x(x), y(y) {};
	MyPoint(MyPoint&& p) noexcept:x(p.x), y(p.y) {};
	MyPoint(const MyPoint& p) :x(p.x), y(p.y) {};
	~MyPoint() {};
	MyPoint& operator=(const MyPoint& p) {
		x = p.x;
		y = p.y;
		return *this;
	}
	bool operator==(const MyPoint& p)const {return (x==p.x&&y==p.y);}
	static bool otr(MyPoint& p) { return(p.x < 0) || (p.y < 0); }
	friend std::ostream& operator<<(std::ostream& os, const MyPoint& p);
	friend std::ostream& operator<<(std::ostream& os, const MyPoint* p);// ������ const MyPoint*& p �� �����?
	bool operator<(const MyPoint& b) {return(sqrt(x * x + y * y) < sqrt(b.x * b.x + b.y * b.y));}
};

