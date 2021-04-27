#include"point.h"
#include<iostream>
using namespace std;

point::point()
{
	cout << "point的默认构造函数" << endl;
}

//用初始列表or构造函数初始化  更简单！
//point::point(int x, int y) :m_x(x), m_y(y)
//{}
point::point(int x, int y)
{
	/*m_x = x;
	m_y = y;*/
	cout << "point的有参构造函数" << endl;
}

point::point(const point& p)
{
	cout << "point的拷贝" << endl;
	this->m_x = p.m_x;
	this->m_y = p.m_y;
}

void point::setX(int x1)//设置x坐标,函数声明，函数实现在对应.cpp文件中编写
{
	m_x = x1;
}

void point::setY(int y1)//设置y坐标
{
	m_y = y1;
}

int point::getX()
{
	return m_x;
}
int point::getY()
{
	return m_y;
}

point::~point()
{
	cout << "point的析构函数" << endl;
}