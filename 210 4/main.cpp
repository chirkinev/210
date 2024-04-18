// Контейнеры STL: 
//stack, queue, priority_queue
//set, multiset, map, multimap

//#include "stdafx.h"

#include <queue>
#include <set>
#include <map>
#include <list>
#include <vector>
#include <string>
#include <clocale>

#include <iostream>
#include <tchar.h>
#include <stack>
#include "data.h"
#include"MyPoint.h"


using namespace std;

#define stop __asm nop
 


int _tmain(int argc, _TCHAR* argv[])
{


	//Напишите шаблон функции для вывода значений stack, queue, priority_queue
	//обратите внимание на то, что контейнеры предоставляют РАЗНЫЕ методы для 
	//получения значений





	////////////////////////////////////////////////////////////////////////////////////
	//stack

	//Создайте стек таким образом, чтобы
	//а) элементы стека стали копиями элементов вектора
	//б) при выводе значений как вектора, так и стека порядок значений был одинаковым 


	vector<char> vC({ 'a','b','c','d','e' });
	stack<char, vector<char>> sC(vector<char>(vC.rbegin(), vC.rend()));
	//for (vector<char>::iterator i = vC.begin(); i != vC.end(); i++) {
	//	sC.push(*i);
	//}
	std::cout <<"Print vector" << std::endl;
	print(vC);
	std::cout << "Print stack" << std::endl;
	print(sC);
	//sC.top();
	stop




		////////////////////////////////////////////////////////////////////////////////////
		//queue

		//Создайте очередь, которая содержит указатели на объекты типа Point,
		//при этом явно задайте базовый контейнер.
		//Измените значения первого и последнего элементов посредством front() и back()
		//Подумайте, что требуется сделать при уничтожении такой очереди?

	queue<MyPoint*, list<MyPoint*>> qP;
	
	qP.push(nullptr);
	qP.push(nullptr);

	std::cout << "Print queue. 2 nulptr element" << std::endl;
	print(qP);

	MyPoint p2(1, 2), p3(3, 4); 

	qP.front() = &p2;
	qP.back() = &p3; // если бы делал через new, то нужно было бы освободить память
					// т.к. очередь диструктурила бы адреса(указатели)
	std::cout << "Print queue. p2(1, 2), p3(3, 4); " << std::endl;
	print(qP);


	stop



	////////////////////////////////////////////////////////////////////////////////////
	//priority_queue
	//а) создайте очередь с приоритетами, которая будет хранить адреса строковых литералов - const char*
	//б) проинициализируйте очередь при создании с помощью вспомогательного массива с элементами const char*
	//в) проверьте "упорядоченность" значений (с помощью pop() ) - если они оказываются не упорядоченными, подумайте:
	//		что сравнивается при вставке?

	
	const char* aC[] = {"rrr","aaa","ddd","ccc","ggg","wew","sss","aaa","aaa"};
	priority_queue<const char*,std::vector<const char*>,cmpCh> pqC;
	for (size_t i = 0; i < sizeof(aC)/sizeof(aC[0]); i++) pqC.push(aC[i]);

	print(pqC);

	 while ( !pqC.empty() )// они упорядочились, хотя по идее должны сравниваться адреса?!
							// значит где то перегружен оператор меньше?
	{
		 
	 std::cout << pqC.top() << " : ";
	              pqC.pop();    
		 
	}

	 std::cout <<  " \n";






	////////////////////////////////////////////////////////////////////////////////////
	//set
	//a) создайте множество с элементами типа Point - подумайте, что необходимо определить
	//		в классе Point (и каким образом)
	//б) распечатайте значения элементов с помощью шаблона, реализованного в предыдущей лаб. работе
	//в) попробуйте изменить любое значение...
	//г) Создайте два множества, которые будут содержать одинаковые значения
	//		типа int, но занесенные в разном порядке
	//д) Вставьте в любое множество диапазон элементов из любого другого
	//	контейнера, например, элементов массива	(что происходит, если в массиве имеются дубли?)

	 set<MyPoint> sP;
	 MyPoint pa[] = { MyPoint(1, 2), MyPoint(3, 4),
					  MyPoint(5, 6),MyPoint(3, 4),
		              MyPoint(1, 2),MyPoint(8, 9) };
	 
	 for (size_t i = 0; i < sizeof(pa) / sizeof(pa[0]); i++)
		 sP.insert(pa[i]); //перегружены оператор < и ==
	 
	 print(sP);//дубли игнорируются







	////////////////////////////////////////////////////////////////////////////////////
	//map, multiset
	//а) создайте map, который хранит пары "фамилия, зарплата" - pair<const char*, int>,
	//	при этом строки задаются строковыми литералами
	//б) заполните контейнер значениями посредством operator[] и insert()
	//в) распечатайте содержимое

	//г) замените один из КЛЮЧЕЙ на новый (была "Иванова", вышла замуж => стала "Петрова")

	 pair <const char*, int> pp[] = { {"Ivanova",100},{"Sidorov",110},{"Tonova",120},{"Pupkin",130},{"Ivanova",100} };
	 pair <const char*, int> pp2[] = { {"Ivanova2",90},{"Sidorov2",80},{"Tonova2",70},{"Pupkin2",60},{"Ivanova",90} };
	 map<const char*, int> mP;

	 for (size_t i = 0; i < sizeof(pp) / sizeof(pp[0]); i++)
		 mP.insert(pp[i]);

	 for (size_t i = 0; i < sizeof(pp2) / sizeof(pp2[0]); i++)
		 mP[pp2[i].first]=pp2[i].second;

	 print(mP);

	 if (!zamuzh(mP,"Ivanova","Petrova"))
		 std::cout << "Ivanova not found\n";

	 if (!zamuzh(mP, "gfdsg", "sdsdgs"))
		 std::cout << "gfdsg not found\n";

	 print(mP);
	 stop




		 //д) Сформируйте любым способом вектор с элементами типа string.
		 //Создайте (и распечатайте для проверки) map<string, int>, который будет
		 //содержать упорядоченные по алфавиту строки и
		 //количество повторений каждой строки в векторе
		 vector<string> vS = { "aaa","bbb","ccc","ttt","ggg","jjj","aaa","aaa","ttt","ggg","aaa"};
		 map<string, int> mS;

	     vector<string>::iterator vi = vS.begin();
		 while (vi != vS.end()) {
			 mS[*vi]++;
			 ++vi;
		 }
		 print(mS);


		//е) 
		//задан массив:
		//const char* words[] = {"Abba", "Alfa", "Beta", "Beauty" ,...};
		//создайте map, в котором каждой букве будет соответствовать совокупность 
		//лексиграфически упорядоченных слов, начинающихся с этой буквы.
		//Подсказка: не стоит хранить дубли одной и той же строки

		//'A' -  "Abba" "Alfa"
		//'B' -  "Beauty" "Beta"  ...
		//...
		 const char* words[] = { "Abba","Abba", "Alfa","Loshad", "Beta", "Beauty" ,"Lion","Kot","Kit","Kaban","Long"};
		 map<char, set<string>> ms;
		 for (size_t i = 0; i < sizeof(words)/sizeof(words[0]); i++)
		 {
			 ms[words[i][0]].insert( string(words[i]));
		 }
		 print(ms);


		//ж)
		//создайте структуру данных, которая будет хранить информацию о студенческих группах.
		//Для каждой группы должны хранится фамилии студентов (по алфавиту). При этом 
		//фамилии могут дублироваться
		//Сами группы тоже должны быть упорядочены по номеру
		//
		//номера 
		 pair <size_t, string> ppp[] = {{1,"Ivanova"},
										{2,"Sidorov"},
										{2,"Tonova"},
										{3,"Jupkin"},
										{2,"Didorov"},
										{1,"Konova"},
										{3,"Pupkin"},
										{1,"Ivanova"}
								 	  };

		 map<size_t, multiset<string>> mis;

		 for (size_t i = 0; i < sizeof(ppp) / sizeof(ppp[0]); i++)
		 {
			 mis[ppp[i].first].insert(ppp[i].second);
		 }
		 print(mis);


	////////////////////////////////////////////////////////////////////////////////////
	//multimap
	//а) создайте "англо-русский" словарь, где одному и тому же ключу будут соответствовать
	//		несколько русских значений - pair<string,string>, например: strange: чужой, странный...
	//б) Заполните словарь парами с помощью метода insert или проинициализируйте с помощью 
	//		вспомогательного массива пара (пары можно конструировать или создавать с помощью шаблона make_pair)
	//в) Выведите все содержимое словаря на экран
	//г) Выведите на экран только варианты "переводов" для заданного ключа. Подсказка: для нахождения диапазона
	//		итераторов можно использовать методы lower_bound() и upper_bound()
		 setlocale(LC_ALL, "Russian");
		 pair <string, pair<string, string>> p1[] = { {"arrjh",{"слово на букву а","кракозябры"}},
										   {"strange",{"странный","чужой"}},
										   {"custom",{"обычный","специальный"}},
										   {"big",{"большой","огромный"}},
										   {"big",{"гигантский","большеватенький"}},
										   {"fire",{"огонь","увольнение"}},
										   {"break",{"перерыв","ломать"}},
										   {"like",{"нравиться","похожий"}} };

		 

		 std::cout << " --------- исходные пары ----------------- \n";
		 for (size_t i = 0; i < sizeof(p1) / sizeof(p1[0]); i++)
		 {
			 std::cout << p1[i].first <<" - "<< p1[i].second << "\n";

		 }
		 std::cout << " ----------- мультимап --------------- \n";

		 multimap<string, pair<string, string>> mm;
		 for (size_t i = 0; i < sizeof(p1) / sizeof(p1[0]); i++)
		 {
			 mm.insert(p1[i]);
		 }

		 print(mm);

		 std::cout << " ----------- big --------------- \n";

		 print(mm, mm.lower_bound("big"), mm.upper_bound("big"));
		
		stop

		return 0;
}

