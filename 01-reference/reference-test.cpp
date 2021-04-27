#include<iostream>
using namespace std;

//引用在C++内部实现本质是一个“指针常量”

//引用只能初始话一次
void test01()
{
	int a = 120, c = 210;
	int& b = a;//自动转换为int* const b = &a；这也说明为啥要初始化，因为指针常量就必须要初始化
	//int& b; b=a; 是错误的
	//假如编写 b = 20，内部发现 b 是引用，自动转换为 *b = 20
	cout << "b=" << b << endl;
	/*int &b = c;//这行即会报错
	cout << "b=" << b << endl;*/
}

//引用必须引用合法的内存空间，即 int &b = 10 为非法

//不要返回局部变量的引用（是否只要局部变量都不返回？因为局部的就只在局部有效嘛）
//（个人理解>答案：普通的局部变量返回就是一种值的传递，如果返回的是引用，）
//（就是对局部变量的一种指向，那局部脱离了局部就“无”了，则返回的这个指向就是乱码）
int& dowork()//这就是一个返回局部变量的引用 的函数。ps：函数定义得 type类型  name函数名（）
{
	int a = 12;//a就是一个局部变量
	return a;//编译后错误列表显示该行“返回局部变量或临时变量的地址 : a”，可见如上所说，引用的本质就是一个指针常量

}

void test02()
{
	int& value = dowork();
	cout << "value = " << value << endl;//第一次能返回a的值是VS的优化
	cout << "value = " << value << endl;//可见以下均为乱码
	cout << "value = " << value << endl;
	cout << "value = " << value << endl;
}

//如果非要返回引用，则需加static保存住局部变量
int& dowork2()
{
	static int a = 12;
	return a;
}
void test03()
{
	int& value = dowork2();
	cout << "value = " << value << endl;
	cout << "value = " << value << endl;
	cout << "value = " << value << endl;
	cout << "value = " << value << endl;
}

//如果函数的返回值是引用，那么这个函数可以作为左值
//例，dowork() = 1000//相当于a = 1000

int main()
{
	//test01();

	//test02();

	test03();

	system("pause");
}