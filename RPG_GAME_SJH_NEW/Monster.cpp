#include "Monster.h"

Monster::Monster()
{
	srand(time(NULL));
}

void Monster::LevelUp(int Attack, int HP)
{
	m_iLevel++;
	m_iAttackDamage += Attack;
	m_iMaxHP += HP;
	m_iMaxEXP += m_iLevel * 10;
	m_iEXP = 0;
}

SELECTATTACK Monster::SelectAttack()
{
	int RNum;

	RNum = rand() % 3 + 1;

	switch (RNum)
	{
	case SELECTATTACK_SCISSORS:
		return SELECTATTACK_SCISSORS;
	case SELECTATTACK_ROCK:
		return SELECTATTACK_ROCK;
	case SELECTATTACK_PAPER:
		return SELECTATTACK_PAPER;
	}
}

void Monster::Hit(int Damage)
{
	m_iHP -= Damage;
}

int Monster::_Attack()
{
	return m_iAttackDamage;
}

Monster Monster::FightMonsterSet()
{
	Monster tmp;

	tmp.m_strName = m_strName;
	tmp.m_iAttackDamage = m_iAttackDamage;
	tmp.m_iMaxHP = m_iMaxHP;
	tmp.m_iMaxEXP = m_iMaxEXP;
	tmp.m_iGetEXP = m_iGetEXP;
	tmp.m_iLevel = m_iLevel;
	tmp.m_iGold = m_iGold;
	tmp.m_iEXP = m_iEXP;
	tmp.m_iHP = m_iHP;

	return tmp;
}

void Monster::ShowInfo(int Width, int Height)
{
	m_DrawManager.DrawMidText("=====" + m_strName + "(" + to_string(m_iLevel) + "Lv)======", Width, Height);
	m_DrawManager.DrawMidText("공격력 = " + to_string(m_iAttackDamage), Width - 9, Height + 1);
	m_DrawManager.DrawMidText("생명력 = " + to_string(m_iHP) + "/" + to_string(m_iMaxHP), Width + 9, Height + 1);
	m_DrawManager.DrawMidText("경험치 = " + to_string(m_iEXP) + "/" + to_string(m_iMaxEXP), Width - 8, Height + 2);
	m_DrawManager.DrawMidText("GetEXP : " + to_string(m_iGetEXP), Width + 7, Height + 2);
	m_DrawManager.DrawMidText("Gold = " + to_string(m_iGold), Width - 9, Height + 3);
}

void Monster::MosterSetData(string Name, int AD, int MaxHP, int MaxEXP, int GetEXP, int Level, int Gold, int EXP, int HP)
{
	m_strName = Name;
	m_iAttackDamage = AD;
	m_iMaxHP = MaxHP;
	m_iMaxEXP = MaxEXP;
	m_iGetEXP = GetEXP;
	m_iLevel = Level;
	m_iGold = Gold;
	m_iEXP = 0;
	m_iHP = HP;
}


Monster::~Monster()
{
}