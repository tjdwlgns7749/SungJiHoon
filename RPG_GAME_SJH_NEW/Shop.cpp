#include "Shop.h"

Shop::Shop()
{

}

void Shop::ShopList(Player *Player)
{
	int Select, Height, i = 0, Page = 0, Count;
	bool Page_Check;

	Height = HEIGHT * 0.1 - 1;
	while (1)
	{
		Count = 0;
		m_DrawManager.BoxErase(WIDTH, HEIGHT);
		m_DrawManager.DrawMidText("보유 Gold : ", WIDTH, Height);
		cout << Player->GoldReturn();

		for (; i < m_tmpList.size() && i < (Page + 1) * 5; i++)
		{
			if (i < (Page + 1) * 5)
			{
				m_tmpList[i]->WeaponInfo(Height + 2 + 3 * Count);
				Count++;
			}
		}
		if (Count + m_tmpList.size() % 5 > (Page + 1) * 5)
			Page_Check = true;
		else
			Page_Check = false;
		m_DrawManager.DrawMidText("이전 페이지", WIDTH, Height + 3 * (Count + 1) - 1);
		m_DrawManager.DrawMidText("다음 페이지", WIDTH, Height + 3 * (Count + 2) - 1);
		m_DrawManager.DrawMidText("나가기", WIDTH, Height + 3 * (Count + 3) - 1);

		Select = m_DrawManager.MenuSelectCursor(Count + 3, 3, WIDTH / 4, Height + 2);

		if (Count + 3 == Select)
			return;
		else if (Count + 1 == Select && Page != 0)
		{
			Page--;
			i = i - 5 - m_tmpList.size() % 5;
		}
		else if (Count + 1 == Select && Page == 0)
			i = 0;
		else if (Count + 2 == Select && Page_Check)
			Page++;
		else if (Count + 2 == Select && !Page_Check)
		{
			if (m_tmpList.size() % 5 == 0)
				i -= 5;
			else
				i -= m_tmpList.size() % 5;
		}
		else if (Select >= 0 && Select <= Count)
		{
			if (Player->GoldReturn() >= m_tmpList[Select + Page * 5 - 1]->WeaponPriceReturn())
				Player->GetWeapon(m_tmpList[Select + Page * 5 - 1]);

			if (Page_Check)
				i -= 5;
			else
			{
				if (m_tmpList.size() % 5 == 0)
					i -= 5;
				else
					i -= m_tmpList.size() % 5;
			}
		}
	}
}

void Shop::tmpListSetting(string WeaponKind)
{
	Weapon *tmp;

	for (int i = 0; i < m_WeaponList.size(); i++)
	{
		if (m_WeaponList[i]->WeaponKindReturn() == WeaponKind)
		{
			tmp = m_WeaponList[i];
			m_tmpList.push_back(tmp);
		}
	}
}

void Shop::ShopMenuDraw()
{
	m_DrawManager.DrawMidText("♧ ♣ S H O P ♣ ♧", WIDTH, HEIGHT*0.3);
	m_DrawManager.DrawMidText("Dagger", WIDTH, HEIGHT*0.4 - 1);
	m_DrawManager.DrawMidText("Gun", WIDTH, HEIGHT*0.5 - 2);
	m_DrawManager.DrawMidText("Sword", WIDTH, HEIGHT*0.6 - 3);
	m_DrawManager.DrawMidText("Wand", WIDTH, HEIGHT*0.7 - 4);
	m_DrawManager.DrawMidText("Bow", WIDTH, HEIGHT*0.8 - 5);
	m_DrawManager.DrawMidText("Hammer", WIDTH, HEIGHT*0.9 - 6);
	m_DrawManager.DrawMidText("돌아가기", WIDTH, HEIGHT - 7);
}

void Shop::ShopMenu(Player *Player)
{
	int Select;

	while (1)
	{
		m_DrawManager.BoxErase(WIDTH,HEIGHT);
		ShopMenuDraw();

		switch (Select = m_DrawManager.MenuSelectCursor(7, 2, WIDTH*0.4, HEIGHT*0.4 - 1))
		{
		case WEAPONKIND_DAGGER:
			tmpListSetting("Dagger");
			break;
		case WEAPONKIND_GUN:
			tmpListSetting("Gun");
			break;
		case WEAPONKIND_SWROD:
			tmpListSetting("Sword");
			break;
		case WEAPONKIND_WAND:
			tmpListSetting("Wand");
			break;
		case WEAPONKIND_BOW:
			tmpListSetting("Bow");
			break;
		case WEAPONKIND_HAMMER:
			tmpListSetting("Hammer");
			break;
		case WEAPONKIND_DEFAULT:
			return;
		}
		ShopList(Player);
		m_tmpList.clear();
	}
}

void Shop::WeaponListLoad()
{
	ifstream Load;
	string Kind, Name;
	int AD, Price;

	Load.open("WeaponList.txt");

	if (Load.is_open())
	{
		while (!Load.eof())
		{
			Load >> Kind;
			Load >> Name;
			Load >> AD;
			Load >> Price;

			if (Kind == "Bow")
			{
				Bow *tmp;
				tmp = new Bow;
				(*tmp).WeaponSetting(Kind, Name, AD, Price);
				m_WeaponList.push_back(tmp);
			}
			else if (Kind == "Dagger")
			{
				Dagger *tmp;
				tmp = new Dagger;
				(*tmp).WeaponSetting(Kind, Name, AD, Price);
				m_WeaponList.push_back(tmp);
			}
			else if (Kind == "Gun")
			{
				Gun *tmp;
				tmp = new Gun;
				(*tmp).WeaponSetting(Kind, Name, AD, Price);
				m_WeaponList.push_back(tmp);
			}
			else if (Kind == "Sword")
			{
				Sword *tmp;
				tmp = new Sword;
				(*tmp).WeaponSetting(Kind, Name, AD, Price);
				m_WeaponList.push_back(tmp);
			}
			else if (Kind == "Wand")
			{
				Wand *tmp;
				tmp = new Wand;
				(*tmp).WeaponSetting(Kind, Name, AD, Price);
				m_WeaponList.push_back(tmp);
			}
			else if (Kind == "Hammer")
			{
				Hammer *tmp;
				tmp = new Hammer;
				(*tmp).WeaponSetting(Kind, Name, AD, Price);
				m_WeaponList.push_back(tmp);
			}
		}
	}
	else
	{
		cout << "실패" << endl;
	}
}


Shop::~Shop()
{

}