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

	//hp0�Ǹ� �׾��
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
		//Ÿ�� ���úκ�
		if (_startTime >= _endTime)
		{
			_startTime = 0;
			isAttack = true;
		}
		if (!isAttack)
			_startTime += _stmn;

		else if (isAttack)
		{
			//�Ϲݰ���
			attack_state = ATTACK;
			isAttack = false;
			//endAttack �Լ���� �Ҳ��� �׶�  �ؿ� ���� ����~~
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
