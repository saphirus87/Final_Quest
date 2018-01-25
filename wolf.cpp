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
	_curruntHp = _maxHp = 45;
	_curruntMp = _maxMp = 45;
	_str = Int = 4;
	_def = 1;
	_m_Def = 3;
	//물리 공격력범위
	_MIN = Str;
	_MAX = Str*1.7;
	_damage = RND->getFromIntTo(MIN, MAX);

	//스킬 공격력 범위
	m_MIN = Int;
	m_MAX = Int * 2.3;
	m_Damage = RND->getFromIntTo(m_MIN, m_MAX);

	//골드
	_MINgold = 10;
	_MAXgold = 14;
	_gold = RND->getFromFloatTo(MINgold, MAXgold);
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

	//스킬소리
}

void wolf::render()
{
	img->alphaRender(getMemDC(), 200, 500,_alpha);
}
