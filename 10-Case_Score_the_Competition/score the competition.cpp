#include<iostream>
#include<string>
#include<deque>
#include<vector>
#include<algorithm>
using namespace std;

/*
* 作业：
* 有5名选手：选手ABCDE，10个评委分别对每一名选手打分，去除最高分，去除评委中最低分，取平均分。
* //1. 创建五名选手，放到vector中
* //2. 遍历vector容器，取出来每一个选手，执行for循环，可以把10个评分打分存到deque容器中
* //3. sort算法对deque容器中分数排序，pop_back pop_front去除最高和最低分
* //4. deque容器遍历一遍，累加分数，累加分数/d.size()
* //5. person.score = 平均分
*/
class Person
{
public:
	Person(string name, int score = 0)
	{
		this->m_Name = name;
		this->m_Score = score;
	}

	string m_Name;
	int m_Score;
};

void printPerson(vector<Person>& v)
{
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "选手" << it->m_Name << "的得分为： " << it->m_Score << endl;
	}
}

void printDeque(deque<int>& d)
{
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void ScoretheCompetition()
{
	//初始化5名选手
	vector<Person> vp;
	Person p1("A");
	Person p2("B");
	Person p3("C");
	Person p4("D");
	Person p5("E");
	vp.push_back(p1);
	vp.push_back(p2);
	vp.push_back(p3);
	vp.push_back(p4);
	vp.push_back(p5);

	//得到存放选手的vector容器首地址，begin迭代器
	vector<Person>::iterator vpBegin = vp.begin();

	deque<int> dScore;
	for (int i = 0; i < 5; i++)//5个选手，循环5次
	{
		cout << "请对选手" << (vpBegin + i)->m_Name << "进行打分（共十次）" << endl;
		for (int j = 0; j < 10; j++)//10位评委打分
		{
			cout << "第 " << j + 1 << " 次打分：" << endl;
			int score;
			cin >> score;
			dScore.push_back(score);
		}

		//对deque容器内的分数排序
		sort(dScore.begin(), dScore.end());
		cout << "排序后： ";
		printDeque(dScore);
		//去掉最高分、最低分，即一头一尾
		dScore.pop_back();
		dScore.pop_front();
		cout << "去掉头尾后： ";
		printDeque(dScore);

		//计算平均分
		int Total = 0;//分数之和
		for (deque<int>::iterator it = dScore.begin(); it != dScore.end(); it++)//循环求和
		{
			Total += *it;//注意，因为要累加，在声明Total后要对其初始化
		}
		cout << "总分： " << Total << endl;
		int Average = Total / dScore.size();

		//将平均分赋值给选手
		(vpBegin + i)->m_Score = Average;

		//因为每个选手的分数都是存在dScore这个deque容器中，所以每一个选手的平均分计算完后，要对dScore容器清空
		dScore.clear();
	}
	//输出选手的情况
	printPerson(vp);
}


int main()
{
	ScoretheCompetition();
}