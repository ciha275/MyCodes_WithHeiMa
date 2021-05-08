#include<iostream>
using namespace std;


//��̬����ת�� static_cast   
//�÷���static_cast<Ŀ������>(ԭʼ����)
//֧�ֻ�������֮���ת����֧�ֻ������������ת��
class Base1 {};
class Child1 : public Base1 {};
class Other {};
void test01()
{
	//��������
	double a = 1.23;
	int b = static_cast<int>(a);//doubleתint�����ȶ�ʧ������ȫ������̬ת��Ҳ��ת
	char c = 'a';
	int d = static_cast<int>(c);//�ַ� a ��ASCI��ֵΪ 97
	cout << "b = " << b << endl;
	cout << "d = " << d << endl;

	//������֮��
	Base1* base1 = NULL;
	Child1* child1 = NULL;
	//��ת�� ����ת��  ����ȫ������̬ת����ת
	Child1* child = static_cast<Child1*>(base1);
	//��ת�� ����ת��  ��ȫ
	Base1* base = static_cast<Base1*>(child1);
	//�޼̳й�ϵ���࣬����ת
	//Other* other = static_cast<Other*>(b1);��������ת����Ч��
}

//��̬����ת�� dynamic_cast   
//�÷���dynamic_cast<Ŀ������>(ԭʼ����)
//�ǳ��ϸ񣬲�֧�ֻ�������ת������֧�ֻ�����������֮�䲻��ȫ��ת��(��ת�� ����ת��)
//��������̬ʱ�����Ի�����������ת�����ڶ�̬ʱ������ָ�������ָ�����������ʵ��ʱ�򿪱ٵĿռ��������Ĵ�С�����Դ�ʱ��ת����ʵ��û�г�����Χ���ʶ��ǰ�ȫ�ģ�
class Base2 
{
	virtual void func() {}
};
class Child2 : public Base2
{
	virtual void func() {}
};
void test02()
{
	//�������� �����ܶ�̬ת��
	//double a = 1.23;
	//int b = dynamic_cast<int>(a);//doubleתint�����ȶ�ʧ������ȫ�����ܶ�̬ת��
	//int a = 10;
	//double b = dynamic_cast<double>(a);//intתdouble��������Ϊ��ȫ����Ҳ���ܶ�̬ת��
	
	//������֮�䣬�޶�̬ʱ
	Base2* base2 = NULL;
	Child2* child2 = NULL;
	//��ת�� ����ת��  ����ȫ����̬ת����֧��
	//Child2* child = dynamic_cast<Child2*>(base2);
	//��ת�� ����ת��  ��ȫ����̬ת��֧��
	Base2* base = dynamic_cast<Base2*>(child2);

	//�����࣬������̬ʱ����ת�ӣ����¶�̬ת��������
	Base2* vbase2 = new Child2;
	Child2* child = dynamic_cast<Child2*>(vbase2);
}

//����ת����const_cast��ֻ�ܵ��������޶��������ܸ��Ļ�������
//ֻ�ܶ�ָ�������ʹ�ã�const��תΪûconst��ûconst��תΪconst
void test03()
{
	// ָ��
	//1��constת��const
	const int* p = NULL;
	//double* newp = const_cast<double*>(p);//����ֻ�ܵ��������޶��������ܸ��Ļ������͡�
	int* newp = const_cast<int*>(p);
	//2����constתconst
	int* p2 = NULL;
	const int* newp2 = const_cast<const int*>(p2);
	// ����
	int num = 10;
	int& numRef = num;
	const int& numRef2 = const_cast<const int&>(numRef);

	//���ܶԷ�ָ��or�����õı��� ʹ��
	//const int a = 10;
	//int b = const_cast<int>(a);
}

//���½���ת����reinterpert_cast�����ȫ����������
void test04()
{
	//int ��ת int*
	int a = 10;
	int* p = reinterpret_cast<int*>(a);
	//����ص���Ҳ�ܻ�ת
	Base1* base = NULL;
	Other* other = reinterpret_cast<Other*>(base);
}

int main()
{
	//test01();
	test02();

}
