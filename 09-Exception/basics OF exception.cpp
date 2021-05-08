#include<iostream>
using namespace std;

//对异常的基本处理
//通过throw在出现异常的情况下抛出异常
//用try来试可能出现异常的代码段，紧跟着的catch捕获throw抛出的异常

class MyException//自定义异常类
{
public:
	void printError()
	{
		cout << "自定义类型异常" << endl;
	}
};

//例，除法，可能就是除0异常
int MyDivide(int a, int b)
{
	if (b == 0)//除数为0，发生除0异常
	{
		//抛出异常，除了基础类型，也能抛出自定义类型的异常
		//throw 1;//抛出int型异常
		//throw 3.14;//抛出double型异常
		//throw 'c';//抛出char型异常

		//除了基础类型，也能抛出自定义类型的异常
		throw MyException();// “ 类名() ”这是匿名对象的写法
	}
	return a / b;//正常情况就返回除法结果
}
void test01()
{
	int a = 10;
	int b = 0;
	try//将可能出现问题的函数，放入try{}模块中
	{
		MyDivide(a, b);
	}

	//将“throw 1”“throw 3.14” ... 等抛出均打开时，可以发现，当catch到一个类型后，其他的catch就不用了

	catch (int)//用catch()捕获抛出的异常类型，此处即为int型
	{
		//catch(){}的{}内就是对此类型异常的处理
		cout << "int型异常" << endl;
	}
	catch (double)
	{
		cout << "double型异常" << endl;
	}
	catch (MyException e)//这里其实是一个值传递，将抛出的匿名对象传给了这里创建的e
	{
		e.printError();
	}
	catch (...)//...表示囊括其他类型异常
	{
		cout << "其他型异常" << endl;
	}
}


int main()
{
	test01();
}