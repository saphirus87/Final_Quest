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
	//_img = IMAGEMANAGER->addFrameImage("player1Move", ".//playerImage//player1Move.bmp", 84, 184, 3, 4, true, RGB(255, 0, 255));
	player::init();

	return S_OK;
}
void player1::release()
{


}
void player1::update()
{

	//물리 공격력범위
	_min = _str;
	_max = _str * 2;
	_damage = RND->getFromIntTo(_min, _max);

	//스킬 공격력 범위
	_m_min = _int;
	_m_min = _int * 2;
	_m_Damage = RND->getFromIntTo(_m_min, _m_max);

	if (_curruntExp >= _maxExp)
	{
		_level = _level + 1;
		_curruntExp = 0;
		_maxExp = 100 * _level;
		_maxHp = 100 + 10 * _level;
		_maxMp = 100 + 10 * _level;
		_curruntHp = _maxHp;
		_curruntMp = _maxHp;
		_str = _str + 2;
		_int = _int + 2;

	}
	if (_isDead)
	{
		if (_curruntHp > 0) return;
		if (_curruntHp <= 0)
		{
			_isDead = false;
		}
	}
	player::update();
}
void player1::render(HDC hdc)
{
	//player::render(hdc);
}
