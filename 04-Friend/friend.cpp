#include<iostream>
#include<string>
using namespace std;

//友元,一个类的友元就是能访问这个类的private
//类、函数、类的成员函数都能做友元
																			//关于这篇中出现的“使用了未定义类型”的问题，https://blog.csdn.net/chuomei5332/article/details/109675366
																			//在用 类::函数 时，保证此前有这个类及其函数的声明
//class Onlyfunc1;//这就是声明一个类但没有定义，所以class Building中用Onlyfunc1::func1()时，编译器不能确定Onlyfunc1这个类中有没有func1()函数

class Building;

//仅类中的func1()作友元，此处只有类内部函数的声明
class Onlyfunc1
{
public:
	Onlyfunc1();
	//{
	//	MybuildingInClass = new Building;	//同样，此处实际用了Building里的构造函数来创建，而在此前只有Building的一个声明，其内部这些构造函数还处于未知，将报错
	//}										//故，Onlyfunc1这个类中的具体函数实现，涉及Building内部函数定义的，需在Building的定义之后实现

	void visitInClass();
	//{
	//	cout << "类的visitInClass在访问 " << MybuildingInClass->sittingRoom << endl;
	//	//cout << "类的visitInClass在访问 " << MybuildingInClass->bedRoom << endl;此类中仅已func1作为友元，故此行不可访问
	//}
	void func1();
	/*{
		cout << "类的func1在访问 " << MybuildingInClass->sittingRoom << endl;
		cout << "类的func1在访问 " << MybuildingInClass->bedRoom << endl;
	}*/

	Building* MybuildingInClass;
};



class Building
{
	friend void visitQUAN(Building& b1);	//全局作友元
	friend class MyClass;					//整个类作友元
	friend void Onlyfunc1::func1();	//类中成员函数作友元

public:
	string sittingRoom = "客厅";

private:
	string bedRoom = "卧室";
};

//全局函数作友元
void visitQUAN(Building& b1)
{
	cout << "全局在访问 " << b1.sittingRoom << endl;
	cout << "全局在访问 " << b1.bedRoom << endl;
}
//整个类作友元
class MyClass
{
public:
	MyClass()
	{
		MybuildingInClass = new Building;
	}

	void visitInClass()
	{
		cout << "类在访问 " << MybuildingInClass->sittingRoom << endl;
		cout << "类在访问 " << MybuildingInClass->bedRoom << endl;
	}

	Building* MybuildingInClass;
};

//仅类中的func1()作友元,class Onlyfunc1的函数定义

	Onlyfunc1::Onlyfunc1()
	{
		MybuildingInClass = new Building;
	}

	void Onlyfunc1::visitInClass()
	{
		cout << "类的visitInClass在访问 " << MybuildingInClass->sittingRoom << endl;
		//cout << "类的visitInClass在访问 " << MybuildingInClass->bedRoom << endl;此类中仅已func1作为友元，故此行不可访问
	}
	void Onlyfunc1::func1()
	{
		cout << "类的func1在访问 " << MybuildingInClass->sittingRoom << endl;
		cout << "类的func1在访问 " << MybuildingInClass->bedRoom << endl;
	}


void test01()
{
	Building building;
	visitQUAN(building);
	MyClass C1;
	Onlyfunc1 C2;
	C1.visitInClass();
	C2.visitInClass();
	C2.func1();

}

int main()
{
	test01();
}
