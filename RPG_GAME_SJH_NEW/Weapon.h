#pragma once
#include "Mecro.h"
#include "MapDraw.h"

enum WEAPONKIND
{
	WEAPONKIND_DAGGER=1,
	WEAPONKIND_GUN,
	WEAPONKIND_SWROD,
	WEAPONKIND_WAND,
	WEAPONKIND_BOW,
	WEAPONKIND_HAMMER,
	WEAPONKIND_DEFAULT
};

class Weapon
{
protected:
	string m_strWeaponName;
	string m_strWeaponKind;
	int m_iWeaponDamege;
	int m_iPrice;

	MapDraw m_DrawManager;
public:
	void WeaponSetting(string Kind,string Name,int AD,int Price);
	void WeaponInfo(int i);

	virtual int Attack(int PlayerDamage);

	inline string WeaponKindReturn()
	{
		return m_strWeaponKind;
	}
	inline int WeaponPriceReturn()
	{
		return m_iPrice;
	}
	inline string WeaponNameReturn()
	{
		return m_strWeaponName;
	}
	inline int WeaponAttackReturn()
	{
		return m_iWeaponDamege;
	}
};


class Dagger : public Weapon
{
public :
	int Attack(int PlayerDamage)
	{
		m_DrawManager.DrawMidText("                              ", WIDTH, HEIGHT * 0.46f + 1);
		int Demage = PlayerDamage + m_iWeaponDamege;
		if (rand() % 100 <= 40)
		{
			m_DrawManager.DrawMidText("헤드샷 (Damage : " + to_string(Demage * 2) + ")", WIDTH, HEIGHT * 0.46f + 1);
			getch();
			return Demage * 2;
		}
		else
			return Demage;
	}
};

class Gun : public Weapon
{
public:
	int Attack(int PlayerDamage)
	{
		m_DrawManager.DrawMidText("                              ", WIDTH, HEIGHT * 0.46f + 1);
		int Demage = PlayerDamage + m_iWeaponDamege;
		if (rand() % 100 <= 40)
		{
			m_DrawManager.DrawMidText("헤드샷 (Damage : " + to_string(Demage * 2) + ")", WIDTH, HEIGHT * 0.46f + 1);
			getch();
			return Demage * 2;
		}
		else
			return Demage;
	}
};

class Sword : public Weapon
{
public:
	int Attack(int PlayerDamage)
	{
		m_DrawManager.DrawMidText("                              ", WIDTH, HEIGHT * 0.46f + 1);
		int Demage = PlayerDamage + m_iWeaponDamege;
		if (rand() % 100 <= 50)
		{
			m_DrawManager.DrawMidText("검 기 (Damage : " + to_string(Demage * 2) + ")", WIDTH, HEIGHT * 0.46f + 1);
			getch();
			return Demage * 2;
		}
		else
			return Demage;
	};
};
class Wand : public Weapon
{
public:
	int Attack(int PlayerDamage)
	{
		m_DrawManager.DrawMidText("                              ", WIDTH, HEIGHT * 0.46f + 1);
		int Demage = PlayerDamage + m_iWeaponDamege;
		if (rand() % 100 <= 1)
		{
			m_DrawManager.DrawMidText("즉 사(Damage : " + to_string(Demage * 2500) + ")", WIDTH, HEIGHT * 0.46f + 1);
			getch();
			return Demage * 2500;
		}
		else
			return Demage;
	}
};

class Bow : public Weapon
{
public:
	int Attack(int PlayerDamage)
	{
		m_DrawManager.DrawMidText("                              ", WIDTH, HEIGHT * 0.46f + 1);
		int Demage = PlayerDamage + m_iWeaponDamege;
		if (rand() % 100 <= 10)
		{
			m_DrawManager.DrawMidText("헤드샷!!(Damage : " + to_string(Demage * 10) + ")", WIDTH, HEIGHT * 0.46f + 1);
			getch();
			return Demage * 10;
		}
		else
			return Demage;
	}
};

class Hammer : public Weapon
{
public:
	int Attack(int PlayerDamage)
	{
		m_DrawManager.DrawMidText("                              ", WIDTH, HEIGHT * 0.46f + 1);
		int Demage = PlayerDamage + m_iWeaponDamege;
		if (rand() % 100 <= 60)
		{
			m_DrawManager.DrawMidText("대지 가르기 (Damage : " + to_string(Demage * 1.5) + ")", WIDTH, HEIGHT * 0.46f + 1);
			getch();
			return Demage * 1.5f;
		}
		else
			return Demage;
	}
};
	
