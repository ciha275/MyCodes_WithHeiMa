#include<iostream>
using namespace std;

class Person
{
public:
	int var;//非静态成员变量
	void func() {};//非静态成员函数,此时func默认有个this指针参数，func(Person* this)
	static int vars;//静态成员变量
	static void funcs() {};//静态成员函数
	//double vard;
	//只有int时Person的size为4，
	//加上double，因内存对齐，所以此时给int也是8字节，此时Person的size则为16
public:
	Person() {};
	//this指针解决命名冲突
	Person(int age)
	{
		this->age = age;
		//age = age;此行age编译器认为都是此函数中的age，
	}
	//一般的函数其实都默认加了this
	void compare(Person& p)
	{
		if (age == p.age)//实际“age == p.age”就是“this->age == p.age”
		{
			cout << "same" << endl;
			return;
		}
		cout << "not same" << endl;
	}

	//年龄相加,不能链式编程
	void agePlus(Person& p)
	{
		this->age += p.age;
	}
	//年龄相加，可链式编程
	Person& agePlusCanLink(Person& p)
	{
		this->age += p.age;
		return *this;//this是指向本体的指针，*this就是返回本体
		//同时返回的是引用，可左值，可链式编程
	}

	int age;


};

//可见只有非静态成员变量才属于对象身上
//静态的变量、函数，不用说，都是单独开辟的区域，所以不同对象访问的静态“ ”都是一样的
//非静态成员函数也不在对象身上
void test01()
{
	cout << "size of Person = " << sizeof(Person) << endl;
}

//对于非静态成员函数，不在对象身上，不同对象调用时的区分就在与“this”指针
void test02()
{
	//this指针指向被调用的成员函数所属的对象
	Person p1;
	Person p2;
	p1.func();//编译器其实加入了参数 Person* this，这个this指向p1
}

void test03()
{
	Person p1(10);
	Person p2(10);
	p1.agePlus(p2);
	//p1.agePlus(p2).agePlus(p2);此行报错，p1.agePlus()对p1的age操作后没有返回值
	cout << "p1.age = " << p1.age << endl;
	Person p3(10);
	//每次都返回了p3，则可链式编程
	p3.agePlusCanLink(p2).agePlusCanLink(p2).agePlusCanLink(p2);
	cout << "p3.age = " << p3.age << endl;
}


int main()
{
	test01();
	test03();
}