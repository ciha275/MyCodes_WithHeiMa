#include<iostream>
using namespace std;
#include<string>

//类型参数化  泛型编程 ———— 模板技术
template<class T>//告诉编译器  紧跟着出现的T不要报错，T是一个通用的类型
void mySwap(T& a , T& b)
{
	T temp;
	temp = a;
	a = b;
	b = temp;
}

//这一段就不是紧跟着了，会报错“不允许使用不完整的类型”、“未定义标识符"T"”
//需要再用“template<class T>”来指明
//void mySwap3(T& a, T& b)
//{
//	T temp;
//}

// template<typename T> 等价于 template<class T>
template<typename T>
void mySwap2() {}//仅是声明，无实现


void test01()
{
	int a = 10;
	int b = 20;
	char c1 = 'c';
	//1、自动类型推导，必须要有类型才能推导
	//mySwap(a, c1);//此时出现了二义性，也推导不出来
	mySwap(a,b);
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	//2、显式的指定类型
	mySwap<int>(a,b);
	//对于无实现的函数模板，自动类型推导调用会报错，
	//mySwap2();
	//因对于一个通用类型T，编译器不知到应该分配多大的内存空间
	//使用显式地指定就避免了问题
	mySwap2<double>();
}

////////////////函数模板和普通函数的区别，及调用规则////////////

//1、普通函数和函数模板的区别
template<class T>
T myPlus(T a, T b)
{
	return a + b;
}

int myPlus2(int a, int b)
{
	return a + b;
}

void test02()
{
	int a = 10;
	int b = 20;
	char c = 'c';//ASCI码 a = 97
//	myPlus(a, c);//类型推导不出来，函数模板不能进行隐式类型转换
	cout << myPlus2(a, c) << endl;//10+99 普通函数可以隐式类型转换

}

//普通函数和函数模板的调用规则
template<class T>
void myPrint(T a, T b)
{
	cout << "template" << endl;
}
template<class T>
void myPrint(T a, T b, T c)
{
	cout << "template(abc)" << endl;
}

void myPrint(int a, int b)
{
	cout << "normal" << endl;
}

void test03()
{
	int a = 1;
	int b = 2;

	//1 如果出现重载(普通和模板相比可以看作是参数类型不同(个人理解))，优先使用普通函数，如果普通函数没有实现，则出现错误“无法解析的外部命令”
	myPrint(a, b);

	//2 想强制调用函数模板，可以使用空参数列表
	myPrint<>(a,b);

	//3 函数模板可以发生重载
	int c = 3;
	myPrint(a, b, c);

	//4 如果函数模板可以产生更好的匹配，优先模板
	char c1 = 'c';
	char d1 = 'd';
	myPrint(c1, d1);//此时调用的模板，因，若调用普通的，还需要进行隐式类型转换
}

////////////////////////函数模板的局限性//////////////////////
///////////不能解决所有类型，如出现不能解决的类型，对该类型进行具体化/////////

class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

	string m_Name;
	int m_Age;
};

template<class T>
bool myCompare(T& a, T& b)
{
	if (a == b)
	{
		return true;
	}
	return false;
}

//一般来说，这样传入person型“myCompare(p1, p2);”，模板能识别是传入了两个person类型，但实际内部不能处理
//可以通过具体化自定义数据类型，解决上述问题
//语法 template<> 返回值 函数名<具体类型>(具体类型 参数名)
template<> bool myCompare<Person>(Person& a, Person& b)
{
	if (a.m_Age == b.m_Age)
	{
		return true;
	}
	return false;
}

void test04()
{
	Person p1("ABC", 30);
	Person p2("DEF", 45);

	int ret = myCompare(p1, p2);
	cout << "ret = " << ret << endl;
}


int main()
{
//	test01();
//	test02();
	test03();
	test04();
}
