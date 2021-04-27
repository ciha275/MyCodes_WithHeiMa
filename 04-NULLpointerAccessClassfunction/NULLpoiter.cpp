#include<iostream>
using namespace std;
class Person
{
public:
	void show()
	{
		cout << "无变量，只是打印" << endl;
	}
	//void showAge()//因为showAge()中有用this，当用空指针时，this=NULL，则是输出NULL->m_age，报错
	//{
	//	cout << "打印变量 age = " << this->m_age << endl;
	//}

	//改良showAge
	void showAge() 
	{
		if (this == NULL)
		{
			return;
		}
		cout << "打印变量 age = " << this->m_age << endl;
	}

private:
	int m_age = 21;
};

void test01()
{
	Person* p = NULL;//设定一个空指针
	p->show();
	p->showAge();//此调用将会导致错误,showAge改良后可用，但自然无输出
}


//常对象与常函数

//常对象：实例对象时，前加const，“const Person p1”
//			则p1的各属性都不能修改了
//常函数：成员函数声明时，后加const，“void showAge() const”
//			则showAge()这个函数中不能去修改属性了

//常对象不能调用普通函数（因普通函数是可能去修改属性的）
//常对象能调用常函数

int main()
{
	test01();
}