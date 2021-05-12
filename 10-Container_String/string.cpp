#include<iostream>
#include<string>
using namespace std;
//�õ�ϵͳ�쳣��ͷ�ļ�
#include<stdexcept>


/*
3.1.2.1 string ���캯��
string();//����һ���յ��ַ��� ����: string str;      
string(const string& str);//ʹ��һ��string�����ʼ����һ��string����
string(const char* s);//ʹ���ַ���s��ʼ��
string(int n, char c);//ʹ��n���ַ�c��ʼ�� 

3.1.2.2 string������ֵ����
string& operator=(const char* s);//char*�����ַ��� ��ֵ����ǰ���ַ���
string& operator=(const string &s);//���ַ���s������ǰ���ַ���
string& operator=(char c);//�ַ���ֵ����ǰ���ַ���
string& assign(const char *s);//���ַ���s������ǰ���ַ���
string& assign(const char *s, int n);//���ַ���s��ǰn���ַ�������ǰ���ַ���
string& assign(const string &s);//���ַ���s������ǰ�ַ���
string& assign(int n, char c);//��n���ַ�c������ǰ�ַ���
string& assign(const string &s, int start, int n);//��s��start��ʼn���ַ���ֵ���ַ���
*/

void test01()
{
	string str;			//Ĭ�Ϲ���
	string str2(str);	//��������
	//string str2 = str; Ҳ��������

	//string(const char* s);//ʹ���ַ���s��ʼ��
	string str3 = "abcd";//�вι��죬�ȼ�string str3("abcd");
	
	//string(int n, char c);//ʹ��n���ַ�c��ʼ��
	string str4(10, 'a');
	cout << str3 << endl;
	cout << str4 << endl;

	//������ֵ   
	//string& operator=(const char* s);//char*�����ַ��� ��ֵ����ǰ���ַ���
	str = "hello";
	//string& operator=(const string &s);//���ַ���s������ǰ���ַ���
	str2 = str3;
	cout << "str = " << str << endl;
	cout << "str2 = " << str2 << endl;

	//string& assign(const char *s, int n);//���ַ���s��ǰn���ַ�������ǰ���ַ���
	string str5;
	str5.assign("abcdefg", 3);
	cout << "str5 = " << str5 << endl;//str5 = abc

	//string& assign(const string &s, int start, int n);//��s��start��ʼn���ַ���ֵ���ַ���
	string str6;
	str6.assign(str, 2, 5);//�ӵ�2λ��ʼ��5���ַ�����ʵ�ʡ�h0 e1 l2 l3 o4������2λ��ֻ�С�llo��3������ str6 = llo
	cout << "str6 = " << str6 << endl;
}


/*
3.1.2.3 string��ȡ�ַ�����
char& operator[](int n);//ͨ��[]��ʽȡ�ַ�
char& at(int n);//ͨ��at������ȡ�ַ�
*/
void test02()
{
	string s = "hello world";
	for (int i = 0; i < s.size(); i++)
	{
		cout << s[i] << " ";
		cout << s.at(i) << endl;
	}

	// [] �� at() �����𣬵�����string����ķ�Χʱ��[]ֱ���жϣ�at()�����׳��쳣
	try
	{
		//cout << s[120] << endl;
		cout << s.at(120) << endl;
	}
	//ʵ�� at() �׳����쳣��ΪԽ���쳣��out_of_range
	catch (out_of_range& e)
	{
		cout << e.what() << endl;
	}
	catch (...)//��������쳣����ʱ������ʹ��...������
	{
		cout << "������ĳ���쳣" << endl;
	}
}


/*
3.1.2.4 stringƴ�Ӳ���
string& operator+=(const string& str);//����+=������
string& operator+=(const char* str);//����+=������
string& operator+=(const char c);//����+=������
string& append(const char *s);//���ַ���s���ӵ���ǰ�ַ�����β
string& append(const char *s, int n);//���ַ���s��ǰn���ַ����ӵ���ǰ�ַ�����β
string& append(const string &s);//ͬoperator+=()
string& append(const string &s, int pos, int n);//���ַ���s�д�pos��ʼ��n���ַ����ӵ���ǰ�ַ�����β
string& append(int n, char c);//�ڵ�ǰ�ַ�����β���n���ַ�c

3.1.2.5 string���Һ��滻
int find(const string& str, int pos = 0) const; //����str��һ�γ���λ��,��pos��ʼ����
int find(const char* s, int pos = 0) const;  //����s��һ�γ���λ��,��pos��ʼ����
int find(const char* s, int pos, int n) const;  //��posλ�ò���s��ǰn���ַ���һ��λ��
int find(const char c, int pos = 0) const;  //�����ַ�c��һ�γ���λ��
int rfind(const string& str, int pos = npos) const;//����str���һ��λ��,��pos��ʼ����
int rfind(const char* s, int pos = npos) const;//����s���һ�γ���λ��,��pos��ʼ����
int rfind(const char* s, int pos, int n) const;//��pos����s��ǰn���ַ����һ��λ��
int rfind(const char c, int pos = 0) const; //�����ַ�c���һ�γ���λ��
string& replace(int pos, int n, const string& str); //�滻��pos��ʼn���ַ�Ϊ�ַ���str
string& replace(int pos, int n, const char* s); //�滻��pos��ʼ��n���ַ�Ϊ�ַ���s
*/
void test03()
{
	//ƴ�Ӳ���  +=  append()
	string s1 = "�ҽ�";
	string s2 = ",ei,��������";
	s1 += s2;
	cout << s1 << endl;
	string s3 = "���������";
	s1.append(s3);
	cout << s1 << endl;

	//find & rfind ���� ������ֵ int��λ��ֵ
	string s = "abcdefgcdeh";
	int cdePos = s.find("cde");
	cout << "cdePos = " << cdePos << endl;//�ҵ���һ��cde��2��λ
	int cdfPos = s.find("cdf");
	cout << "cdfPos = " << cdfPos << endl;//find�Ҳ��������� -1
	//rfind��findһ���������Ǵ�β��ʼ��ͷ�������ҵ����ǡ����һ�γ��ֵ�λ�á�
	int RevcdePos = s.rfind("cde");
	cout << "RevcdePos = " << RevcdePos << endl;//�ҵ����һ��cde��7��λ

	//replace�滻 
	//string& replace(int pos, int n, const char* s); 
	//�滻��pos��ʼ��n���ַ�Ϊ�ַ���s������pos��ʼ��n��������n����Ҫ�ˣ���������s������
	string s4 = "ciha";
	s4.replace(2, 1, " real ");//������Ȼֻ�Ǵ�2��λ��ʼ��1������������" real "�ӿո��ܹ�6λ
	cout << s4 << endl;

}


/*
3.1.2.6 string�Ƚϲ���
compare������>ʱ���� 1��<ʱ���� -1��==ʱ���� 0��
�Ƚ����ִ�Сд���Ƚ�ʱ�ο��ֵ�˳����Խǰ���ԽС��
��д��A��Сд��aС��
int compare(const string& s) const;//���ַ���s�Ƚ�
int compare(const char* s) const;//���ַ���s�Ƚ�
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
3.1.2.7 string�Ӵ�
string substr(int pos = 0, int n = npos) const;
//������pos��ʼ��n���ַ���ɵ��ַ���
*/
void test05()
{
	string s1 = "abcdefg";
	string s2 = s1.substr(1, 3);//��1��λȡ3��������bcd��
	cout << s2 << endl;

	//���������Ӵ��Ͳ��ң�ʵ�֡���ȡ�����ַ���û�����
	string email = "myUserName@qq.com";
	int pos = email.find('@');//�����ַ���@����λ�ã���Ϊһ��@ǰ�����û���
	string UserName = email.substr(0, pos);//������1����ȡn��λǰ�����о���n-1������ʱ��0���������Ժ������Ǹú�λǰ��ĸ���
	cout << "�����û����� " << UserName << endl;
}


/*
3.1.2.8 string�����ɾ������
string& insert(int pos, const char* s); //�����ַ���
string& insert(int pos, const string& str); //�����ַ���
string& insert(int pos, int n, char c);//��ָ��λ�ò���n���ַ�c
string& erase(int pos, int n = npos);//ɾ����Pos��ʼ��n���ַ�
*/
void test06()
{
	//string& insert(int pos, const char* s); //�����ַ���
	string s1 = "abc";
	s1.insert(1, "123");
	cout << s1 << endl;

	//string& erase(int pos, int n = npos);//ɾ����Pos��ʼ��n���ַ�
	s1.erase(1, 3);//�Ѳ����123ɾ��
	cout << s1 << endl;
}


/*
3.1.2.9 string��c-style�ַ���ת��
//string ת char*
string str = "itcast";
const char* cstr = str.c_str();
//char* ת string
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
	//stringתconst char*
	const char* cs = s.c_str();
	func1(cs);//const char* ������ʽת����string

	//const char*תstring������string�Ŀ������죬���߸�ֵ��������
	string s2(cs);
	//func2(s2);//string ��������ʽת����const char*
}


/*
//��������
*/
void test08()
{
	string s = "abcd";
	char& a = s[1];//'b'
	char& b = s[2];//'c'
	//a��b����s��1��2��λ�ˣ��ı�a b�͸ı���s������λ
	a = '1';
	b = '2';
	cout << s << endl;
	cout << (int*)s.c_str() << endl;//��ʾs��ʱ�ĵ�ַ����c_strתΪchar*������ǿ��ת��Ϊint*��ʾ��ַ

	s = "aaaaaaaaaaaaaaaaaaaaaa";//��s���¸�ֵ��
	//��Ȼ��ʱԭ���Ĵ洢�ռ䲻�������ô������ݣ����Ի���һ���µĴ�Ŀռ䣬����ָ��ԭ�ռ��ָ�롢���þ���Ч��
	/*a = '1';
	b = '2';*/
	cout << s << endl;
	cout << (int*)s.c_str() << endl;//�ɼ���ʱ��ַ������ĵ�ַ��ͬ��
}

/*
* С��������һ��stringȫ��Ϊ��С��д
*/
void test09()
{
	string s = "asdFGHffs";
	for (int i = 0; i < s.size(); i++)
	{
		//�Ĵ�д
		//s[i] = toupper(s[i]);
		//��Сд
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
