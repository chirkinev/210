// Iter_Alg.cpp : Defines the entry point for the console application.
//
//Итераторы. Стандартные алгоритмы. Предикаты.

#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <tchar.h>
#include"MyPoint2.h"
#include"data.h"
//#include "main.h"
#include "Rect.h"


using namespace std;
#define	  stop __asm nop


int _tmain(int argc, _TCHAR* argv[])
{

	///////////////////////////////////////////////////////////////////

		//Задание 1. Итераторы

		//Реверсивные итераторы. Сформируйте set<Point>. Подумайте, что
		//нужно перегрузить в классе Point. Создайте вектор, элементы которого 
		//являются копиями элементов set, но упорядочены по убыванию

	    set<MyPoint> sP;
		sP.insert(MyPoint(3, 3));
		sP.insert(MyPoint(2, 3));
		sP.insert(MyPoint(1, 3));
		sP.insert(MyPoint(0, 3));
		sP.insert(MyPoint(3, 4));

		vector<MyPoint> vP(sP.rbegin(), sP.rend());

		//print (sP);
		//print(vP);


		//Потоковые итераторы. С помощью ostream_iterator выведите содержимое
		//vector и set из предыдущего задания на экран.
		std::cout << "------------------------- set ------------\n";
		std::copy(sP.begin(),sP.end(),std::ostream_iterator<MyPoint>(std::cout," ; "));		std::cout << "\n";
		std::cout << "------------------------- vector ------------\n";
		std::copy(vP.begin(), vP.end(), std::ostream_iterator<MyPoint>(std::cout, " ; "));		std::cout << "\n";

		//Итераторы вставки. С помощью возвращаемых функциями:
		//back_inserter()
		//front_inserter()
		//inserter()
		//итераторов вставки добавьте элементы в любой из созданных контейнеров. Подумайте:
		//какие из итераторов вставки можно использовать с каждым контейнером.

		std::cout << "------------------------- vector ------------\n";
		back_insert_iterator<vector<MyPoint>> vib = back_inserter(vP);
		*vib = MyPoint(7, 7);
		std::copy(vP.begin(), vP.end(), std::ostream_iterator<MyPoint>(std::cout, " ; "));		std::cout << "\n";

		insert_iterator<vector<MyPoint>> vii = inserter(vP,vP.begin()+2);
		*vii = MyPoint(7, 6);
		std::copy(vP.begin(), vP.end(), std::ostream_iterator<MyPoint>(std::cout, " ; "));		std::cout << "\n";

		//front_insert_iterator<vector<MyPoint>> vif = front_inserter(vP); // не прокатит, потому, что для вектора нет 
																			// вставки в начало
		//*vif = MyPoint(7, 5);*/

		//--------------------------------------------------------------------------------------------------------
		/*back_insert_iterator<set<MyPoint>> sib = back_inserter(sP); // не прокатит, потому, что для set нет 
																			// вставки в end
		*sib = MyPoint(7, 7);
		std::copy(sP.begin(), sP.end(), std::ostream_iterator<MyPoint>(std::cout, " ; "));
		std::cout << "\n";*/
		std::cout << "------------------------- set ------------\n";
		std::copy(sP.begin(), sP.end(), std::ostream_iterator<MyPoint>(std::cout, " ; "));std::cout << "\n";

		insert_iterator<set<MyPoint>> sii = inserter(sP , sP.find(MyPoint(0, 3)));// куда insert не важно, встанет упорядочено
		*sii = MyPoint(7, 6);

		std::copy(sP.begin(),sP.end(),std::ostream_iterator<MyPoint>(std::cout," ; "));		std::cout << "\n";

		//front_insert_iterator<set<MyPoint>> sif = front_inserter(sP); // не прокатит, потому, что для set нет 
		// 																			// вставки в начало																		
		//*sif = MyPoint(7, 5);
		//std::copy(sP.begin(), sP.end(), std::ostream_iterator<MyPoint>(std::cout, " ; "));
		//std::cout << "\n";


	///////////////////////////////////////////////////////////////////

		//Задание 2. Обобщенные алгоритмы (заголовочный файл <algorithm>). Предикаты.

		// алгоритм for_each() - вызов заданной функции для каждого элемента любой последовательности
		//(массив, vector, list...)
		//С помощью алгоритма for_each в любой последовательности с элементами любого типа
		//распечатайте значения элементов
		//Подсказка : неплохо вызываемую функцию определить как шаблон

		std::cout << "------------------------- for_each ------------\n";

	
		print2(vP);
		print2(sP);
		for_each(vP.begin(), vP.end(), printx<MyPoint>);
		
		
		stop

			//С помощью алгоритма for_each в любой последовательности с элементами типа Point
			//измените "координаты" на указанное значение (такой предикат тоже стоит реализовать 
			//как шаблон) и выведите результат с помощью предыдущего предиката

		std::cout << "------------------------- change ------------\n";
		vector<MyPoint> vP2 = vP;
		changePointTo(vP, MyPoint(2, 3));

		print2(vP);
		
		//С помощью алгоритма find() найдите в любой последовательности элементов Point
		//все итераторы на элемент Point с указанным значением.

		vP2.push_back(MyPoint(2,3));
		vP2.push_back(MyPoint(5, 3));
		vP2.push_back(MyPoint(6, 3));
		vP2.push_back(MyPoint(2, 3));
		std::cout << "------------------------- find ------------\n";
		std::copy(vP2.begin(), vP2.end(), std::ostream_iterator<MyPoint>(std::cout, " \n"));		std::cout << "\n";


		vector<vector<MyPoint>::iterator> res;
		vector<MyPoint>::iterator itr = vP2.begin();
		while (itr != vP2.end()) {
			//vector<MyPoint>::iterator it2 
			itr= find(itr, vP2.end(), MyPoint(2, 3));
			if (itr != vP2.end()) { res.push_back(itr); ++itr; }
		};
		
		for (size_t i = 0; i < res.size(); i++)
		{
			std::cout << *res.at(i) << " ; ";
		}



		//С помощью алгоритма sort() отсортируйте любую последовательность элементов Point. 
		////По умолчанию алгоритм сортирует последовательность по возрастанию.
		//Что должно быть определено в классе Point?
		// Замечание: обобщенный алгоритм sort не работает со списком, так как
		//это было бы не эффективно => для списка сортировка реализована методом класса!!!

		sort(vP2.begin(), vP2.end());
		std::copy(vP2.begin(), vP2.end(), std::ostream_iterator<MyPoint>(std::cout, " \n"));		std::cout << "\n";


		//С помощью алгоритма find_if() найдите в любой последовательности элементов Point
		//итератор на элемент Point, удовлетворяющий условию: координаты x и y лежат в промежутке
		//[-n, +m].
		vP2.push_back(MyPoint(-2, 0));
		vP2.push_back(MyPoint(5, 3));
		vP2.push_back(MyPoint(6, 3));
		vP2.push_back(MyPoint(2, 3));

		const int n = 3;
		const int m = 2;
		std::cout << "------------------------- find if -n="<<-n<<" m= "<<m<<" ------------\n";
		std::copy(vP2.begin(), vP2.end(), std::ostream_iterator<MyPoint>(std::cout, " \n"));		std::cout << "\n";
		std::cout << "----\n";
		vector<MyPoint>::iterator itr2 = vP2.begin();
		std::cout << "\n";
		
		vector<MyPoint>::iterator res2 = find_if(itr2, vP2.end(), interv(n, m));
		if (res2!=vP2.end())std::cout << *res2;
		std::cout << "\n";	std::cout << "----\n";

		//С помощью алгоритма sort() отсортируйте любую последовательность элементов Rect,
		//располагая прямоугольники по удалению центра от начала координат.

		vector<Rect> vR = { Rect(1,2,4,3),
						Rect(2,3,4,3),
						Rect(1,2,6,1),
						Rect(-3,3,2,-2),
		};

		std::cout << "----Rect unsorted---------------\n";
		for (size_t i = 0; i < vR.size(); i++)
		{
			std::cout <<vR[i]<< "\n";
		}

		sort(vR.begin(), vR.end(), cmpRect);
		std::cout << "----Rect sorted---------------\n";
		for (size_t i = 0; i < vR.size(); i++)
		{
			std::cout << vR[i] << "\n";
		}



	{//transform
		//Напишите функцию, которая с помощью алгоритма transform переводит 
		//содержимое объекта string в нижний регистр.
		//Подсказка: класс string - это "почти" контейнер, поэтому для него
		// определены методы begin() и end()


		//Заполните list объектами string. С помощью алгоритма transform сформируте
		//значения "пустого" set, конвертируя строки в нижний регистр




		stop
	}

	{//copy_if
		//Дан вектор с элементами типа string. С помощью copy_if() требуется
		//вывести сначала строки, начинающиеся с буквы "А" или "а", затем с "Б"...
		//При этом порядок строк в исходном векторе менять не нужно!



		stop

			//Дан multimap, содержаций пары: "месяц - количество денй в месяце"
			//pair<string, int>. С помощью copy_if сформируйте ДВА map-а: первый -
			//с парами, содержащими четное количество дней, 2-ой - нечетное.
			std::multimap<string, int> month{
				{"January", 31}, {"February", 28}, {"February", 29}, { "March", 31},
				{"April", 30}, {"May",31}, {"June", 30}, {"July", 31}, {"August",31},
				{"September",30}, {"October", 31}, {"November",30}, {"December",31}
		};



		stop

			//Распечатайте multimap и map-ы, используя написанный вами ранее шаблон
			//функции, выводящей элементы ЛЮБОГО контейнера на печать.
			//Что нужно сделать дополнительно для вывода пары?



			stop
	}

	return 0;
}

