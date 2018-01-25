#include "stdafx.h"
#include "player.h"


player::player()
{
}


player::~player()
{
}


HRESULT player::init()
{
	_dir = PLAYER_DOWN;
	_isAttack = false;
	_curruntHp = _maxHp = 100;
	_curruntMp = _maxMp = 100;
	_str = _int = 10;
	_level = 1;
	_startTime = 0;
	_endTime = 5;
	_def = 0;
	_m_def = 0;
	_maxExp = 100;
	_curruntExp = 0;
	_isDead = true;

	_x = WINSIZEX / 2;
	_y = WINSIZEY / 2;
	_frameX = 0;

	return S_OK;
}
void player::release()
{

}
void player::update()
{
	attack();

	if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
	{
		_dir = PLAYER_LEFT;
		_x -= 3;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
	{
		_dir = PLAYER_RIGHT;
		_x += 3;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_UP))
	{
		_dir = PLAYER_UP;
		_y -= 3;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
	{
		_dir = PLAYER_DOWN;
		_y += 3;
	}


	_count++;
	if (_count == 10)
	{
		_count = 0;
		if (_frameX < _img->getMaxFrameX()) _frameX++;
		else _frameX = 0;
	}
}
void player::render(HDC hdc)
{
	_img->frameRender(hdc, _x, _y, _frameX, _dir);
}

void player::attack()
{
	if (_isDead)
	{
		_startTime = _startTime + 0.2;

		if (_startTime >= _endTime)
		{
			_isAttack = true;
			_startTime = 0;
		}
		if (_startTime < _endTime)
		{
			_isAttack = false;
		}
	}
	if (!_isDead)
	{
		_startTime = 0;
		_isAttack = false;
	}

	

}