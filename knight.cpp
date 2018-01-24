#include "stdafx.h"
#include "knight.h"


knight::knight()
{
}


knight::~knight()
{
}

HRESULT knight::init()
{
	img = IMAGEMANAGER->addImage("knight", "enemyimages/knight.bmp", 32, 48, true, RGB(255, 0, 255));
	curruntHp = maxHp = 50;
	curruntMp = maxMp = 50;
	Str = Int = 5;
	Def = 1;
	m_Def = 1;
	//물리 공격력범위
	MIN = Str;
	MAX = Str*1.5;
	Damage = RND->getFromIntTo(MIN, MAX);

	//스킬 공격력 범위
	m_MIN = Int;
	m_MAX = Int * 3;
	m_Damage = RND->getFromIntTo(m_MIN, m_MAX);

	//골드
	MINgold = 9;
	MAXgold = 14;
	gold = RND->getFromFloatTo(MINgold, MAXgold);
	//경험치
	exp = 17;
	return S_OK;
}

void knight::release()
{
}

void knight::update()
{
}

void knight::render()
{
}
