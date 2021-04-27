#include<iostream>
using namespace std;

class Animal
{
public:
	Animal() {};
	Animal(int a) {};

	virtual void speak()//当加了virtual关键字后，Animal的内部会发生改变，见GitHub笔记
	{
		cout << "动物在说话" << endl;
	}
};

class Cat : public Animal
{
public:
	Cat() 
	{
		cout << "moren of cat" << endl;
	}
	Cat(int a)
	{
		cout << "youcan of cat" << endl;
	}
	//当子类Cat写了父类的同名函数，将会覆盖虚函数表中的函数，即 &Animal::speak 被覆盖为 &Cat::speak，这种写法叫重写
	//重写，必须 返回值、参数个数、类型、顺序 都相同
	void speak()
	{
		cout << "猫在说话" << endl;
	}
};

//在调用doSpeak时，在编译阶段就会寻找参数类型，如此处，发现是Animal类型，然后就绑定了
//这种就是静态联编，编译阶段就定好了地址
//希望调用的是cat的speak，就不能以前绑定好函数的地址，需要在运行是再去确定函数地址
//这种就是动态联编，方法，父类中使用虚函数，关键字virtual，这样就发生了多态
//        “多态：父类的引用或指针，指向子类对象”
//PS：对于多态，静态多态通常是函数重载，编译阶段确定地址；动态多态，需要虚函数，继承关系，运行中确定地址
void doSpeak(Animal& animal)
{
	animal.speak();
}

void test01()
{
	Cat cat;
	doSpeak(cat);//如此编写不报错，是因为有继承关系，编译器允许类型转换
	//多态后，“父类的引用或指针，指向子类对象”，在此处，doSpeak本来是调用Animal类，此处写cat，即是Animal& animal = cat，引用指向了子类对象
}

void test02()
{
	cout << sizeof(Animal) << endl;
	//回顾，类的对象模型，本来函数不属于对象，则sizeof（Animal）= 1，
	//加了virtual后发生了改变，此时sizeof(Animal)=4

	//虚函数表的内部工作原理，调用函数（具体原理步骤见GitHub）
	Animal* animal = new Cat;
	animal->speak();//↓两句等价
	((void(*)()) (*((int*)*(int*)animal)))();
}


int main()
{
	test01();
	test02();
}
