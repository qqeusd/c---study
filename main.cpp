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
	std::cout << "插入成功\n";
	a.append(ma, en, ch, i, na);
}

int main()
{
	svec aj;
	while (1)
	{
		std::cout << "请选择你要进行的操作：\n1.加入\n2.打印\n3.退出并保存\n4.读取\n";
		int key;std::cin >> key;
		if (key == 1)
		{
			a1(aj);
		}
		else if (key == 2)
		{
		zk:
			std::cout << "请选择打印顺序：\ng：成绩\nn：姓名\n";
			std::string k;std::cin >> k;
			std::cout << "请选择打印方式：\n1.详细\n2.简单\n";
			int k1;std::cin >> k1;
			if (k1 == 1)
			{
				aj.print(1,k);
				std::cout << "打印完毕\n\n";
				system("pause");
			}
			else if (k1 == 2)
			{
				aj.print(0,k);
				std::cout << "打印完毕\n\n";
				system("pause");
			}
			else
			{
				std::cout << "输入非法\n";
				goto zk;
			}
		}
		else if (key == 3)
		{
			std::string fi;
			std::cout << "请输入存入文件：";
			std::cin >> fi;
			aj.save(fi);
			/*std::cout << "保存成功";*/
			break;
		}
		else if (key == 4)
		{
			std::string fina;
			std::cout << "请输入要读出的文件：\n";
			std::cin >> fina;
			aj.read(fina);
		}
		else
		{
			std::cout << "输入非法\n";
		}
	}
}
