#pragma once
#include"Weapon.h"
#include<string>
#include<iostream>
using namespace std;

class DragonSword : public Weapon
{
public:
	DragonSword();

	//获取基础伤害
	virtual int getBaseDamage();

	//获取吸血
	virtual int getSuckBlood();

	//获取是否定身
	virtual bool getHold();

	//获取是否暴击
	virtual bool getCrit();

	//吸血率 定身率 暴击率 
	int suckRate;
	int holdRate;
	int critRate;

	//传入概率判断是否触发
	bool isTriger(int rate);
};