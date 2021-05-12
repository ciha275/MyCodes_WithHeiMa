#include<iostream>
#include<vector>
#include<list>
using namespace std;

void test01()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
		cout << v.capacity() << endl;//���Կ���vector����������push_back��һ�������¶�̬����
	}
}


/*
3.2.4.1 vector���캯��
vector<T> v; //����ģ��ʵ����ʵ�֣�Ĭ�Ϲ��캯��
vector(v.begin(), v.end());//��v[begin(), end())�����е�Ԫ�ؿ���������
vector(n, elem);//���캯����n��elem����������
vector(const vector &vec);//�������캯����

3.2.4.2 vector���ø�ֵ����
assign(beg, end);//��[beg, end)�����е����ݿ�����ֵ������
assign(n, elem);//��n��elem������ֵ������
vector& operator=(const vector  &vec);//���صȺŲ�����
swap(vec);// ��vec�뱾���Ԫ�ػ�����

3.2.4.3 vector��С����
size();//����������Ԫ�صĸ���
empty();//�ж������Ƿ�Ϊ��
resize(int num);//����ָ�������ĳ���Ϊnum���������䳤������Ĭ��ֵ�����λ�á����������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ����
resize(int num, elem);//����ָ�������ĳ���Ϊnum���������䳤������elemֵ�����λ�á����������̣���ĩβ����������>�ȵ�Ԫ�ر�ɾ����
capacity();//����������
reserve(int len);//����Ԥ��len��Ԫ�س��ȣ�Ԥ��λ�ò���ʼ����Ԫ�ز��ɷ��ʡ�
*/
void printVector(vector<int> v)//дһ��ͨ�õ������ʾint��vector�ķ���
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";//��vector�ڵ�Ԫ��Ҫ�õ�����iterator������
	}
	cout << endl;
}

void test02()
{
	vector<int> v;//Ĭ�Ϲ���
	//vector(v.begin(), v.end());//��v[begin(), end())�����е�Ԫ�ؿ���������
	int arr[] = { 2,3,4,1,9 };
	vector<int> v1(arr, arr + sizeof(arr) / sizeof(int));
	vector<int> v2(v1.begin(), v1.end());
	printVector(v2);
	//vector(n, elem);//���캯����n��elem����������
	vector<int> v3(10, 100);
	printVector(v3);

	//��ֵʹ��
	vector<int> v4;
	v4.assign(v3.begin(), v3.end());
	printVector(v4);
	//swap(vec);// ��vec�뱾���Ԫ�ػ�����
	v4.swap(v2);
	cout << "swap���v4: " << endl;
	printVector(v4);
	cout << "v4��������С�� " << v4.size() << endl;

	//empty();//�ж������Ƿ�Ϊ��
	if (v4.empty())
	{
		cout << "v4Ϊ��" << endl;
	}
	else
	{
		cout << "v4��Ϊ��" << endl;
	}

	//resize(int num, elem);
	//����ָ�������ĳ���Ϊnum���������䳤������elemֵ�����λ�ã�Ĭ��Ϊ0�����������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ����
	//v4 Ŀǰ���� 23419
	v4.resize(10, -1);
	printVector(v4);
	v4.resize(3);
	printVector(v4);

}

//����swap�����ռ�
void test03()
{
	vector<int> v;
	for (int i = 0; i < 100000; i++)
	{
		v.push_back(i);
	}
	cout << "v�������� " << v.capacity() << endl;
	cout << "v�Ĵ�С�� " << v.size() << endl;

	v.resize(7);//��С���С���ˣ����������Ǻܴ�����˷�
	cout << "v�������� " << v.capacity() << endl;
	cout << "v�Ĵ�С�� " << v.size() << endl;
	//����swap�ͷſռ�
	vector<int>(v).swap(v);//��vector<int>(v)��ͨ��v��������һ���������󣬾͵���v�������Ǹ�����С���v������������������������Ŀռ��û�˷ѣ�������������v���������������ڸ��н������Զ��ͷ���
	cout << "v�������� " << v.capacity() << endl;
	cout << "v�Ĵ�С�� " << v.size() << endl;
}

//reserve(int len);//����Ԥ��len��Ԫ�س��ȣ�Ԥ��λ�ò���ʼ����Ԫ�ز��ɷ��ʡ�
void test04()
{
	vector<int> v;
	v.reserve(89564);//����ܴ���֪��һ����Ҫ�Ĵ�С����Ԥ������ɼ��ٿռ俪�ٵĴ���

	int* p = NULL;//���ָ��v�ĵ�ַ
	int num = 0;//����
	for (int i = 0; i < 100000; i++)
	{
		v.push_back(i);
		if (p != &v[0])
		{
			p = &v[0];//���p����v�ĵ�ַ������p�������ַ
			num++;
		}
		/*��ν��̬���Ӵ�С����������ԭ�ռ�֮�������¿ռ䣨��Ϊ�޷���֤ԭ�ռ�֮�����п����õĿռ䣩��
		����һ�������ڴ�ռ䣬Ȼ��ԭ���ݿ������¿ռ䣬���ͷ�ԭ�ռ䡣��ˣ���vector���κβ�����
		һ������ռ�����·��䣬ָ��ԭ�ռ�����е�������ʧЧ�ˡ�*/
		/*����ÿһ��p����v�ĵ�ַ��˵��������ʮ������Ĺ������·�����һ�οռ䣬����һ�����ݵĿ�����Ų��*/
	}
	cout << num << endl;//�ɼ�����Ԥ���ռ䣬��һ�δεĶ�̬������Ҫ30�ε��¿ռ���䣬��һ�ʴ���
	//����Ԥ����89564�Ĵ��¿ռ��ֻ��Ҫ���ο��٣����ܴ��100000������
}


/*
3.2.4.4 vector���ݴ�ȡ����
at(int idx); //��������idx��ָ�����ݣ����idxԽ�磬�׳�out_of_range�쳣��
operator[];//��������idx��ָ�����ݣ�Խ��ʱ������ֱ�ӱ���
front();//���������е�һ������Ԫ��
back();//�������������һ������Ԫ��

3.2.4.5 vector�����ɾ������
insert(const_iterator pos, int count,ele);//������ָ��λ��pos����count��Ԫ��ele.
push_back(ele); //β������Ԫ��ele
pop_back();//ɾ�����һ��Ԫ��
erase(const_iterator start, const_iterator end);//ɾ����������start��end֮���Ԫ��
erase(const_iterator pos);//ɾ��������ָ���Ԫ��
clear();//ɾ������������Ԫ��
*/
void test05()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);

	cout << "v��front�� " << v.front() << endl;
	cout << "v��back�� " << v.back() << endl;

	v.insert(v.begin(), 2, 123);//����һ �������� ������ ��������� ������ ��������
	//������v1��Ҳ��int�ͣ����԰�v1��ĳ�β��룬�硰v.insert(v.begin(), v1.begin(), v1.end())����
	
	v.pop_back();//ɾ�����һλ
	printVector(v);
	cout << "v��back�� " << v.back() << endl;

	v.erase(v.begin());//ɾ��
	printVector(v);

	//ȫ������ɾ��
	v.clear();// ���ߵȼ� v.erase(v.begin(), v.end())
	if (v.empty())
	{
		cout << "v����" << endl;
	}
	else
	{
		cout << "vû��" << endl;
	}
}


//vector���������
void test06()
{
	//��ʼ��
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	//�������
	//��������� reverse_iterator   ����ͷ rbegin()   �����β rend()
	for (vector<int>::reverse_iterator it = v.rbegin(); it != v.rend(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}


//����ж�һ�������ĵ������Ƿ���������ʵĵ�����
void test07()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	//vector�ĵ�������������ʵĵ�������֧����Ծ����
	vector<int>::iterator itBegin = v.begin();
	itBegin = itBegin + 4;//�����д���������������������������ʵĵ�����

	//�� list�ĵ������Ͳ�֧���������
	list<int> l;
	for (int i = 0; i < 10; i++)
	{
		l.push_back(i);
	}
	list<int>::iterator litBegin = l.begin();
	//litBegin = litBegin + 4;//�����
}

int main()
{
	//test01();
	//test02();
	//test03();
	//test04();
	//test05();
	//test06();
	test07();
}
