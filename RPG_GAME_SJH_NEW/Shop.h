#pragma once
#include "Mecro.h"
#include "Weapon.h"
#include "Player.h"
#include "MapDraw.h"

class Shop
{
private:
	vector<Weapon*>m_WeaponList;
	vector<Weapon*>m_tmpList;

	MapDraw m_DrawManager;
public:
	void WeaponListLoad();

	void ShopMenu(Player *Player);
	void ShopMenuDraw();

	void tmpListSetting(string WeaponKind);

	void ShopList(Player *Player);

	Shop();
	~Shop();
};

