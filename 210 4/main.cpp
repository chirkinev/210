// ���������� STL: 
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


	//�������� ������ ������� ��� ������ �������� stack, queue, priority_queue
	//�������� �������� �� ��, ��� ���������� ������������� ������ ������ ��� 
	//��������� ��������





	////////////////////////////////////////////////////////////////////////////////////
	//stack

	//�������� ���� ����� �������, �����
	//�) �������� ����� ����� ������� ��������� �������
	//�) ��� ������ �������� ��� �������, ��� � ����� ������� �������� ��� ���������� 


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

		//�������� �������, ������� �������� ��������� �� ������� ���� Point,
		//��� ���� ���� ������� ������� ���������.
		//�������� �������� ������� � ���������� ��������� ����������� front() � back()
		//���������, ��� ��������� ������� ��� ����������� ����� �������?

	queue<MyPoint*, list<MyPoint*>> qP;
	
	qP.push(nullptr);
	qP.push(nullptr);

	std::cout << "Print queue. 2 nulptr element" << std::endl;
	print(qP);

	MyPoint p2(1, 2), p3(3, 4); 

	qP.front() = &p2;
	qP.back() = &p3; // ���� �� ����� ����� new, �� ����� ���� �� ���������� ������
					// �.�. ������� ������������� �� ������(���������)
	std::cout << "Print queue. p2(1, 2), p3(3, 4); " << std::endl;
	print(qP);


	stop



	////////////////////////////////////////////////////////////////////////////////////
	//priority_queue
	//�) �������� ������� � ������������, ������� ����� ������� ������ ��������� ��������� - const char*
	//�) ������������������ ������� ��� �������� � ������� ���������������� ������� � ���������� const char*
	//�) ��������� "���������������" �������� (� ������� pop() ) - ���� ��� ����������� �� ��������������, ���������:
	//		��� ������������ ��� �������?

	
	const char* aC[] = {"rrr","aaa","ddd","ccc","ggg","wew","sss","aaa","aaa"};
	priority_queue<const char*,std::vector<const char*>,cmpCh> pqC;
	for (size_t i = 0; i < sizeof(aC)/sizeof(aC[0]); i++) pqC.push(aC[i]);

	print(pqC);

	 while ( !pqC.empty() )// ��� �������������, ���� �� ���� ������ ������������ ������?!
							// ������ ��� �� ���������� �������� ������?
	{
		 
	 std::cout << pqC.top() << " : ";
	              pqC.pop();    
		 
	}

	 std::cout <<  " \n";






	////////////////////////////////////////////////////////////////////////////////////
	//set
	//a) �������� ��������� � ���������� ���� Point - ���������, ��� ���������� ����������
	//		� ������ Point (� ����� �������)
	//�) ������������ �������� ��������� � ������� �������, �������������� � ���������� ���. ������
	//�) ���������� �������� ����� ��������...
	//�) �������� ��� ���������, ������� ����� ��������� ���������� ��������
	//		���� int, �� ���������� � ������ �������
	//�) �������� � ����� ��������� �������� ��������� �� ������ �������
	//	����������, ��������, ��������� �������	(��� ����������, ���� � ������� ������� �����?)

	 set<MyPoint> sP;
	 MyPoint pa[] = { MyPoint(1, 2), MyPoint(3, 4),
					  MyPoint(5, 6),MyPoint(3, 4),
		              MyPoint(1, 2),MyPoint(8, 9) };
	 
	 for (size_t i = 0; i < sizeof(pa) / sizeof(pa[0]); i++)
		 sP.insert(pa[i]); //����������� �������� < � ==
	 
	 print(sP);//����� ������������







	////////////////////////////////////////////////////////////////////////////////////
	//map, multiset
	//�) �������� map, ������� ������ ���� "�������, ��������" - pair<const char*, int>,
	//	��� ���� ������ �������� ���������� ����������
	//�) ��������� ��������� ���������� ����������� operator[] � insert()
	//�) ������������ ����������

	//�) �������� ���� �� ������ �� ����� (���� "�������", ����� ����� => ����� "�������")

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




		 //�) ����������� ����� �������� ������ � ���������� ���� string.
		 //�������� (� ������������ ��� ��������) map<string, int>, ������� �����
		 //��������� ������������� �� �������� ������ �
		 //���������� ���������� ������ ������ � �������
		 vector<string> vS = { "aaa","bbb","ccc","ttt","ggg","jjj","aaa","aaa","ttt","ggg","aaa"};
		 map<string, int> mS;

	     vector<string>::iterator vi = vS.begin();
		 while (vi != vS.end()) {
			 mS[*vi]++;
			 ++vi;
		 }
		 print(mS);


		//�) 
		//����� ������:
		//const char* words[] = {"Abba", "Alfa", "Beta", "Beauty" ,...};
		//�������� map, � ������� ������ ����� ����� ��������������� ������������ 
		//��������������� ������������� ����, ������������ � ���� �����.
		//���������: �� ����� ������� ����� ����� � ��� �� ������

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


		//�)
		//�������� ��������� ������, ������� ����� ������� ���������� � ������������ �������.
		//��� ������ ������ ������ �������� ������� ��������� (�� ��������). ��� ���� 
		//������� ����� �������������
		//���� ������ ���� ������ ���� ����������� �� ������
		//
		//������ 
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
	//�) �������� "�����-�������" �������, ��� ������ � ���� �� ����� ����� ���������������
	//		��������� ������� �������� - pair<string,string>, ��������: strange: �����, ��������...
	//�) ��������� ������� ������ � ������� ������ insert ��� ������������������ � ������� 
	//		���������������� ������� ���� (���� ����� �������������� ��� ��������� � ������� ������� make_pair)
	//�) �������� ��� ���������� ������� �� �����
	//�) �������� �� ����� ������ �������� "���������" ��� ��������� �����. ���������: ��� ���������� ���������
	//		���������� ����� ������������ ������ lower_bound() � upper_bound()
		 setlocale(LC_ALL, "Russian");
		 pair <string, pair<string, string>> p1[] = { {"arrjh",{"����� �� ����� �","����������"}},
										   {"strange",{"��������","�����"}},
										   {"custom",{"�������","�����������"}},
										   {"big",{"�������","��������"}},
										   {"big",{"����������","���������������"}},
										   {"fire",{"�����","����������"}},
										   {"break",{"�������","������"}},
										   {"like",{"���������","�������"}} };

		 

		 std::cout << " --------- �������� ���� ----------------- \n";
		 for (size_t i = 0; i < sizeof(p1) / sizeof(p1[0]); i++)
		 {
			 std::cout << p1[i].first <<" - "<< p1[i].second << "\n";

		 }
		 std::cout << " ----------- ��������� --------------- \n";

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

