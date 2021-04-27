#include<iostream>
#include<string>
using namespace std;
#include"MyString.h"
#pragma warning(disable : 4996)


void test01()
{
	MyString str = "abc";

	cout << str << endl;

	/*cout << "请输入str新的内容：" << endl;

	cin >> str;								//通过重载<<和>>来实现对MyString类型的输入输出

	cout << "新内容为：" << str << endl;*/

	MyString str2(str);
	cout << "str2 = " << str2 << endl;

	MyString str3 = "aaaaaa";
	cout << "str3 = " << str3 << endl;
	
	str3 = str2;
	str3 = "aaaa";

	cout << "str3 = " << str3 << endl;

	str3[0] = 'w';

	cout << "str3 第一个位置为 = " << str3[0] << endl;

	MyString str4 = "";
	
	/*for test
	cout << "str2.m_Size= " << str2.getSize() << endl;
	cout << "str3.m_Size= " << str3.getSize() << endl;
	cout << str2 + str3 << endl;
	/*for test*/

	str4 = (str2 + str3); //字符串拼接

	cout << "str4 为 " << str4 << endl;

	if (str3 == str4)
	{
		cout << "str3 与 str4相等" << endl;
	}
	else
	{
		cout << "str3 与 str4不相等" << endl;
	}

	/*int a = 10;
	cin >> a;
	cout << "a = " << a << endl;*/
}

int main()
{
	test01();
	MyString s1("aql");
	cin >> s1;
	cout << s1 << endl;
}
