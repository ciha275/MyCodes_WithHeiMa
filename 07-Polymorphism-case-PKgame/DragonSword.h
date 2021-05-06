#pragma once
#include"Weapon.h"
#include<string>
#include<iostream>
using namespace std;

class DragonSword : public Weapon
{
public:
	DragonSword();

	//��ȡ�����˺�
	virtual int getBaseDamage();

	//��ȡ��Ѫ
	virtual int getSuckBlood();

	//��ȡ�Ƿ���
	virtual bool getHold();

	//��ȡ�Ƿ񱩻�
	virtual bool getCrit();

	//��Ѫ�� ������ ������ 
	int suckRate;
	int holdRate;
	int critRate;

	//��������ж��Ƿ񴥷�
	bool isTriger(int rate);
};