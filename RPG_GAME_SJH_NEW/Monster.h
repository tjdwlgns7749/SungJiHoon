#pragma once
#include "Character.h"

class Monster : public Character
{
private:

public:

	void LevelUp(int Attack, int HP);
	void Hit(int Damage);
	int _Attack();
	void MosterSetData(string Name,int AD,int MaxHP,int MaxEXP,int GetEXP,int Level,int Gold,int EXP,int HP);
	void ShowInfo(int Width, int Height);
	Monster FightMonsterSet();
	SELECTATTACK SelectAttack();

	inline string NameReturn() { return m_strName; }
	inline int AttackDamageReturn() { return m_iAttackDamage; }
	inline int MaxHPReturn() { return m_iMaxHP; }
	inline int MaxEXPReturn() { return m_iMaxEXP; }
	inline int GetEXPReturn() { return m_iGetEXP; }
	inline int LevelReturn() { return m_iLevel; }
	inline int GoldReturn() { return m_iGold; }
	inline int EXPreturn() { return m_iEXP; }
	inline int HPReturn() { return m_iHP; }


	Monster();
	~Monster();
};

