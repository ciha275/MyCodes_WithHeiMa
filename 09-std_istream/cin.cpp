#include<iostream>
using namespace std;

/*
* cin.get()			一次只能读一个字符
* cin.get(两个参数)	可以读字符串，最后的换行留在缓冲区
* cin.getline()		读字符串，最后的换行拿掉并丢弃
* cin.ignore(N)		忽略N个字符
* cin.peek()		看一个字符，不拿
* cin.putback()		放回一个字符
*/

//cin.get()			一次只能读一个字符
void test01()
{
	//输入as  缓冲区 a s 换行  

	char c = cin.get();//拿 a
	cout << "c= " << c << endl;
	c = cin.get();//拿 s
	cout << "c= " << c << endl;
	c = cin.get();//拿 换行
	cout << "c= " << c << endl;

	c = cin.get();//之前输入的as及相关换行，已经拿完了，等待新输入
	cout << "c= " << c << endl;
}

//cin.get(两个参数)	可以读字符串，最后的换行留在缓冲区
void test02()
{
	char buf[1024];
	cin.get(buf, 1024);

	char c = cin.get();
	
	if (c == '\n')
	{
		cout << "说明换行还在缓冲区，被c = cin.get()拿走" << endl;
	}
	else
	{
		cout << "说明换行不在缓冲区" << endl;
	}

	cout << buf << endl;
}

//cin.getline()		读字符串，最后的换行拿掉并丢弃
void test03()
{
	char buf[1024];
	cin.getline(buf, 1024);

	char c = cin.get();//此时getline将换行拿取了，故c = cin.get()啥也收不到，在等待输入

	if (c == '\n')
	{
		cout << "说明换行还在缓冲区，被c = cin.get()拿走" << endl;
	}
	else
	{
		cout << "说明换行不在缓冲区" << endl;
	}

	cout << buf << endl;
}

//cin.ignore(N)		忽略N个字符
void test04()
{
	//输入abcd，则c = d
	cin.ignore(3);
	char c = cin.get();
	cout << c << endl;
}

//cin.peek()		看一个字符，不拿
void test05()
{
	//输入as peek只看不拿
	char c = cin.peek();
	cout << c << endl;
	//，所以第二个还是a
	c = cin.get();
	cout << c << endl;
}

//cin.putback(字符a)		放回一个字符a，只能字符
void test06()
{
	char c = cin.get();
	cin.putback(c);
	char c1 = cin.get();
	char buf[1024];
	cin.getline(buf, 1024);
	cout << "c = " << c << endl;
	cout << "c1 = " << c1 << endl;
	cout << "buf = " << buf << endl;
}

//案例1 判断用户输入是数字or字符串（默认纯数字or纯字符串）
void test07()
{
	cout << "请输入数字or字符串" << endl;
	//既希望查看第一个字符，又希望不影响缓冲区内容，选用peek
	//也可 先cin.get()拿取一个，再putback()放回，但较麻烦
	char a = cin.peek();
	if (a >= '0' && a <= '9')
	{
		int num;
		cin >> num;
		cout << "that is number: " << num << endl;
	}
	else
	{
		char buf[1024];
		cin.getline(buf, 1024);
		cout << "that is string: " << buf << endl;
	}
}

//案例2 用户输入0~9数字，正确就显示，错误重新输入
void test08()
{
	cout << "please input a number within 0 and 9" << endl;
	int num;

	while (true)//使用true保证一直循环，只有使用到break才能退出
	{
		cin >> num;
		if (num >= 0 && num <= 9)
		{
			cout << "your number is: " << num << endl;
			break;
		}
		cout << "please input again" << endl;
		//因为在缓冲区其实有标志位，0正常，1不正常
		//num类型是int，假如输入时输入了char类型，则会改变标志位，导致循环出错
		/*似乎VS2019自动优化？输入char类型后没有无限循环，直接得0*/
		//cout << cin.fail() << endl;//用cin.fail()查看标志位
		//cin.clear();//重置标志位
		//cout << cin.fail() << endl;//用cin.fail()查看标志位
		//cin.sync();//清空缓冲区
		//cout << cin.fail() << endl;//用cin.fail()查看标志位
	}
}

int main()
{
	//test01();
	//test02();
	//test03();
	//test04();
	//test05();
	//test06();
	//test07();
	test08();

}
