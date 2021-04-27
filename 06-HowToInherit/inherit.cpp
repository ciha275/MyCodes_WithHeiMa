#include<iostream>
using namespace std;

class Base1//基类
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};

///////////////////////////////////公有继承public///////////////////////
class Son1 : public Base1
{
public:
	void func()
	{
		cout << m_A << endl;//基类中公有的属性，可继承，	还是public，		类外能访问
		cout << m_B << endl;//基类中保护的属性，可继承，	还是protected，	类外不能访问
	  //cout << m_C << endl;//基类中私有的属性，不可继承
	}
};
void MyFunc1()
{
	Son1 s1;
	s1.m_A;//仍是public，故类外访问
  //s1.m_B;//仍是protected，故类外不能访问
}

///////////////////////////////////保护继承protected///////////////////////
class Son2 : protected Base1
{
public:
	void func()
	{
		cout << m_A << endl;//基类中公有的属性，可继承，	变为protected，	类外不能访问
		cout << m_B << endl;//基类中保护的属性，可继承，	还是protected，	类外不能访问
	  //cout << m_C << endl;//基类中私有的属性，不可继承
	}
};
void MyFunc2()
{
	Son2 s2;
  //s2.m_A;//变为protected，故类外不能访问
  //s1.m_B;//仍是protected，故类外不能访问
}

///////////////////////////////////私有继承private///////////////////////
class Son3 : private Base1
{
public:
	void func()
	{
		cout << m_A << endl;//基类中公有的属性，可继承，	变为private，	类外不能访问
		cout << m_B << endl;//基类中保护的属性，可继承，	变为private，	类外不能访问
	  //cout << m_C << endl;//基类中私有的属性，不可继承
	}
};

class GrandSon : public Son3
{
	//因为Son3私有继承后所有属性都是私有了，所以GrandSon啥也继承不到
	//cout << m_A << endl;
};

/////////////////////////////////////继承中的对象模型///////////////////////
//查看子类大小
void test01()
{
	//虽然Son3全是private，GrandSon啥也没继承
	//实际上，子类会继承父类的私有成员，只是被编译给隐藏了，访问不到私有成员
	cout << "子类实际有的大小 ：" << sizeof(GrandSon) << endl;
}

int main()
{
	test01();
	
}
