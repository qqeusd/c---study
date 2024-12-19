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
		std::cout << "————————————————————————————————————————————————\n";
		std::cout << "1.加入\n2.打印\n3.退出并保存\n4.读取\n5.查找\n6.删除\n请选择你要进行的操作：";
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
			break;
		}
		else if (key == 4)
		{
			std::string fina;
			std::cout << "请输入要读出的文件：";
			std::cin >> fina;
			aj.read(fina);
		}
		else if (key == 5)
		{
			std::cout << "请输入姓名：";
			std::string n; std::cin >> n;
			std::cout << "请输入学号：";
			int nu; std::cin >> nu;
			std::cout << '\n';
			student* p = aj.find(n, nu);
			if (p == nullptr)std::cout << "没有该学生数据\n\n";
			else { aj.print_single(p, 1); std::cout << "已打印相关信息\n\n"; }
			system("pause");
		}
		else if (key == 6)
		{
			std::cout << "请输入姓名：";
			std::string n; std::cin >> n;
			std::cout << "请输入学号：";
			int nu; std::cin >> nu;
			std::cout << '\n';
			student* p = aj.find(n, nu);
			if (p == nullptr)std::cout << "没有该学生数据\n\n";
			else { aj.print_single(p, 1);}
			n:std::cout << "你确定删除该数据？（y/n）：";
			char oi;std::cin >> oi;
			if (oi == 'y')
			{
				aj.pop_name(n,nu);
				aj.pop_grades(n, nu);
				std::cout << "已删除\n\n";
			}
			else if (oi == 'n')
			{
				
			}
			else
			{
				std::cout << "非法输入，请重试。\n";
				goto n;
			}
		}
		else
		{
			std::cout << "输入非法\n";
		}
	}
}
