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

 class cmpCh {
public:
	bool operator() (const char* a, const char* b) {
		if (strcmp(a, b) > 0) return true;
		return false;
	}
};

template <typename C>
void print(const C& data) {
	for (typename C::const_iterator it = begin(data); it != end(data); ) {
		std::cout << *it /*<< " ;--- "*/;
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

template <typename C, typename A>
void print(const std::stack<C, A>& data) {

	std::stack<C, A> tmp(data);
	//std::stack<C> tmp;
	size_t d = data.size();
	/*for (size_t i = 0; i < d; i++)
	{	
		tmp.push(tmp2.top());
		tmp2.pop();
	}*/
	
	for (size_t i = 0; i < d; i++)
	{
		std::cout << tmp.top() << " ; ";
		tmp.pop();
	}


	//
	//size_t d = data.size();

	//for (size_t i = 0; i < d; i++)
	//{
	//	std::cout << data.top() << " ; ";
	//	data.pop();
	//}

	//std::cout << std::endl;
	//
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

template <typename C, typename D, typename Cmp>
void print(const std::priority_queue<C, D, Cmp>& data) {

	std::priority_queue<C, D, Cmp> tmp(data);

	size_t d = data.size();

	for (size_t i = 0; i < d; i++)
	{
		std::cout << tmp.top() << " ; ";
		tmp.pop();
	}

	std::cout << std::endl;
}

//template <typename C>
//void print(C data) {
//
//	size_t d = data.size();
//
//	for (size_t i = 0; i < d; i++)
//	{
//		std::cout << data.top() << " ; ";
//		data.pop();
//	}
//
//	std::cout << std::endl;
//}

//template <typename C, typename D>
//void print(const std::list<C, D>& data) {
//
//	std::list<C, D> tmp(data);
//
//	size_t d = data.size();
//
//	for (size_t i = 0; i < d; i++)
//	{
//		std::cout << *tmp.top() << " ; ";
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
	os << p.first << " : " << p.second << "\n";
	return os;
}

bool zamuzh(std::map<const char*, int>& mP, const char* oldf, const char* newf);

//extern bool cmpCh(const char* a, const char* b);