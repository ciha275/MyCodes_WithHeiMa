#pragma once
#include<iostream>
using namespace std;

template<class T>
class MyArray
{
public:

	//有参构造，创建空的指定容量capacity的数组
	explicit MyArray(int capacity)//防止隐式类型转换 防止 MyArray arr = 10; 写法
	{
		this->m_Capacity = capacity;
		this->m_Size = 0;
		//指针指向，堆区开辟的新的T类型的容量m_Capacity的数组
		this->pAddress = new T[this->m_Capacity];
	}

	//拷贝构造
	MyArray(const MyArray& array)
	{
		this->m_Capacity = array.m_Capacity;
		this->m_Size = array.m_Size;
		this->pAddress = new T[this->m_Capacity];
		for (int i = 0; i < this->m_Size; i++)
		{
			this->pAddress[i] = array[i];
		}
	}
	~MyArray()
	{
		if (this->pAddress != NULL)
		{
			delete[] this->pAddress;
			this->pAddress = NULL;
		}
	}

	//=赋值操作符重载
	MyArray& operator=(MyArray& array)
	{
		//先判断原始数据，有就清空
		if (this->pAddress != NULL)
		{
			delete[] this->pAddress;
			this->pAddress = NULL;
		}
		//随后，=赋值操作符嘛，就相当于拷贝
		this->m_Capacity = array.m_Capacity;
		this->m_Size = array.m_Size;
		this->pAddress = new T[this->m_Capacity];
		for (int i = 0; i < this->m_Size; i++)
		{
			this->pAddress[i] = array[i];
		}
	}

	//[]重载，比如希望能直接 cout<<arr[i]<<endl; ，就需要重载[]，使其能认识MyArray这个类型
	T& operator[](int index)
	{
		return this->pAddress[index];
	}

	//尾插法
	void push_Back(T val)
	{
		this->pAddress[this->m_Size] = val;
		this->m_Size++;
	}
	
	//获取大小
	int getSize()
	{
		return this->m_Size;
	}
	//获取容量
	int getCapacity()
	{
		return this->m_Capacity;
	}



private:
	T* pAddress;//指向堆区的指针
	int m_Capacity;
	int m_Size;

};

