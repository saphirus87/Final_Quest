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
		_img->frameRender(getMemDC(), _x, _y, _frameX, _dir);
	}
	if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
	{
		_dir = PLAYER_RIGHT;
		_x += 3;
		_img->frameRender(getMemDC(), _x, _y, _frameX, _dir);
	}
	if (KEYMANAGER->isOnceKeyDown(VK_UP))
	{
		_dir = PLAYER_UP;
		_y -= 3;
		_img->frameRender(getMemDC(), _x, _y, _frameX, _dir);
	}
	if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
	{
		_dir = PLAYER_DOWN;
		_y += 3;
		_img->frameRender(getMemDC(), _x, _y, _frameX, _dir);
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
	if (_isBattle)// 배틀 돌입 
	{
		_startTime = _startTime + 0.2;

		if (_startTime >= _endTime)
		{
			_isFight = true;
		}
		if (_startTime < _endTime)
		{
			//초기화
			_def = 0;
			_m_def = 0;
			_isFight = false;
		}
	}
	if (!_isBattle)
	{
		_startTime = 0;
		_isFight = false;
	}
}


//방어력, 마법 방어력(장비 있을 시 증가, 없을 시 초기값 그대로 가져감)
void player::hitLogic()
{
	// if( 적 데미지가 물리 데미지(통상공격) 일 경우
	// {
	// 	 _curruntHp = _curruntHp + _def - 적 데미지
	// }
	// else if(적 데미지가 마법 데미지(스킬) 일 경우)
	// {
	// 	_curruntHp = _curruntHp + _m_def - 적 스킬 데미지
	// }
}