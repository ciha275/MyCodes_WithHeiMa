#include<iostream>
using namespace std;


//静态类型转换 static_cast   
//用法：static_cast<目标类型>(原始对象)
//支持基础类型之间的转换，支持基类与派生类的转换
class Base1 {};
class Child1 : public Base1 {};
class Other {};
void test01()
{
	//基础类型
	double a = 1.23;
	int b = static_cast<int>(a);//double转int，精度丢失，不安全，但静态转换也能转
	char c = 'a';
	int d = static_cast<int>(c);//字符 a 的ASCI码值为 97
	cout << "b = " << b << endl;
	cout << "d = " << d << endl;

	//父子类之间
	Base1* base1 = NULL;
	Child1* child1 = NULL;
	//父转子 向下转换  不安全，但静态转换能转
	Child1* child = static_cast<Child1*>(base1);
	//子转父 向上转换  安全
	Base1* base = static_cast<Base1*>(child1);
	//无继承关系的类，不能转
	//Other* other = static_cast<Other*>(b1);报错“类型转换无效”
}

//动态类型转换 dynamic_cast   
//用法：dynamic_cast<目标类型>(原始对象)
//非常严格，不支持基础类型转换，不支持基类与派生类之间不安全的转换(父转子 向下转换)
//当发生多态时，可以基类向派生类转换（在多态时，父类指针或引用指向子类对象，其实这时候开辟的空间就是子类的大小，所以此时父转子其实并没有超出范围，故而是安全的）
class Base2 
{
	virtual void func() {}
};
class Child2 : public Base2
{
	virtual void func() {}
};
void test02()
{
	//基础类型 都不能动态转换
	//double a = 1.23;
	//int b = dynamic_cast<int>(a);//double转int，精度丢失，不安全，不能动态转换
	//int a = 10;
	//double b = dynamic_cast<double>(a);//int转double，个人认为安全，但也不能动态转换
	
	//父子类之间，无多态时
	Base2* base2 = NULL;
	Child2* child2 = NULL;
	//父转子 向下转换  不安全，动态转换不支持
	//Child2* child = dynamic_cast<Child2*>(base2);
	//子转父 向上转换  安全，动态转换支持
	Base2* base = dynamic_cast<Base2*>(child2);

	//父子类，发生多态时，父转子，向下动态转换，可行
	Base2* vbase2 = new Child2;
	Child2* child = dynamic_cast<Child2*>(vbase2);
}

//常量转换（const_cast）只能调节类型限定符，不能更改基础类型
//只能对指针或引用使用，const的转为没const，没const的转为const
void test03()
{
	// 指针
	//1、const转非const
	const int* p = NULL;
	//double* newp = const_cast<double*>(p);//报错“只能调节类型限定符，不能更改基础类型”
	int* newp = const_cast<int*>(p);
	//2、非const转const
	int* p2 = NULL;
	const int* newp2 = const_cast<const int*>(p2);
	// 引用
	int num = 10;
	int& numRef = num;
	const int& numRef2 = const_cast<const int&>(numRef);

	//不能对非指针or非引用的变量 使用
	//const int a = 10;
	//int b = const_cast<int>(a);
}

//重新解释转换（reinterpert_cast）最不安全，基本不用
void test04()
{
	//int 能转 int*
	int a = 10;
	int* p = reinterpret_cast<int*>(a);
	//不相关的类也能互转
	Base1* base = NULL;
	Other* other = reinterpret_cast<Other*>(base);
}

int main()
{
	//test01();
	test02();

}
