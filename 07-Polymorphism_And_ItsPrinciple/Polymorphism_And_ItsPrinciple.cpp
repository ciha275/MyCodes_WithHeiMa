#include<iostream>
using namespace std;

class Animal
{
public:
	Animal() {};
	Animal(int a) {};

	virtual void speak()//������virtual�ؼ��ֺ�Animal���ڲ��ᷢ���ı䣬��GitHub�ʼ�
	{
		cout << "������˵��" << endl;
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
	//������Catд�˸����ͬ�����������Ḳ���麯�����еĺ������� &Animal::speak ������Ϊ &Cat::speak������д������д
	//��д������ ����ֵ���������������͡�˳�� ����ͬ
	void speak()
	{
		cout << "è��˵��" << endl;
	}
};

//�ڵ���doSpeakʱ���ڱ���׶ξͻ�Ѱ�Ҳ������ͣ���˴���������Animal���ͣ�Ȼ��Ͱ���
//���־��Ǿ�̬���࣬����׶ξͶ����˵�ַ
//ϣ�����õ���cat��speak���Ͳ�����ǰ�󶨺ú����ĵ�ַ����Ҫ����������ȥȷ��������ַ
//���־��Ƕ�̬���࣬������������ʹ���麯�����ؼ���virtual�������ͷ����˶�̬
//        ����̬����������û�ָ�룬ָ���������
//PS�����ڶ�̬����̬��̬ͨ���Ǻ������أ�����׶�ȷ����ַ����̬��̬����Ҫ�麯�����̳й�ϵ��������ȷ����ַ
void doSpeak(Animal& animal)
{
	animal.speak();
}

void test01()
{
	Cat cat;
	doSpeak(cat);//��˱�д����������Ϊ�м̳й�ϵ����������������ת��
	//��̬�󣬡���������û�ָ�룬ָ��������󡱣��ڴ˴���doSpeak�����ǵ���Animal�࣬�˴�дcat������Animal& animal = cat������ָ�����������
}

void test02()
{
	cout << sizeof(Animal) << endl;
	//�عˣ���Ķ���ģ�ͣ��������������ڶ�����sizeof��Animal��= 1��
	//����virtual�����˸ı䣬��ʱsizeof(Animal)=4

	//�麯������ڲ�����ԭ�����ú���������ԭ�����GitHub��
	Animal* animal = new Cat;
	animal->speak();//������ȼ�
	((void(*)()) (*((int*)*(int*)animal)))();
}


int main()
{
	test01();
	test02();
}
