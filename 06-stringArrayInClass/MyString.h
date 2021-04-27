#pragma once
#include<string>
#include<iostream>
using namespace std;
#pragma warning(disable : 4996)

class MyString
{
	friend ostream& operator<<(ostream& cout, MyString& str);
	friend istream& operator>>(istream& cin, MyString& str);
	
public:
	//有参构造
	MyString(const char* str);
	//拷贝构造
	MyString(const MyString& str);
	//析构
	~MyString();

	//重载=运算符，默认会重载=，但只是浅拷贝，易出问题
	MyString& operator=(const char* str);
	MyString& operator=(const MyString& str);
	//重载[]运算符，能按位str[i]查找
	char& operator[](int index);
	//重载+运算符，实现两个字符串的拼接
	MyString operator+(const char* str);
	MyString operator+(const MyString& str);
	//重载==运算符，判断两字符串相等否
	bool operator==(const char* str);
	bool operator==(const MyString& str);
	
	/**/int getSize();

private:
	char* pString;//指向堆区的指针
	int m_Size;//字符串大小

};
