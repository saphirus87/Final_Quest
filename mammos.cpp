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
	img = IMAGEMANAGER->addImage("mammos", "enemyimages/mammos.bmp", 173, 114, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("mammos_hit", "enemyimages/mammos_hit.bmp", 173, 114, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("mammos_die", "enemyimages/mammos_die.bmp", 173, 114, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("wolf_attack", "enemyimages/mammos_attack.bmp", 600, 134, 3, 1, true, RGB(255, 0, 255));
	isAttack = false;
	_startTime = 0.0f;
	_endTime = 5.0f;
	_curruntHp = _maxHp = 60;
	_curruntMp = _maxMp = 60;
	_str = _int = 3;
	_def = 2;
	_m_Def = 2;
	//물리 공격력범위
	_MIN = _str;
	_MAX = _str*1.3;
	_damage = RND->getFromIntTo(_MIN, _MAX);

	//스킬 공격력 범위
	_m_MIN = _int;
	_m_MAX = _int * 2;
	_m_Damage = RND->getFromIntTo(_m_MIN, _m_MAX);

	//골드
	_MINgold = 10;
	_MAXgold = 15;
	_gold = RND->getFromFloatTo(_MINgold, _MAXgold);
	//경험치
	_exp = 21;
	return S_OK;
}

void mammos::release()
{
}

void mammos::update()
{
	enemy::update();
	cout << "맘모스" << endl;

	if (attack_state == ATTACK)
	{
		frameCount++;
		if (frameCount >= IMAGEMANAGER->findImage("mammos_attack")->getMaxFrameX())
		{
			frameCount = 0;
			attack_state = NONE;
		}
		IMAGEMANAGER->findImage("mammos_attack")->setFrameX(frameCount);
	}


	//스킬소리
}

void mammos::render(HDC hdc)
{
	switch (state)
	{
	case LIFE_NONE:
		img->render(hdc, 200, 300);
		break;
	case HIT:
		IMAGEMANAGER->findImage("mammos_hit")->render(hdc, 200, 300);
		break;
	case DIE:
		IMAGEMANAGER->findImage("mammos_hit")->alphaRender(hdc, 200, 300, _alpha);
		break;
	default:
		break;
	}

	if (attack_state == ATTACK)
		IMAGEMANAGER->findImage("wolf_attack")->frameRender(hdc, 500, 500,
			IMAGEMANAGER->findImage("wolf_attack")->getFrameX(),
			IMAGEMANAGER->findImage("wolf_attack")->getFrameY());

}
