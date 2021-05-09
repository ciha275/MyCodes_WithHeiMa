#include<iostream>
#include<string>
using namespace std;
//利用系统提供的标准异常，包含头文件 <stdexcept>
#include<stdexcept>

/**********************************异常利用多态派生************************************/
//基本思路：有一个异常基类，随后不同的异常类型继承于他，成为各个派生类
//异常基类
class BaseException
{
public:
	virtual void printError()
	{}
};

class NullPointerException : public BaseException
{
public:
	virtual void printError()
	{
		cout << "空指针异常" << endl;
	}
};

class OutofRangeException : public BaseException
{
public:
	virtual void printError()
	{
		cout << "越界异常" << endl;
	}
};

void doWork()
{
	//最终的异常类型，就取决于抛出的异常类型

	//throw NullPointerException();
	
	throw OutofRangeException();
}

void test01()
{
	try
	{
		doWork();
	}
	catch (BaseException& e)//在函数中抛出的是子类匿名对象，此处捕获基类，即基类引用指向了子类对象，发生了多态
	{
		e.printError();
	}
}

/**********************************利用系统的标准异常派生************************************/
//系统其实也就有个基类异常，随后派生，系统标准异常头文件<stdexcept>
class MyOutofRangeException : public exception	//exception系统标准异常的基类，可右键查看代码，明确需要自己的子类需要写哪些（就是那些有 virtual 的多态内容需要实现）
{
public:
	MyOutofRangeException(string errInfo)//有参构造，可以输入错误信息
	{
		this->m_errInfo = errInfo;
	}

	//继承exception基类需要写的内容
	//析构
	virtual ~MyOutofRangeException()
	{

	}
	virtual const char* what() const	//后const表示常函数，前const，返回的是const char*类型
	{
		//返回错误信息，但内部维护是string，返回值 char*
		//string 转 char*    .c_str()
		return this->m_errInfo.c_str();
	}

	string m_errInfo;//内部维护错误信息
};


class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;

		//对年龄做检测
		if (age < 0 || age > 100)
		{
			//out_of_range就是系统的一个标准异常
			//throw out_of_range("年龄越界");
			
			//利用自己编写的异常派生类
			throw MyOutofRangeException("我自己的越界异常");
		}
	}

	string m_Name;
	int m_Age;
};

void test02()
{
	try
	{
		Person p1("mingzi", 120);
	}
	catch (MyOutofRangeException& e)
	{
		cout << e.what() << endl;
	}
}

int main()
{
	test01();
	test02();
}