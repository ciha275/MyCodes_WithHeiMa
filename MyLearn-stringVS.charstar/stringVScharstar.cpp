//char*
#include <iostream>
using namespace std;
//string
#include<string>

void testCharArray()

{
	char ch1[12] = "Hello Wrold"; //这里只能ch1[12]，ch1[11]编译不通过,提示array bounds overflow
	char* pch1, * pch2 = (char*)"string";
	char* pch3, * pch4;
	pch3 = &ch1[2];	//ch1[2]的地址赋给pch3
	char ch = 'c';
	pch4 = &ch;
	pch1 = ch1;

	cout << ch1 << endl;	//输出ch1[0]到\0之前的所有字符
	cout << pch1 << endl;	//输出ch1[0]到\0之前的所有字符
	cout << pch2 << endl;	//输出ch1[0]到\0之前的所有字符
	cout << pch3 << endl;	//输出ch1[2]到\0之前的所有字符
	cout << *pch3 << endl;	//解引用pch3输出pch3指向的字符
	cout << *pch4 << endl;	//解引用pch4输出pch4指向的字符
}

void testString() 
{ 
	string s1 = "this";	
	string s2 = string(" is");	
	string s3, s4;	
	s3 = string(" a").append("string.");	
	s4 = s1 + s2 + s3;	
	cout << s1 << endl;	
	cout << s2 << endl;	
	cout << s3 << endl;	
	cout << s4 << endl;	
	cout << s4.size() << endl;	
	s4.insert(s4.end() - 7, 1, ' ');	
	cout << s4 << endl; 
}

//char*和string类型的转换
void pCharToString()
{
	//from char* to string
	char* ch = (char*)"hello world";
	string s1 = ch;	//直接初始化或赋值
	string s2(ch), s3;
	s3 = string(ch);
	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	//from string to char*
	string str = string("string is commonly used.");
	/*************************************************************************
	其实没有很大的必要将string转换成char*,因为string可以直接当成字符数组来使用，
	即通过下标来访问字符元素，如str[1]表示第1个字符't'
	**************************************************************************/
	const char* ch1 = str.c_str();
	cout << ch1 << endl;
}


int main()
{
	testCharArray();
	testString();
	pCharToString();
}
