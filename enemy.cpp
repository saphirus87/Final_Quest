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
	state = LIFE;
	attack_skill = NONE;
	_alpha = 255;
	return S_OK;
}

void enemy::release()
{
}

void enemy::update()
{
	if (state == LIFE)
	{
		//타임 셋팅부분
		if (_startTime >= endTime)
		{
			_startTime = 0;
			isAttack = true;
		}
		if (!isAttack)
			_startTime += 0.08;

		else if (isAttack)
		{
			_attack = RND->getFromIntTo(0, 4);
			if (_curruntMp>=20 _attack = 0)
			{
				//스킬공격
				attack_skill = SKILL;
				_curruntMp -= 20;
				isAttack = false;
			}
			else
			{
				//일반공격
				attack_skill = ATTACK;
				isAttack = false;
				//떄리는소리 사운드매니저로
			}
		}
	}
	if (state==LIFE&&_curruntHp <= 0;)
	{
		state = DIE;
		_alpha--;
	}
}

void enemy::render()
{
}
