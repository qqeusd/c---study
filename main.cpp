#include<iostream>
#include<string>
#include<vector>
#include "struvec.h"

void a1(svec &a);
void a1(svec &a)
{
	std::string na;
	int ch, ma, en,i;
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
	/*svec aj;
	while (1)
	{
		std::cout << "��ѡ����Ҫ���еĲ�����\n1.����\n2.��ӡ\n3.�˳�������\n";
		int key;std::cin >> key;
		if (key == 1)
		{
			a1(aj);
		}
		else if(key == 2)
		{
			zk:
			std::cout << "��ѡ���ӡ��ʽ��\n1.��ϸ\n2.��\n";
			int k1;std::cin >> k1;
			if (k1 == 1)
			{
				aj.print(1);
				std::cout << "��ӡ���\n\n";
				system("pause");
			}
			else if (k1 == 2)
			{
				aj.print(0);
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
			std::cout << "����ɹ�";
			break;
		}
		else
		{
			std::cout << "����Ƿ�\n";
		}
	}*/
}