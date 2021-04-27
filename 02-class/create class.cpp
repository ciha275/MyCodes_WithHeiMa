#include<iostream>
using namespace std;

const double pi = 3.1415;

//1.设计一个类，求圆的周长
class circle //class+类名，注意类的花括号{}后要接分号;函数的花括号后没;
{
public://公共权限
	//在类里写函数→→成员函数
	//double circumference(double r)//函数有参数
	//{
	//	return 2 * pi * r;
	//}
	double circumference()//函数无参数，实现过程中应该是自己找变量名
	{
		return 2 * pi * r;
	}
	//设置半径，成员属性（成员变量）/成员方法（也就是成员函数）
	//1.成员属性（成员变量）
	double r;
	//2.成员方法（也就是成员函数）
	void set_r(int m_r)//此处函数形参与变量名重复了，导致出错，原因？
	{
		r = m_r;
	}
	circle()
	{
		cout << "moren" << endl;
	}
	circle(const circle& p)
	{
		cout << "kaobei" << endl;
	}
	~circle()
	{
		cout << "xigou" << endl;
	}
};

void test01()
{
	//通过类 创建对象（类就是对象的抽象，对象就是类的实例）
	circle yuan;// yuan 就是对象
	//给对象的半径这一属性赋值
	//yuan.r = 20;
	//用类的函数简介给类的变量（属性）赋值
	yuan.set_r(20);
	//输出圆的周长
	//cout << "周长 = " << yuan.circumference(20) << endl;//类的成员函数有参数则需要给参数
	cout << "周长 = " << yuan.circumference() << endl;
	cout << yuan.r << endl;
	circle c2(yuan);
}

int main()
{
	test01();
}
