#include<iostream>
using namespace std;

class Base1//基类
{
public:
	Base1()
	{
		m_A = 10;
		cout << "Base1的默认构造" << endl;
	}
	~Base1()
	{
		cout << "Base1的析构函数" << endl;
	}

	int m_A;

protected:
	int m_B;
private:
	int m_C;
};

//子类会继承父类的成员函数、成员属性
//但是，子类不会继承父类的构造、析构函数
//只有父类知道自己的构造和析构

class Son1 : public Base1
{
public:
	Son1()
	{
		cout << "son1的默认构造" << endl;
	}
	~Son1()
	{
		cout << "son1的析构" << endl;
	}
};

void test01()
{
	Base1 b1;
	Son1 s1;//可见调用子类时会先调用父类
}

//对于父类有参构造，可在子类中用初始化列表方式，显式地调用父类有参构造
class Base2
{
public:
	Base2(int a)
	{
		this->m_A = a;
		cout << "有参构造函数" << endl;
	}
	
	int m_A;
};

class Son2 : public Base2
{
public:
	Son2(int a) : Base2(a)
	{}
};

void test02()
{
	Son2 s2(35);
}

/////////////////////////////对于同名函数、属性的处理/////////////////////////
class Base3
{
public:
	Base3()
	{
		cout << "Base3的默认构造" << endl;
		this->m_S = 123;
	}
	void func()
	{
		cout << "Base3的func" << endl;
	}
	void func(int a)
	{
		cout << "Base3的有参func" << endl;
	}

	int m_S;
};

class Son3 : public Base3
{
public:
	Son3()
	{
		cout << "Son3的默认构造" << endl;
		this->m_S = 111;
	}
	void func()
	{
		cout << "Son3的func" << endl;
	}

	int m_S;
};

//父类和子类中有同名属性m_S
void test03()
{
	Son3 s3;
	cout << s3.m_S << endl;//默认就近原则，故调用子类的m_S
	//用::确定作用域，来调用父类的m_S
	cout << s3.Base3::m_S << endl;

	//成员函数同理
	s3.func();
	s3.Base3::func();

	//单加参数也不能直接找到父类的有参func，
	//因同名后就近原则是把父类同名的版本都隐藏了，包括有参
	//故要调用父类的必须作用域

	//s3.func(1);
	s3.Base3::func(1);
}


/////////////////////////////////静态成员的处理///////////////////
//其实就和普通成员函数、变量一样
class Base4
{
public:
	static void func()
	{
		cout << "base4 func" << endl;
	}
	static void func(int a)
	{
		cout << "base4 func(int)" << endl;
	}
	static int m_A;
};
int Base4::m_A = 10;//静态成员，类外定义

class Son4 : public Base4
{
public:
	static void func()
	{
		cout << "son4 func" << endl;
	}
	
	static int m_A;
};
int Son4::m_A = 11;//静态成员，类外定义

//静态成员，子类可继承
void test04()
{
	cout << Son4::m_A << endl;//访问静态成员，类名+::
	//访问父类同名
	cout << Son4::Base4::m_A << endl;

	Son4::func();
	Son4::Base4::func(1);
}

int main()
{
	test01();
	test02();
	test03();
	test04();
}
