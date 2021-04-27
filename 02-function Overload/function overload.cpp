#include<iostream>
using namespace std;

//函数重载  的条件↓
//函数名称相同，在同一个作用域下
//函数参数的  个数不同、类型不同、排列顺序不同
void func()
{
	cout << "无参数的func()" << endl;
}
void func(int a)
{
	cout << "有参数的func(int a)" << endl;
}
void func(double a)
{
	cout << "有参数的func(double a)" << endl;
}
void func(int a, double b)
{
	cout << "有参数的func(int a, double b)" << endl;
}
void func(double a, int b)
{
	cout << "有参数的func(double a, int b)" << endl;
}

//返回值不可以作为重载条件，因调用函数时可能并不用返回值
//可见此段报错↓
//int func(double a, int b)
//{
//	cout << "有参数的func(double a, int b)" << endl;
//}

void test01()
{
	func();
	func(1);
	func(1.1);
	func(1, 2.2);
	func(2.2, 1);
}

//重载遇上函数默认参数，要注意二义性
void func2(int a, int b = 10)
{
	cout << "func2(int a, int b = 10)" << endl;
}
void func2(int a)
{
	cout << "func2(int a)" << endl;
}
void test02()
{
	//func2(15);//报错“有多个func2实例与参数列表匹配
}

//引用的重载
void func3(int& a)
{
	cout << "&a" << endl;
}
void func3(const int& a)
{
	cout << "const &a" << endl;//const 将会分配内存空间，实质为 int temp = 10, const int& a = temp
}
void test03()
{
	//int a = 10;	//↓此可
	//func3(a);		//↓段行
	func3(10); //此段会打印“const &a”
}

int main()
{
	//test01();
	test03();
}


