#include<iostream>
using namespace std;

class Person
{
public:
	Person(int a)
	{
		cout << "Person的构造" << endl;
		this->m_Age = a;
	}
	void showAge()
	{
		cout << "年龄是： " << this->m_Age << endl;
	}
	~Person()
	{
		cout << "Person的析构" << endl;
	}

private:
	int m_Age;

};

//智能指针
//为了避免在堆区创建后忘记释放的问题，创建一个智能指针类
//智能指针的构造调用后就会在堆区创建对象，析构调用也会运用delete释放堆区
class SmartPointer
{
public:
	//智能指针的构造，将一个创建在堆区的对象的指针传给私有指针进行维护
	SmartPointer(Person* person)
	{
		cout << "smart的构造" << endl;
		this->person = person;
	}
	//智能指针的析构，释放堆区的对象
	~SmartPointer()
	{
		cout << "smart的析构" << endl;
		if (this->person != NULL)//如果指针有指向对象，将会释放
		{
			delete this->person;
			this->person = NULL;//避免野指针，让释放后，指针指向空
		}
	}

	//->运算符重载，期望的效果：sp->对象属性 = p->对象属性，p是对象的指针
	//故，应该返回person*指针，不需要参数
	Person* operator->()
	{
		return this->person;
	}
	//*运算符重载，期望的效果：*sp.对象属性 = *p.对象属性，p是对象的指针
	//故，应该返回person对象本体，不需要参数，注意是返回引用，不然就是值传递了
	Person& operator*()
	{
		return *this->person;
	}

private:
	Person* person;//成员属性，维护一个私有指针指向对象
};


void test01()
{
	////在栈区开辟，将会自动析构
	//Person p1(10);
	//p1.showAge();
	////在堆区开辟（new 一个），必须记得用delete来释放
	//Person* p2 = new Person(20);
	//p2->showAge();
	//delete p2;//忘记delete，不会释放,可见仅调用一个析构


	//这个智能指针的类，实际就是在栈区创建对象
	SmartPointer sp(new Person(21));//在堆区创建的对象的指针传给智能指针
	//指针运算符->和*，希望能直接对sp使用，故需要重载
	sp->showAge();//实际此处"sp->"这么个函数是返回的person* person这个指针，指针访问属性，应该是person->属性，所以实际应该是sp->->showAge()，但编译器优化了
	(*sp).showAge();

}
int main()
{
	test01();
}




