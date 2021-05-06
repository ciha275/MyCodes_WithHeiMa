#include<iostream>
using namespace std;
#include<string>

///////////////////////��ģ�壬��ʵ����template<class T>�����һ����/////////////
template<class NameType, class AgeType = int>//��ģ�������Ĭ�����ͣ�����ģ��û��
class Person
{
public:
	Person(NameType name, AgeType age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	void showPerson()
	{
		cout << "����: " << this->m_Age << " ����: " << this->m_Name << endl;
	}
	NameType m_Name;
	AgeType m_Age;
};

void test01()
{
	//�Զ������Ƶ� ��ģ�岻֧��
	//Person p("�����", 300);

	//ʹ����ʽָ��
	Person<string, int> p("�����", 300);
	p.showPerson();

}

////////////////////////////��Ա�����ĵ���ʱ��//////////////////////////////

class Person1
{
public:
	void showPerson1()
	{
		cout << "Person1�ĵ���" << endl;
	}
};
class Person2
{
public:
	void showPerson2()
	{
		cout << "Person2�ĵ���" << endl;
	}
};
template<class T>
class myClass
{
public:
	T obj;
	void func1()
	{
		obj.showPerson1();
	}
	void func2()
	{
		obj.showPerson2();
	}
};
//��ģ��ĳ�Ա����һ��ʼ���ᴴ����������ʱ��ȥ����
//�����Ǵ����ˣ���ôshowPerson1()��showPerson2()����������Person1��Person2�ģ�
//obj�������Ҫô��Person1��ҪôPerson2��Ҫô�����ǣ�
//��func1��func2����һ���򶼱�����δ�����ɼ��ʼ��û��ȷ��

void test02()
{
	myClass<Person1> m;
	m.func1();
	//m.func2();//��ʱ����func2()��Ҳ��ȥ����showPerson2()������ʱ��Person1��û��showPerson2()�����Ա�����޷��������������
}


/////////////////////////////��ģ������������//////////////////////////
/////////���������Person��ģ��

//1 ָ����������
void doWork(Person<string, int>& p)
{
	p.showPerson();
}

void test031()
{
	Person<string, int> p("A", 10);
	doWork(p);
}

//2 ����ģ�廯
template<class T1, class T2>
void doWork2(Person<T1, T2>& p)
{
	//��β鿴����
	cout << typeid(T1).name() << endl;
	cout << typeid(T2).name() << endl;

	p.showPerson();
}

void test032()
{
	Person<string, int> p("B", 20);
	doWork2(p);
}

//3 ����ģ�廯
template<class T>
void doWork3(T& p)
{
	cout << typeid(T).name() << endl;

	p.showPerson();
}
void test033()
{
	Person<string, int> p("C", 30);
	doWork3(p);
}


////////////////////////////��ģ���еļ̳м�������///////////////////////////
////////////////������ģ���࣬����̳�ʱ������߻�����T������//////////////////

template<class T>
class Base
{
public:
	T m_A;
};
//ֱ�Ӽ̳� class Child :: public Base ����
//�ڹ���ChildʱҲ�����Base�Ĺ��죬���ܻ��m_A��ֵ�����漰�����ڴ�
//����ʱ��m_A�����ͻ���T��δ֪����˱���������̳�ʱ����Base��T������
class Child1 : public Base<int>
{
	
};

//child2Ҳ����ģ�壬�����Ϳ��Բ��ع̶�Base��T����
template<class T1, class T2>
class Child2 : public Base<T2>
{
public:
	Child2()
	{
		cout << typeid(T1).name() << endl;
		cout << typeid(T2).name() << endl;
	}

	T1 m_B;
};

void test04()
{
	Child2<int, double> child;
	//��Ӧ��֪��m_B��int  m_A��double
}

//////////////////////��ģ������ʵ�ֳ�Ա����////////////////////
template<class T1, class T2>
class Person4
{
public:
	Person4(T1 name, T2 age);
		/*{
			this->m_Name = name;
			this->m_Age = age;
		}*/
	void showPerson();
	/*{
		cout << "name: " << this->m_Name << " age: " << this->m_Age << endl;
	}*/
	T1 m_Name;
	T2 m_Age;
};
//����ʵ�ֳ�Ա������
//��ģ��Person4::Person4(T1 name, T2 age)
//ģ��Person4<T1, T2>::Person4(T1 name, T2 age)
template<class T1, class T2>
Person4<T1, T2>::Person4(T1 name, T2 age)
{
	this->m_Name = name;
	this->m_Age = age;
}
template<class T1, class T2>
void Person4<T1, T2>::showPerson()
{
	cout << "name: " << this->m_Name << " age: " << this->m_Age << endl;
}

void test05()
{
	Person4<string, int> p4("Mt", 156);
	p4.showPerson();
}

//////////////////////////////////////��Ԫ��������ģ��//////////////////////////////////////

//����ʵ�ֵ�printPerson2����������Person5������У�������������
//�ñ�������ǰ����printPerson2����������printPerson2�������漰Person5�����
//�ñ���������Person5������
template<class T1, class T2> class Person5;
template<class T1, class T2> void printPerson2(Person5<T1, T2>& p);

template<class T1, class T2>
class Person5
{
	//��Ԫ��������ʵ�֣�������ʵ�ֶ�д�����ˣ���ʵ���൱�ڳ�Ա����
	friend void printPerson1(Person5<T1, T2>& p)
	{
		cout << "name: " << p.m_Name << " age: " << p.m_Age << endl;
	}
	//��Ԫ��������ʵ�֣�
	//һ���������friend void printPerson1(Person5<T1, T2>& p);��������ͨ����������
	//���ÿղ����б�<>���߱�������ģ�庯��������
	friend void printPerson2<>(Person5<T1, T2>& p);

public:
	Person5(T1 name, T2 age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	
private:
	T1 m_Name;
	T2 m_Age;
};

//����ʵ�֣��ɼ���ʱ����һ��ģ�庯��
template<class T1, class T2>
void printPerson2(Person5<T1, T2>& p)
{
	cout << "name: " << p.m_Name << " age: " << p.m_Age << endl;
}

void test06()
{
	Person5<string, int> p("TOM", 10);
	printPerson1(p);//��Ȼ˵���൱�ڳ�Ա�����������ֵ��÷�ʽ���ɼ�����һ��ȫ�ֺ���

	printPerson2(p);
}



int main()
{
	//test01();
	//test02();

	//test031();
	//test032();
	//test033();

	//test04();

	//test05();
	test06();

}