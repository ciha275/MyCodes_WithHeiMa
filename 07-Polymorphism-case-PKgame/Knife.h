#pragma once
#include"Weapon.h"
#include<string>
#include<iostream>
using namespace std;

class Knife : public Weapon
{
public:
	//Knife��Ĭ�Ϲ���
	Knife();

	//��ȡ�����˺�
	virtual int getBaseDamage();

	//��ȡ��Ѫ
	virtual int getSuckBlood();

	//��ȡ�Ƿ���
	virtual bool getHold();

	//��ȡ�Ƿ񱩻�
	virtual bool getCrit();
};



