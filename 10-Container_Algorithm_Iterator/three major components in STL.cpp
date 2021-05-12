#include<iostream>
#include<string>
using namespace std;
//使用容器vector的头文件
#include<vector>
//使用系统算法的头文件
#include<algorithm>

//迭代器，可以起遍历功能，可以指向容器中的元素   用指针理解
//普通指针也是一种迭代器
void test01()
{
	int array[] = {1, 4, 5, 2, 6, 8};

	int* p = array;//指针p指向数组首地址  &array[0]
	
	//遍历数组元素
	for (int i = 0; i < (sizeof(array) / sizeof(int)); i++)
	{
		cout << array[i] << " ";
		cout << *(p++/* p+i 也行 */) << " ";
	}
}

/********************************************************************/
//容器初识
void MyPrint(int a)
{
	cout << a << " ";
}
void test02()
{
	//声明一个vector容器，在容器中存放int类型数据，对象名 v
	vector<int> v; //像模板的使用，在<>中声明类型

	//向容器中添加数据
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);

	//遍历 1
	//利用迭代器遍历容器中的数据 "vector<int>::iterator itBegin"声明一个迭代器对象itBegin
	vector<int>::iterator itBegin = v.begin(); //让迭代器itBegin指向v容器的起始位置
	vector<int>::iterator itEnd = v.end(); //itEnd指向容器最后一个数据的下一个地址
	while (itBegin != itEnd)
	{
		cout << *itBegin << " ";
		itBegin++;
	}
	cout << endl;

	//遍历 2
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	//遍历 3
	//利用系统算法 for_each(参数一 开头， 参数二 结尾， 参数三 回调函数)
	//for_each具体功能可查看定义，回调函数，将会对开头到结尾之间的每个元素调用回调函数
	for_each(v.begin(), v.end(), MyPrint);
	cout << endl;
}

/********************************************************************/
//操作自定义数据类型					/*不管什么类型，关键搞清楚迭代器加个*是指向的什么，就是容器存放的元素，容器声明时<>里的内容*/
class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

	string m_Name;
	int m_Age;
};

void test03()
{
	Person p1("张三", 18);
	Person p2("李四", 28);
	Person p3("王五", 38);
	Person p4("宋六", 48);

	vector<Person> v;
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);

	//遍历
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "name: " << (*it).m_Name << " age: " << (*it).m_Age << endl;
	}
}

//存放自定义类型的指针
void test04()
{
	Person p1("张三", 18);
	Person p2("李四", 28);
	Person p3("王五", 38);
	Person p4("宋六", 48);

	vector<Person*> v;	//存放的是Person*
	v.push_back(&p1);	//存放时就应是地址 &p1
	v.push_back(&p2);
	v.push_back(&p3);
	v.push_back(&p4);

	//遍历     存放的是指针，*it 是指针，通过 "->" 访问
	for (vector<Person*>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "name: " << (*it)->m_Name << " age: " << (*it)->m_Age << endl;
	}
}

/********************************************************************/
//容器嵌套
//一个大容器v ，存放 3 个小容器 v1,v2,v3 ，
//每个小容器放5个int数，最后通过大容器遍历输出
void test05()
{
	vector<vector<int>> v;
	vector<int> v1;
	vector<int> v2;
	vector<int> v3;

	for (int i = 0; i < 5; i++)
	{
		v1.push_back(i);
		v2.push_back(i+10);
		v3.push_back(i+100);
	}
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);

	for (vector<vector<int>>::iterator IT = v.begin(); IT != v.end(); IT++)
	{
		for (vector<int>::iterator it = (*IT).begin(); it != (*IT).end(); it++)
		{
			cout << (*it) << " ";
		}
		cout << endl;//每输出完一个小容器换行一次
	}

}


int main()
{
	//test01();
	//test02();
	//test03();
	//test04();
	test05();
}

