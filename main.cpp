#include<iostream>
#include<string>
#include<vector>
#include "struvec.h"

void a1(svec& a);
void a1(svec& a)
{
	std::string na;
	int ch, ma, en, i;
	std::cout << "name: ";
	std::cin >> na;
	std::cout << "chinese: ";
	std::cin >> ch;
	std::cout << "math: ";
	std::cin >> ma;
	std::cout << "englidh: ";
	std::cin >> en;
	std::cout << "numb: ";
	std::cin >> i;
	std::cout << '\n';
	std::cout << "����ɹ�\n";
	a.append(ma, en, ch, i, na);
}

int main()
{
	
	svec aj;
	while (1)
	{
		std::cout << "������������������������������������������������������������������������������������������������\n";
		std::cout << "1.����\n2.��ӡ\n3.�˳�������\n4.��ȡ\n5.����\n6.ɾ��\n��ѡ����Ҫ���еĲ�����";
		int key;std::cin >> key;
		if (key == 1)
		{
			a1(aj);
		}
		else if (key == 2)
		{
		zk:
			std::cout << "��ѡ���ӡ˳��\ng���ɼ�\nn������\n";
			std::string k;std::cin >> k;
			std::cout << "��ѡ���ӡ��ʽ��\n1.��ϸ\n2.��\n";
			int k1;std::cin >> k1;
			if (k1 == 1)
			{
				aj.print(1,k);
				std::cout << "��ӡ���\n\n";
				system("pause");
			}
			else if (k1 == 2)
			{
				aj.print(0,k);
				std::cout << "��ӡ���\n\n";
				system("pause");
			}
			else
			{
				std::cout << "����Ƿ�\n";
				goto zk;
			}
		}
		else if (key == 3)
		{
			std::string fi;
			std::cout << "����������ļ���";
			std::cin >> fi;
			aj.save(fi);
			break;
		}
		else if (key == 4)
		{
			std::string fina;
			std::cout << "������Ҫ�������ļ���";
			std::cin >> fina;
			aj.read(fina);
		}
		else if (key == 5)
		{
			std::cout << "������������";
			std::string n; std::cin >> n;
			std::cout << "������ѧ�ţ�";
			int nu; std::cin >> nu;
			std::cout << '\n';
			student* p = aj.find(n, nu);
			if (p == nullptr)std::cout << "û�и�ѧ������\n\n";
			else { aj.print_single(p, 1); std::cout << "�Ѵ�ӡ�����Ϣ\n\n"; }
			system("pause");
		}
		else if (key == 6)
		{
			std::cout << "������������";
			std::string n; std::cin >> n;
			std::cout << "������ѧ�ţ�";
			int nu; std::cin >> nu;
			std::cout << '\n';
			student* p = aj.find(n, nu);
			if (p == nullptr)std::cout << "û�и�ѧ������\n\n";
			else { aj.print_single(p, 1);}
			n:std::cout << "��ȷ��ɾ�������ݣ���y/n����";
			char oi;std::cin >> oi;
			if (oi == 'y')
			{
				aj.pop_name(n,nu);
				aj.pop_grades(n, nu);
				std::cout << "��ɾ��\n\n";
			}
			else if (oi == 'n')
			{
				
			}
			else
			{
				std::cout << "�Ƿ����룬�����ԡ�\n";
				goto n;
			}
		}
		else
		{
			std::cout << "����Ƿ�\n";
		}
	}
}
