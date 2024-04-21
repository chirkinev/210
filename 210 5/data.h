#pragma once
#include <stack>
#include <iostream>
#include <queue>
#include <set>
#include <map>
#include <list>
#include <vector>
#include <string>
#include <clocale>
#include <algorithm>
#include "MyPoint2.h"
#include <string>

template<typename T>
void printx(const T& p)
{
	std::cout << p << " ; ";
}




template <typename C >
void print2(const C& data) {
	for_each(begin(data), end(data),printx<typename C::value_type> /*[](typename C::value_type element) { std::cout << element << " "; }*/);
	
	std::cout << std::endl;
}

template <typename C >
void changePointTo(C& data, const MyPoint& p) {
	for_each(begin(data), end(data), [&](typename C::value_type &element) 
		{ element =p; });
}



template <typename C>
void print(const C& data) {
	for (typename C::const_iterator it = begin(data); it != end(data); ) {
		std::cout << *it << " ;";
		++it;
	}
	std::cout << std::endl;
}


template <typename C>
void print(const C& data,const typename C::const_iterator b,const typename C::const_iterator e) {
	for (typename C::const_iterator it = b; it != e; ) {
		std::cout << *it /*<< " ;--- "*/;
		++it;
	}
	std::cout << std::endl;
}

template <typename C>
void print(const std::stack<C>& data) {

	std::stack<C> tmp2(data);
	std::stack<C> tmp;
	size_t d = data.size();
	for (size_t i = 0; i < d; i++)
	{	
		tmp.push(tmp2.top());
		tmp2.pop();
	}
	
	for (size_t i = 0; i < d; i++)
	{
		std::cout << tmp.top() << " ; ";
		tmp.pop();
	}
	
	std::cout << std::endl;
}

template <typename C,typename D>
void print(const std::queue<C, D>& data) {

	std::queue<C,D> tmp(data);
	
	size_t d = data.size();

	for (size_t i = 0; i < d; i++)
	{
		std::cout << tmp.front() << " ; ";
		tmp.pop();
	}

	std::cout << std::endl;
}

template <typename C, typename D>
void print(const std::priority_queue<C, D>& data) {

	std::priority_queue<C, D> tmp(data);

	size_t d = data.size();

	for (size_t i = 0; i < d; i++)
	{
		std::cout << tmp.top() << " ; ";
		tmp.pop();
	}

	std::cout << std::endl;
}

//template <typename C, typename D>
//void print(const std::list<C, D>& data) {
//
//	std::list<C, D> tmp(data);
//
//	size_t d = data.size();
//
//	for (size_t i = 0; i < d; i++)
//	{
//		std::cout << *(tmp.back()) << " ; ";
//		tmp.pop();
//	}
//
//	std::cout << std::endl;
//}



template <typename C>
std::ostream& operator<<(std::ostream& os, const std::set<C>& p)
{
	using namespace std;
	os << std::endl;
	for (typename set<C>::const_iterator it = begin(p); it != end(p); ) {
		os << *it << " ; ";
		++it;
	}
	os << std::endl;

	
	return os;
}

template <typename C>
std::ostream& operator<<(std::ostream& os, const std::multiset<C>& p)
{
	using namespace std;
	os << std::endl;
	for (typename set<C>::const_iterator it = begin(p); it != end(p); ) {
		os << *it << " ; ";
		++it;
	}
	os << std::endl;


	return os;
}
template <typename C, typename D>
std::ostream& operator<<(std::ostream& os, const std::pair<C, D>& p)
{
	os << p.first << " : " << p.second /*<< "\n"*/;
	return os;
}

bool zamuzh(std::map<const char*, int>& mP, const char* oldf, const char* newf);

//class interv;
class interv {
	int n;
	int m;
public:
	interv(int ni, int mi) :n(ni), m(mi) {};
	bool operator() (const MyPoint& p) const {
		if ((p.getx() >= (-n)) &&
			(p.getx() <= m) && 
			(p.gety() >= (-n)) &&
			(p.gety() <= m)) return true;
		return false;
	}
};
char chToLo(unsigned char c);

std::string strToLo(const std::string& sS);

class  strFirstLeter {
	char chr;
public:
	strFirstLeter(const char in) :chr(in) {};

	bool operator() (const std::string& st) const {
		if (st.size() == 0)return false;// надеемся, что чар нам дадут сразу корректный и в нижнем регистре, 
										// а сринг не надеемся ни на то
		if (std::tolower(st[0]) == chr) return true;
		return false;

	}

};

class saveNechet_retTrueIfChet {
	std::multimap<std::string, int>* nechet;
public:
	saveNechet_retTrueIfChet(std::multimap < std::string, int>& nc) :nechet(&nc) {};

	bool operator() (const std::pair<std::string, int>& par) const {
		//int tmp = par.second();
		if (par.second % 2) return true;
		nechet->insert(par);
		return false;


	}
};