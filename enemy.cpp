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
	state = LIFE_NONE;
	attack_state = NONE;
	_alpha = 255;
	frameCount = count = 0;
	_stmn = RND->getFromFloatTo(0.01f, 0.05f);
	return S_OK;
}

void enemy::release()
{
}

void enemy::update()
{
	count++;
	Attack();

	//hp0되면 죽어라
	if (_curruntHp <= 0)
	{
		state = DIE;
		_alpha--;
	}
}

void enemy::render(HDC hdc)
{
}

void enemy::Attack()
{
	if (state == LIFE_NONE)
	{
		//타임 셋팅부분
		if (_startTime >= _endTime)
		{
			_startTime = 0;
			isAttack = true;
		}
		if (!isAttack)
			_startTime += _stmn;

		else if (isAttack)
		{
			//일반공격
			attack_state = ATTACK;
			isAttack = false;
			//endAttack 함수사용 할껀대 그때  밑에 사운드 뺴기~~
			SOUNDMANAGER->play("70.basic", 0.7f);
		}
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
