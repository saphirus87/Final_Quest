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
	img = IMAGEMANAGER->addImage("wolf", "enemyimages/wolf.bmp", 48, 48, true, RGB(255, 0, 255));
	curruntHp = maxHp = 45;
	curruntMp = maxMp = 45;
	Str = Int = 4;
	Def = 1;
	m_Def = 3;
	//물리 공격력범위
	MIN = Str;
	MAX = Str*1.7;
	Damage = RND->getFromIntTo(MIN, MAX);

	//스킬 공격력 범위
	m_MIN = Int;
	m_MAX = Int * 2.3;
	m_Damage = RND->getFromIntTo(m_MIN, m_MAX);

	//골드
	MINgold = 10;
	MAXgold = 14;
	gold = RND->getFromFloatTo(MINgold, MAXgold);
	//경험치
	exp = 18;
	return S_OK;
}

void wolf::release()
{
}

void wolf::update()
{
}

void wolf::render()
{
}
