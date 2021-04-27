#include<iostream>
using namespace std;

class Person
{
public:
	Person()
	{
		//m_Age = 100;//最好不在构造函数定义
	}
	static int m_Age;//静态成员变量，共享数据，不同对象的数据都相同
	//静态成员变量只能类内声明，类外定义
	int m_nonsta;

	//静态成员函数
	static void func1()
	{
		//m_nonsta = 10;静态函数不可调用普通变量
		cout << "use of func1" << endl;
	}
	//普通函数既可以调用静态变量也可调用普通变量
	void nomal_func(int jingtai, int putong)
	{
		m_Age = jingtai;
		m_nonsta = putong;
	}
private:
	//静态成员变量也是有权限
	static int m_priv;
	//静态成员函数也是有权限
	static void func2()
	{
		cout << "use of func2" << endl;
	}

};
int Person::m_Age = 0;//类外的定义，初始化
int Person::m_priv = 10;


void test01()
{
	//1.通过对象属性（p.m_Age）访问静态变量
	Person p1;
	p1.m_Age = 1;
	Person p2;
	p2.m_Age = 2;
	//2.通过类名访问静态变量（Person::m_Age）
	cout << "m_Age = " << Person::m_Age << endl;
	//不推荐使用构造函数定义静态变量原因即，若直接以类名访问，无创建对象那一步，不会调用构造函数，则对应静态变量没有初始化
	cout << "m_Age = " << p1.m_Age << endl;
	cout << "m_Age = " << p2.m_Age << endl;
	//打印结果均为2，说明了静态变量的共享特性

	//p1.m_A = 35;		两行均报错，
	//Person::m_A = 46;	说明静态变量也是有权限控制的

	//静态成员函数也可通过对象or类名访问
	p1.func1();
	p2.func1();
	Person::func1();//显示三次“use of func1”

	//p1.func2();		private中的func2
	//Person::func2();	同样无法访问，可见静态函数同样有权限控制

	//普通函数调用静态与普通变量
	p2.nomal_func(58, 36);
	cout << "m_nonsta = " << p2.m_nonsta << endl;
	cout << "m_Age = " << Person::m_Age << endl;
	cout << "m_Age = " << p1.m_Age << endl;
	cout << "m_Age = " << p2.m_Age << endl;
}

int main()
{
	test01();
}

