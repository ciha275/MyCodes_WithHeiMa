#include<iostream>
#include<string>
using namespace std;
//ʹ������vector��ͷ�ļ�
#include<vector>
//ʹ��ϵͳ�㷨��ͷ�ļ�
#include<algorithm>

//��������������������ܣ�����ָ�������е�Ԫ��   ��ָ�����
//��ָͨ��Ҳ��һ�ֵ�����
void test01()
{
	int array[] = {1, 4, 5, 2, 6, 8};

	int* p = array;//ָ��pָ�������׵�ַ  &array[0]
	
	//��������Ԫ��
	for (int i = 0; i < (sizeof(array) / sizeof(int)); i++)
	{
		cout << array[i] << " ";
		cout << *(p++/* p+i Ҳ�� */) << " ";
	}
}

/********************************************************************/
//������ʶ
void MyPrint(int a)
{
	cout << a << " ";
}
void test02()
{
	//����һ��vector�������������д��int�������ݣ������� v
	vector<int> v; //��ģ���ʹ�ã���<>����������

	//���������������
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);

	//���� 1
	//���õ��������������е����� "vector<int>::iterator itBegin"����һ������������itBegin
	vector<int>::iterator itBegin = v.begin(); //�õ�����itBeginָ��v��������ʼλ��
	vector<int>::iterator itEnd = v.end(); //itEndָ���������һ�����ݵ���һ����ַ
	while (itBegin != itEnd)
	{
		cout << *itBegin << " ";
		itBegin++;
	}
	cout << endl;

	//���� 2
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	//���� 3
	//����ϵͳ�㷨 for_each(����һ ��ͷ�� ������ ��β�� ������ �ص�����)
	//for_each���幦�ܿɲ鿴���壬�ص�����������Կ�ͷ����β֮���ÿ��Ԫ�ص��ûص�����
	for_each(v.begin(), v.end(), MyPrint);
	cout << endl;
}

/********************************************************************/
//�����Զ�����������					/*����ʲô���ͣ��ؼ�������������Ӹ�*��ָ���ʲô������������ŵ�Ԫ�أ���������ʱ<>�������*/
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
	Person p1("����", 18);
	Person p2("����", 28);
	Person p3("����", 38);
	Person p4("����", 48);

	vector<Person> v;
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);

	//����
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "name: " << (*it).m_Name << " age: " << (*it).m_Age << endl;
	}
}

//����Զ������͵�ָ��
void test04()
{
	Person p1("����", 18);
	Person p2("����", 28);
	Person p3("����", 38);
	Person p4("����", 48);

	vector<Person*> v;	//��ŵ���Person*
	v.push_back(&p1);	//���ʱ��Ӧ�ǵ�ַ &p1
	v.push_back(&p2);
	v.push_back(&p3);
	v.push_back(&p4);

	//����     ��ŵ���ָ�룬*it ��ָ�룬ͨ�� "->" ����
	for (vector<Person*>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "name: " << (*it)->m_Name << " age: " << (*it)->m_Age << endl;
	}
}

/********************************************************************/
//����Ƕ��
//һ��������v ����� 3 ��С���� v1,v2,v3 ��
//ÿ��С������5��int�������ͨ���������������
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
		cout << endl;//ÿ�����һ��С��������һ��
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

