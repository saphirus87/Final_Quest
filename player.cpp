#include "stdafx.h"
#include "player.h"


player::player()
{
}


player::~player()
{
}


HRESULT player::init()
{
	// 배틀 커맨드 창 이미지 추가
	IMAGEMANAGER->addImage("battleSelectScene", ".//userInterface//battleSelectScene.bmp", 341, 200, true, RGB(255, 0, 255));

	// 배틀 커맨드 사용 가능 불가로 초기화
	_isCommandReady = false;
	// 초기 커맨드 위치는 기본공격
	_curCommand = ATTACK_COMMAND;

	_dir = PLAYER_DOWN;
	_isAttack = false;
	_curruntHp = _maxHp = 100;
	_curruntMp = _maxMp = 100;
	_str = _int = 10;
	_agi = 10;
	_level = 1;
	_curActGauge = 0;
	_maxActGauge = 5;
	_def = 0;
	_m_def = 0;
	_maxExp = 100;
	_curruntExp = 0;
	_isDead = true;

	_x = WINSIZEX / 2;
	_y = WINSIZEY / 2;
	_frameX = 0;

	// 사용 가능 커맨드
	_enableCommand = ATTACK_COMMAND | ITEM_COMMAND | MAGIC_COMMAND | RUN_COMMAND;

	return S_OK;
}
void player::release()
{

}
void player::update()
{
	if (_isCommandReady)
	{
		selectCommand();
	}
}
void player::render(void)
{
	HFONT hFont = CreateFont(30, 0, 0, 0, 600, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, VARIABLE_PITCH | FF_ROMAN, TEXT("consolas"));
	HFONT oFont = (HFONT)SelectObject(getMemDC(), hFont);

	SetBkMode(getMemDC(), TRANSPARENT);
	SetTextColor(getMemDC(), RGB(220, 220, 220));
	if (_isCommandReady) drawCommand();
	drawPlayerName();

	SelectObject(getMemDC(), oFont);
	DeleteObject(hFont);
	DeleteObject(oFont);
}

void player::drawCommand(void)
{
	IMAGEMANAGER->findImage("battleSelectScene")->render(getMemDC(), 100, 557);
	TextOut(getMemDC(), 170, COMMAND1_POSY, "ATTACK", strlen("ATTACK"));
	TextOut(getMemDC(), 170, COMMAND2_POSY, "ITEM", strlen("ITEM"));
	TextOut(getMemDC(), 170, COMMAND3_POSY, "MAGIC", strlen("MAGIC"));
	TextOut(getMemDC(), 170, COMMAND4_POSY, "RUN", strlen("RUN"));
	
	if (_curCommand == ATTACK_COMMAND) IMAGEMANAGER->findImage("선택")->render(getMemDC(), 130, COMMAND1_POSY);
	if (_curCommand == ITEM_COMMAND) IMAGEMANAGER->findImage("선택")->render(getMemDC(), 130, COMMAND2_POSY);
	if (_curCommand == MAGIC_COMMAND) IMAGEMANAGER->findImage("선택")->render(getMemDC(), 130, COMMAND3_POSY);
	if (_curCommand == RUN_COMMAND) IMAGEMANAGER->findImage("선택")->render(getMemDC(), 130, COMMAND4_POSY);

}

void player::selectCommand(void)
{
	if (KEYMANAGER->isOnceKeyDown(VK_UP))
	{
		_curCommand = (BATTLE_COMAAND)(_curCommand / 2);
		
		if (_curCommand == 0)
		{
			if (_enableCommand & DEFFENCE_COMMAND) _curCommand = DEFFENCE_COMMAND;
			else if (_enableCommand & RUN_COMMAND) _curCommand = RUN_COMMAND;
			else if (_enableCommand & MAGIC_COMMAND) _curCommand = MAGIC_COMMAND;
			else if (_enableCommand & ITEM_COMMAND) _curCommand = ITEM_COMMAND;
			else if (_enableCommand & ATTACK_COMMAND) _curCommand = ATTACK_COMMAND;
		}
	}
	
	if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
	{
		_curCommand = (BATTLE_COMAAND)(_curCommand * 2);

		if (_curCommand > _enableCommand)
		{
			if (_enableCommand & ATTACK_COMMAND) _curCommand = ATTACK_COMMAND;
			else if (_enableCommand & ITEM_COMMAND) _curCommand = ITEM_COMMAND;
			else if (_enableCommand & MAGIC_COMMAND) _curCommand = MAGIC_COMMAND;
			else if (_enableCommand & RUN_COMMAND) _curCommand = RUN_COMMAND;
			else if (_enableCommand & DEFFENCE_COMMAND) _curCommand = DEFFENCE_COMMAND;
		}
	}
}

void player::levelUp(void)
{

}

void player::drawPlayerName(void)
{
	if (_isCommandReady) SetTextColor(getMemDC(), RGB(180, 180, 40));

	if (_partyPos == 1) TextOut(getMemDC(), 450, PLAYER1_NAME_Y, _name.c_str(), strlen(_name.c_str()));
	if (_partyPos == 2) TextOut(getMemDC(), 450, PLAYER2_NAME_Y, _name.c_str(), strlen(_name.c_str()));
	if (_partyPos == 3) TextOut(getMemDC(), 450, PLAYER3_NAME_Y, _name.c_str(), strlen(_name.c_str()));

	if (_isCommandReady) SetTextColor(getMemDC(), RGB(220, 220, 220));
}

void player::increaseActGauge(void)
{
	if (_curActGauge < MAX_ACT_GAUGE) _curActGauge += _agi;
	else _isCommandReady = true;
}
