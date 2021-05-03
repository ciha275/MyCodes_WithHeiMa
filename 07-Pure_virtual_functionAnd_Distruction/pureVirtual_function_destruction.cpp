#include<iostream>
using namespace std;
#include<string>
#pragma warning(disable: 4996)

/*********************���麯��**********************/
class Calculator
{
public:
	//�麯�� virtual int getResult(){return 0}
	virtual int getResult() = 0;//���麯��
	//�����������˴��麯��������̳и���󣬱��� �����д��麯��ʵ��
	//����������˴��麯������������ֳ�Ϊ�������࣬��������޷�ʵ��������

	int val1;
	int val2;
};

//�ӷ�������
class PlusCalculator : public Calculator
{
public:
	//�Դ��麯����ʵ��
	//�����������˴��麯��������̳и���󣬱��� �����д��麯��ʵ��
	//���˶�ʵ��ע�ͺ󽫻ᱨ��
	virtual int getResult()
	{
		return val1 + val2;
	}
};

//�����и�����ԭ�򣺶���չ���ţ����޸Ĺر�
//�����麯��/���麯������̬�����ܷ������չ
//�����ʱ��Ҫ�Ӹ����������ϴ�������ظ���
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
	//ʹ�üӷ�
	abc = new PlusCalculator;
	abc->val1 = 10;
	abc->val2 = 20;

	cout << abc->getResult() << endl;

	delete abc;
	//ʹ�ü���
	abc = new SubCalculator;
	abc->val1 = 10;
	abc->val2 = 20;

	cout << abc->getResult() << endl;

	delete abc;
}

/*********************������&��������**********************/
class Animal
{
public:
	virtual void speak()
	{
		cout << "������˵��" << endl;
	}

	//��ͨ��������������������������ܵ����ͷŲ��ɾ�
	//�������������
	/*virtual	~Animal()
	{
		cout << "��������" << endl;
	}*/
	//��������
	virtual ~Animal() = 0;
	//����������Ҫ����Ҳ��Ҫʵ�֣���������������ʵ��
};
Animal::~Animal()
{
	cout << "����Ĵ�������" << endl;
}
//���������˴�����������Ҳ���ڳ����࣬����ʵ����
//void func()
//{
//	Animal aa;//����
//}


class Cat : public Animal
{
public:
	Cat(const char* str)//�вι��츳����
	{
		this->m_Name = new char[strlen(str) + 1];
		strcpy(this->m_Name, str);
	}

	virtual void speak()//�Ը����麯������д
	{
		cout << "è��˵��" << endl;
	}

	~Cat()
	{
		cout << "è������" << endl;
		//��Ϊ�и����֣������˶���������ʱӦ�����ͷţ�delete
		if (this->m_Name != NULL)
		{
			delete[] this->m_Name;
			this->m_Name = NULL;
		}
	}

	char* m_Name;//��Cat�������������
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

