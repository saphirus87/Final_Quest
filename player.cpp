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
	_selectCommand = NO_COMMAND;
	_commandInfo.damagetype = NORMAL_DAMAGE;
	_commandInfo.selectCommand = NO_COMMAND;
	_commandInfo.target = 1;
	_commandInfo.totalDamage = 0;

	//_dir = PLAYER_DOWN;
	//_isAttack = false;
	
	// 플레이어 공통부분 초기화 (레벨, 경험치, 행동 게이지...)
	_level = 1;
	_curActGauge = 0;
	_maxActGauge = 5;
	_maxExp = 100;
	_currentExp = 0;
	_isDead = true;
	_isDamageDraw = false;

	_actGauge = new progressBar;
	_actGauge->frontBarInit("chargeActGauge", ".//userInterface//ProgressBar.bmp", 0, 0, 140, 14);
	_completeActGauge = new progressBar;
	_completeActGauge->frontBarInit("completeActGauge", ".//userInterface//ProgressComplete.bmp", 0, 0, 140, 14);

	_x = WINSIZEX / 2;
	_y = WINSIZEY / 2;
	_frameX = 0;

	// 사용 가능 커맨드
	_enableCommand = ATTACK_COMMAND | ITEM_COMMAND | MAGIC_COMMAND | RUN_COMMAND;

	//임시로 적 숫자 1로 초기화
	_nowenemycount = 0;

	_playerEquip[0].itemtype = TYPE_HEAD;
	_playerEquip[1].itemtype = TYPE_BODY;
	_playerEquip[2].itemtype = TYPE_RIGHT;
	_playerEquip[3].itemtype = TYPE_LEFT;
	_playerEquip[4].itemtype = TYPE_ACCESSARY;

	for (int i = 0; i < 5; i++)
	{
		_playerEquip[i].code = 0;
		_playerEquip[i].name = "없음";
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

	if (TIMEMANAGER->getWorldTime() - _damageDrawTimer > 1.2f && _isDamageDraw)
	{
		_isDamageDraw = false;
	}

	setBattlePos();
}
void player::render(void)
{
	char target[128];

	HFONT hFont = CreateFont(30, 0, 0, 0, 600, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, VARIABLE_PITCH | FF_ROMAN, TEXT("consolas"));
	HFONT oFont = (HFONT)SelectObject(getMemDC(), hFont);

	SetBkMode(getMemDC(), TRANSPARENT);
	SetTextColor(getMemDC(), RGB(220, 220, 220));
	if (_isCommandReady) drawCommand();
	drawPlayerInfoInBattle();

	SelectObject(getMemDC(), oFont);
	DeleteObject(hFont);
	DeleteObject(oFont);

	wsprintf(target, "curTarget : %d", _commandInfo.target);
	if (_isDebug) TextOut(getMemDC(), 500, 100, target, strlen(target));
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
	outlineTextOut(getMemDC(), 170, COMMAND1_POSY, "ATTACK", RGB(220, 220, 220), RGB(0, 0, 0), 2);
	outlineTextOut(getMemDC(), 170, COMMAND2_POSY, "ITEM", RGB(220, 220, 220), RGB(0, 0, 0), 2);
	outlineTextOut(getMemDC(), 170, COMMAND3_POSY, "MAGIC", RGB(220, 220, 220), RGB(0, 0, 0), 2);
	outlineTextOut(getMemDC(), 170, COMMAND4_POSY, "RUN", RGB(220, 220, 220), RGB(0, 0, 0), 2);
	
	if (_curCommand == ATTACK_COMMAND) IMAGEMANAGER->findImage("선택")->render(getMemDC(), 130, COMMAND1_POSY);
	if (_curCommand == ITEM_COMMAND) IMAGEMANAGER->findImage("선택")->render(getMemDC(), 130, COMMAND2_POSY);
	if (_curCommand == MAGIC_COMMAND) IMAGEMANAGER->findImage("선택")->render(getMemDC(), 130, COMMAND3_POSY);
	if (_curCommand == RUN_COMMAND) IMAGEMANAGER->findImage("선택")->render(getMemDC(), 130, COMMAND4_POSY);

}

void player::selectCommand(void)
{
	switch (_selectCommand)
	{
	case NO_COMMAND:
		if (KEYMANAGER->isOnceKeyDown(VK_UP))
		{
			_curCommand = (BATTLE_COMMAND)(_curCommand / 2);

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
			_curCommand = (BATTLE_COMMAND)(_curCommand * 2);

			if (_curCommand > _enableCommand)
			{
				if (_enableCommand & ATTACK_COMMAND) _curCommand = ATTACK_COMMAND;
				else if (_enableCommand & ITEM_COMMAND) _curCommand = ITEM_COMMAND;
				else if (_enableCommand & MAGIC_COMMAND) _curCommand = MAGIC_COMMAND;
				else if (_enableCommand & RUN_COMMAND) _curCommand = RUN_COMMAND;
				else if (_enableCommand & DEFFENCE_COMMAND) _curCommand = DEFFENCE_COMMAND;
			}
		}

		if (KEYMANAGER->isOnceKeyDown(VK_RETURN))
		{
			_selectCommand = _curCommand;
		}
		break;
	case ATTACK_COMMAND:
		commandAttack();
		break;
	case ITEM_COMMAND:
		commandItem();
		break;
	case MAGIC_COMMAND:
		commandMagic();
		break;
	case RUN_COMMAND:
		commandRun();
		break;
	case DEFFENCE_COMMAND:
		// 방어는 미구현
		break;
	case ALL_COMMAND:
		break;
	default:
		break;
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
	COLORREF nameColor = RGB(220, 220, 220);

	if (_partyPos == 1) drawPos = PLAYER1_NAME_Y;
	if (_partyPos == 2) drawPos = PLAYER2_NAME_Y;
	if (_partyPos == 3) drawPos = PLAYER3_NAME_Y;
	
	// 플레이어 이름 출력
	if (_isCommandReady) nameColor = RGB(180, 180, 40);
	//TextOut(getMemDC(), 450, drawPos, _name.c_str(), strlen(_name.c_str()));
	outlineTextOut(getMemDC(), 450, drawPos, _name.c_str(), nameColor, RGB(0, 0, 0), 1);
	if (_isCommandReady) nameColor = RGB(220, 220, 220);

	// 플레이어 체력 출력
	wsprintf(displayHp, "%d / %d", _currentHp, _maxHp);
	outlineTextOut(getMemDC(), 650, drawPos, displayHp, RGB(220, 220, 220), RGB(0, 0, 0), 1);
	//TextOut(getMemDC(), 650, drawPos, displayHp, strlen(displayHp));

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

void player::commandAttack(void)
{
	if (KEYMANAGER->isOnceKeyDown(VK_UP))
	{
		--_commandInfo.target;//일단 -1을 한 후(0~2)
		_commandInfo.target--;//키 이동
		if (_commandInfo.target < 0)_commandInfo.target += _nowenemycount;//예외 추가
		++_commandInfo.target;//다시 +1
	}

	if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
	{
		--_commandInfo.target;//일단 -1을 한 후
		_commandInfo.target++;//키 이동
		_commandInfo.target = _commandInfo.target % _nowenemycount;//예외 추가
		++_commandInfo.target;
	}

	if (KEYMANAGER->isOnceKeyDown(VK_RETURN))
	{
		_commandInfo.damagetype = NORMAL_DAMAGE;
		_commandInfo.selectCommand = ATTACK_COMMAND;
		_commandInfo.totalDamage = RND->getFromIntTo(_str / 2, _str * 1.5);
		_damageDrawTimer = TIMEMANAGER->getWorldTime();
		_isDamageDraw = true;
	}
}

void player::commandItem(void)
{

}


void player::commandMagic(void)
{

}

void player::commandRun(void)
{
	SOUNDMANAGER->stop("배틀");
	SOUNDMANAGER->setMP3Volume(0.75f);
	if (SOUNDMANAGER->isPlaySound("티나"))
		SOUNDMANAGER->setVolume("티나", 0.75f);

	_commandInfo.damagetype = NORMAL_DAMAGE;
	_commandInfo.selectCommand = RUN_COMMAND;
	_commandInfo.target = 1;
	_commandInfo.totalDamage = 0;

	_curActGauge = 0;
}

void player::commandReset(void)
{
	_commandInfo.damagetype = NORMAL_DAMAGE;
	_commandInfo.target = 1;
	_commandInfo.totalDamage = 0;

	if (_commandInfo.selectCommand != NO_COMMAND)
	{
		_isCommandReady = false;
		_curActGauge = 0;
		_commandInfo.selectCommand = NO_COMMAND;
		_selectCommand = NO_COMMAND;
	}
	
}

void player::setBattlePos(void)
{
	if (_partyPos == 1)
	{
		_x = 850;
		_y = 180;
	}
	else if (_partyPos == 2)
	{
		_x = 910;
		_y = 330;
	}
	else if (_partyPos == 3)
	{
		_x = 960;
		_y = 480;
	}
}


