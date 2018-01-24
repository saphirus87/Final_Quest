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
	IMAGEMANAGER->addImage("mammos", "enemyimages/mammos.bmp", 63, 48, true, RGB(255, 0, 255));
	curruntHp = maxHp = 60;
	curruntMp = maxMp = 60;
	Str = Int = 3;
	Def = 2;
	m_Def = 2;
	//물리 공격력범위
	MIN = Str;
	MAX = Str*1.3;
	Damage = RND->getFromIntTo(MIN, MAX);

	//스킬 공격력 범위
	m_MIN = Int;
	m_MAX = Int * 2;
	m_Damage = RND->getFromIntTo(m_MIN, m_MAX);

	//골드
	MINgold = 10;
	MAXgold = 15;
	gold = RND->getFromFloatTo(MINgold, MAXgold);
	//경험치
	exp = 21;
	return S_OK;
}

void mammos::release()
{
}

void mammos::update()
{
}

void mammos::render()
{
}
