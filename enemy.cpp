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
		//Ÿ�� ���úκ�
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
				//��ų����
				attack_skill = SKILL;
				_curruntMp -= 20;
				isAttack = false;
			}
			else
			{
				//�Ϲݰ���
				attack_skill = ATTACK;
				isAttack = false;
				//�����¼Ҹ� ����Ŵ�����
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
