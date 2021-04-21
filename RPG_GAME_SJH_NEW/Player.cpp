#include "Player.h"

Player::Player()
{
	m_eWeapon = WEAPONKIND_DEFAULT;
}

void Player::DataLoad(string FileName)
{
	ifstream load;
	int eWeapon;
	string Kind, Name;
	int Price, Damage;
	load.open(FileName);

	load >> m_strName;
	load >> m_iAttackDamage;
	load >> m_iMaxHP;
	load >> m_iMaxEXP;
	load >> m_iGetEXP;
	load >> m_iLevel;
	load >> m_iGold;
	load >> m_iEXP;
	load >> m_iHP;
	load >> eWeapon;
	if (eWeapon != WEAPONKIND_DEFAULT)
	{
		Weapon* tmp;

		load >> Kind;
		load >> Name;
		load >> Price;
		load >> Damage;

		if (Kind == "Dagger")
		{
			tmp = new Dagger;
			tmp->WeaponSetting(Kind, Name, Damage, Price);
			m_pWeapon = tmp;
		}
		else if (Kind == "Gun")
		{
			tmp = new Gun;
			tmp->WeaponSetting(Kind, Name, Damage, Price);
			m_pWeapon = tmp;
		}
		else if (Kind == "Sword")
		{
			tmp = new Sword;
			tmp->WeaponSetting(Kind, Name, Damage, Price);
			m_pWeapon = tmp;
		}
		else if (Kind == "Wand")
		{
			tmp = new Wand;
			tmp->WeaponSetting(Kind, Name, Damage, Price);
			m_pWeapon = tmp;
		}
		else if (Kind == "Hammer")
		{
			tmp = new Hammer;
			tmp->WeaponSetting(Kind, Name, Damage, Price);
			m_pWeapon = tmp;
		}
	}
	load.close();
	WeaponKindSelect(Kind);
}

void Player::DataSave(int Number, string FileName)
{
	ofstream save;
	save.open(FileName + to_string(Number) + ".txt");
	save << m_strName << " ";
	save << m_iAttackDamage << " ";
	save << m_iMaxHP << " ";
	save << m_iMaxEXP << " ";
	save << m_iGetEXP << " ";
	save << m_iLevel << " ";
	save << m_iGold << " ";
	save << m_iEXP << " ";
	save << m_iHP << endl;
	save << m_eWeapon << " ";
	if (m_eWeapon != WEAPONKIND_DEFAULT)
	{
		save << m_pWeapon->WeaponKindReturn() << " ";
		save << m_pWeapon->WeaponNameReturn() << " ";
		save << m_pWeapon->WeaponAttackReturn() << " ";
		save << m_pWeapon->WeaponPriceReturn() << " ";
	}
	save.close();
}


void Player::Penalty()
{
	m_iEXP = 0;
	m_iGetEXP = 0;
}

void Player::LevelUp(int Attack,int HP)
{
	m_iLevel++;
	m_iAttackDamage += Attack;
	m_iMaxHP += HP;
	m_iMaxEXP += m_iLevel * 10;
	m_iEXP = 0;
}

int Player::_Attack()
{
	if (m_eWeapon != WEAPONKIND_DEFAULT)
		return m_pWeapon->Attack(m_iAttackDamage);
	else
		return m_iAttackDamage;
}

void Player::Hit(int Damage)
{
	m_iHP -= Damage;
}

void Player::WeaponKindSelect(string WeaponKind)
{
	if (WeaponKind == "Dagger")
		m_eWeapon = WEAPONKIND_DAGGER;
	else if (WeaponKind == "Gun")
		m_eWeapon = WEAPONKIND_GUN;
	else if (WeaponKind == "Swrod")
		m_eWeapon = WEAPONKIND_SWROD;
	else if (WeaponKind == "Wand")
		m_eWeapon = WEAPONKIND_WAND;
	else if (WeaponKind == "Bow")
		m_eWeapon = WEAPONKIND_BOW;
	else if (WeaponKind == "Hammer")
		m_eWeapon = WEAPONKIND_HAMMER;
}

void Player::GetWeapon(Weapon* weapon)
{
	m_pWeapon = weapon;
	WeaponKindSelect(m_pWeapon->WeaponKindReturn());
	m_iGold -= m_pWeapon->WeaponPriceReturn();
}

SELECTATTACK Player::SelectAttack()
{
	char ch;

	if (kbhit())
	{
		ch = getch();

		switch (ch)
		{
		case SCISSORS:
			return SELECTATTACK_SCISSORS;
		case ROCK:
			return SELECTATTACK_ROCK;
		case PAPER:
			return SELECTATTACK_PAPER;
		}
	}
}

void Player::ShowInfo(int Width, int Height)
{
	YELLOW
	m_DrawManager.DrawMidText("=====" + m_strName + "(" + to_string(m_iLevel) + "Lv)======", Width, Height);
	m_DrawManager.DrawMidText("공격력 = " + to_string(m_iAttackDamage), Width - 9, Height + 1);
	m_DrawManager.DrawMidText("생명력 = " + to_string(m_iHP) + "/" + to_string(m_iMaxHP), Width + 9, Height + 1);
	m_DrawManager.DrawMidText("경험치 = " + to_string(m_iEXP) + "/" + to_string(m_iMaxEXP), Width - 8, Height + 2);
	m_DrawManager.DrawMidText("GetEXP : " + to_string(m_iGetEXP), Width + 7, Height + 2);
	m_DrawManager.DrawMidText("Gold = " + to_string(m_iGold), Width - 9, Height + 3);
	if (m_eWeapon != WEAPONKIND_DEFAULT)
	{
		m_DrawManager.DrawMidText("무기타입 : " + m_pWeapon->WeaponKindReturn(), Width - 12, Height + 4);
		m_DrawManager.DrawMidText("무기 이름" + m_pWeapon->WeaponNameReturn(), Width + 8, Height + 4);
		m_DrawManager.DrawMidText("공격력 : " + to_string(m_pWeapon->WeaponAttackReturn()), Width - 12, Height + 5);
	}
	ORIGINAL
}

bool Player::PlayerDefaultLoad(string Name,string FileName)
{
	ifstream Load;


	Load.open(FileName);

	if (Load.is_open())
	{
		m_strName = Name;

		while (!Load.eof())
		{
			Load >> m_iAttackDamage;
			Load >> m_iMaxHP;
			Load >> m_iMaxEXP;
			Load >> m_iGetEXP;
			Load >> m_iLevel;
			Load >> m_iGold;
		}
		m_iEXP = 0;
		m_iHP = m_iMaxHP;
		m_eWeapon = WEAPONKIND_DEFAULT;

		return true;
	}
	else
		return false;
}

Player::~Player()
{
}