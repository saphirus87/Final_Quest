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
	IMAGEMANAGER->addImage("actGaugeBox", ".//userInterface//ProgressBar_Box.bmp", 170, 23, true, RGB(255, 0, 255));

	// 배틀 커맨드 사용 가능 불가로 초기화
	_isCommandReady = false;
	// 초기 커맨드 위치는 기본공격
	_curCommand = ATTACK_COMMAND;

	//_dir = PLAYER_DOWN;
	//_isAttack = false;
	
	// 플레이어 공통부분 초기화 (레벨, 경험치, 행동 게이지...)
	_level = 1;
	_curActGauge = 0;
	_maxActGauge = 5;
	_maxExp = 100;
	_currentExp = 0;
	_isDead = true;

	_actGauge = new progressBar;
	_actGauge->frontBarInit("chargeActGauge", ".//userInterface//ProgressBar.bmp", 0, 0, 140, 14);
	_completeActGauge = new progressBar;
	_completeActGauge->frontBarInit("completeActGauge", ".//userInterface//ProgressComplete.bmp", 0, 0, 140, 14);

	_x = WINSIZEX / 2;
	_y = WINSIZEY / 2;
	_frameX = 0;

	// 사용 가능 커맨드
	_enableCommand = ATTACK_COMMAND | ITEM_COMMAND | MAGIC_COMMAND | RUN_COMMAND;

	_playerEquip[0].itemtype = TYPE_HEAD;
	_playerEquip[1].itemtype = TYPE_BODY;
	_playerEquip[2].itemtype = TYPE_RIGHT;
	_playerEquip[3].itemtype = TYPE_LEFT;
	_playerEquip[4].itemtype = TYPE_ACCESSARY;

	for (int i = 0; i < 5; i++)
	{
		_playerEquip[i].code = 0;
		_playerEquip[i].name = "";
		_playerEquip[i].price = 0;
		_playerEquip[i].value = 0;
		_playerEquip[i].count = 0;
	}

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
	drawPlayerInfoInBattle();

	SelectObject(getMemDC(), oFont);
	DeleteObject(hFont);
	DeleteObject(oFont);
}

void player::statusRender(void)
{
	// 메인 메뉴 스테이터스 창에서 그려줄 함수
}

void player::equipRender(void)
{
	// 메인 메뉴 장비창에서 그려줄 함수
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
	_level++;
	_currentExp -= _maxExp;
	_maxExp += _level * 100;
	
	_currentHp = _maxHp;
	_currentMp = _maxMp;
}

void player::drawPlayerInfoInBattle(void)
{
	char displayHp[128];
	int drawPos = 0;

	if (_partyPos == 1) drawPos = PLAYER1_NAME_Y;
	if (_partyPos == 2) drawPos = PLAYER2_NAME_Y;
	if (_partyPos == 3) drawPos = PLAYER3_NAME_Y;
	
	// 플레이어 이름 출력
	if (_isCommandReady) SetTextColor(getMemDC(), RGB(180, 180, 40));
	TextOut(getMemDC(), 450, drawPos, _name.c_str(), strlen(_name.c_str()));
	if (_isCommandReady) SetTextColor(getMemDC(), RGB(220, 220, 220));

	// 플레이어 체력 출력
	wsprintf(displayHp, "%d / %d", _currentHp, _maxHp);
	TextOut(getMemDC(), 650, drawPos, displayHp, strlen(displayHp));

	// 플레이어 행동 게이지 출력
	IMAGEMANAGER->findImage("actGaugeBox")->render(getMemDC(), 810, drawPos +5);
	_actGauge->setX(825);
	_actGauge->setY(drawPos + 2);
	_completeActGauge->setX(825);
	_completeActGauge->setY(drawPos + 2);

	if (!_isCommandReady) _actGauge->render();
	else _completeActGauge->render();
}

void player::increaseActGauge(void)
{
	if (_curActGauge < MAX_ACT_GAUGE) _curActGauge += _agi;
	else _isCommandReady = true;

	_actGauge->setGauge(_curActGauge, MAX_ACT_GAUGE);
	_actGauge->update();
	_completeActGauge->update();
	
}
