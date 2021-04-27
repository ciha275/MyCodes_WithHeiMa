#include "MyString.h"


//有参构造
MyString::MyString(const char* str)
{
	cout << "有参构造" << endl;
	this->pString = new char[strlen(str) + 1];
	strcpy(this->pString, str);
	this->m_Size = strlen(str);
}

MyString::MyString(const MyString& str)
{
	cout << "拷贝构造" << endl;
	this->pString = new char[(str.m_Size)+1];
	strcpy(this->pString, str.pString);
	this->m_Size = str.m_Size;
}

MyString::~MyString()
{
	cout << "析构" << endl;
	if (this->pString != NULL)
	{
		delete[] this->pString;//注意这是数组，delete后接[]
		this->pString = NULL;
	}
}

MyString& MyString::operator=(const char* str)
{
	cout << "调用了重载=的常量型" << endl;
	if (this->pString != NULL)
	{
		delete[] this->pString;
		this->pString = NULL;
	}
	this->pString = new char[strlen(str) + 1];
	strcpy(this->pString,str);
	return *this;//返回自身，this是自身的指针，*this就是自身
}

MyString& MyString::operator=(const MyString& str)
{
	cout << "调用了重载=的拷贝型" << endl;
	if (this->pString != NULL)
	{
		delete[] this->pString;
		this->pString = NULL;
	}
	this->pString = new char[strlen(str.pString) + 1];
	//this->pString = new char[str.m_Size + 1];
	strcpy(this->pString, str.pString);
	return *this;//返回自身，this是自身的指针，*this就是自身
}


char& MyString::operator[](int index)
{
	return this->pString[index];
}

MyString MyString::operator+(const char* str)
{
	//计算返回的字符串开辟的大小
	int newSize = this->m_Size + /**/strlen(str)/**/+1;

	char* temp = new char[newSize];
	
	//清零,随后进行两次拼接
	memset(temp,0,newSize);
	
	//strcat()是接在尾部，但因此时temp全是0，故尾部即是头部
	strcat(temp, this->pString);
	strcat(temp, /**/str/**/);
	
	//要返回自己的数组类型，所以创建对象来接受这个temp
	MyString newstr(temp);//有参构造												//！！！！！！！注意！！！！！！！！
	delete[] temp;//释放这个临时字符数组											//重载+运算符，返回值是 值传递！！
	return newstr;																//返回值应该是 值传递！！！！！！
}																				//最后返回的newstr是局部变量！！返回引用的话找不到！！

MyString MyString::operator+(const MyString& str)
{
	//计算返回的字符串开辟的大小
	int newSize = this->m_Size + /**/strlen(str.pString)/**/+1;

	char* temp = new char[newSize];
	
	//清零,随后进行两次拼接
	memset(temp, 0, newSize);
	
	//strcat()是接在尾部，但因此时temp全是0，故尾部即是头部
	strcat(temp, this->pString);
	strcat(temp, /**/str.pString/**/);
	
	//要返回自己的数组类型，所以创建对象来接受这个temp
	MyString newstr(temp);//有参构造
	delete[] temp;//释放这个临时字符数组
	
	//cout << "newstr= " << newstr << endl;

	return newstr;
}

bool MyString::operator==(const char* str)
{
	if (strcmp(this->pString, str) && (this->m_Size == strlen(str)))
	{
		return true;
	}
	return false;
}

bool MyString::operator==(const MyString& str)
{
	if (strcmp(this->pString, str.pString) && (this->m_Size == str.m_Size))
	{
		return true;
	}
	return false;
}

int MyString::getSize()
{
	return this->m_Size;
}

//输出运算符<<(左移运算符)的重载，注意设置友元
ostream& operator<<(ostream& cout, MyString& str)
{
	cout << str.pString;
	return cout;
}

//输入运算符>>(右移运算符)的重载，注意设置友元
istream& operator>>(istream& cin, MyString& str)
{
	//先判断原始是否有数据，若有，清空
	if (str.pString != NULL)
	{
		delete[] str.pString;
		str.pString = NULL;
	}
	
	//用户输入内容
	char buf[1024];
	cin >> buf;
	
	//把用户输入的字符串赋值给str
	str.pString = new char[strlen(buf)+1];
	str.m_Size = strlen(buf);
	strcpy(str.pString, buf);
	return cin;
}