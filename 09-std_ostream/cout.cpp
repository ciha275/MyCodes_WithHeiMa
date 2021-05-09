#include<iostream>
#include<iomanip>	//ʹ�ÿ��Ʒ���ͷ�ļ�
using namespace std;

/*
* cout.put()	�򻺳���д�ַ�
* cout.write()	�ӻ�����дn���ַ�����ǰ�������
*/
//ʵ��һ���ֱ����cout << �������������
void test01()
{
	//cout.put()	�򻺳���д�ַ���Ȼ����ʾ��Ӧ����
	cout.put('10').put('\n').put('b');
	cout.put('\n');

	//cout.write()	�ӻ�����дn���ַ�����ǰ�������
	char buf[1024] = "zheshiyichuan zifu";
	cout.write( buf, (sizeof(buf) / sizeof(char)) );
	cout << endl;
}

/****************************���������ʽ******************************/
void test02()
{
	//ͨ������Ա��������ʽ�����
	int number = 99;

	cout.width(20);				//���20
	cout.fill('*');				//��ָ���������ո�
	cout.setf(ios::left);		//���ø�ʽ���������������
	cout.unsetf(ios::dec);		//ж��ʮ����
	cout.setf(ios::hex);		//��װʮ������
	cout.setf(ios::showbase);	//ǿ����ʾ��������Ļ��� 0 0x
	cout.unsetf(ios::hex);		//ж��ʮ������
	cout.setf(ios::oct);		//��װ�˽���
	cout << number << endl;
}

void test03()
{
	//���ÿ��Ʒ���ʽ ��ʽ�����
	int number = 99;

	cout << setw(10)
		<< setfill('*')
		<< setiosflags(ios::showbase)	//��ʾ����
		<< setiosflags(ios::left)		//�����
		<< hex							//����ʮ������
		<< number
		<< endl;
}



/****************************���������ʽ******************************/

int main()
{
	test01();
	test02();
	test03();
}
