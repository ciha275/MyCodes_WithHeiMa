#include<iostream>
#include<string>
#include"Hero.h"
#include"Monster.h"
#include"Weapon.h"
#include"Knife.h"
#include"DragonSword.h"
#include<ctime>
using namespace std;
#pragma warning (disable: 4996)

void play()
{
	//创建怪物
	Monster* monster = new Monster;
	//创建英雄
	Hero* hero = new Hero;
	//创建武器
	Weapon* knife = new Knife;
	Weapon* dragon = new DragonSword;

	//让用户选择武器
	cout << "请选择武器" << endl;
	cout << "1、赤手空拳" << endl;
	cout << "2、小刀" << endl;
	cout << "3、屠龙刀" << endl;

	int oper;
	cin >> oper;
	switch (oper)
	{
	case 1:
		cout << "你选择了空手" << endl;
		break;
	case 2:
		hero->EquipWeapon(knife);
		break;
	case 3:
		hero->EquipWeapon(dragon);
		break;
	}

	getchar();//输入缓冲区有个回车，多获取一次
	
	int  round = 1;

	while (true)
	{
		getchar();
		system("cls");

		cout << "--------当前是第 " << round << " 回合开始-------" << endl;
		/*if (hero->m_Hp <= 0)
		{
			cout << "hero: " << hero->m_Name << " dead,OVER" << endl;
			break;
		}*/

		hero->Attack(monster);

		if (monster->m_Hp <= 0)
		{
			cout << "monster: " << monster->m_Name << " dead,PASS" << endl;
			break;
		}
		
		monster->Attack(hero);

		if (hero->m_Hp <= 0)
		{
			cout << "hero: " << hero->m_Name << " dead,OVER" << endl;
			break;
		}

		cout << "英雄： " << hero->m_Name << " 血量： "<< hero->m_Hp << endl;
		cout << "怪物： " << monster->m_Name << " 血量： " << monster->m_Hp << endl;

		round++;
	}

	delete monster;
	delete hero;
	delete dragon;
	delete knife;


}

int main()
{
	srand((unsigned int)time(NULL));

	play();

	system("pause");
}


