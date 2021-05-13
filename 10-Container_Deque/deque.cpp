#include<iostream>
#include<deque>
#include<algorithm>
using namespace std;


//vector�ǵ���������deque��˫��������deque������Ҳ�����ڴ�

/*
3.3.3.1 deque���캯��
deque<T> deqT;//Ĭ�Ϲ�����ʽ
deque(beg, end);//���캯����[beg, end)�����е�Ԫ�ؿ���������
deque(n, elem);//���캯����n��elem����������
deque(const deque &deq);//�������캯����

3.3.3.2 deque��ֵ����
assign(beg, end);//��[beg, end)�����е����ݿ�����ֵ������
assign(n, elem);//��n��elem������ֵ������
deque& operator=(const deque &deq); //���صȺŲ�����
swap(deq);// ��deq�뱾���Ԫ�ػ���

3.3.3.3 deque��С����
deque.size();//����������Ԫ�صĸ���
deque.empty();//�ж������Ƿ�Ϊ��
deque.resize(num);//����ָ�������ĳ���Ϊnum,�������䳤������Ĭ��ֵ�����λ�á����������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ����
deque.resize(num, elem); //����ָ�������ĳ���Ϊnum,�������䳤������elemֵ�����λ��,���������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ����
*/
void printDeque(deque<int>& d)
{
	//iterator ��ͨ�������� reverse_iterator ����������� const_iterator ֻ��������
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
	{
		//������ֻ��������const_iterator���Ա�֤��ֻ���������Ӱ������������
		//*it = 100;�Ͳ���
		cout << *it << " ";
	}
	cout << endl;
}

void test01()
{
	deque<int> d;
	d.push_back(1);
	d.push_back(2);
	d.push_back(3);
	d.push_back(4);

	//deque(beg, end);//���캯����[beg, end)�����е�Ԫ�ؿ���������
	deque<int> d2(d.begin(), d.end());
	d2.push_back(1000);

	//����
	d.swap(d2);
	printDeque(d);

	//��С  empty��size��resize������ǰ��һ��

}


/*
3.3.3.4 deque˫�˲����ɾ������
push_back(elem);//������β�����һ������
push_front(elem);//������ͷ������һ������
pop_back();//ɾ���������һ������
pop_front();//ɾ��������һ������

3.3.3.5 deque���ݴ�ȡ
at(idx);//��������idx��ָ�����ݣ����idxԽ�磬�׳�out_of_range��
operator[];//��������idx��ָ�����ݣ����idxԽ�磬���׳��쳣��ֱ�ӳ���
front();//���ص�һ�����ݡ�
back();//�������һ������

3.3.3.6 deque�������
insert(pos,elem);//��posλ�ò���һ��elemԪ�صĿ��������������ݵ�λ�á�
insert(pos,n,elem);//��posλ�ò���n��elem���ݣ��޷���ֵ��
insert(pos,beg,end);//��posλ�ò���[beg,end)��������ݣ��޷���ֵ��

3.3.3.7 dequeɾ������
clear();//�Ƴ���������������
erase(beg,end);//ɾ��[beg,end)��������ݣ�������һ�����ݵ�λ�á�
erase(pos);//ɾ��posλ�õ����ݣ�������һ�����ݵ�λ�á�
*/
void test02()
{
	deque<int> d;
	/*
	push_back(elem);//������β�����һ������
	push_front(elem);//������ͷ������һ������
	*/
	d.push_back(1);
	d.push_back(2);
	d.push_front(3);
	d.push_front(4);
	//Ӧ�� 4312
	printDeque(d);
	/*
	pop_back();//ɾ���������һ������
	pop_front();//ɾ��������һ������
	*/
	d.pop_front();
	d.pop_back();
	//Ӧ�� 3 1
	printDeque(d);

	//at() �� [] ��ǰ��Ҳһ����at�׳��쳣��[]ֱ���ж�
	cout << "front: " << d.front() << endl;
	cout << "back: " << d.back() << endl;

	//insert(pos,beg,end);//��posλ�ò���[beg,end)��������ݣ��޷���ֵ��
	deque<int> d2;
	d2.push_back(10);
	d2.push_back(20);
	d2.insert(d2.begin()+1, d.begin(), d.end());//��10 20֮�����
	printDeque(d2);

	//clear erase ����ͬǰ
	d2.erase(d2.begin(), d2.end());//��ͬclear
	if (d2.empty())
	{
		cout << "d2Ϊ��" << endl;
	}
}


//����sort
bool myCompare(int v1, int v2)
{
	return v1 > v2;
}
void test03()
{
	deque<int> d;
	d.push_back(329);
	d.push_back(319);
	d.push_back(419);
	d.push_back(369);
	d.push_back(499);
	printDeque(d);

	//����sort ����һ ��ͷ �������� ��β ���������� �ص�������
	sort(d.begin(), d.end());//Ĭ�Ͼ��Ǵ�С����
	printDeque(d);
	sort(d.begin(), d.end(), myCompare);//ʹ���Լ���д�Ļص�����
	printDeque(d);

}

int main()
{
	//test01();
	//test02();
	test03();
}
