#include "Character.h"

Character::Character()
{

}

void Character::LevelUp(int Attack,int HP)
{
}

void Character::ShowInfo(int Width,int Height)
{
}

bool Character::LevelUpCheck()
{
	if (m_iEXP != m_iMaxEXP)
		return false;
	else
		return true;
}

SELECTATTACK Character::SelectAttack()
{
	return SELECTATTACK_DEFAULT;
}

void Character::GetBooty(int exp, int gold,int GetEXP)
{
	m_iEXP += exp;
	m_iGold += gold;
	m_iGetEXP += GetEXP;
}

void Character::Hit(int Damage)
{

}
int Character::_Attack()
{
	return 0;
}

Character::~Character()
{

}