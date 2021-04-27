#pragma once


class point
{
public:
	point();
	~point();
	point(int x, int y);
	point(const point& p);

	void setX(int x1);//设置x坐标,函数声明，函数实现在对应.cpp文件中编写
	void setY(int y1);//设置y坐标
	int getX();//X坐标
	int getY();//y坐标


private:
	int m_x;//点x坐标
	int m_y;//点y坐标
};