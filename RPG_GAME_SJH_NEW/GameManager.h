#pragma once
#include "Shop.h"
#include "Mecro.h"
#include "MapDraw.h"
#include "Player.h"
#include "Monster.h"


enum RESULT
{
	RESULT_WIN=1,
	RESULT_DEFEAT,
	RESULT_DRAW
};

enum GAMEMENU
{
	GAMEMENU_DONGEON=1,
	GAMEMENU_PLAYERINFO,
	GAMEMENU_MONSTERINFO,
	GAMEMENU_WEAPONSHOP,
	GAMEMENU_SAVE,
	GAMEMENU_EXIT
};

enum STARTMENU
{
	STARTMENU_NEWGAME=1,
	STARTMENU_LOADGAME,
	STARTMENU_EXIT
};

class GameManager
{
private:
	Shop m_Shop;
	MapDraw m_DrawManager;
	Player m_Player;
	vector<Monster>m_MonsterList;
	int m_iMonsterCount;
	bool m_bGameOver;
	bool m_bGameOver2;

public:
	void StartMenu();
	void StartMenuDraw();

	bool DefaultLoad();
	bool MonsterDefaultLoad(string FileName);

	void GameMenu();
	void GameMenuDraw();

	void DongeonMenu();
	void DongeonMenuDraw();

	void InDongeon(int floor);
	void InDongeonDraw(int floor);

	void FightCheck(SELECTATTACK P1, SELECTATTACK M1, Monster& FightMonster);
	void ResultDraw(RESULT Result);
	void AttackSelectDraw(SELECTATTACK P1, SELECTATTACK M1);
	void FightExit(RESULT result, int floor);

	void Save();
	void SaveList(int Width, int Height);
	bool FileCheckPlayer(int Count);
	bool FileCheckMonster(int Count);

	void MonsterSave(int Number,string FileName);

	bool Load();
	bool DataLoad(int Number);

	void MonsterLoad(string FileName);

	GameManager();
	~GameManager();

};

