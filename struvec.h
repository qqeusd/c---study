#pragma once
#ifndef STRUVEC_H
#define STRUVEC_H
#include<iostream>
#include<fstream>
#include<string>
struct student
{
	student* _parent;
	student* _left;//big
	student* _right;//small
	int _math;
	int _eng;
	int _chi;
	int _sum;
	int _numb;
	std::string _name;
	student(int math, int eng, int chi, int numb, std::string name)
		:_math(math),
		_eng(eng),
		_chi(chi),
		_numb(numb),
		_name(name),
		_parent(nullptr),
		_left(nullptr),
		_right(nullptr)
	{
		_sum = math + eng + chi;
	}
	student()
		:_math(0),
		_eng(0),
		_chi(0),
		_numb(0),
		_sum(0),
		_parent(nullptr),
		_left(nullptr),
		_right(nullptr),
		_name(" ")
	{

	}
};
class svec
{
private:
	student* root;
	int numb;
	int space;
public:
	svec()
	{
		root = nullptr;
		numb = 0;
		space = 0;
	}

private:student* app_create(int ma, int en, int ch, int nu, std::string na)
	{
		student* p = new student(ma, en, ch, nu, na);
		return p;
	}
public:void append(int math, int english, int chinese,int numbs,std::string name)
{
	student* ps = app_create(math, english, chinese, numbs, name);
	this->insert(ps);
}

public:void insert(student* p)
{
	student* cur = p;
	if (root == nullptr)
	{
		root = cur;
		numb++;
	}
	else
	{
		student* p = root;///当前a的位置
		student* p1 = nullptr;
		int sons[4] = { cur->_sum,cur->_chi,cur->_math,cur->_numb };
		while (1)
		{
			int pares[4] = { p->_sum,p->_chi,p->_math,p->_numb };
			for (int i = 0; i < 4; i++)
			{
				if (sons[i] < pares[i])
				{
					p1 = p->_right;
					break;
				}
				if (sons[i] > pares[i])
				{
					p1 = p->_left;
					break;
				}
			}
			if (p1 == nullptr)
			{
				int son[4] = { cur->_sum,cur->_chi,cur->_math,cur->_numb }, pare[4] = { p->_sum,p->_chi,p->_math,p->_numb };
				for (int i = 0; i < 4; i++)
				{
					if (son[i] > pare[i])
					{
						p->_left = cur;
						break;
					}
					if (son[i] < pare[i])
					{
						p->_right = cur;
						break;
					}
				}
				break;
			}
			p = p1;
		}
	}
	numb++;
}
public:void insert(student& a)
	{
		student* cur = &a;
		if (root == nullptr)
		{
			root = cur;
			numb++;
		}
		else
		{
			student* p = root;///当前a的位置
			student* p1 = nullptr;
			int sons[4] = { cur->_sum,cur->_chi,cur->_math,cur->_numb };
			while (1)
			{
				int pares[4] = { p->_sum,p->_chi,p->_math,p->_numb };
				for (int i = 0; i < 4; i++)
				{
					if (sons[i] < pares[i])
					{
						p1 = p->_right;
						break;
					}
					if (sons[i] > pares[i])
					{
						p1 = p->_left;
						break;
					}
				}
				if (p1 == nullptr)
				{
					int son[4] = { cur->_sum,cur->_chi,cur->_math,cur->_numb }, pare[4] = { p->_sum,p->_chi,p->_math,p->_numb };
					for (int i = 0; i < 4; i++)
					{
						if (son[i] > pare[i])
						{
							p->_left = cur;
							break;
						}
						if (son[i] < pare[i])
						{
							p->_right = cur;
							break;
						}
					}
					break;
				}
				p = p1;
			}
		}
		numb++;
	}


	void print(bool ke)
	{
		print_mid(root,ke);
	}

	private:void print_mid(student* p,bool key)
	{
		if (p == nullptr)return;
		print_mid(p->_left,key);
		print_single(p, key);
		print_mid(p->_right,key);
	}

	void print_single(student* p, bool keys)
	{
		if (keys)
		{
			std::cout << p->_name << '\t' << "学号: " << p->_numb << '\n';
			std::cout << "语文: " << p->_chi << '\n';
			std::cout << "数学: " << p->_math << '\n';
			std::cout << "英语: " << p->_eng << '\n';
			std::cout << "总分: " << p->_sum << '\n' << std::endl;
		}
		if (!keys)
		{
			std::cout << "姓名: " << p->_name << '\t' << "总分: " << p->_sum << '\n';
		}
	}
	
	///something about save
	public:void save(std::string ku = "文本.txt")
	{
		std::ofstream file(ku);
		write_in(file, root);
		file.close();
	}
	private:void write_in(std::ofstream& f,student*p)
	{
		if (p == nullptr)f << '#' << '\n';
		else
		{
			f << p->_chi << ' ' << p->_eng << ' ' << p->_math << ' ' << p->_numb << ' ' << p->_name << ' ' << '\n';
			write_in(f,p->_left);
			write_in(f, p->_right);
		}
	}
};

#endif
