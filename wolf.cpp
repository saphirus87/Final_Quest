#include "stdafx.h"
#include "wolf.h"


wolf::wolf()
{
}


wolf::~wolf()
{
}

HRESULT wolf::init()
{
	enemy::init();
	isAttack = false;
	_startTime = 0.0f;
	_endTime = 5.0f;
	img = IMAGEMANAGER->addImage("wolf", "enemyimages/wolf.bmp", 48, 48, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("wolf_attack", "enemyimages/wolf_attack.bmp", 600, 134, 3, 1, true, RGB(255, 0, 255));
	_curruntHp = _maxHp = 45;
	_curruntMp = _maxMp = 45;
	_str = _int = 4;
	_def = 1;
	_m_Def = 3;
	//물리 공격력범위
	_MIN = _str;
	_MAX = _str*1.7;
	_damage = RND->getFromIntTo(_MIN, _MAX);

	//스킬 공격력 범위
	_m_MIN = _int;
	_m_MAX = _int * 2.3;
	_m_Damage = RND->getFromIntTo(_m_MIN, _m_MAX);

	//골드
	_MINgold = 10;
	_MAXgold = 14;
	_gold = RND->getFromFloatTo(_MINgold, _MAXgold);
	//경험치
	_exp = 18;
	//
	return S_OK;
}

void wolf::release()
{
}

void wolf::update()
{
	enemy::update();
	cout << "울프" << endl;

	if (attack_state == ATTACK)
	{
		frameCount++;
		if (frameCount >= IMAGEMANAGER->findImage("wolf_attack")->getMaxFrameX())
		{
			frameCount = 0;
			attack_state = NONE;
		}
		IMAGEMANAGER->findImage("wolf_attack")->setFrameX(frameCount);
	}

	//스킬소리
}

void wolf::render(HDC hdc)
{
	img->alphaRender(getMemDC(), 200, 500,_alpha);
	if (attack_state==ATTACK)
		IMAGEMANAGER->findImage("wolf_attack")->frameRender(hdc, 500, 500,
			IMAGEMANAGER->findImage("wolf_attack")->getFrameX(), 
			IMAGEMANAGER->findImage("wolf_attack")->getFrameY());
}
