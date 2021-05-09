#include<iostream>
#include<string>
using namespace std;
//����ϵͳ�ṩ�ı�׼�쳣������ͷ�ļ� <stdexcept>
#include<stdexcept>

/**********************************�쳣���ö�̬����************************************/
//����˼·����һ���쳣���࣬���ͬ���쳣���ͼ̳���������Ϊ����������
//�쳣����
class BaseException
{
public:
	virtual void printError()
	{}
};

class NullPointerException : public BaseException
{
public:
	virtual void printError()
	{
		cout << "��ָ���쳣" << endl;
	}
};

class OutofRangeException : public BaseException
{
public:
	virtual void printError()
	{
		cout << "Խ���쳣" << endl;
	}
};

void doWork()
{
	//���յ��쳣���ͣ���ȡ�����׳����쳣����

	//throw NullPointerException();
	
	throw OutofRangeException();
}

void test01()
{
	try
	{
		doWork();
	}
	catch (BaseException& e)//�ں������׳����������������󣬴˴�������࣬����������ָ����������󣬷����˶�̬
	{
		e.printError();
	}
}

/**********************************����ϵͳ�ı�׼�쳣����************************************/
//ϵͳ��ʵҲ���и������쳣�����������ϵͳ��׼�쳣ͷ�ļ�<stdexcept>
class MyOutofRangeException : public exception	//exceptionϵͳ��׼�쳣�Ļ��࣬���Ҽ��鿴���룬��ȷ��Ҫ�Լ���������Ҫд��Щ��������Щ�� virtual �Ķ�̬������Ҫʵ�֣�
{
public:
	MyOutofRangeException(string errInfo)//�вι��죬�������������Ϣ
	{
		this->m_errInfo = errInfo;
	}

	//�̳�exception������Ҫд������
	//����
	virtual ~MyOutofRangeException()
	{

	}
	virtual const char* what() const	//��const��ʾ��������ǰconst�����ص���const char*����
	{
		//���ش�����Ϣ�����ڲ�ά����string������ֵ char*
		//string ת char*    .c_str()
		return this->m_errInfo.c_str();
	}

	string m_errInfo;//�ڲ�ά��������Ϣ
};


class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;

		//�����������
		if (age < 0 || age > 100)
		{
			//out_of_range����ϵͳ��һ����׼�쳣
			//throw out_of_range("����Խ��");
			
			//�����Լ���д���쳣������
			throw MyOutofRangeException("���Լ���Խ���쳣");
		}
	}

	string m_Name;
	int m_Age;
};

void test02()
{
	try
	{
		Person p1("mingzi", 120);
	}
	catch (MyOutofRangeException& e)
	{
		cout << e.what() << endl;
	}
}

int main()
{
	test01();
	test02();
}