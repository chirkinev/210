#include "vect.h"

//void printVector(std::vector& v)
//{
//	for (size_t i = 0; i < v.size(); i++) {
//		std::cout << "size " << v.size() << " capacity" << v.capacity() << " max_size() " << v.max_size();
//	}
//}

//void deleteDubles(std::vector<char>& v) // можно просто v.erase(j) но чет заморочился
//{
//	size_t counterDubles = 0;
//	std::vector<char>::iterator i = v.begin();
//	std::vector<char>::iterator j = i + 1;
//	while (j != v.end()) {
//		if (*i == *j) {
//			while (*i == *j) {++j;counterDubles++; }
//			counterDubles++;
//			std::vector<char>::iterator k = j;
//			size_t delt = k - i;
//			while (k != v.end()) {	*(k-delt) = *k; ++k;}
//			j=i+1;
//			for (size_t i = 0; i < counterDubles; i++) v.pop_back();
//			counterDubles = 0;
//			
//		}
//		else {++j;++i;}
//		
//	}
//}
void takeOffElement(std::vector<char>& v, std::vector<char>::iterator j)
{  
	while ((j+1) != v.end()) {
		*j = *(j + 1);
		++j;
	}
	v.pop_back();
}

void deleteDubles(std::vector<char>& v) {

	std::vector<char>::iterator i = v.begin();
	std::vector<char>::iterator j;
	if (i != v.end()) j = i + 1; else return;
	size_t count = 0;
	while (i != v.end()&& j != v.end()) {

		if (*i == *j)
		{
			while (*i == *j) {
				v.erase(j);
				i = v.begin() + count;
				j = i + 1;
			}
			v.erase(i);
			i = v.begin() + count;
			j = i + 1;


		}
		else { ++i; ++j; count++;		}
	}
}

void erase(std::vector<char>& v)
{
	size_t counterDubles = 0;
	std::vector<char>::iterator i = v.begin();
	std::vector<char>::iterator j = i + 1;
	while (i != v.end() ) {
		
		while (j != v.end()) {
			if (*i == *j) 
				 takeOffElement(v, j);
			    
			                            // можно просто v.erase(j) 
										// только заного переопределять i и j
										// так как вектор станет новый
			else ++j;
		}
		++i;
		if(i != v.end())j = i + 1;
	}

}

std::vector<char>& invert(const std::vector<char>& v)
{ 
	std::vector<char> *res = new std::vector<char>();
	/*std::vector<char>::reverse_iterator ri = v.begin();*/
	/*std::reverse_iterator<std::vector<char>>*/ // опять не понял, какой нужен тип?
	auto ri = std::make_reverse_iterator(v.end());
	for (size_t i = 0; i < v.size(); i++)
	{
		res->push_back(*ri);
		++ri;
	}
	return *res;

}
