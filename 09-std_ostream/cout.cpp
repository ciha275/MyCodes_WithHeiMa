#include<iostream>
#include<iomanip>	//使用控制符的头文件
using namespace std;

/*
* cout.put()	向缓冲区写字符
* cout.write()	从缓冲区写n个字符到当前输出流中
*/
//实际一般就直接用cout << 来连接输出内容
void test01()
{
	//cout.put()	向缓冲区写字符，然后显示对应内容
	cout.put('10').put('\n').put('b');
	cout.put('\n');

	//cout.write()	从缓冲区写n个字符到当前输出流中
	char buf[1024] = "zheshiyichuan zifu";
	cout.write( buf, (sizeof(buf) / sizeof(char)) );
	cout << endl;
}

/****************************控制输出格式******************************/
void test02()
{
	//通过流成员函数，格式化输出
	int number = 99;

	cout.width(20);				//宽度20
	cout.fill('*');				//用指定内容填充空格
	cout.setf(ios::left);		//设置格式，输入内容左对齐
	cout.unsetf(ios::dec);		//卸载十进制
	cout.setf(ios::hex);		//安装十六进制
	cout.setf(ios::showbase);	//强制显示输出整数的基数 0 0x
	cout.unsetf(ios::hex);		//卸载十六进制
	cout.setf(ios::oct);		//安装八进制
	cout << number << endl;
}

void test03()
{
	//利用控制符方式 格式化输出
	int number = 99;

	cout << setw(10)
		<< setfill('*')
		<< setiosflags(ios::showbase)	//显示基数
		<< setiosflags(ios::left)		//左对齐
		<< hex							//设置十六进制
		<< number
		<< endl;
}



/****************************控制输出格式******************************/

int main()
{
	test01();
	test02();
	test03();
}
