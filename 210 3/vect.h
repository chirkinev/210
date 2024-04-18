#pragma once
#include <vector>
#include <iostream>

void deleteDubles(std::vector<char>& v);
void erase(std::vector<char>& v);

std::vector<char>& invert (const std::vector<char>& v);

template <typename T>
void printVector(const std::vector<T>& v) 
{
	std::cout << "-------------\nsize: " << v.size() << " capacity: " << v.capacity() << " max_size: " << v.max_size() << "\n";
	for (size_t i = 0; i < v.size(); i++) {
		std::cout << "V[" << i <<"]= "<< v[i] << " ;";
	}
	std::cout << "\n";
}


//template <typename T>
//std::ostream& operator<<(std::ostream& os,std::vector<T>& v)
//{
//	os << "=========\nsize: " << v.size() << " capacity: " << v.capacity() << " max_size: " << v.max_size() << "\n";
//	
//	for (size_t i = 0; i < v.size(); i++) {
//		//for (size_t j = 0; j < v[i].size(); j++)
//		{
//			std::cout << " V[" << j << "]= " << v[i] << ";";
//		}
//		os << "\n";
//		/*std::cout << "V[" << i << "]= " << v[i] << " ;";*/
//	}
//	return os;
//}


template <typename T>
std::ostream& operator<<(std::ostream& os, std::vector<T>& v)
{
	
	for (size_t i = 0; i < v.size(); i++) 
			std::cout << v[i]  << ";";
		
	os << "\n";
		
	return os;
}


template <typename T>
void insert(std::vector<T> &v, const T& t) {

	for (size_t i = 0; i <v.size() ; i++)
			if (t == v[i]) return;

	v.insert(v.begin, t);
	/* или так
	
	v.push_back(T());
	for (size_t i = v.size(); i >1 ; i--)
			v[i] = std::move(v[(i - 1)]);
	
	v[0] = t;
	*/
}


template <typename T>
void insert(std::vector<T> &v, T&& t) {

	
	for (size_t i = 0; i < v.size(); i++)
	if (t == v[i]) return;

	// v.insert(v.begin, t);
	 v.push_back(T());
	for (size_t i = v.size(); i > 1; i--)
			v[i-1] = std::move(v[(i - 2)]);
	
	v[0] = std::move(t);
}

template <typename T>
void insertEach(std::vector<T>& v, const T& t) {
		
	/*if ((v.size()*2)> v.capacity())*/ 
	std::vector<char>::iterator it = v.begin();
	size_t p = v.size();
	for (size_t i = 0; i < p; i++)
	{
		v.insert(it, t);
		it=v.begin()+(i+1)*2;
	}

	/*for (size_t i = v.size(); i > 0; i--) v.push_back(T());
	for (size_t i = v.size(),j= v.size()/2; i > 1; i -= 2,j--) {
		v[i-1] = std::move(v[j-1]);
		v[i - 2] = t;
	}*/

}

template <typename C>
void print(const C& data) {
	for (/*C::iterator*/ auto  it = begin(data); it != end(data); ++it) {
		std::cout << *it << " ; ";
	}
	std::cout << std::endl;
}

