// Iter_Alg.cpp : Defines the entry point for the console application.
//
//���������. ����������� ���������. ���������.

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

		//������� 1. ���������

		//����������� ���������. ����������� set<Point>. ���������, ���
		//����� ����������� � ������ Point. �������� ������, �������� �������� 
		//�������� ������� ��������� set, �� ����������� �� ��������

	    set<MyPoint> sP;
		sP.insert(MyPoint(3, 3));
		sP.insert(MyPoint(2, 3));
		sP.insert(MyPoint(1, 3));
		sP.insert(MyPoint(0, 3));
		sP.insert(MyPoint(3, 4));

		vector<MyPoint> vP(sP.rbegin(), sP.rend());

		//print (sP);
		//print(vP);


		//��������� ���������. � ������� ostream_iterator �������� ����������
		//vector � set �� ����������� ������� �� �����.
		std::cout << "------------------------- set ------------\n";
		std::copy(sP.begin(),sP.end(),std::ostream_iterator<MyPoint>(std::cout," ; "));		std::cout << "\n";
		std::cout << "------------------------- vector ------------\n";
		std::copy(vP.begin(), vP.end(), std::ostream_iterator<MyPoint>(std::cout, " ; "));		std::cout << "\n";

		//��������� �������. � ������� ������������ ���������:
		//back_inserter()
		//front_inserter()
		//inserter()
		//���������� ������� �������� �������� � ����� �� ��������� �����������. ���������:
		//����� �� ���������� ������� ����� ������������ � ������ �����������.

		std::cout << "------------------------- vector ------------\n";
		back_insert_iterator<vector<MyPoint>> vib = back_inserter(vP);
		*vib = MyPoint(7, 7);
		std::copy(vP.begin(), vP.end(), std::ostream_iterator<MyPoint>(std::cout, " ; "));		std::cout << "\n";

		insert_iterator<vector<MyPoint>> vii = inserter(vP,vP.begin()+2);
		*vii = MyPoint(7, 6);
		std::copy(vP.begin(), vP.end(), std::ostream_iterator<MyPoint>(std::cout, " ; "));		std::cout << "\n";

		//front_insert_iterator<vector<MyPoint>> vif = front_inserter(vP); // �� ��������, ������, ��� ��� ������� ��� 
																			// ������� � ������
		//*vif = MyPoint(7, 5);*/

		//--------------------------------------------------------------------------------------------------------
		/*back_insert_iterator<set<MyPoint>> sib = back_inserter(sP); // �� ��������, ������, ��� ��� set ��� 
																			// ������� � end
		*sib = MyPoint(7, 7);
		std::copy(sP.begin(), sP.end(), std::ostream_iterator<MyPoint>(std::cout, " ; "));
		std::cout << "\n";*/
		std::cout << "------------------------- set ------------\n";
		std::copy(sP.begin(), sP.end(), std::ostream_iterator<MyPoint>(std::cout, " ; "));std::cout << "\n";

		insert_iterator<set<MyPoint>> sii = inserter(sP , sP.find(MyPoint(0, 3)));// ���� insert �� �����, ������� �����������
		*sii = MyPoint(7, 6);

		std::copy(sP.begin(),sP.end(),std::ostream_iterator<MyPoint>(std::cout," ; "));		std::cout << "\n";

		//front_insert_iterator<set<MyPoint>> sif = front_inserter(sP); // �� ��������, ������, ��� ��� set ��� 
		// 																			// ������� � ������																		
		//*sif = MyPoint(7, 5);
		//std::copy(sP.begin(), sP.end(), std::ostream_iterator<MyPoint>(std::cout, " ; "));
		//std::cout << "\n";


	///////////////////////////////////////////////////////////////////

		//������� 2. ���������� ��������� (������������ ���� <algorithm>). ���������.

		// �������� for_each() - ����� �������� ������� ��� ������� �������� ����� ������������������
		//(������, vector, list...)
		//� ������� ��������� for_each � ����� ������������������ � ���������� ������ ����
		//������������ �������� ���������
		//��������� : ������� ���������� ������� ���������� ��� ������

		std::cout << "------------------------- for_each ------------\n";

	
		print2(vP);
		print2(sP);
		for_each(vP.begin(), vP.end(), printx<MyPoint>);
		
		
		stop

			//� ������� ��������� for_each � ����� ������������������ � ���������� ���� Point
			//�������� "����������" �� ��������� �������� (����� �������� ���� ����� ����������� 
			//��� ������) � �������� ��������� � ������� ����������� ���������

		std::cout << "------------------------- change ------------\n";
		vector<MyPoint> vP2 = vP;
		changePointTo(vP, MyPoint(2, 3));

		print2(vP);
		
		//� ������� ��������� find() ������� � ����� ������������������ ��������� Point
		//��� ��������� �� ������� Point � ��������� ���������.

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



		//� ������� ��������� sort() ������������ ����� ������������������ ��������� Point. 
		////�� ��������� �������� ��������� ������������������ �� �����������.
		//��� ������ ���� ���������� � ������ Point?
		// ���������: ���������� �������� sort �� �������� �� �������, ��� ���
		//��� ���� �� �� ���������� => ��� ������ ���������� ����������� ������� ������!!!

		sort(vP2.begin(), vP2.end());
		std::copy(vP2.begin(), vP2.end(), std::ostream_iterator<MyPoint>(std::cout, " \n"));		std::cout << "\n";


		//� ������� ��������� find_if() ������� � ����� ������������������ ��������� Point
		//�������� �� ������� Point, ��������������� �������: ���������� x � y ����� � ����������
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

		//� ������� ��������� sort() ������������ ����� ������������������ ��������� Rect,
		//���������� �������������� �� �������� ������ �� ������ ���������.

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
		//�������� �������, ������� � ������� ��������� transform ��������� 
		//���������� ������� string � ������ �������.
		//���������: ����� string - ��� "�����" ���������, ������� ��� ����
		// ���������� ������ begin() � end()


		//��������� list ��������� string. � ������� ��������� transform ����������
		//�������� "�������" set, ����������� ������ � ������ �������




		stop
	}

	{//copy_if
		//��� ������ � ���������� ���� string. � ������� copy_if() ���������
		//������� ������� ������, ������������ � ����� "�" ��� "�", ����� � "�"...
		//��� ���� ������� ����� � �������� ������� ������ �� �����!



		stop

			//��� multimap, ���������� ����: "����� - ���������� ���� � ������"
			//pair<string, int>. � ������� copy_if ����������� ��� map-�: ������ -
			//� ������, ����������� ������ ���������� ����, 2-�� - ��������.
			std::multimap<string, int> month{
				{"January", 31}, {"February", 28}, {"February", 29}, { "March", 31},
				{"April", 30}, {"May",31}, {"June", 30}, {"July", 31}, {"August",31},
				{"September",30}, {"October", 31}, {"November",30}, {"December",31}
		};



		stop

			//������������ multimap � map-�, ��������� ���������� ���� ����� ������
			//�������, ��������� �������� ������ ���������� �� ������.
			//��� ����� ������� ������������� ��� ������ ����?



			stop
	}

	return 0;
}

