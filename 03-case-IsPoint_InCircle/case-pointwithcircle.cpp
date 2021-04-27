#include<iostream>
using namespace std;
#include"point.h"
#include"circle.h"//分文件编写，需要在.h声明，在.cpp中实现

//全局函数判断点与圆的关系,参数使用引用传递而不是值传递(circle c, point p)，
//可以减少一份开销，因值传递是新开辟内存空间将值传入，后进行运算
void PointWithCircle(circle& c, point& p)
{
	//获取距离的平方
	//c → 一个圆circle类；c.getCenter() → 一个点point类；c.getCenter().getX() 得到了点的x/y坐标
	int distance = (c.getCenter().getX() - p.getX()) * (c.getCenter().getX() - p.getX()) + (c.getCenter().getY() - p.getY()) * (c.getCenter().getY() - p.getY());
	int r = (c.getR()) * (c.getR());
	if (r == distance)
	{
		cout << "点在yuan上" << endl;
		return;//注意return的添加，防止条件内执行完后顺序执行另一条件内语句
	}
	else if (r > distance)
	{
		cout << "点在yuan内" << endl;
		return;
	}
	cout << "点在yuan外" << endl;
}

void test01()
{
	point p1;
	point center1;
	p1.setY(5);
	p1.setX(5);
	center1.setX(5);
	center1.setY(0);
	circle c1(5, center1);//构造函数/初始化列表的调用，在实例对象的同时，调用格式“类名 对象名（构造函数参数列表格式）”。
	//调用成员函数判断
	//c1.PointWithCircleByClass(p1);
	//调用全局函数
	PointWithCircle(c1, p1);
}

int main()
{
	test01();
	system("pause");
	return EXIT_SUCCESS;
}