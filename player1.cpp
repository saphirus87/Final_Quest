#include "stdafx.h"
#include "player1.h"


player1::player1()
{
}


player1::~player1()
{
}

HRESULT player1::init()
{
	_level = 1;
	_str = _int = 10;
	_curruntHp = _maxHp = 100 * _level;
	_curruntMp = _maxMp = 100 * _level;
	_startTime = 0; 
	_endTime = 5;
	_def = 0;
	_m_def = 0;
	_maxExp = _currentExp = 0;
	_isDead = true;

	//물리 공격력범위
	_min = _str;
	_max = _str * 1.7;
	_damage = RND->getFromIntTo(_min, _max);

	//스킬 공격력 범위
	_m_min = _int;
	_m_min = _int * 2.3;
	_m_Damage = RND->getFromIntTo(_m_min, _m_max);


	return S_OK;
}
void player1::release()
{


}
void player1::update()
{


}
void player1::render()
{


}
