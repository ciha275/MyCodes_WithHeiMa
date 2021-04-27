#include<iostream>
using namespace std;
#include"MyArray.h"

void test01()
{
	//这是在堆区创建数组
	//MyArray *a2 = new MyArray(30);
	//MyArray *a3 = new MyArray(*a2);

	MyArray a2(30);
	//MyArray a3(a2);
	//用a3拷贝a2，在哪都行，但在此处，
	//a2并未被赋值，则a3拷贝出来数据为乱码，a2在后面赋值后也与a3无关了

	for (int i = 0; i < 10; ++i)
	{
		a2.pushback(i);		//要用pushback()才是一位位的初始化，压入，用setData()数组大小m_Size没有变化,a3拷贝a2时需根据i<m_Size写入数据，因此a3无数据
	}
	for (int i = 0; i < 10; ++i)
	{
		cout << (a2)[i] << endl;//因为重载了[]，所以能这样访问
	}
	cout << "a2 size = " << a2.showSize() << "; a2 capacity = " << a2.showCapacity() << endl;
	cout << "a2 first = " << (a2)[0] << "; a2 last = " << (a2)[9] << endl;
	
	MyArray a3(a2);
	cout << "a3 size = " << a3.showSize() << "; a3 capacity = " << a3.showCapacity() << endl;
	cout << "a3 first = " << (a3)[0] << "; a3 last = " << (a3)[9] << endl;
}

int main()
{
	test01();
}