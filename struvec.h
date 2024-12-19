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
	student* _last;
	student* _next;
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
		_right(nullptr),
		_last(nullptr),
		_next(nullptr)
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
		_last(nullptr),
		_next(nullptr),
		_name(" ")
	{

	}
};
class svec
{
private:
	student* root;
	int numb;
	student* root_g;
public:
	svec()
	{
		root = nullptr;
		numb = 0;
		root_g = nullptr;
	}

private:student* app_create(int ma, int en, int ch, int nu, std::string na)
{
	student* p = new student(ma, en, ch, nu, na);
	return p;
}
public:void append(int math, int english, int chinese, int numbs, std::string name)
{
	student* ps = app_create(math, english, chinese, numbs, name);
	rank_g(ps);
	this->insert(ps);
}
	  ///find
public:student* find(std::string name, int numb)
	{
		student *p = find_in(name, numb, root);
		return p;
	}

	  student* find_in(std::string name,int numb,student *p)
	  {
		  while (1)
		  {
			  if (p == nullptr)
			  {
				  return nullptr;
			  }
			  if (name > p->_name)
			  {
				  p = p->_left;
			  }
			  else if (name < p->_name)
			  {
				  p = p->_right;
			  }
			  else if (name == p->_name)
			  {
				  if (numb == p->_numb)
				  {
					  return p;
				  }
				  else if (numb < p->_numb)
				  {
					  p = p->_right;
				  }
				  else if (numb > p->_numb)
				  {
					  p = p->_left;
				  }
			  }
		  }
	  }

	  ///insert
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
		while (1)
		{
			if (cur->_name < p->_name)
			{
				p1 = p->_right;
			}
			else if (cur->_name > p->_name)
			{
				p1 = p->_left;
			}
			else if (cur->_name == p->_name)
			{
				if (cur->_numb < p->_numb)
				{
					p1 = p->_right;
				}
				else if (cur->_numb > p->_numb)
				{
					p1 = p->_left;
				}
				else if (cur->_numb == p->_numb)
				{
					std::cout << "failed to insert the student,the information has been exit\n";
					break;
				}
			}
			if (p1 == nullptr)
			{
				if (cur->_name < p->_name)
				{
					p->_right = cur;
					break;
				}
				else if (cur->_name > p->_name)
				{
					p->_left = cur;
					break;
				}
				else if (cur->_name == p->_name)
				{
					if (cur->_numb < p->_numb)
					{
						p->_right = cur;
						break;
					}
					else if (cur->_numb > p->_numb)
					{
						p->_left = cur;
						break;
					}
				}
			}
			/*int pares[4] = { p->_sum,p->_chi,p->_math,p->_numb };
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
			}*/
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
			/*int pares[4] = { p->_sum,p->_chi,p->_math,p->_numb };
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
			}*/
			if (cur->_name < p->_name)
			{
				p1 = p->_right;
			}
			else if (cur->_name > p->_name)
			{
				p1 = p->_left;
			}
			else if (cur->_name == p->_name)
			{
				if (cur->_numb < p->_numb)
				{
					p1 = p->_right;
				}
				else if (cur->_numb > p->_numb)
				{
					p1 = p->_left;
				}
				else if (cur->_numb == p->_numb)
				{
					std::cout << "failed to insert the student,the information has been exit\n";
					break;
				}
			}
			if (p1 == nullptr)
			{
				if (cur->_name < p->_name)
				{
					p->_right = cur;
				}
				else if (cur->_name > p->_name)
				{
					p->_left = cur;
				}
				else if (cur->_name == p->_name)
				{
					if (cur->_numb < p->_numb)
					{
						p->_right = cur;
					}
					else if (cur->_numb > p->_numb)
					{
						p->_left = cur;
					}
				}
			}
			p = p1;
		}
	}
	numb++;
}
	  ///rank by grades
	  
	void rank_g(student* p)
	{
		if (root_g == nullptr)
		{
			root_g = p;
		}
		else
		{
			student* p1 = root_g;
			while(1)
			{
				if (p->_sum > p1->_sum)
				{
					if (p1->_last == nullptr)
					{
						root_g = p;
						p->_next = p1;
						p1->_last = p;
						break;
					}
					else
					{
						p1->_last->_next = p;
						p->_last = p1->_last;
						p->_next = p1;
						p1->_last = p;
						break;
					}
				}
				else if (p->_sum < p1->_sum)
				{
					if (p1->_next == nullptr)
					{
						p1->_next = p;
						p->_last = p1;
						break;
					}
					else
					{
						p1 = p1->_next;
					}
				}
				else if (p->_sum == p1->_sum)
				{
					if (p->_numb > p1->_numb)
					{
						if (p1->_last == nullptr)
						{
							root_g = p;
							p->_next = p1;
							p1->_last = p;
							break;
						}
						else
						{
							p1->_last->_next = p;
							p->_last = p1->_last;
							p->_next = p1;
							p1->_last = p;
							break;
						}
					}
					else if (p->_numb < p1->_numb)
					{
						if (p1->_next == nullptr)
						{
							p1->_next = p;
							p->_last = p1;
							break;
						}
						else
						{
							p1 = p1->_next;
						}
					}
				}
			}
		}
	}

	///delete
	public:void pop(std::string name, int numb)
	{
		student* p = root;
		student* record;
		while (1)
		{
			if (p->_left->_name == name && p->_left->_numb == numb)
			{
				if (p->_left->_left == nullptr)
				{
					record = p->_left;
					p->_left = p->_left->_right;
					delete record;
				}
				else
				{
					record = p->_left;
					to_right(p->_left->_right, p->_left->_left);
					p->_left = p->_left->_left;
					delete record;
				}
				return;
			}
			if (p->_right->_name == name && p->_right->_numb == numb)
			{
				if (p->_right->_right == nullptr)
				{
					record = p->_right;
					p->_right = p->_right->_left;
					delete record;
				}
				else
				{
					record = p->_right;
					to_left(p->_right->_left, p->_right->_right);
					p->_right = p->_right->_right;
					delete record;
				}
				return;
			}
			if (name > p->_name)
			{
				if (p->_left == nullptr)
				{
					std::cout << "no such a student\n\n";
					return;
				}
				p = p->_left;
			}
			else if (name < p->_name)
			{
				if (p->_right == nullptr)
				{
					std::cout << "no such a student\n\n";
					return;
				}
				p = p->_right;
			}
			else if (name == p->_name)
			{
				if (numb < p->_numb)
				{
					if (p->_right == nullptr)
					{
						std::cout << "no such a student\n\n";
						return;
					}
					p = p->_right;
				}
				else if (numb > p->_numb)
				{
					if (p->_left == nullptr)
					{
						std::cout << "no such a student\n\n";
						return;
					}
					p = p->_left;
				}
			}
		}
	}

	void to_left(student* p, student* p1)
    {
		while (1)
		{
			if (p1->_left == nullptr)
			{
				p1->_left = p;
				break;
			}
			p1 = p1->_left;
		}
	}
	void to_right(student* p, student* p1)
	{
		while (1)
		{
			if (p1->_right == nullptr)
			{
				p1->_right = p;
				break;
			}
			p1 = p1->_right;
		}
	}

	  ///imformation out put

	  void print(bool ke,std::string form)
	  {
		  if(form == "n")
		  {
			  print_mid(root, ke);
		  }
		  else if (form == "g")
		  {
			  print_g(root_g, ke);
		  }
		  else
		  {
			  std::cout << "illegal input\n\n";
		  }
	  }

private:void print_mid(student* p, bool key)
{
	if (p == nullptr)return;
	print_mid(p->_left, key);
	print_single(p, key);
	print_mid(p->_right, key);
}
	   void print_g(student*p,bool key)
	   {
		   if (p == nullptr)return;
		   else
		   {
			   print_single(p, key);
			   print_g(p->_next, key);
		   }
	   }

public:void print_single(student* p, bool keys)
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
	file.clear();
	write_in(file, root);
	file.close();
	std::cout << "保存成功\n";
}
private:void write_in(std::ofstream& f, student* p)
{
	if (p == nullptr)f << "# " << '\n';
	else
	{
		f << p->_chi << ' ' << p->_eng << ' ' << p->_math << ' ' << p->_numb << ' ' << p->_name << ' ' << '\n';
		write_in(f, p->_left);
		write_in(f, p->_right);
	}
}
	   ///some thing about read
public:void read(std::string ku = "文本.txt")
{
	std::ifstream file(ku);
	if (root != nullptr)
	{
		std::cout << "the tree can't be create because it is not clear\n";
		file.close();
		return;
	}
	else
	{
		root = create(file);
		create_tree(root, file);
		file.close();
		std::cout << "读取成功\n";
	}
}


private:student* create(std::ifstream& f)
{
	student* p = new student;
	std::string ch1;
	std::getline(f, ch1, ' ');
	if (ch1 == "#")
	{
		p = nullptr;
		f.ignore();
	}
	else
	{
		int ma, en, ch, nu;
		std::string na, ma1, en1, nu1;
		ch = std::stoi(ch1);
		std::getline(f, en1, ' ');en = std::stoi(en1);
		std::getline(f, ma1, ' ');ma = std::stoi(ma1);
		std::getline(f, nu1, ' ');nu = std::stoi(nu1);
		std::getline(f, na, ' ');f.ignore();
		student c(ma, en, ch, nu, na);
		*p = c;
	}
	return p;
}

    void create_tree(student* p, std::ifstream& fi)
    {
		rank_g(p);
		p->_left = create(fi);
		if (p->_left != nullptr)create_tree(p->_left, fi);
		p->_right = create(fi);
		if (p->_right != nullptr)create_tree(p->_right, fi);
    }
};

#endif