//Стандартная библиотека шаблонов - STL 
	//Контейнеры стандартной библиотеки - vector
	//Итераторы

#include <iostream>
#include <vector>
#include "vect.h"
#include"MyString.h"
#include "Point.h"
#include <list>
#include <algorithm>
#include <deque>

#pragma warning(disable: 4786)


using namespace std;

#define	  stop __asm nop

Counter* Counter::m_pHead = 0;
unsigned int Counter::m_curCounters = 0;
int main()
{
	// Контейнер стандартной библиотеки vector 

//////////////////////////////////////////////////////////////////////
	//Создание векторов. 

	//Создайте следующие вектора:
	//---------------------------
	//пустой вектор целых чисел - vInt и проверьте с помощью функции size(),
	//что его размер нулевой. 

	std::vector<int> vInt;
	std::cout << "size of empty vector "<< vInt.size() << "\n\n";

	//Раскомментируйте следующий фрагмент, подумайте - все ли корректно
	//Если есть некорректности, - исправьте

	vInt.push_back(1);
	vInt.front()=1; //  вектор ,был пустой
	
	

	//С помощью функции push_back() в цикле заполните вектор какими-либо значениями.
	//На каждой итерации цикла следите за размером вектора с помощью методов
	//size(), capacity(), max_size() и выводите значения элементов. 
	//
	//Подсказка: так как такая проверка понадобится Вам и в следующих заданиях,
	//напишите шаблон функции, которая для вектора, содержащего элементы любого типа
	//выводит его "реквизиты" и значения элементов на консоль.
	printVector(vInt);

	for (size_t i = 0; i < 10; i++)
	{
		vInt.push_back(rand() % 100);
		printVector(vInt);

	}

	//вектор вещественных - vDouble1 с заданным Вами начальным размером  и
	//проверьте результат с помощью созданного Вами шаблона. Как будут
	//проинициализированы элементы вектора?

	std::vector<double> vDouble(10/*,0.5*/);
	printVector(vDouble); // 0



	//вектор объектов типа MyString с начальным размером - 5 элементов
	//и инициализацией каждого элемента строкой "A"
	//C помощью функции at() а также с помощью оператора
	//индексирования []  измените значения каких-либо элементов.
	//Попробуйте "выйти" за границы вектора с помощью at() и
	//с помощью []. 

	std::vector<MyString> vMyString(5,MyString("A"));
	printVector(vMyString);
	vMyString[1] = "BBB";
	vMyString[3] = "ccc";
	printVector(vMyString);
	//vMyString[7] = "ddd"; //run time error
	vMyString.at(1) = "ddd";
	vMyString.at(2) = "uuu";
	printVector(vMyString);
	try {
		vMyString.at(8) = "KKK";
	}
	catch (const exception& m) { std::cout << "kakaya dosada - " << m.what()<<"  ::  "<< typeid(m).name()<<"\n\n"; }



	//вектор вещественных - vDouble3, который является копией элементов
	// [0,5) массива вещественных чисел dMas. Предворительно массив dMas 
	//нужно создать и проинициализировать!

	double dMas[] = { 0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8};
	std::vector<double> vDouble3(dMas, dMas + 5/*sizeof dMas / sizeof dMas[0]*/);
	printVector(vDouble3);



	//вектор вещественных - vDouble4, который является копией элементов
	// [2,5) вектора vDouble3. 
	std::vector<double> vDouble4(vDouble3.begin() + 2, vDouble3.begin()+5);
	printVector(vDouble4);



	//вектор элементов типа Point - vPoint1 а) с начальным размером 3. Какой конструктор
	//будет вызван для каждого элемента?

	std::vector<MyPoint> vPoint1(3); // конструктор по умолчанию

	//b) vPoint2 с начальным размером 5 и проинициализируйте каждый элемент координатами (1,1).

	std::vector<MyPoint> vPoint2(5,MyPoint(1,1));

	//вектор указателей на Point - vpPoint с начальным размером 5

	std::vector<MyPoint*> vpPoint(5);
	
	//Подумайте: как корректно заставить эти указатели "указывать" на объекты Point
	{
		for (size_t i = 0; i < vpPoint.size(); i++)
		{
			//vpPoint[i] = &vPoint2[i]; // или так
			vpPoint[i] = &vPoint2[0]+i; // или так
		}

		//Подсказка: для вывода на печать значений скорее всего Вам понадобится
			//а) специализация Вашей шаблонной функции
			//б) или перегрузка operator<< для Point*
		
		printVector(vPoint2);
		printVector(vpPoint);
	}//Какие дополнительные действия нужно предпринять для такого вектора?


	///////////////////////////////////////////////////////////////////////
	//Резервирование памяти.
	//Подумайте, всегда ли верны приведенные ниже проверки?
		
		{
		size_t n = 20;
		vector<int> v(n);
		v.resize(n/2);
		if (v.capacity() == n) { } // true
		printVector(v);
		//true? yes;
		}
		

		
		{
			int n = 10;
			size_t m = 3;
		vector<int> v(n);
		v.reserve(m);
		if (v.capacity() == m) {}; // true?
		printVector(v);			// true если m>=n
		}
		

		
		{
		vector<int> v(3,5);
		printVector(v);
		v.resize(4,10); //значения? 5 5 5 10
		printVector(v);
		v.resize(5); //значения? 5 5 5 10 0
		printVector(v);

		}
		

		//Создайте два "пустых" вектора с элементами
		//любого (но одного и того же типа) типа. 
		//В первом векторе зарезервируйте память под 5 элементов, а потом заполните
		//его значениями с помощью push_back.
		//Второй вектор просто заполните значениями посредством push_back.
		//
		//Сравните размер, емкость векторов и значения элементов
		{
			vector<int> v;
			v.reserve(5);
			vector<int> v1;
			for (size_t i = 0; i < 5; i++)
			{
				v.push_back(i + 100); // пуши начались с 5 го элемента, т.к первые [0..4] были по умолчанию 0
				v1.push_back(i + 20); // пуши начались с 0 го элемента
			}
			printVector(v);
			printVector(v1);

			stop








			//!!! shrink_to_fit - Уменьшение емкости вектора.
			//Для любого вектора из предыдущего задания требуется уменьшить емкость
			//до size.
			v1.shrink_to_fit();
			printVector(v1);


		}
		//Создание "двухмерного вектора" - вектора векторов
		//Задан одномерный массив int ar[] = {11,2,4,3,5};
		//Создайте вектор векторов следующим образом:
		//вектор vv[0] - содержит 11 элементов со значением 11
		//vv[1] - содержит 2,2
		//vv[2] - содержит 4,4,4,4
		//...
		//Распечатайте содержимое такого двухмерного вектора по строкам
		//с помощью:

		//std::cout<<vv<<std::endl;
		unsigned int ar[] = { 11,2,4,3,5 };

		vector<vector<int>> vv{ vector<int>(ar[0],ar[0]),vector<int>(ar[1],ar[1]),
			vector<int>(ar[2],ar[2]),vector<int>(ar[3],ar[3]),vector<int>(ar[4],ar[4]) };


		std::cout << vv << std::endl;

		// или так все равно не красиво :-(

		vector<vector<int>> vv1(sizeof(ar) / sizeof(ar[0]));

		for (size_t i = 0; i < sizeof(ar)/sizeof(ar[0]); i++)
		{
			vv1[i].assign(ar[i], ar[i]);
		}

		std::cout << vv1 << std::endl;

		stop

			///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

				//Вставка элемента последовательности insert().
				//Реализуйте функцию, которая должна вставлять новый элемент
					//в начало вектора только при условии, что в векторе такого
					 //значения еще нет.


				//Проверьте работоспособность функции - в вектор vChar2 вставьте в начало вектора символ только при
				//условии, что в векторе такого символа еще нет.
					 //например: vChar2 - abc 
					 //При попытке вставить 'a' попытка должна быть проигнорирована
					 //При попытке вставить 'q' vChar2 - qabc 

			vector<char> vChar2 = { 'a','b','c' };
			std::cout << vChar2 << std::endl;
			insert(vChar2, 'a');
			std::cout << vChar2 << std::endl;
			insert(vChar2, 'q');
			std::cout << vChar2 << std::endl;

			//std::copy(vChar2.begin(), vChar2.end(), std::ostream_iterator<char>(std::cout, " "));

			//Реализуйте функцию, которая должна вставлять новый элемент
				 //перед каждым элементом вектора
			//Проверьте работоспособность функции - вставьте перед каждым элементом вектора vChar2 букву 'W'
			insertEach(vChar2, 'W');
			std::cout << vChar2 << std::endl;
		


		///////////////////////////////////////////////////////////////////
			//Напишите функцию, которая должна удалять только повторяющиеся последовательности.
			//Например: было - "qwerrrrty12222r3", стало - "qwety1r3"
			const char* str= "qwerrrrty12222r3";
			vector<char> vChar3 (str,str+ strlen(str));
			std::cout << vChar3 << std::endl;
			deleteDubles(vChar3);
			std::cout << vChar3 << std::endl;


		stop

		///////////////////////////////////////////////////////////////////

			//Удаление элемента последовательности erase()
			//Напишите функцию удаления из любого вектора всех дублей 
				 //Например: было - "qwerrrrty12222r3", стало - "qwerty123"

			const char* str2 = "qwerrrrty12222r3";
		    vector<char> vChar4(str2, str2 + strlen(str2));

			std::cout << vChar4 << std::endl;
			erase(vChar4);
			std::cout << vChar4 << std::endl;


			stop

				///////////////////////////////////////////////////////////////////
					//Создайте новый вектор таким образом, чтобы его элементы стали
					//копиями элементов любого из созданных ранее векторов, но расположены
					//были бы в обратном порядке

				
			//vector<char> vChar5 = (vChar4);
			vector<char> vChar5 (vChar4.crbegin(), vChar4.crend());
			//std::make_reverse_iterator(v.end())
			//реверсивные итераторы

			std::cout << vChar4 << std::endl;
			std::cout << vChar5 << std::endl;
			stop



				///////////////////////////////////////////////////////////////////

					//Задание 1. Списки. Операции, характерные для списков.
					//Создайте пустой список из элементов Point - ptList1 и наполните
					//его значениями с помощью методов push_back(),
					//push_front, insert()

				std::list<char> lCh;
			lCh.push_back('f');
			lCh.push_front('a');
			for (size_t i = 0; i < 5; i++)
			 lCh.insert(++lCh.begin(), char('t'+i));
			stop

				//Напишите шаблон функции, которая будет выводить элементы
				//ЛЮБОГО КОНТЕЙНЕРА на печать. Проверьте работу шаблона на контейнерах
				//vector и list. Подсказка - хотелось бы увидеть тип контейнера.
				print(lCh);

			//Сделайте любой из списков "реверсивным" - reverse()
			
			lCh.reverse();
			print(lCh);

			//Создайте список ptList2 из элементов Point таким образом, чтобы он стал 
			//копией вектора элементов типа Point, но значения элементов списка располагались
			//бы в обратном порядке 
			std::list<MyPoint> lP;
			lP.push_back(MyPoint(1,2));
			lP.push_front(MyPoint(3, 4));
			for (size_t i = 0; i < 3; i++)
				lP.insert(++lP.begin(), MyPoint(i+20, 20-i));
			print(lP);
			//lP.reverse();
			//print(lP);

			std::list<MyPoint> ptList2(lP.crbegin(), lP.crend());
			print(ptList2);
			stop
			//Отсортируйте списки  ptList1 и ptList2 - методом класса list - sort()
			//по возрастанию.
			//Подумайте: что должно быть перегружено в классе Point для того, чтобы
			//работала сортировка

			lP.sort(); // по расстоянию от (0,0)
			print(lP);


		stop

		//Объедините отсортированные списки - merge(). Посмотрите: что
		//при этом происходит с каждым списком.
			std::list<MyPoint> lP2;
		lP2.push_back(MyPoint(50, 2));
		lP2.push_front(MyPoint(30, 4));
		for (size_t i = 0; i < 3; i++)
			lP2.insert(++lP2.begin(), MyPoint(i + 18, -2 - i));

		lP2.sort();

		//std::list<MyPoint> lP3(lP.size() + lP2.size());
		//std::merge(lP.begin(), lP.end(), lP2.begin(), lP2.end(), lP3.begin());
		
		print(lP);;
		print(lP2);
		//print(lP3);
		
		lP.merge(lP2);	
		print(lP);
		stop

		//Исключение элемента из списка - remove()
		//Исключите из списка элемент с определенным значением.
		//Подумайте: что должно быть перегружено в классе Point?
		print(lP2);
		lP2.remove(MyPoint(50, 2));
		print(lP2);
		stop
		//Исключение элемента из списка, удовлетворяющего заданному условию:
		//любая из координат отрицательна - remove_if(). 

		lP2.remove_if<>(&MyPoint::otr);
		print(lP2);
		//Исключение из списка подряд расположенных дублей - unique(). 
		std::list<MyPoint> lP4;
		lP4.push_back(MyPoint(50, 2));
		lP4.push_front(MyPoint(30, 4));
		for (size_t i = 0; i < 3; i++)
			lP4.insert(++lP4.begin(), MyPoint(18,3));
		lP4.push_front(MyPoint(31, 4));
		lP4.push_front(MyPoint(32, 4));
		print(lP4);
		lP4.unique();
		print(lP4);

		stop

		///////////////////////////////////////////////////////////////////
			//Задание 2.Очередь с двумя концами - контейнер deque

			//Создайте пустой deque с элементами типа Point. С помощью
			//assign заполните deque копиями элементов вектора. С помощью
			//разработанного Вами в предыдущем задании универсального шаблона
			//выведите значения элементов на печать
			std::deque<MyPoint> dP;
		     dP.assign(lP4.begin(),lP4.end());
			 print(dP);
			 stop

			//Создайте deque с элементами типа MyString. Заполните его значениями
			//с помощью push_back(), push_front(), insert()
			//С помощью erase удалите из deque все элементы, в которых строчки
			//начинаются с 'A' или 'a'
			 std::deque<MyString> dS;
			 dS.push_back(MyString("aaa"));
			 dS.push_front(MyString("bbb"));
			 dS.push_front(MyString("Abb"));
			 dS.insert(++dS.begin(), MyString("ccc"));
			 print(dS);


			 for (std::deque<MyString>::iterator it = dS.begin(); it != dS.end();)
			 {				 
				 if (it->firstChar() == 'a'|| it->firstChar() == 'A')
					 it = dS.erase(it);
				 else
					 ++it;
			 }
			 print(dS);
			 stop



		return 0;
}