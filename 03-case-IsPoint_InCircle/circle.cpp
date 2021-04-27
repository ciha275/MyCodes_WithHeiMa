#include<iostream>
#include"circle.h"
using namespace std;

//利用构造函数利用初始化列表给属性赋值
//比point中给每个属性编写函数赋值更方便
circle::circle(int r, point p) :m_r(r), center(p)
{
	cout << "circle的有参构造函数" << endl;
}
//等价于
//circle::circle(int r, point p)
//{
//	m_r = r;
//	center = p;
//}

point circle::getCenter()
{
	return center;
}
int circle::getR()
{
	return m_r;
}
//利用类的成员函数判断点与圆关系，函数在circle类内，则仅需传入point数据来比较，故一个参数
void circle::PointWithCircleByClass(point& p)
{
	//获取距离的平方
	int distance = (center.getX() - p.getX()) * (center.getX() - p.getX()) + (center.getY() - p.getY()) * (center.getY() - p.getY());
	int r = m_r * m_r;
	if (r == distance)
	{
		cout << "点在元上" << endl;
		return;
	}
	else if (r > distance)
	{
		cout << "点在元内" << endl;
		return;
	}
	cout << "点在元外" << endl;

}

circle::~circle()
{
	cout << "circle的析构函数" << endl;
}

