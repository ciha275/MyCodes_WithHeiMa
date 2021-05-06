#include<iostream>
using namespace std;
#include<string>
#pragma warning(disable: 4996)

/*********************纯虚函数**********************/
class Calculator
{
public:
	//虚函数 virtual int getResult(){return 0}
	virtual int getResult() = 0;//纯虚函数
	//当父类中有了纯虚函数，子类继承父类后，必须 对所有纯虚函数实现
	//如果父类有了纯虚函数，这个父类又称为，抽象类，这个父类无法实例化对象

	int val1;
	int val2;
};

//加法计算器
class PlusCalculator : public Calculator
{
public:
	//对纯虚函数的实现
	//当父类中有了纯虚函数，子类继承父类后，必须 对所有纯虚函数实现
	//将此段实现注释后将会报错
	virtual int getResult()
	{
		return val1 + val2;
	}
};

//开发有个开闭原则：对扩展开放，对修改关闭
//利用虚函数/纯虚函数，多态，就能方便的扩展
//例如此时需要加个减法，以上代码均不必更改
class SubCalculator : public Calculator
{
	virtual int getResult()
	{
		return val1 - val2;
	}
};

void test01()
{
	Calculator* abc;
	//使用加法
	abc = new PlusCalculator;
	abc->val1 = 10;
	abc->val2 = 20;

	cout << abc->getResult() << endl;

	delete abc;
	//使用减法
	abc = new SubCalculator;
	abc->val1 = 10;
	abc->val2 = 20;

	cout << abc->getResult() << endl;

	delete abc;
}

/*********************虚析构&纯虚析构**********************/
class Animal
{
public:
	virtual void speak()
	{
		cout << "动物在说话" << endl;
	}

	//普通析构，不会调用子类析构，可能导致释放不干净
	//利用虚析构解决
	/*virtual	~Animal()
	{
		cout << "动物析构" << endl;
	}*/
	//纯虚析构
	virtual ~Animal() = 0;
	//纯虚析构需要声明也需要实现，类内声明，类外实现
};
Animal::~Animal()
{
	cout << "动物的纯虚析构" << endl;
}
//如果类出现了纯虚析构，类也属于抽象类，不可实例化
//void func()
//{
//	Animal aa;//报错
//}


class Cat : public Animal
{
public:
	Cat(const char* str)//有参构造赋名字
	{
		this->m_Name = new char[strlen(str) + 1];
		strcpy(this->m_Name, str);
	}

	virtual void speak()//对父类虚函数的重写
	{
		cout << "猫在说话" << endl;
	}

	~Cat()
	{
		cout << "猫的析构" << endl;
		//因为有个名字，开辟了堆区，析构时应将其释放，delete
		if (this->m_Name != NULL)
		{
			delete[] this->m_Name;
			this->m_Name = NULL;
		}
	}

	char* m_Name;//在Cat这个子类多个名字
};

void test02()
{
	Animal* animal = new Cat("mao");
	animal->speak();

	delete animal;

}

int main()
{
	test01();
	test02();

}

