#pragma once
#include "Character.h"
#include "Weapon.h"

class Player : public Character
{
private:
	Weapon* m_pWeapon;
	WEAPONKIND m_eWeapon;

public:

	void DataLoad(string FileName);
	void DataSave(int Number, string FileName);
	void LevelUp(int Attack, int HP);
	void Hit(int Damage);
	int _Attack();
	bool PlayerDefaultLoad(string Name,string FileName);
	void ShowInfo(int Width, int Height);
	SELECTATTACK SelectAttack();
	void GetWeapon(Weapon* weapon);
	void WeaponKindSelect(string WeaponKind);
	void Penalty();
	
	inline int GoldReturn()
	{
		return m_iGold;
	}
	inline void Heal()
	{
		m_iHP = m_iMaxHP;
	}

	Player();
	~Player();

};

