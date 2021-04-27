#include<iostream>
using namespace std;

//宏 可能有的缺陷
//1.格式不注意
#define MyAdd(x,y) x+y
void test01()
{
	int result = MyAdd(10, 20) * 20;

	cout << "result = " << result << endl;//实际显示 410 ，希望值(10+20)*20=600，原因在于宏定义并没有（x+y）

}
//2.个人理解）宏是一种原原本本的替换，内联函数他就是一种函数，与函数不同在于，内联函数在适当地方可像预定义宏一样展开，所以不需要函数调用的开销
#define MyCompare(x,y) ((x)<(y) ? (x):(y))
inline void mycompare(int x, int y)
{
	int result = x < y ? x : y;
	cout << "result of inline = " << result << endl;
}
void test02()
{
	int a = 10;
	int b = 20;

	//int result = MyCompare(++a, b);//预定义宏原原本本的展开，相当于int res = ((++a)<(b) ? (++a):(b))，则会顺序执行两次++a，导致最后传回值为12
	//cout << "result = " << result << endl;//设想值应为11

	mycompare(++a, b);//直接等价于下两行代码，不过此处作为函数的“值传递”，直接传入（++a）即11 这个值
	//int result = 11 < 20 ? 11 : 20;
	//cout << "result of inline = " << result << endl;

}
//内联函数只是对编译器的一个“建议”，编译器可能不接受这建议，没有声明内联的函数，编译器也可能加上内联


int main()
{
	//test01();
	test02();
}