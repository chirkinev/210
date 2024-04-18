#pragma once
#include <iostream>

template <typename Type> void Swap(Type& a, Type& b)
{
	 Type tmp = std::move(a);
	 a = std::move(b);
	 b = std::move(tmp);
 };


template <typename Type,size_t maxsize> class MyStack
{
	Type element[maxsize];
	size_t count;
public:
	MyStack() :count(0) { 
		for (size_t i = 0; i < maxsize; i++)
			element[i] = Type();
	};

	//MyStack& operator<<( Type&& in);

	MyStack& operator<<(Type&& in)
	{
		if ((count + 1) <= maxsize) {
			this->element[count] = std::move(in);
			count++;
		}
		else throw("Can`t push element. Stack is full\n");

		return *this;
	};

	MyStack& operator<<(const Type& in)
	{
		if ((count + 1) <= maxsize) {
			this->element[count] = in;
			count++;
		}
		else throw("Can`t push element. Stack is full\n");

		return *this;
	};



	MyStack& operator>>(Type& in)
	{
		if (count  > 0) {
			in = std::move(this->element[count-1]);
			count--;
		}
		else throw("Can`t pop element. Stack is empty\n");

		return *this;
	};
	Type& operator[](const size_t c)
	{
		if (c < count) {
			return element[c-1];
		}
		else throw("Can`t modify element. Out of range\n");

	};
	

	template <typename Type, size_t maxsize>
	friend std::ostream& operator << (std::ostream& os, const MyStack< Type, maxsize>& v);
};


template <typename Type, size_t maxsize>
std::ostream& operator<<(std::ostream& os, const MyStack< Type, maxsize>& v)
{
	for (size_t i = 0; i < v.count; i++)
		os << v.element[i] << " ; ";
	os << "\n";
	return os;
}




template <typename Type> class MyStack2
{
struct element {
		element* pointerNext;
		Type pElement;
		element() :pointerNext(0) { pElement = Type(); };
		//~element() { ~pElement(); };
	};
    element* lastel;
	size_t count;
public:
	MyStack2<Type>() :count(0),lastel(0) {};
	~MyStack2<Type>() {	while(count)pop();	};

	MyStack2<Type>(MyStack2<Type>&& ms)noexcept {
		//while (count)pop();
		lastel=ms.lastel;
		count=ms.count;
		ms.count = 0;
		ms.lastel=0;
	}
	MyStack2<Type>& operator=(MyStack2<Type>&& ms)noexcept {
		while (count)pop();
		lastel = ms.lastel;
		count = ms.count;
		ms.count = 0;
		ms.lastel = 0;
		return *this;
	}

	void push(const Type& el) {
		count++;
		element* p = new(element);
		p->pointerNext = lastel;
		p->pElement = el;
		lastel = p;
	}

	Type pop() {
		if (count > 0) {
			Type ret = std::move( lastel->pElement);
			element* tmp = lastel->pointerNext;
			delete(lastel);
			lastel = tmp;
			count--;
			return ret;
		}
		else throw("Can`t pop element. Stack is empty\n");
	}

	/*MyStack2<Type>(const MyStack2<Type>& ms){
		count = 0;
		lastel = 0;
		for (size_t i = 0; i < ms.count; i++) 
		{
			element* tmppointer = ms.lastel;
			for (size_t j = 0; j < (ms.count - i - 1); j++)
				tmppointer = tmppointer->pointerNext;
			push(tmppointer->pElement);
	    }
	};*/

	MyStack2<Type>(const MyStack2<Type>& ms) {
		count = 0;
		lastel = 0;
		MyStack2<element*> tmpStack;
		element* tmp = ms.lastel;
		for (size_t i = 0; i < ms.count; i++)
		{
			tmpStack.push(tmp);
			tmp=tmp->pointerNext;
		}
		for (size_t i = 0; i < ms.count; i++)
		{
			tmp = tmpStack.pop();
			this->push((*tmp).pElement);
			
		}
				
	};





	MyStack2<Type>& operator=(const MyStack2<Type>& ms) {
		while (count)pop();
		/*for (size_t i = 0; i < ms.count; i++)
		{
			element* tmppointer = ms.lastel;
			for (size_t j = 0; j < (ms.count - i - 1); j++)
				tmppointer = tmppointer->pointerNext;
			push(tmppointer->pElement);
		}*/

		MyStack2<element*> tmpStack;
		element* tmp = ms.lastel;
		for (size_t i = 0; i < ms.count; i++)
		{
			tmpStack.push(tmp);
			tmp = tmp->pointerNext;
		}
		for (size_t i = 0; i < ms.count; i++)
		{
			tmp = tmpStack.pop();
			this->push((*tmp).pElement);

		}


		return *this;


	}

	template <typename Type>
	friend std::ostream& operator << (std::ostream& os, const MyStack2< Type>& v);
};

template<typename Type>
inline std::ostream& operator<<(std::ostream& os, const MyStack2<Type>& v)
{
	typename MyStack2<Type>::element* tmp = v.lastel;//typename MyStack2<Type>::element* tmp
													//- почему не подходит? 
													// error C3861: tmp: идентификатор не найден
	for (size_t i = 0; i < v.count; i++) {
		os << tmp->pElement << " ; ";
		tmp = tmp->pointerNext;
	}
	os << "\n";
	return os;
}


