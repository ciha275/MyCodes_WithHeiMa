#include<iostream>
#include<string>
#include<deque>
#include<vector>
#include<algorithm>
using namespace std;

/*
* ��ҵ��
* ��5��ѡ�֣�ѡ��ABCDE��10����ί�ֱ��ÿһ��ѡ�ִ�֣�ȥ����߷֣�ȥ����ί����ͷ֣�ȡƽ���֡�
* //1. ��������ѡ�֣��ŵ�vector��
* //2. ����vector������ȡ����ÿһ��ѡ�֣�ִ��forѭ�������԰�10�����ִ�ִ浽deque������
* //3. sort�㷨��deque�����з�������pop_back pop_frontȥ����ߺ���ͷ�
* //4. deque��������һ�飬�ۼӷ������ۼӷ���/d.size()
* //5. person.score = ƽ����
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
		cout << "ѡ��" << it->m_Name << "�ĵ÷�Ϊ�� " << it->m_Score << endl;
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
	//��ʼ��5��ѡ��
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

	//�õ����ѡ�ֵ�vector�����׵�ַ��begin������
	vector<Person>::iterator vpBegin = vp.begin();

	deque<int> dScore;
	for (int i = 0; i < 5; i++)//5��ѡ�֣�ѭ��5��
	{
		cout << "���ѡ��" << (vpBegin + i)->m_Name << "���д�֣���ʮ�Σ�" << endl;
		for (int j = 0; j < 10; j++)//10λ��ί���
		{
			cout << "�� " << j + 1 << " �δ�֣�" << endl;
			int score;
			cin >> score;
			dScore.push_back(score);
		}

		//��deque�����ڵķ�������
		sort(dScore.begin(), dScore.end());
		cout << "����� ";
		printDeque(dScore);
		//ȥ����߷֡���ͷ֣���һͷһβ
		dScore.pop_back();
		dScore.pop_front();
		cout << "ȥ��ͷβ�� ";
		printDeque(dScore);

		//����ƽ����
		int Total = 0;//����֮��
		for (deque<int>::iterator it = dScore.begin(); it != dScore.end(); it++)//ѭ�����
		{
			Total += *it;//ע�⣬��ΪҪ�ۼӣ�������Total��Ҫ�����ʼ��
		}
		cout << "�ܷ֣� " << Total << endl;
		int Average = Total / dScore.size();

		//��ƽ���ָ�ֵ��ѡ��
		(vpBegin + i)->m_Score = Average;

		//��Ϊÿ��ѡ�ֵķ������Ǵ���dScore���deque�����У�����ÿһ��ѡ�ֵ�ƽ���ּ������Ҫ��dScore�������
		dScore.clear();
	}
	//���ѡ�ֵ����
	printPerson(vp);
}


int main()
{
	ScoretheCompetition();
}