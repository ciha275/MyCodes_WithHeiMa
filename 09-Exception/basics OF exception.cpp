#include<iostream>
using namespace std;

//���쳣�Ļ�������
//ͨ��throw�ڳ����쳣��������׳��쳣
//��try���Կ��ܳ����쳣�Ĵ���Σ������ŵ�catch����throw�׳����쳣

class MyException//�Զ����쳣��
{
public:
	void printError()
	{
		cout << "�Զ��������쳣" << endl;
	}
};

//�������������ܾ��ǳ�0�쳣
int MyDivide(int a, int b)
{
	if (b == 0)//����Ϊ0��������0�쳣
	{
		//�׳��쳣�����˻������ͣ�Ҳ���׳��Զ������͵��쳣
		//throw 1;//�׳�int���쳣
		//throw 3.14;//�׳�double���쳣
		//throw 'c';//�׳�char���쳣

		//���˻������ͣ�Ҳ���׳��Զ������͵��쳣
		throw MyException();// �� ����() ���������������д��
	}
	return a / b;//��������ͷ��س������
}
void test01()
{
	int a = 10;
	int b = 0;
	try//�����ܳ�������ĺ���������try{}ģ����
	{
		MyDivide(a, b);
	}

	//����throw 1����throw 3.14�� ... ���׳�����ʱ�����Է��֣���catch��һ�����ͺ�������catch�Ͳ�����

	catch (int)//��catch()�����׳����쳣���ͣ��˴���Ϊint��
	{
		//catch(){}��{}�ھ��ǶԴ������쳣�Ĵ���
		cout << "int���쳣" << endl;
	}
	catch (double)
	{
		cout << "double���쳣" << endl;
	}
	catch (MyException e)//������ʵ��һ��ֵ���ݣ����׳����������󴫸������ﴴ����e
	{
		e.printError();
	}
	catch (...)//...��ʾ�������������쳣
	{
		cout << "�������쳣" << endl;
	}
}


int main()
{
	test01();
}