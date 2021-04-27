#include<iostream>
#include<string>
using namespace std;

//单例模式就是要保证一个类的对象唯一一个
//将默认构造函数，拷贝函数私有化，保证不能创建新的对象
//构建唯一的(静态)指针，并私有化，static 类名* variable
//静态，类内声明，类外定义

class Printer
{
private:
	Printer()
	{}
	Printer(const Printer& p)
	{}

public:
	//对外提供getInstance方法访问指针
	static Printer* getInstance()//注意返回的是“static Printer*”类型
	{
		return thePrinter;
	}

	void print(string s)
	{
		cout << s << endl;
	}
private:
	static Printer* thePrinter;
};
Printer* Printer::thePrinter = new Printer;

void test01()
{
	//拿到打印机
	//Printer* MyGet = Printer::getInstance();
	Printer* MyGet;
	MyGet = Printer::getInstance();//此处即为通过类名访问静态函数，因为单例模式，也就无所谓对象了，就无对象访问
	MyGet->print("first use ->");
	(*MyGet).print("second use *");
}

int main()
{
	test01();
}

