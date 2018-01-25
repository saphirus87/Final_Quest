#include "stdafx.h"
#include "mammos.h"


mammos::mammos()
{
}


mammos::~mammos()
{
}

HRESULT mammos::init()
{
	enemy::init();
	img = new image;
	img->init("enemyimages/mammos.bmp", 173, 114, true, RGB(255, 0, 255));

	img_hit = new image;
	img_hit->init("enemyimages/mammos_hit.bmp", 173, 114, true, RGB(255, 0, 255));

	img_die = new image;
	img_die->init("enemyimages/mammos_die.bmp", 173, 114, true, RGB(255, 0, 255));

	img_attack = new image;
	img_attack->init("enemyimages/mammos_attack.bmp", 600, 134, 3, 1, true, RGB(255, 0, 255));

	isAttack = false;
	_startTime = 0.0f;
	_endTime = 22.0f;
	_curruntHp = _maxHp = 60;
	_curruntMp = _maxMp = 60;
	_str = _int = 3;
	_def = 2;
	_m_Def = 2;
	//���� ���ݷ¹���
	_MIN = _str;
	_MAX = _str*1.3;
	_damage = RND->getFromIntTo(_MIN, _MAX);

	//��ų ���ݷ� ����
	_m_MIN = _int;
	_m_MAX = _int * 2;
	_m_Damage = RND->getFromIntTo(_m_MIN, _m_MAX);

	//���
	_MINgold = 10;
	_MAXgold = 15;
	_gold = RND->getFromFloatTo(_MINgold, _MAXgold);
	//����ġ
	_exp = 21;
	return S_OK;
}

void mammos::release()
{
}

void mammos::update()
{
	enemy::update();

	if (attack_state == ATTACK)
	{
		if (count % 10 == 0)
		{
			frameCount++;
			if (frameCount >= img_attack->getMaxFrameX())
			{
				frameCount = 0;
				attack_state = NONE;
			}
			img_attack->setFrameX(frameCount);
		}
	}


	//��ų�Ҹ�
}

void mammos::render(HDC hdc)
{
	switch (state)
	{
	case LIFE_NONE:
		img->render(hdc, x, y);
		break;
	case HIT:
		img_hit->render(hdc, x, y);
		break;
	case DIE:
		img_die->alphaRender(hdc,x,y,_alpha);
		break;
	default:
		break;
	}

	if (attack_state == ATTACK)
		img_attack->frameRender(hdc,x+300,y, img_attack->getFrameX(), img_attack->getFrameY());

}
