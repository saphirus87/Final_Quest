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
			_startTime += 0.04;

		else if (isAttack)
		{
			//일반공격
			attack_state = ATTACK;
			enemySound();
			isAttack = false;
			//사운드s
		}
	}
}

void enemy::enemySound()
{
	SOUNDMANAGER->play("70.basic", 1.0f);
}
