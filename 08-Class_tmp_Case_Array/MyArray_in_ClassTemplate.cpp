#include<iostream>
using namespace std;
#include"MyArray.hpp"
#include<string>

//���int��������ķ���
void printIntArray(MyArray<int>& arr)
{
	for (int i = 0; i < arr.getSize(); i++)
	{
		cout << arr[i] << endl;
	}
}


void test01()
{
	MyArray<int> arr1(10);//����TΪint���͵ģ�����10��int ����
	for (int i = 0; i < 10; i++)
	{
		arr1.push_Back(i + 100);
	}
	printIntArray(arr1);
}

class Person
{
public:
	//����һ�� �� ���͵�����ʱ��һ�������������Ĭ�Ϲ���
	Person() 
	{
		cout << "����Ĭ��" << endl;
		this->m_Age = 0;
		this->m_Name = "nothing";
	}
	Person(string name, int age)
	{
		cout << "�вι���" << endl;
		this->m_Name = name;
		this->m_Age = age;
	}

	string m_Name;
	int m_Age;
};

//���Person��������
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
	//�ڿ���̨���ڿ��Կ������⿪��Person�������飬10��Ԫ�ؿռ䣬����10�Ρ�����Ĭ�ϡ�
	
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
