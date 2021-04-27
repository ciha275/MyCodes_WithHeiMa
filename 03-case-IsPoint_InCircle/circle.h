#pragma once
#include"point.h"

class circle
{
public:
	circle();//默认构造函数的声明
	circle(int r, point p);//有参构造函数的声明
	circle(const circle& c);//拷贝构造函数的声明
	~circle();//析构函数

	point getCenter();
	/*{
		return center;
	}*/
	int getR();
	/*{
		return m_r;
	}*/
	//利用类的成员函数判断点与圆关系
	void PointWithCircleByClass(point& p);
private:
	point center;
	int m_r;


};
