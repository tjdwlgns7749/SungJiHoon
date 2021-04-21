#include "Weapon.h"

void Weapon::WeaponSetting(string Kind, string Name, int AD, int Price)
{
	m_strWeaponKind = Kind;
	m_strWeaponName = Name;
	m_iWeaponDamege = AD;
	m_iPrice = Price;
}

int Weapon::Attack(int PlayerDamage)
{
	return 0;
}

void Weapon::WeaponInfo(int i)
{
	m_DrawManager.DrawMidText("가격 :", WIDTH * 0.7f, i);
	cout << m_iPrice;
	m_DrawManager.DrawMidText("무기타입 : ", WIDTH * 1.3f, i);
	cout << m_strWeaponKind;
	m_DrawManager.DrawMidText("무기이름 : ", WIDTH * 0.6f, i + 1);
	cout << m_strWeaponName;
	m_DrawManager.DrawMidText("공격력 : ", WIDTH * 1.3f, i + 1);
	cout << m_iWeaponDamege;
}

