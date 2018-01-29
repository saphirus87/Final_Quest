#include "stdafx.h"
#include "enemy.h"


enemy::enemy()
{
}


enemy::~enemy()
{
}


HRESULT enemy::init()
{
	//x = y = namePositionX = namePositionY = 0;
	state = LIFE_NONE;
	attack_state = NONE;
	_alpha = ALPHA_MAX_VALUE;
	frameCount = count = 0;
	battle.totalDamage = 0;
	GOLD = RND->getFromIntTo(13, 20);
	EXP = RND->getFromIntTo(13, 15);
	battle.playerTarget = RND->getFromIntTo(1, 3);
	aimPlayer = battle.playerTarget;
	_stmn = RND->getFromFloatTo(MIN_STMN , MAX_STMN);
	return S_OK;
}

void enemy::release()
{
}

void enemy::update()
{
	GOLD = RND->getFromIntTo(13, 22);
	EXP = RND->getFromIntTo(13, 15);
	//hp0되면 죽어라
	if (_curruntHp <= 0)
	{
		state = DIE;
		if(_alpha>=0)
		_alpha--;
	}
}

void enemy::render(HDC hdc)
{
	HFONT hFont = CreateFont(30, 0, 0, 0, 600, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, VARIABLE_PITCH | FF_ROMAN, TEXT("consolas"));
	HFONT oFont = (HFONT)SelectObject(getMemDC(), hFont);

	SetBkMode(getMemDC(), TRANSPARENT);
	SetTextColor(getMemDC(), RGB(220, 220, 220));

	nameInfo();
	SelectObject(getMemDC(), oFont);
	DeleteObject(hFont);
	DeleteObject(oFont);
}

void enemy::Attack(int damage)
{
	if (state == LIFE_NONE)
	{
		//타임 셋팅부분
		if (_startTime >= _endTime)
		{
			_damage = damage;
			_startTime = 0;
			isAttack = true;
			battle.playerTarget = RND->getFromIntTo(1, 3);
			SOUNDMANAGER->play("70.basic", 0.7f);
			attack_state = ATTACK;
			isAttack = false;
		}
		if (!isAttack) _startTime += _stmn;
	}
}

void enemy::endAttack()
{	
	enemySound();
	attack_state = NONE;
}

void enemy::enemySound()
{
	SOUNDMANAGER->play("70.basic", 0.8f);
}

void enemy::nameInfo()
{

}
