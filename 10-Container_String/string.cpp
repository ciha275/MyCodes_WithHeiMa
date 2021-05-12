#include<iostream>
#include<string>
using namespace std;
//用到系统异常的头文件
#include<stdexcept>


/*
3.1.2.1 string 构造函数
string();//创建一个空的字符串 例如: string str;      
string(const string& str);//使用一个string对象初始化另一个string对象
string(const char* s);//使用字符串s初始化
string(int n, char c);//使用n个字符c初始化 

3.1.2.2 string基本赋值操作
string& operator=(const char* s);//char*类型字符串 赋值给当前的字符串
string& operator=(const string &s);//把字符串s赋给当前的字符串
string& operator=(char c);//字符赋值给当前的字符串
string& assign(const char *s);//把字符串s赋给当前的字符串
string& assign(const char *s, int n);//把字符串s的前n个字符赋给当前的字符串
string& assign(const string &s);//把字符串s赋给当前字符串
string& assign(int n, char c);//用n个字符c赋给当前字符串
string& assign(const string &s, int start, int n);//将s从start开始n个字符赋值给字符串
*/

void test01()
{
	string str;			//默认构造
	string str2(str);	//拷贝构造
	//string str2 = str; 也拷贝构造

	//string(const char* s);//使用字符串s初始化
	string str3 = "abcd";//有参构造，等价string str3("abcd");
	
	//string(int n, char c);//使用n个字符c初始化
	string str4(10, 'a');
	cout << str3 << endl;
	cout << str4 << endl;

	//基本赋值   
	//string& operator=(const char* s);//char*类型字符串 赋值给当前的字符串
	str = "hello";
	//string& operator=(const string &s);//把字符串s赋给当前的字符串
	str2 = str3;
	cout << "str = " << str << endl;
	cout << "str2 = " << str2 << endl;

	//string& assign(const char *s, int n);//把字符串s的前n个字符赋给当前的字符串
	string str5;
	str5.assign("abcdefg", 3);
	cout << "str5 = " << str5 << endl;//str5 = abc

	//string& assign(const string &s, int start, int n);//将s从start开始n个字符赋值给字符串
	string str6;
	str6.assign(str, 2, 5);//从第2位开始的5个字符，但实际“h0 e1 l2 l3 o4”，第2位起，只有“llo”3个，故 str6 = llo
	cout << "str6 = " << str6 << endl;
}


/*
3.1.2.3 string存取字符操作
char& operator[](int n);//通过[]方式取字符
char& at(int n);//通过at方法获取字符
*/
void test02()
{
	string s = "hello world";
	for (int i = 0; i < s.size(); i++)
	{
		cout << s[i] << " ";
		cout << s.at(i) << endl;
	}

	// [] 和 at() 的区别，当超出string对象的范围时，[]直接中断，at()将会抛出异常
	try
	{
		//cout << s[120] << endl;
		cout << s.at(120) << endl;
	}
	//实际 at() 抛出的异常即为越界异常，out_of_range
	catch (out_of_range& e)
	{
		cout << e.what() << endl;
	}
	catch (...)//当不清楚异常类型时，可以使用...来概括
	{
		cout << "发生了某种异常" << endl;
	}
}


/*
3.1.2.4 string拼接操作
string& operator+=(const string& str);//重载+=操作符
string& operator+=(const char* str);//重载+=操作符
string& operator+=(const char c);//重载+=操作符
string& append(const char *s);//把字符串s连接到当前字符串结尾
string& append(const char *s, int n);//把字符串s的前n个字符连接到当前字符串结尾
string& append(const string &s);//同operator+=()
string& append(const string &s, int pos, int n);//把字符串s中从pos开始的n个字符连接到当前字符串结尾
string& append(int n, char c);//在当前字符串结尾添加n个字符c

3.1.2.5 string查找和替换
int find(const string& str, int pos = 0) const; //查找str第一次出现位置,从pos开始查找
int find(const char* s, int pos = 0) const;  //查找s第一次出现位置,从pos开始查找
int find(const char* s, int pos, int n) const;  //从pos位置查找s的前n个字符第一次位置
int find(const char c, int pos = 0) const;  //查找字符c第一次出现位置
int rfind(const string& str, int pos = npos) const;//查找str最后一次位置,从pos开始查找
int rfind(const char* s, int pos = npos) const;//查找s最后一次出现位置,从pos开始查找
int rfind(const char* s, int pos, int n) const;//从pos查找s的前n个字符最后一次位置
int rfind(const char c, int pos = 0) const; //查找字符c最后一次出现位置
string& replace(int pos, int n, const string& str); //替换从pos开始n个字符为字符串str
string& replace(int pos, int n, const char* s); //替换从pos开始的n个字符为字符串s
*/
void test03()
{
	//拼接操作  +=  append()
	string s1 = "我叫";
	string s2 = ",ei,不告诉你";
	s1 += s2;
	cout << s1 << endl;
	string s3 = "，就是玩儿";
	s1.append(s3);
	cout << s1 << endl;

	//find & rfind 查找 ，返回值 int型位置值
	string s = "abcdefgcdeh";
	int cdePos = s.find("cde");
	cout << "cdePos = " << cdePos << endl;//找到第一个cde，2号位
	int cdfPos = s.find("cdf");
	cout << "cdfPos = " << cdfPos << endl;//find找不到，返回 -1
	//rfind和find一样，不过是从尾开始到头，所以找到的是“最后一次出现的位置”
	int RevcdePos = s.rfind("cde");
	cout << "RevcdePos = " << RevcdePos << endl;//找到最后一个cde，7号位

	//replace替换 
	//string& replace(int pos, int n, const char* s); 
	//替换从pos开始的n个字符为字符串s，就是pos开始数n个数，这n个不要了，换成整个s的内容
	string s4 = "ciha";
	s4.replace(2, 1, " real ");//所以虽然只是从2号位开始数1个，但换上了" real "加空格总共6位
	cout << s4 << endl;

}


/*
3.1.2.6 string比较操作
compare函数在>时返回 1，<时返回 -1，==时返回 0。
比较区分大小写，比较时参考字典顺序，排越前面的越小。
大写的A比小写的a小。
int compare(const string& s) const;//与字符串s比较
int compare(const char* s) const;//与字符串s比较
*/
void test04()
{
	string s1 = "abc";
	string s2 = "aac";

	if (s1.compare(s2) == 0)
	{
		cout << "s1 = s2" << endl;
	}
	else if (s1.compare(s2) == 1)
	{
		cout << "s1 > s2" << endl;
	}
	else
	{
		cout << "s1 < s2" << endl;
	}
}


/*
3.1.2.7 string子串
string substr(int pos = 0, int n = npos) const;
//返回由pos开始的n个字符组成的字符串
*/
void test05()
{
	string s1 = "abcdefg";
	string s2 = s1.substr(1, 3);//从1号位取3个，即“bcd”
	cout << s2 << endl;

	//可以利用子串和查找，实现“提取邮箱地址的用户名”
	string email = "myUserName@qq.com";
	int pos = email.find('@');//查找字符‘@’的位置，因为一般@前就是用户名
	string UserName = email.substr(0, pos);//正常从1数起，取n号位前面所有就是n-1个，此时从0计数，所以号数就是该号位前面的个数
	cout << "邮箱用户名： " << UserName << endl;
}


/*
3.1.2.8 string插入和删除操作
string& insert(int pos, const char* s); //插入字符串
string& insert(int pos, const string& str); //插入字符串
string& insert(int pos, int n, char c);//在指定位置插入n个字符c
string& erase(int pos, int n = npos);//删除从Pos开始的n个字符
*/
void test06()
{
	//string& insert(int pos, const char* s); //插入字符串
	string s1 = "abc";
	s1.insert(1, "123");
	cout << s1 << endl;

	//string& erase(int pos, int n = npos);//删除从Pos开始的n个字符
	s1.erase(1, 3);//把插入的123删除
	cout << s1 << endl;
}


/*
3.1.2.9 string和c-style字符串转换
//string 转 char*
string str = "itcast";
const char* cstr = str.c_str();
//char* 转 string
char* s = "itcast";
string str(s);
*/
void func1(string s)
{
	cout << s << endl;
}
void func2(const char* cs)
{
	cout << cs << endl;
}
void test07()
{
	string s = "abc";
	//string转const char*
	const char* cs = s.c_str();
	func1(cs);//const char* 可以隐式转换成string

	//const char*转string，利用string的拷贝构造，或者赋值操作都行
	string s2(cs);
	//func2(s2);//string 不可以隐式转换成const char*
}


/*
//常见错误
*/
void test08()
{
	string s = "abcd";
	char& a = s[1];//'b'
	char& b = s[2];//'c'
	//a，b就是s的1、2号位了，改变a b就改变了s的这两位
	a = '1';
	b = '2';
	cout << s << endl;
	cout << (int*)s.c_str() << endl;//显示s此时的地址，先c_str转为char*类型再强制转换为int*显示地址

	s = "aaaaaaaaaaaaaaaaaaaaaa";//对s重新赋值，
	//显然此时原本的存储空间不够存放这么大的数据，所以会找一块新的大的空间，所以指向原空间的指针、引用就无效了
	/*a = '1';
	b = '2';*/
	cout << s << endl;
	cout << (int*)s.c_str() << endl;//可见此时地址与上面的地址不同了
}

/*
* 小案例，把一个string全改为大（小）写
*/
void test09()
{
	string s = "asdFGHffs";
	for (int i = 0; i < s.size(); i++)
	{
		//改大写
		//s[i] = toupper(s[i]);
		//改小写
		s[i] = tolower(s[i]);
	}
	cout << s << endl;
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
	//test08();
	test09();
}
