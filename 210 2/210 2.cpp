﻿//Исключения

//Шаблоны: 
	//		шаблоны функций,
	//		шаблоны классов,

//#include <cstdlib>
#include <tchar.h>
#include <iostream>
#include "Swap.h"
#include"MyString.h"
//#include <stdexcept>

#define stop __asm nop

Counter* Counter::m_pHead = 0;
unsigned int Counter::m_curCounters = 0;

int _tmain(int argc, _TCHAR* argv[])
{
	
	////////////////////////////////////////////////////////////////////////////
		//Тема. Шаблоны функций.
		//Создайте шаблон функции перестановки местами двух
		//значений - Swap(). Проверьте работоспособность созданного
		//шаблона с помощью приведенного ниже фрагмента кода.
		//Подсказка 1: объявление шаблона корректнее поместить в .h-файл.

		int iX = 1, iY = -1;
		Swap(iX, iY);

		double dX = 0.5, dY = -5.5;
		Swap(dX, dY);


		////Подсказка 2: подумайте, что нужно реализовать, для того,
		////			чтобы следующий вызов работал с объектами MyString
		////			не только корректно, но и эффективно
		MyString str1("One"), str2("Two");
		Swap(str1, str2);

	
	/////////////////////////////////////////////////////////////////////

		//Тема. Шаблоны классов.
		//Задание 1.
		//Создайте шаблон класса MyStack для хранения элементов любого типа T.
		// 
		//Подсказка: 1. элементы нужно где-то хранить - простым и удобным средством
		//			 для хранения последовательно расположенных в памяти элементов
		//			 является массив, 
		//			 2. для задания максимального размера стека может быть использован
		//			 параметр-константа шаблона
		//			 3. обязательными операциями со стеком являются "push" и "pop".
		//			 Реализуйте эти операции, перегрузив operator<< ("push") и operator>> ("pop")
		//           Для того, чтобы гарантировать корректное выполнение этих операций 
		//			 хорошо было бы генерировать исключение в аварийной ситуации
		//			 4. дополнительно реализуйте operator[] таким образом, чтобы пользователь
		//			 мог читать/изменять значения только тех элементов, которые он формировал
		//           5. предоставьте возможность печати хранимых в стеке элементов

		//С помощью шаблона MyStack создайте стек из 5 элементов int - iStack и
		//стек из 10 элементов MyString - strStack и поэкспериментируйте с функциями
		//operator<< и operator>>, operator[]

		// Следующий фрагмент кода должен выполняться корректно

		
		
	
		{
			try {
				MyStack< int, 5 > iStack;
				iStack << 1 << 2 << 3 << 4 << 5;
				std::cout << iStack;
				//iStack << 6;				// Can`t push element. Stack is full

				int ar[5];
				iStack >> ar[0] >> ar[1] >> ar[2] >> ar[3] >> ar[4];
				std::cout << iStack;
				//iStack >> ar[0];			// Can`t pop element. Stack is empty

				MyStack< MyString,10> strStack;
				strStack << MyString("Aaa") << MyString("Bbb") << MyString("Ccc");
				MyString str("Ddd");
				strStack << str;
				std::cout << strStack;

				str = strStack[1];
				strStack[2] = str;
				//strStack[5] = str;		// Can`t modify element. Out of range
				std::cout << strStack;

				MyString s1, s2;
				strStack >> s1 >> s2;
				std::cout << strStack<<"\n";
				std::cout << s1<<"\n"<<s2<<"\n";
			}
			catch ( const char* err ) {
				std::cout << err;
				// exception handling
			}
		}
		//*/


		//Задание 2. 
		// Реализуйте шаблон стека - MyStack2 таким образом, чтобы 
		//для хранения элементов использовался ОДНОСВЯЗНЫЙ список.
		//Реализуйте возможность распечатать элементы стека в том порядке, в котором их заносил (push())
		//пользователь
		// 
		//Подсказка: 1. обязательными операциями со стеком являются "push" и "pop". 
		//           Реализуйте эти операции с помощью соответствующих методов.	
		//			 2. operator[] для такого стека реализовывать не нужно (почему?)
		//           3. зато нужно реализовать всю функциональность сложного класса (конструктор копирования, 
		//			 оператор присваивания, ...)

		// Проверьте работоспособность разработанного шаблона класса
		
		try {

		
			MyStack2< MyString> s1;
			s1.push(MyString("Aaa"));
			s1.push(MyString("Bbb"));
			s1.push(MyString("Ccc"));
			s1.push(MyString("Ddd"));

			MyStack2< MyString> s2(s1);
			std::cout << s1 << s2;
			MyString str = s1.pop();
			std::cout << str<<"\n"<<"--------------------\n";
			s1.pop();
			std::cout << s1 << s2;

			s1 = s2;
			//std::cout << s1 << s2;

			std::cout << s1;

			s1.pop();
			s2 = s1;
			std::cout << s2;

			MyStack2< MyString> s3(std::move(s1));
			std::cout << s3 << s1;

			s2.pop();
			s3 = std::move(s2);
			std::cout << s3 << s2;

			//s2.pop(); // Can`t pop element. Stack is empty
		}
		catch (const char* err) {
			std::cout << err;
			// exception handling
		}
		

	return 0;
}

