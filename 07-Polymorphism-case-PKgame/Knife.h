#pragma once
#include"Weapon.h"
#include<string>
#include<iostream>
using namespace std;

class Knife : public Weapon
{
public:
	//Knife的默认构造
	Knife();

	//获取基础伤害
	virtual int getBaseDamage();

	//获取吸血
	virtual int getSuckBlood();

	//获取是否定身
	virtual bool getHold();

	//获取是否暴击
	virtual bool getCrit();
};



