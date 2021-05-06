#include<iostream>
using namespace std;
#include<string>

//���Ͳ�����  ���ͱ�� �������� ģ�弼��
template<class T>//���߱�����  �����ų��ֵ�T��Ҫ����T��һ��ͨ�õ�����
void mySwap(T& a , T& b)
{
	T temp;
	temp = a;
	a = b;
	b = temp;
}

//��һ�ξͲ��ǽ������ˣ��ᱨ��������ʹ�ò����������͡�����δ�����ʶ��"T"��
//��Ҫ���á�template<class T>����ָ��
//void mySwap3(T& a, T& b)
//{
//	T temp;
//}

// template<typename T> �ȼ��� template<class T>
template<typename T>
void mySwap2() {}//������������ʵ��


void test01()
{
	int a = 10;
	int b = 20;
	char c1 = 'c';
	//1���Զ������Ƶ�������Ҫ�����Ͳ����Ƶ�
	//mySwap(a, c1);//��ʱ�����˶����ԣ�Ҳ�Ƶ�������
	mySwap(a,b);
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	//2����ʽ��ָ������
	mySwap<int>(a,b);
	//������ʵ�ֵĺ���ģ�壬�Զ������Ƶ����ûᱨ��
	//mySwap2();
	//�����һ��ͨ������T����������֪��Ӧ�÷�������ڴ�ռ�
	//ʹ����ʽ��ָ���ͱ���������
	mySwap2<double>();
}

////////////////����ģ�����ͨ���������𣬼����ù���////////////

//1����ͨ�����ͺ���ģ�������
template<class T>
T myPlus(T a, T b)
{
	return a + b;
}

int myPlus2(int a, int b)
{
	return a + b;
}

void test02()
{
	int a = 10;
	int b = 20;
	char c = 'c';//ASCI�� a = 97
//	myPlus(a, c);//�����Ƶ�������������ģ�岻�ܽ�����ʽ����ת��
	cout << myPlus2(a, c) << endl;//10+99 ��ͨ����������ʽ����ת��

}

//��ͨ�����ͺ���ģ��ĵ��ù���
template<class T>
void myPrint(T a, T b)
{
	cout << "template" << endl;
}
template<class T>
void myPrint(T a, T b, T c)
{
	cout << "template(abc)" << endl;
}

void myPrint(int a, int b)
{
	cout << "normal" << endl;
}

void test03()
{
	int a = 1;
	int b = 2;

	//1 �����������(��ͨ��ģ����ȿ��Կ����ǲ������Ͳ�ͬ(�������))������ʹ����ͨ�����������ͨ����û��ʵ�֣�����ִ����޷��������ⲿ���
	myPrint(a, b);

	//2 ��ǿ�Ƶ��ú���ģ�壬����ʹ�ÿղ����б�
	myPrint<>(a,b);

	//3 ����ģ����Է�������
	int c = 3;
	myPrint(a, b, c);

	//4 �������ģ����Բ������õ�ƥ�䣬����ģ��
	char c1 = 'c';
	char d1 = 'd';
	myPrint(c1, d1);//��ʱ���õ�ģ�壬����������ͨ�ģ�����Ҫ������ʽ����ת��
}

////////////////////////����ģ��ľ�����//////////////////////
///////////���ܽ���������ͣ�����ֲ��ܽ�������ͣ��Ը����ͽ��о��廯/////////

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

template<class T>
bool myCompare(T& a, T& b)
{
	if (a == b)
	{
		return true;
	}
	return false;
}

//һ����˵����������person�͡�myCompare(p1, p2);����ģ����ʶ���Ǵ���������person���ͣ���ʵ���ڲ����ܴ���
//����ͨ�����廯�Զ����������ͣ������������
//�﷨ template<> ����ֵ ������<��������>(�������� ������)
template<> bool myCompare<Person>(Person& a, Person& b)
{
	if (a.m_Age == b.m_Age)
	{
		return true;
	}
	return false;
}

void test04()
{
	Person p1("ABC", 30);
	Person p2("DEF", 45);

	int ret = myCompare(p1, p2);
	cout << "ret = " << ret << endl;
}


int main()
{
//	test01();
//	test02();
	test03();
	test04();
}
