#include<iostream>
using namespace std;
#include<string>

///////////////////////类模板，其实就是template<class T>后紧跟一个类/////////////
template<class NameType, class AgeType = int>//类模板可以有默认类型，函数模板没有
class Person
{
public:
	Person(NameType name, AgeType age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	void showPerson()
	{
		cout << "年龄: " << this->m_Age << " 姓名: " << this->m_Name << endl;
	}
	NameType m_Name;
	AgeType m_Age;
};

void test01()
{
	//自动类型推导 类模板不支持
	//Person p("孙悟空", 300);

	//使用显式指定
	Person<string, int> p("孙悟空", 300);
	p.showPerson();

}

////////////////////////////成员函数的调用时机//////////////////////////////

class Person1
{
public:
	void showPerson1()
	{
		cout << "Person1的调用" << endl;
	}
};
class Person2
{
public:
	void showPerson2()
	{
		cout << "Person2的调用" << endl;
	}
};
template<class T>
class myClass
{
public:
	T obj;
	void func1()
	{
		obj.showPerson1();
	}
	void func2()
	{
		obj.showPerson2();
	}
};
//类模板的成员函数一开始不会创建，在运行时才去创建
//假设是创建了，那么showPerson1()、showPerson2()两个函数是Person1和Person2的，
//obj这个对象，要么是Person1，要么Person2，要么都不是，
//即func1和func2总有一个或都报错，但未报错，可见最开始并没有确定

void test02()
{
	myClass<Person1> m;
	m.func1();
	//m.func2();//此时调用func2()，也就去创建showPerson2()，但此时是Person1，没有showPerson2()这个成员，就无法创建，因而报错
}


/////////////////////////////类模板做函数参数//////////////////////////
/////////用最上面的Person类模板

//1 指定传入类型
void doWork(Person<string, int>& p)
{
	p.showPerson();
}

void test031()
{
	Person<string, int> p("A", 10);
	doWork(p);
}

//2 参数模板化
template<class T1, class T2>
void doWork2(Person<T1, T2>& p)
{
	//如何查看类型
	cout << typeid(T1).name() << endl;
	cout << typeid(T2).name() << endl;

	p.showPerson();
}

void test032()
{
	Person<string, int> p("B", 20);
	doWork2(p);
}

//3 整体模板化
template<class T>
void doWork3(T& p)
{
	cout << typeid(T).name() << endl;

	p.showPerson();
}
void test033()
{
	Person<string, int> p("C", 30);
	doWork3(p);
}


////////////////////////////类模板中的继承及其问题///////////////////////////
////////////////基类是模板类，子类继承时必须告诉基类中T的类型//////////////////

template<class T>
class Base
{
public:
	T m_A;
};
//直接继承 class Child :: public Base 报错
//在构造Child时也会调用Base的构造，可能会给m_A赋值，则涉及分配内存
//而此时，m_A的类型还是T，未知，因此报错；解决，继承时给定Base中T的类型
class Child1 : public Base<int>
{
	
};

//child2也是类模板，这样就可以不必固定Base的T类型
template<class T1, class T2>
class Child2 : public Base<T2>
{
public:
	Child2()
	{
		cout << typeid(T1).name() << endl;
		cout << typeid(T2).name() << endl;
	}

	T1 m_B;
};

void test04()
{
	Child2<int, double> child;
	//对应可知，m_B是int  m_A是double
}

//////////////////////类模板类外实现成员函数////////////////////
template<class T1, class T2>
class Person4
{
public:
	Person4(T1 name, T2 age);
		/*{
			this->m_Name = name;
			this->m_Age = age;
		}*/
	void showPerson();
	/*{
		cout << "name: " << this->m_Name << " age: " << this->m_Age << endl;
	}*/
	T1 m_Name;
	T2 m_Age;
};
//类外实现成员函数，
//非模板Person4::Person4(T1 name, T2 age)
//模板Person4<T1, T2>::Person4(T1 name, T2 age)
template<class T1, class T2>
Person4<T1, T2>::Person4(T1 name, T2 age)
{
	this->m_Name = name;
	this->m_Age = age;
}
template<class T1, class T2>
void Person4<T1, T2>::showPerson()
{
	cout << "name: " << this->m_Name << " age: " << this->m_Age << endl;
}

void test05()
{
	Person4<string, int> p4("Mt", 156);
	p4.showPerson();
}

//////////////////////////////////////友元函数与类模板//////////////////////////////////////

//类外实现的printPerson2，声明是在Person5这个类中，编译器看不到
//让编译器提前看到printPerson2声明，又因printPerson2函数中涉及Person5这个类
//让编译器看到Person5类声明
template<class T1, class T2> class Person5;
template<class T1, class T2> void printPerson2(Person5<T1, T2>& p);

template<class T1, class T2>
class Person5
{
	//友元函数类内实现，声明和实现都写在这了，其实就相当于成员函数
	friend void printPerson1(Person5<T1, T2>& p)
	{
		cout << "name: " << p.m_Name << " age: " << p.m_Age << endl;
	}
	//友元函数类外实现，
	//一般的声明：friend void printPerson1(Person5<T1, T2>& p);，这是普通函数的声明
	//利用空参数列表<>告诉编译器是模板函数的声明
	friend void printPerson2<>(Person5<T1, T2>& p);

public:
	Person5(T1 name, T2 age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	
private:
	T1 m_Name;
	T2 m_Age;
};

//类外实现，可见此时这是一个模板函数
template<class T1, class T2>
void printPerson2(Person5<T1, T2>& p)
{
	cout << "name: " << p.m_Name << " age: " << p.m_Age << endl;
}

void test06()
{
	Person5<string, int> p("TOM", 10);
	printPerson1(p);//虽然说就相当于成员函数，但这种调用方式，可见仍是一个全局函数

	printPerson2(p);
}



int main()
{
	//test01();
	//test02();

	//test031();
	//test032();
	//test033();

	//test04();

	//test05();
	test06();

}