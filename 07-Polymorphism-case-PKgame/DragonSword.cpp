#include"DragonSword.h"

DragonSword::DragonSword()
{
	this->m_BaseDamage = 20;
	this->WeapenName = "����";
	this->suckRate = 20;
	this->holdRate = 30;
	this->critRate = 35;
}

int DragonSword::getBaseDamage()
{
	return this->m_BaseDamage;
}

int DragonSword::getSuckBlood()
{
	if (isTriger(suckRate))
	{
		return this->m_BaseDamage * 0.5;
	}
	return 0;
}

bool DragonSword::getHold()
{
	if (isTriger(holdRate))
	{
		return true;
	}
	return false;
}

bool DragonSword::getCrit()
{
	if (isTriger(critRate))
	{
		return true;
	}
	return false;
}

bool DragonSword::isTriger(int rate)
{
	//ͨ��isTrigger�ж��Ƿ񴥷�
	//���0~100
	int num = rand() % 100 + 1;
	if (num < rate)
	{
		return true;
	}

	return false;
}
