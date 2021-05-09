#include<iostream>
using namespace std;

/*
* cin.get()			һ��ֻ�ܶ�һ���ַ�
* cin.get(��������)	���Զ��ַ��������Ļ������ڻ�����
* cin.getline()		���ַ��������Ļ����õ�������
* cin.ignore(N)		����N���ַ�
* cin.peek()		��һ���ַ�������
* cin.putback()		�Ż�һ���ַ�
*/

//cin.get()			һ��ֻ�ܶ�һ���ַ�
void test01()
{
	//����as  ������ a s ����  

	char c = cin.get();//�� a
	cout << "c= " << c << endl;
	c = cin.get();//�� s
	cout << "c= " << c << endl;
	c = cin.get();//�� ����
	cout << "c= " << c << endl;

	c = cin.get();//֮ǰ�����as����ػ��У��Ѿ������ˣ��ȴ�������
	cout << "c= " << c << endl;
}

//cin.get(��������)	���Զ��ַ��������Ļ������ڻ�����
void test02()
{
	char buf[1024];
	cin.get(buf, 1024);

	char c = cin.get();
	
	if (c == '\n')
	{
		cout << "˵�����л��ڻ���������c = cin.get()����" << endl;
	}
	else
	{
		cout << "˵�����в��ڻ�����" << endl;
	}

	cout << buf << endl;
}

//cin.getline()		���ַ��������Ļ����õ�������
void test03()
{
	char buf[1024];
	cin.getline(buf, 1024);

	char c = cin.get();//��ʱgetline��������ȡ�ˣ���c = cin.get()ɶҲ�ղ������ڵȴ�����

	if (c == '\n')
	{
		cout << "˵�����л��ڻ���������c = cin.get()����" << endl;
	}
	else
	{
		cout << "˵�����в��ڻ�����" << endl;
	}

	cout << buf << endl;
}

//cin.ignore(N)		����N���ַ�
void test04()
{
	//����abcd����c = d
	cin.ignore(3);
	char c = cin.get();
	cout << c << endl;
}

//cin.peek()		��һ���ַ�������
void test05()
{
	//����as peekֻ������
	char c = cin.peek();
	cout << c << endl;
	//�����Եڶ�������a
	c = cin.get();
	cout << c << endl;
}

//cin.putback(�ַ�a)		�Ż�һ���ַ�a��ֻ���ַ�
void test06()
{
	char c = cin.get();
	cin.putback(c);
	char c1 = cin.get();
	char buf[1024];
	cin.getline(buf, 1024);
	cout << "c = " << c << endl;
	cout << "c1 = " << c1 << endl;
	cout << "buf = " << buf << endl;
}

//����1 �ж��û�����������or�ַ�����Ĭ�ϴ�����or���ַ�����
void test07()
{
	cout << "����������or�ַ���" << endl;
	//��ϣ���鿴��һ���ַ�����ϣ����Ӱ�컺�������ݣ�ѡ��peek
	//Ҳ�� ��cin.get()��ȡһ������putback()�Żأ������鷳
	char a = cin.peek();
	if (a >= '0' && a <= '9')
	{
		int num;
		cin >> num;
		cout << "that is number: " << num << endl;
	}
	else
	{
		char buf[1024];
		cin.getline(buf, 1024);
		cout << "that is string: " << buf << endl;
	}
}

//����2 �û�����0~9���֣���ȷ����ʾ��������������
void test08()
{
	cout << "please input a number within 0 and 9" << endl;
	int num;

	while (true)//ʹ��true��֤һֱѭ����ֻ��ʹ�õ�break�����˳�
	{
		cin >> num;
		if (num >= 0 && num <= 9)
		{
			cout << "your number is: " << num << endl;
			break;
		}
		cout << "please input again" << endl;
		//��Ϊ�ڻ�������ʵ�б�־λ��0������1������
		//num������int����������ʱ������char���ͣ����ı��־λ������ѭ������
		/*�ƺ�VS2019�Զ��Ż�������char���ͺ�û������ѭ����ֱ�ӵ�0*/
		//cout << cin.fail() << endl;//��cin.fail()�鿴��־λ
		//cin.clear();//���ñ�־λ
		//cout << cin.fail() << endl;//��cin.fail()�鿴��־λ
		//cin.sync();//��ջ�����
		//cout << cin.fail() << endl;//��cin.fail()�鿴��־λ
	}
}

int main()
{
	//test01();
	//test02();
	//test03();
	//test04();
	//test05();
	//test06();
	//test07();
	test08();

}
