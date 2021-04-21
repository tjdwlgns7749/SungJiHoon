#include "GameManager.h"

GameManager::GameManager()
{
	char buf[256];
	sprintf(buf, "mode con: lines=%d cols=%d", HEIGHT + 1, WIDTH * 2);
	system(buf);
	m_iMonsterCount = 0;
	m_bGameOver = false;
	m_bGameOver2 = false;
	srand(time(NULL));
}

bool GameManager::FileCheckPlayer(int Count)
{
	ifstream load;
	load.open("SavePlayer" + to_string(Count) + ".txt");
	if (load.is_open())
		return true;
	else
		return false;
}

bool GameManager::FileCheckMonster(int Count)
{
	ifstream load;
	load.open("SavePlayer" + to_string(Count) + ".txt");
	if (load.is_open())
		return true;
	else
		return false;
}

void GameManager::SaveList(int Width, int Height)
{
	string OX;

	m_DrawManager.BoxErase(WIDTH, HEIGHT);
	for (int i = 0;i < 10;i++)
	{
		if (FileCheckPlayer(i + 1) && FileCheckMonster(i + 1))
			OX = "o";
		else
			OX = "X";
		m_DrawManager.DrawPoint(to_string(i + 1) + "번 슬롯 : <파일여부 :" + OX + ">", Width, Height + 2 * i);
	}
	m_DrawManager.DrawPoint(to_string(10 + 1) + ". 돌아가기", Width, Height + 2 * 10);

}

void GameManager::MonsterSave(int Number,string FileName)
{
	ofstream save;
	
	save.open(FileName + to_string(Number) + ".txt");
	save << m_MonsterList.size() << endl;
	for (int i = 0;i < m_MonsterList.size();i++)
	{
		save << m_MonsterList[i].NameReturn() << " ";
		save << m_MonsterList[i].AttackDamageReturn() << " ";
		save << m_MonsterList[i].MaxHPReturn() << " ";
		save << m_MonsterList[i].MaxEXPReturn() << " ";
		save << m_MonsterList[i].GetEXPReturn() << " ";
		save << m_MonsterList[i].LevelReturn() << " ";
		save << m_MonsterList[i].GoldReturn() << " ";
		save << m_MonsterList[i].EXPreturn() << " ";
		save << m_MonsterList[i].HPReturn() << endl;
	}
	save.close();
}

void GameManager::Save()
{
	int Width = WIDTH / 3, Height = HEIGHT * 0.1f + 2, Select;
	string File;

	SaveList(Width, Height);
	Select = m_DrawManager.MenuSelectCursor(11, 2, Width - 2, Height);
	File = "SavePlayer";
	m_Player.DataSave(Select, File);

	File = "SaveMonster";
	MonsterSave(Select,File);
}

void GameManager::AttackSelectDraw(SELECTATTACK P1, SELECTATTACK M1)
{
	YELLOW
	if (P1 == SELECTATTACK_SCISSORS)
	{
		m_DrawManager.DrawMidText("가위", WIDTH, HEIGHT * 0.4f);
	}
	else if (P1 == SELECTATTACK_ROCK)
	{
		m_DrawManager.DrawMidText("바위", WIDTH, HEIGHT * 0.4f);
	}
	else
	{
		m_DrawManager.DrawMidText("보", WIDTH, HEIGHT * 0.4f);
	}
	ORIGINAL

	if (M1 == SELECTATTACK_SCISSORS)
	{
		m_DrawManager.DrawMidText("가위", WIDTH, HEIGHT * 0.6f + 1);
	}
	else if (M1 == SELECTATTACK_ROCK)
	{
		m_DrawManager.DrawMidText("바위", WIDTH, HEIGHT * 0.6f + 1);
	}
	else
	{
		m_DrawManager.DrawMidText("보", WIDTH, HEIGHT * 0.6f + 1);
	}
}

void GameManager::ResultDraw(RESULT Result)
{
	m_DrawManager.DrawMidText("             ", WIDTH, HEIGHT * 0.4f + 1);
	m_DrawManager.DrawMidText("             ", WIDTH, HEIGHT * 0.6f);
	RED
	if (Result == RESULT_WIN)
	{
		m_DrawManager.DrawMidText("Win", WIDTH, HEIGHT * 0.4f + 1);
		m_DrawManager.DrawMidText("Lose", WIDTH, HEIGHT * 0.6f);
	}
	else if (Result == RESULT_DEFEAT)
	{
		m_DrawManager.DrawMidText("Lose", WIDTH, HEIGHT * 0.4f + 1);
		m_DrawManager.DrawMidText("Win", WIDTH, HEIGHT * 0.6f);
	}
	else
	{
		m_DrawManager.DrawMidText("Draw", WIDTH, HEIGHT * 0.4f + 1);
		m_DrawManager.DrawMidText("Draw", WIDTH, HEIGHT * 0.6f);
	}
	ORIGINAL
}

void GameManager::FightCheck(SELECTATTACK P1, SELECTATTACK M1, Monster& FightMonster)
{
	int Damage;

	if (P1 == SELECTATTACK_SCISSORS)
	{
		AttackSelectDraw(P1, M1);

		if (M1 == SELECTATTACK_PAPER)
		{
			ResultDraw(RESULT_WIN);
			Damage = m_Player._Attack();
			FightMonster.Hit(Damage);
			FightMonster.ShowInfo(WIDTH, HEIGHT * 0.8);
		}
		else if (M1 == SELECTATTACK_ROCK)
		{
			ResultDraw(RESULT_DEFEAT);
			Damage = FightMonster._Attack();
			m_Player.Hit(Damage);
			m_Player.ShowInfo(WIDTH, HEIGHT * 0.1);
		}
		else
		{
			ResultDraw(RESULT_DRAW);
		}
	}
	else if (P1 == SELECTATTACK_ROCK)
	{
		AttackSelectDraw(P1, M1);

		if (M1 == SELECTATTACK_SCISSORS)
		{
			ResultDraw(RESULT_WIN);
			Damage = m_Player._Attack();
			FightMonster.Hit(Damage);
			FightMonster.ShowInfo(WIDTH, HEIGHT * 0.8);
		}
		else if (M1 == SELECTATTACK_PAPER)
		{
			ResultDraw(RESULT_DEFEAT);
			Damage = FightMonster._Attack();
			m_Player.Hit(Damage);
			m_Player.ShowInfo(WIDTH, HEIGHT * 0.1);
		}
		else
		{
			ResultDraw(RESULT_DRAW);
		}
	}
	else if (P1 == SELECTATTACK_PAPER)
	{
		AttackSelectDraw(P1, M1);

		if (M1 == SELECTATTACK_ROCK)
		{
		
			ResultDraw(RESULT_WIN);
			Damage = m_Player._Attack();
			FightMonster.Hit(Damage);
			FightMonster.ShowInfo(WIDTH, HEIGHT * 0.8);
		}
		else if (M1 == SELECTATTACK_SCISSORS)
		{
			ResultDraw(RESULT_DEFEAT);
			Damage = FightMonster._Attack();
			m_Player.Hit(Damage);
			m_Player.ShowInfo(WIDTH, HEIGHT * 0.1);
		}
		else
		{
			ResultDraw(RESULT_DRAW);
		}
	}
}

void GameManager::InDongeonDraw(int floor)
{
	m_DrawManager.BoxErase(WIDTH, HEIGHT);
	m_Player.ShowInfo(WIDTH, HEIGHT * 0.1);
	m_MonsterList[floor].ShowInfo(WIDTH, HEIGHT * 0.8);
	YELLOW
	m_DrawManager.DrawMidText("가위 : 1 바위 : 2 보 : 3", WIDTH, HEIGHT * 0.3);
	RED
	m_DrawManager.DrawMidText("--------------------------vs--------------------------",WIDTH, HEIGHT * 0.5);
	ORIGINAL;
}

void GameManager::FightExit(RESULT result, int floor)
{
	m_DrawManager.BoxErase(WIDTH, HEIGHT);
	if (result == RESULT_WIN)
	{
		RED
		m_DrawManager.DrawMidText(m_Player.NameReturn() + " 승리!!", WIDTH, HEIGHT * 0.3);
		m_DrawManager.DrawMidText(m_Player.NameReturn() + "가 경험치 " + to_string(m_MonsterList[floor].GetEXPretrun()) + "를 얻었습니다.", WIDTH, HEIGHT * 0.4);
		ORIGINAL
		getch();
		m_Player.GetBooty(m_MonsterList[floor].GetEXPretrun(), m_MonsterList[floor].GetGoldReturn(),m_MonsterList[floor].GetEXPretrun());
		if (m_Player.LevelUpCheck())
		{
			int RAttack,RHP;
			RAttack = rand() % 4;
			RHP = rand() % 10;

			m_Player.LevelUp(RAttack, RHP);

			m_DrawManager.BoxErase(WIDTH, HEIGHT);

			PUPPLE
			m_DrawManager.DrawMidText(m_Player.NameReturn(), WIDTH * 0.9, HEIGHT * 0.3);
			cout << "레벨 업 ! ";
			m_DrawManager.DrawMidText("공격력 : ", WIDTH * 0.9, HEIGHT * 0.4);
			cout << RAttack << "증가 ! ";
			m_DrawManager.DrawMidText("생명력 : ", WIDTH * 0.9, HEIGHT * 0.5);
			cout << RHP << "증가 ! ";
			ORIGINAL
			getch();
		}
	}
	else if(result == RESULT_DEFEAT)
	{
		RED
		m_DrawManager.DrawMidText(m_MonsterList[floor].NameReturn() + " 승리!!", WIDTH, HEIGHT * 0.3);
		m_DrawManager.DrawMidText(m_MonsterList[floor].NameReturn() + "가 경험치 " + to_string(m_Player.GetEXPretrun()) + "를 얻었습니다.", WIDTH, HEIGHT * 0.4);
		ORIGINAL
		getch();
		m_MonsterList[floor].GetBooty(m_Player.GetEXPretrun(), m_Player.GetGoldReturn(),m_Player.GetEXPretrun());
		if (m_MonsterList[floor].LevelUpCheck())
		{
			int RAttack, RHP;
			RAttack = rand() % 4;
			RHP = rand() % 10;

			m_MonsterList[floor].LevelUp(RAttack, RHP);

			m_DrawManager.BoxErase(WIDTH, HEIGHT);

			PUPPLE
				m_DrawManager.DrawMidText(m_MonsterList[floor].NameReturn(), WIDTH * 0.9, HEIGHT * 0.3);
			cout << "레벨 업 ! ";
			m_DrawManager.DrawMidText("공격력 : ", WIDTH * 0.9, HEIGHT * 0.4);
			cout << RAttack << "증가 ! ";
			m_DrawManager.DrawMidText("생명력 : ", WIDTH * 0.9, HEIGHT * 0.5);
			cout << RHP << "증가 ! ";
			ORIGINAL
			getch();
		}
		if (m_Player.GetEXPretrun() == 0)
		{
			m_bGameOver = true;
			m_bGameOver2 = true;
			m_MonsterList.clear();
		}
		m_Player.Penalty();
	}
	m_Player.Heal();
}

void GameManager::InDongeon(int floor)
{
	bool PlayerLife = false, MonsterLife = false;
	Monster FightMonster;
	SELECTATTACK Player, Monster;

	InDongeonDraw(floor);

	FightMonster = m_MonsterList[floor].FightMonsterSet();
	
	while (!PlayerLife && !MonsterLife)
	{
		Player = m_Player.SelectAttack();
		Monster = m_MonsterList[floor].SelectAttack();
		FightCheck(Player, Monster, FightMonster);
		if (m_Player.HPreturn() <= 0)
		{
			PlayerLife = true;
			FightExit(RESULT_DEFEAT, floor);
		}

		if (FightMonster.HPreturn() <= 0)
		{
			MonsterLife = true;
			FightExit(RESULT_WIN, floor);
			m_Player.Heal();
		}
	}
}

void GameManager::DongeonMenuDraw()
{
	m_DrawManager.BoxErase(WIDTH, HEIGHT);
	m_DrawManager.DrawMidText("=====던전 입구=====", WIDTH, HEIGHT * 0.2);
	for (int i = 0;i < m_MonsterList.size();i++)
		m_DrawManager.DrawMidText(to_string(i + 1) + "층던전 : [" + m_MonsterList[i].NameReturn() + "]", WIDTH, (HEIGHT * 0.4 - 1) + (float)(i * 2));
	m_DrawManager.DrawMidText("돌아가기", WIDTH, (HEIGHT * 0.4 - 1) + (float)(6 * 2));
}

void GameManager::DongeonMenu()
{
	int Select;

	while (!m_bGameOver2)
	{
		DongeonMenuDraw();
		Select = m_DrawManager.MenuSelectCursor(7, 2, WIDTH * 0.2, HEIGHT * 0.4 - 1);
		if (Select == 7)
			return;
		else
			InDongeon(Select - 1);
	}
}


bool GameManager::MonsterDefaultLoad(string FileName)
{
	ifstream Load;

	Load.open(FileName);

	if (Load.is_open())
	{
		Monster tmpMonster;

		Load >> m_iMonsterCount;
		for (int i = 0;i < m_iMonsterCount;i++)
		{
			string Name;
			int AD, MaxHP, MaxEXP, GetEXP, Level, Gold;
			Load >> Name;
			Load >> AD;
			Load >> MaxHP;
			Load >> MaxEXP;
			Load >> GetEXP;
			Load >> Level;
			Load >> Gold;

			tmpMonster.MosterSetData(Name, AD, MaxHP, MaxEXP, GetEXP, Level, Gold, 0, MaxHP);
			m_MonsterList.push_back(tmpMonster);
		}
		return true;
	}
	else
		return false;
}

bool GameManager::DefaultLoad()
{
	string FileName;
	string Name;
	bool PlayerLoadCheck = false;
	bool MonsterLoadCheck = false;

	m_DrawManager.BoxErase(WIDTH, HEIGHT);
	YELLOW
	m_DrawManager.DrawMidText("Player 이름 입력 : ", WIDTH, HEIGHT * 0.5);
	ORIGINAL
	cin >> Name;

	FileName = "DefaultPlayer.txt";
	PlayerLoadCheck = m_Player.PlayerDefaultLoad(Name,FileName);

	FileName = "DefaultMonster.txt";
	MonsterLoadCheck = MonsterDefaultLoad(FileName);

	if (PlayerLoadCheck && MonsterLoadCheck)
		return true;
	else
	{
		cout << "파일없음" << endl;
		return false;
	}
}

void GameManager::StartMenuDraw()
{
	m_DrawManager.BoxDraw(0, 0, WIDTH, HEIGHT);
	m_DrawManager.DrawMidText("☆★ DonGeonRPG ★☆", WIDTH, HEIGHT * 0.4f);
	m_DrawManager.DrawMidText("New Game", WIDTH, HEIGHT * 0.5f);
	m_DrawManager.DrawMidText("Load Game", WIDTH, HEIGHT * 0.6f);
	m_DrawManager.DrawMidText("GameExit", WIDTH, HEIGHT * 0.7f);
}

void GameManager::GameMenuDraw()
{
	m_DrawManager.BoxErase(WIDTH, HEIGHT);
	m_DrawManager.DrawMidText("☆★ Menu ★☆", WIDTH, HEIGHT * 0.3f);
	m_DrawManager.DrawMidText("Dongeon", WIDTH, HEIGHT * 0.4f - 1);
	m_DrawManager.DrawMidText("Player Info", WIDTH, HEIGHT * 0.5f - 2);
	m_DrawManager.DrawMidText("Monster Info", WIDTH, HEIGHT * 0.6f - 3);
	m_DrawManager.DrawMidText("Weapon Shop", WIDTH, HEIGHT * 0.7f - 4);
	m_DrawManager.DrawMidText("Save", WIDTH, HEIGHT * 0.8f - 5);
	m_DrawManager.DrawMidText("Exit", WIDTH, HEIGHT * 0.9f - 6);
}

void GameManager::GameMenu()
{
	while (!m_bGameOver)
	{
		GameMenuDraw();
		switch (m_DrawManager.MenuSelectCursor(6, 2, WIDTH * 0.3, HEIGHT * 0.4 - 1))
		{
		case GAMEMENU_DONGEON:
			m_bGameOver2 = false;
			DongeonMenu();
			break;
		case GAMEMENU_PLAYERINFO:
			m_DrawManager.BoxErase(WIDTH, HEIGHT);
			m_Player.ShowInfo(WIDTH, HEIGHT * 0.5);
			getch();
			break;
		case GAMEMENU_MONSTERINFO:
			m_DrawManager.BoxErase(WIDTH, HEIGHT);
			for (int i = 0;i < m_MonsterList.size();i++)
				m_MonsterList[i].ShowInfo(WIDTH, HEIGHT * 0.1f + i * 4);
			getch();
			break;
		case GAMEMENU_WEAPONSHOP:
			m_Shop.ShopMenu(&m_Player);
			break;
		case GAMEMENU_SAVE:
			Save();
			break;
		case GAMEMENU_EXIT:
			return;
		}
	}
}

void GameManager::MonsterLoad(string FileName)
{
	ifstream load;
	string Name;
	int AttackDamage, GetEXP, Level, Gold, MaxHP, MaxEXP, NowEXP, NowHP;
	Monster tmp;
	load.open(FileName);

	load >> m_iMonsterCount;
	for (int i = 0;i < m_iMonsterCount;i++)
	{
		load >> Name;
		load >> AttackDamage;
		load >> MaxHP;
		load >> MaxEXP;
		load >> GetEXP;
		load >> Level;
		load >> Gold;
		load >> NowEXP;
		load >> NowHP;

		tmp.MosterSetData(Name, AttackDamage, MaxHP, MaxEXP, GetEXP, Level, Gold, NowEXP, NowHP);
		m_MonsterList.push_back(tmp);
	}
	load.close();
}

bool GameManager::DataLoad(int Number)
{
	string FileName;

	if (FileCheckPlayer(Number) && FileCheckMonster(Number))
	{
		FileName = "SavePlayer" + to_string(Number) + ".txt";
		m_Player.DataLoad(FileName);
		FileName = "SaveMonster" + to_string(Number) + ".txt";
		MonsterLoad(FileName);
		return true;
	}
	else
	{
		m_DrawManager.BoxErase(WIDTH, HEIGHT);
		m_DrawManager.DrawMidText("해당 파일이 없습니다.", WIDTH, HEIGHT / 2);
		getch();
		return false;
	}

}

bool GameManager::Load()
{
	bool Check = false;

	int Width = WIDTH / 3, Height = HEIGHT * 0.1f + 2, Select;

	while (1)
	{
		SaveList(Width, Height);
		Select = m_DrawManager.MenuSelectCursor(10 + 1, 2, Width - 2, Height);
		Check = DataLoad(Select);

		if (Select == 10 + 1)
			return false;
		else
		{
			if (Check)
				return true;
			else
				return false;
		}
	}
}

void GameManager::StartMenu()
{
	while (1)
	{
		m_Shop.WeaponListLoad();
		StartMenuDraw();

		switch (m_DrawManager.MenuSelectCursor(3, 3, WIDTH * 0.4, HEIGHT * 0.5))
		{
		case STARTMENU_NEWGAME:
			m_bGameOver = false;
			if (DefaultLoad())
				GameMenu();
			break;
		case STARTMENU_LOADGAME:
			if(Load())
				GameMenu();
			break;
		case STARTMENU_EXIT:
			return;
		}
	}
}

GameManager::~GameManager()
{
	m_MonsterList.clear();
}