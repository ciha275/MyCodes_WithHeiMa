#pragma once
#include"Weapon.h"
#include"Monster.h"
#include<string>
#include<iostream>
using namespace std;

class Monster;//��������

class Hero
{
public:
	Hero();

	string m_Name;//����
	int m_Atk;//������
	int m_Def;//������
	int m_Hp;//Ѫ��
	Weapon* weapon;//����

	void EquipWeapon(Weapon* weapon);

	void Attack(Monster* monster);
};
