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
	img = IMAGEMANAGER->addImage("mammos", "enemyimages/mammos.bmp", 63, 48, true, RGB(255, 0, 255));
	isAttack = false;
	_startTime = 0.0f;
	_endTime = 5.0f;
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
	cout << "����" << endl;

	if (attack_state == ATTACK)
	{
		frameCount++;
		if (frameCount >= IMAGEMANAGER->findImage("attack")->getMaxFrameX())
		{
			frameCount = 0;
			attack_state = NONE;
		}
		IMAGEMANAGER->findImage("attack")->setFrameX(frameCount);
	}


	//��ų�Ҹ�
}

void mammos::render(HDC hdc)
{
	img->alphaRender(getMemDC(), 200, 300,_alpha);
}
