#include<iostream>
using namespace std;
#include"MyArray.hpp"
#include<string>

//输出int类型数组的方法
void printIntArray(MyArray<int>& arr)
{
	for (int i = 0; i < arr.getSize(); i++)
	{
		cout << arr[i] << endl;
	}
}


void test01()
{
	MyArray<int> arr1(10);//给定T为int类型的，容量10的int 数组
	for (int i = 0; i < 10; i++)
	{
		arr1.push_Back(i + 100);
	}
	printIntArray(arr1);
}

class Person
{
public:
	//调用一个 类 类型的数组时，一定会调用这个类的默认构造
	Person() 
	{
		cout << "调用默认" << endl;
		this->m_Age = 0;
		this->m_Name = "nothing";
	}
	Person(string name, int age)
	{
		cout << "有参构造" << endl;
		this->m_Name = name;
		this->m_Age = age;
	}

	string m_Name;
	int m_Age;
};

//输出Person类型数组
void printPersonArray(MyArray<Person>& arr)
{
	for (int i = 0; i < arr.getSize(); i++)
	{
		cout << "name: " << arr[i].m_Name << " age: " << arr[i].m_Age << endl;
	}
}

void test02()
{
	Person p1("A", 11);
	Person p2("B", 12);
	Person p3("C", 13);
	Person p4("D", 14);
	Person p5("E", 15);
	Person p6("F", 16);
	Person p7("G", 17);

	MyArray<Person> arr2(10);
	//在控制台窗口可以看到在这开辟Person类型数组，10个元素空间，就有10次“调用默认”
	
	arr2.push_Back(p1);
	arr2.push_Back(p2);
	arr2.push_Back(p3);
	arr2.push_Back(p4);
	arr2.push_Back(p5);
	arr2.push_Back(p6);
	arr2.push_Back(p7);

	printPersonArray(arr2);
}


int main()
{
	test01();
	test02();
}
