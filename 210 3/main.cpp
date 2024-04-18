//����������� ���������� �������� - STL 
	//���������� ����������� ���������� - vector
	//���������

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
	// ��������� ����������� ���������� vector 

//////////////////////////////////////////////////////////////////////
	//�������� ��������. 

	//�������� ��������� �������:
	//---------------------------
	//������ ������ ����� ����� - vInt � ��������� � ������� ������� size(),
	//��� ��� ������ �������. 

	std::vector<int> vInt;
	std::cout << "size of empty vector "<< vInt.size() << "\n\n";

	//���������������� ��������� ��������, ��������� - ��� �� ���������
	//���� ���� ��������������, - ���������

	vInt.push_back(1);
	vInt.front()=1; //  ������ ,��� ������
	
	

	//� ������� ������� push_back() � ����� ��������� ������ ������-���� ����������.
	//�� ������ �������� ����� ������� �� �������� ������� � ������� �������
	//size(), capacity(), max_size() � �������� �������� ���������. 
	//
	//���������: ��� ��� ����� �������� ����������� ��� � � ��������� ��������,
	//�������� ������ �������, ������� ��� �������, ����������� �������� ������ ����
	//������� ��� "���������" � �������� ��������� �� �������.
	printVector(vInt);

	for (size_t i = 0; i < 10; i++)
	{
		vInt.push_back(rand() % 100);
		printVector(vInt);

	}

	//������ ������������ - vDouble1 � �������� ���� ��������� ��������  �
	//��������� ��������� � ������� ���������� ���� �������. ��� �����
	//������������������� �������� �������?

	std::vector<double> vDouble(10/*,0.5*/);
	printVector(vDouble); // 0



	//������ �������� ���� MyString � ��������� �������� - 5 ���������
	//� �������������� ������� �������� ������� "A"
	//C ������� ������� at() � ����� � ������� ���������
	//�������������� []  �������� �������� �����-���� ���������.
	//���������� "�����" �� ������� ������� � ������� at() �
	//� ������� []. 

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



	//������ ������������ - vDouble3, ������� �������� ������ ���������
	// [0,5) ������� ������������ ����� dMas. �������������� ������ dMas 
	//����� ������� � �������������������!

	double dMas[] = { 0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8};
	std::vector<double> vDouble3(dMas, dMas + 5/*sizeof dMas / sizeof dMas[0]*/);
	printVector(vDouble3);



	//������ ������������ - vDouble4, ������� �������� ������ ���������
	// [2,5) ������� vDouble3. 
	std::vector<double> vDouble4(vDouble3.begin() + 2, vDouble3.begin()+5);
	printVector(vDouble4);



	//������ ��������� ���� Point - vPoint1 �) � ��������� �������� 3. ����� �����������
	//����� ������ ��� ������� ��������?

	std::vector<MyPoint> vPoint1(3); // ����������� �� ���������

	//b) vPoint2 � ��������� �������� 5 � ������������������ ������ ������� ������������ (1,1).

	std::vector<MyPoint> vPoint2(5,MyPoint(1,1));

	//������ ���������� �� Point - vpPoint � ��������� �������� 5

	std::vector<MyPoint*> vpPoint(5);
	
	//���������: ��� ��������� ��������� ��� ��������� "���������" �� ������� Point
	{
		for (size_t i = 0; i < vpPoint.size(); i++)
		{
			//vpPoint[i] = &vPoint2[i]; // ��� ���
			vpPoint[i] = &vPoint2[0]+i; // ��� ���
		}

		//���������: ��� ������ �� ������ �������� ������ ����� ��� �����������
			//�) ������������� ����� ��������� �������
			//�) ��� ���������� operator<< ��� Point*
		
		printVector(vPoint2);
		printVector(vpPoint);
	}//����� �������������� �������� ����� ����������� ��� ������ �������?


	///////////////////////////////////////////////////////////////////////
	//�������������� ������.
	//���������, ������ �� ����� ����������� ���� ��������?
		
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
		printVector(v);			// true ���� m>=n
		}
		

		
		{
		vector<int> v(3,5);
		printVector(v);
		v.resize(4,10); //��������? 5 5 5 10
		printVector(v);
		v.resize(5); //��������? 5 5 5 10 0
		printVector(v);

		}
		

		//�������� ��� "������" ������� � ����������
		//������ (�� ������ � ���� �� ����) ����. 
		//� ������ ������� �������������� ������ ��� 5 ���������, � ����� ���������
		//��� ���������� � ������� push_back.
		//������ ������ ������ ��������� ���������� ����������� push_back.
		//
		//�������� ������, ������� �������� � �������� ���������
		{
			vector<int> v;
			v.reserve(5);
			vector<int> v1;
			for (size_t i = 0; i < 5; i++)
			{
				v.push_back(i + 100); // ���� �������� � 5 �� ��������, �.� ������ [0..4] ���� �� ��������� 0
				v1.push_back(i + 20); // ���� �������� � 0 �� ��������
			}
			printVector(v);
			printVector(v1);

			stop








			//!!! shrink_to_fit - ���������� ������� �������.
			//��� ������ ������� �� ����������� ������� ��������� ��������� �������
			//�� size.
			v1.shrink_to_fit();
			printVector(v1);


		}
		//�������� "����������� �������" - ������� ��������
		//����� ���������� ������ int ar[] = {11,2,4,3,5};
		//�������� ������ �������� ��������� �������:
		//������ vv[0] - �������� 11 ��������� �� ��������� 11
		//vv[1] - �������� 2,2
		//vv[2] - �������� 4,4,4,4
		//...
		//������������ ���������� ������ ����������� ������� �� �������
		//� �������:

		//std::cout<<vv<<std::endl;
		unsigned int ar[] = { 11,2,4,3,5 };

		vector<vector<int>> vv{ vector<int>(ar[0],ar[0]),vector<int>(ar[1],ar[1]),
			vector<int>(ar[2],ar[2]),vector<int>(ar[3],ar[3]),vector<int>(ar[4],ar[4]) };


		std::cout << vv << std::endl;

		// ��� ��� ��� ����� �� ������� :-(

		vector<vector<int>> vv1(sizeof(ar) / sizeof(ar[0]));

		for (size_t i = 0; i < sizeof(ar)/sizeof(ar[0]); i++)
		{
			vv1[i].assign(ar[i], ar[i]);
		}

		std::cout << vv1 << std::endl;

		stop

			///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

				//������� �������� ������������������ insert().
				//���������� �������, ������� ������ ��������� ����� �������
					//� ������ ������� ������ ��� �������, ��� � ������� ������
					 //�������� ��� ���.


				//��������� ����������������� ������� - � ������ vChar2 �������� � ������ ������� ������ ������ ���
				//�������, ��� � ������� ������ ������� ��� ���.
					 //��������: vChar2 - abc 
					 //��� ������� �������� 'a' ������� ������ ���� ���������������
					 //��� ������� �������� 'q' vChar2 - qabc 

			vector<char> vChar2 = { 'a','b','c' };
			std::cout << vChar2 << std::endl;
			insert(vChar2, 'a');
			std::cout << vChar2 << std::endl;
			insert(vChar2, 'q');
			std::cout << vChar2 << std::endl;

			//std::copy(vChar2.begin(), vChar2.end(), std::ostream_iterator<char>(std::cout, " "));

			//���������� �������, ������� ������ ��������� ����� �������
				 //����� ������ ��������� �������
			//��������� ����������������� ������� - �������� ����� ������ ��������� ������� vChar2 ����� 'W'
			insertEach(vChar2, 'W');
			std::cout << vChar2 << std::endl;
		


		///////////////////////////////////////////////////////////////////
			//�������� �������, ������� ������ ������� ������ ������������� ������������������.
			//��������: ���� - "qwerrrrty12222r3", ����� - "qwety1r3"
			const char* str= "qwerrrrty12222r3";
			vector<char> vChar3 (str,str+ strlen(str));
			std::cout << vChar3 << std::endl;
			deleteDubles(vChar3);
			std::cout << vChar3 << std::endl;


		stop

		///////////////////////////////////////////////////////////////////

			//�������� �������� ������������������ erase()
			//�������� ������� �������� �� ������ ������� ���� ������ 
				 //��������: ���� - "qwerrrrty12222r3", ����� - "qwerty123"

			const char* str2 = "qwerrrrty12222r3";
		    vector<char> vChar4(str2, str2 + strlen(str2));

			std::cout << vChar4 << std::endl;
			erase(vChar4);
			std::cout << vChar4 << std::endl;


			stop

				///////////////////////////////////////////////////////////////////
					//�������� ����� ������ ����� �������, ����� ��� �������� �����
					//������� ��������� ������ �� ��������� ����� ��������, �� �����������
					//���� �� � �������� �������

				
			//vector<char> vChar5 = (vChar4);
			vector<char> vChar5 (vChar4.crbegin(), vChar4.crend());
			//std::make_reverse_iterator(v.end())
			//����������� ���������

			std::cout << vChar4 << std::endl;
			std::cout << vChar5 << std::endl;
			stop



				///////////////////////////////////////////////////////////////////

					//������� 1. ������. ��������, ����������� ��� �������.
					//�������� ������ ������ �� ��������� Point - ptList1 � ���������
					//��� ���������� � ������� ������� push_back(),
					//push_front, insert()

				std::list<char> lCh;
			lCh.push_back('f');
			lCh.push_front('a');
			for (size_t i = 0; i < 5; i++)
			 lCh.insert(++lCh.begin(), char('t'+i));
			stop

				//�������� ������ �������, ������� ����� �������� ��������
				//������ ���������� �� ������. ��������� ������ ������� �� �����������
				//vector � list. ��������� - �������� �� ������� ��� ����������.
				print(lCh);

			//�������� ����� �� ������� "�����������" - reverse()
			
			lCh.reverse();
			print(lCh);

			//�������� ������ ptList2 �� ��������� Point ����� �������, ����� �� ���� 
			//������ ������� ��������� ���� Point, �� �������� ��������� ������ �������������
			//�� � �������� ������� 
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
			//������������ ������  ptList1 � ptList2 - ������� ������ list - sort()
			//�� �����������.
			//���������: ��� ������ ���� ����������� � ������ Point ��� ����, �����
			//�������� ����������

			lP.sort(); // �� ���������� �� (0,0)
			print(lP);


		stop

		//���������� ��������������� ������ - merge(). ����������: ���
		//��� ���� ���������� � ������ �������.
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

		//���������� �������� �� ������ - remove()
		//��������� �� ������ ������� � ������������ ���������.
		//���������: ��� ������ ���� ����������� � ������ Point?
		print(lP2);
		lP2.remove(MyPoint(50, 2));
		print(lP2);
		stop
		//���������� �������� �� ������, ���������������� ��������� �������:
		//����� �� ��������� ������������ - remove_if(). 

		lP2.remove_if<>(&MyPoint::otr);
		print(lP2);
		//���������� �� ������ ������ ������������� ������ - unique(). 
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
			//������� 2.������� � ����� ������� - ��������� deque

			//�������� ������ deque � ���������� ���� Point. � �������
			//assign ��������� deque ������� ��������� �������. � �������
			//�������������� ���� � ���������� ������� �������������� �������
			//�������� �������� ��������� �� ������
			std::deque<MyPoint> dP;
		     dP.assign(lP4.begin(),lP4.end());
			 print(dP);
			 stop

			//�������� deque � ���������� ���� MyString. ��������� ��� ����������
			//� ������� push_back(), push_front(), insert()
			//� ������� erase ������� �� deque ��� ��������, � ������� �������
			//���������� � 'A' ��� 'a'
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