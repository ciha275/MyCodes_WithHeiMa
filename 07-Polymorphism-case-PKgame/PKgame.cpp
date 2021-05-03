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
	//��������
	Monster* monster = new Monster;
	//����Ӣ��
	Hero* hero = new Hero;
	//��������
	Weapon* knife = new Knife;
	Weapon* dragon = new DragonSword;

	//���û�ѡ������
	cout << "��ѡ������" << endl;
	cout << "1�����ֿ�ȭ" << endl;
	cout << "2��С��" << endl;
	cout << "3��������" << endl;

	int oper;
	cin >> oper;
	switch (oper)
	{
	case 1:
		cout << "��ѡ���˿���" << endl;
		break;
	case 2:
		hero->EquipWeapon(knife);
		break;
	case 3:
		hero->EquipWeapon(dragon);
		break;
	}

	getchar();//���뻺�����и��س������ȡһ��
	
	int  round = 1;

	while (true)
	{
		getchar();
		system("cls");

		cout << "--------��ǰ�ǵ� " << round << " �غϿ�ʼ-------" << endl;
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

		cout << "Ӣ�ۣ� " << hero->m_Name << " Ѫ���� "<< hero->m_Hp << endl;
		cout << "��� " << monster->m_Name << " Ѫ���� " << monster->m_Hp << endl;

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


