#include<iostream>
using namespace std;

////////////////////////////////多继承////////////////////////////////

class Base1
{
public:
	Base1()
	{
		this->m_A = 10;
	}
	int m_A;
};

class Base2
{
public:
	Base2()
	{
		this->m_A = 20;
	}
	int m_A;
};

class Son1 : public Base1, public Base2//多继承的写法 
{
public:
	int m_C;
	int m_D;
};

void test01()
{
	cout << sizeof(Son1) << endl;//大小16，可见有4个int，即Base1 2均继承了

	//多继承，若父类有同名属性，导致二义性
	Son1 s1;
	//s1.m_A;//二义性，无法直接访问
	cout << s1.Base1::m_A << endl;
	cout << s1.Base2::m_A << endl;
}

////////////////////////////////菱形继承////////////////////////////////

class DiamondBase
{
public:
	int m_A;
};

class DiamondSon1 : public DiamondBase
{
	
};
class DiamondSon2 : public DiamondBase
{

};

class DiamondGrandson : public DiamondSon1, public DiamondSon2
{

};

void test02()
{
	DiamondGrandson Gs;
	//Gs.m_A;//此时grandson就会继承son1里父类的m_A，也继承son2里的m_A，导致二义性
}

//使用虚基类解决菱形继承的问题
class DiamondSon1V : virtual public DiamondBase
{

};
class DiamondSon2V : virtual public DiamondBase
{

};

class DiamondGrandsonV : public DiamondSon1V, public DiamondSon2V
{

};

void test03()
{
	DiamondGrandsonV GsV;
	GsV.m_A;//此时可访问了
	//利用虚基类，操作的是一份共享的数据
	GsV.DiamondSon1V::m_A = 10;
	GsV.DiamondSon2V::m_A = 20;

	cout << GsV.DiamondSon1V::m_A << endl;
	cout << GsV.DiamondSon2V::m_A << endl;
	cout << GsV.m_A << endl;
	//可见输出均为20，因为利用虚基类后，在son1V、son2V中有虚基类指针vbptr，通过不同的偏移量来找到同一个m_A
}

int main()
{
	//test01();
	test03();
}
