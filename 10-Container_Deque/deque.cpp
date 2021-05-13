#include<iostream>
#include<deque>
#include<algorithm>
using namespace std;


//vector是单端容器，deque是双端容器，deque的优势也就在于此

/*
3.3.3.1 deque构造函数
deque<T> deqT;//默认构造形式
deque(beg, end);//构造函数将[beg, end)区间中的元素拷贝给本身。
deque(n, elem);//构造函数将n个elem拷贝给本身。
deque(const deque &deq);//拷贝构造函数。

3.3.3.2 deque赋值操作
assign(beg, end);//将[beg, end)区间中的数据拷贝赋值给本身。
assign(n, elem);//将n个elem拷贝赋值给本身。
deque& operator=(const deque &deq); //重载等号操作符
swap(deq);// 将deq与本身的元素互换

3.3.3.3 deque大小操作
deque.size();//返回容器中元素的个数
deque.empty();//判断容器是否为空
deque.resize(num);//重新指定容器的长度为num,若容器变长，则以默认值填充新位置。如果容器变短，则末尾超出容器长度的元素被删除。
deque.resize(num, elem); //重新指定容器的长度为num,若容器变长，则以elem值填充新位置,如果容器变短，则末尾超出容器长度的元素被删除。
*/
void printDeque(deque<int>& d)
{
	//iterator 普通迭代器， reverse_iterator 逆序迭代器， const_iterator 只读迭代器
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
	{
		//这里用只读迭代器const_iterator可以保证，只会输出，不影响容器内内容
		//*it = 100;就不行
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

	//deque(beg, end);//构造函数将[beg, end)区间中的元素拷贝给本身。
	deque<int> d2(d.begin(), d.end());
	d2.push_back(1000);

	//交换
	d.swap(d2);
	printDeque(d);

	//大小  empty，size，resize，都和前面一样

}


/*
3.3.3.4 deque双端插入和删除操作
push_back(elem);//在容器尾部添加一个数据
push_front(elem);//在容器头部插入一个数据
pop_back();//删除容器最后一个数据
pop_front();//删除容器第一个数据

3.3.3.5 deque数据存取
at(idx);//返回索引idx所指的数据，如果idx越界，抛出out_of_range。
operator[];//返回索引idx所指的数据，如果idx越界，不抛出异常，直接出错。
front();//返回第一个数据。
back();//返回最后一个数据

3.3.3.6 deque插入操作
insert(pos,elem);//在pos位置插入一个elem元素的拷贝，返回新数据的位置。
insert(pos,n,elem);//在pos位置插入n个elem数据，无返回值。
insert(pos,beg,end);//在pos位置插入[beg,end)区间的数据，无返回值。

3.3.3.7 deque删除操作
clear();//移除容器的所有数据
erase(beg,end);//删除[beg,end)区间的数据，返回下一个数据的位置。
erase(pos);//删除pos位置的数据，返回下一个数据的位置。
*/
void test02()
{
	deque<int> d;
	/*
	push_back(elem);//在容器尾部添加一个数据
	push_front(elem);//在容器头部插入一个数据
	*/
	d.push_back(1);
	d.push_back(2);
	d.push_front(3);
	d.push_front(4);
	//应该 4312
	printDeque(d);
	/*
	pop_back();//删除容器最后一个数据
	pop_front();//删除容器第一个数据
	*/
	d.pop_front();
	d.pop_back();
	//应该 3 1
	printDeque(d);

	//at() 和 [] 与前面也一样，at抛出异常，[]直接中断
	cout << "front: " << d.front() << endl;
	cout << "back: " << d.back() << endl;

	//insert(pos,beg,end);//在pos位置插入[beg,end)区间的数据，无返回值。
	deque<int> d2;
	d2.push_back(10);
	d2.push_back(20);
	d2.insert(d2.begin()+1, d.begin(), d.end());//在10 20之间插入
	printDeque(d2);

	//clear erase 操作同前
	d2.erase(d2.begin(), d2.end());//等同clear
	if (d2.empty())
	{
		cout << "d2为空" << endl;
	}
}


//排序sort
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

	//调用sort 参数一 开头 ，参数二 结尾 ，（参数三 回调函数）
	sort(d.begin(), d.end());//默认就是从小到大
	printDeque(d);
	sort(d.begin(), d.end(), myCompare);//使用自己编写的回调函数
	printDeque(d);

}

int main()
{
	//test01();
	//test02();
	test03();
}
