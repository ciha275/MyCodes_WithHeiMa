#pragma once


class MyArray
{
public:
	MyArray();//默认构造，可初始化数组容量，选择默认200
	MyArray(int a);//有参构造，可选择性的设置数组容量
	MyArray(const MyArray& myarray);//拷贝构造，能复制一个已有数组
	~MyArray();//要设置对数组空间的释放

	//显示大小
	int showSize();
	//显示容量
	int showCapacity();

	//尾插法，插入一个数据在尾部
	void pushback(int index);

	//根据索引设置数据
	void setData(int i, int index);

	//重载[]，能像一般数组一样使用，如，输出array[i],array[i]=x 
	int& operator[](int index);//返回引用使得即可作左值，也可右值

private:
	//一个数组应该有一些属性，数组的容量，数组大小（实际装了多少），这个数组的位置（一个指针指向数组）
	int* pAdress;//指向真正存储数据的指针
	int m_Capacity;//数组容量
	int m_Size;//数组大小

};