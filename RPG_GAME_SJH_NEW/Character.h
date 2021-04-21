#pragma once
#include "Mecro.h"
#include "MapDraw.h"

#define SCISSORS '1'
#define ROCK '2'
#define PAPER '3'

enum SELECTATTACK
{
	SELECTATTACK_SCISSORS = 1,
	SELECTATTACK_ROCK,
	SELECTATTACK_PAPER,
	SELECTATTACK_DEFAULT
};

class Character
{
protected:
	string m_strName;
	int m_iAttackDamage;
	int m_iMaxHP;
	int m_iMaxEXP;
	int m_iGetEXP;
	int m_iLevel;
	int m_iGold;
	int m_iEXP;
	int m_iHP;

	MapDraw m_DrawManager;

public:
	void GetBooty(int exp,int gold,int GetEXP);
	bool LevelUpCheck();

	virtual int _Attack();
	virtual void Hit(int Damage);
	virtual void ShowInfo(int Width, int Height);
	virtual SELECTATTACK SelectAttack();
	virtual void LevelUp(int Attack, int HP);

	inline string NameReturn() { return m_strName; }
	inline int HPreturn() { return m_iHP; }
	inline int GetEXPretrun() { return m_iGetEXP; }
	inline int GetGoldReturn() { return m_iGold; }

	Character();
	~Character();
};

