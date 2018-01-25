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

	//hp0�Ǹ� �׾��
	if (_curruntHp <= 0)
	{
		state = DIE;
		_alpha--;
	}
}

void enemy::render()
{
}

void enemy::Attack()
{
	if (state == LIFE)
	{
		//Ÿ�� ���úκ�
		if (_startTime >= _endTime)
		{
			_startTime = 0;
			isAttack = true;
		}
		if (!isAttack)
			_startTime += 0.08;

		else if (isAttack)
		{
			//�Ϲݰ���
			attack_state = ATTACK;
			enemySound();
			isAttack = false;
			//����s
		}
	}
}

void enemy::enemySound()
{
	SOUNDMANAGER->play("70.basic", 1.0f);
}
