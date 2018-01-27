#include "stdafx.h"
#include "player3.h"


player3::player3()
{
}


player3::~player3()
{

}


HRESULT player3::init()
{
	player::init();

	// 플레이어2 능력치 초기화
	_currentHp = _maxHp = 80;
	_currentMp = _maxMp = 120;
	_str = 8;
	_int = 12;
	_agi = 12;
	_def = 2;
	_m_def = 3;

	_name = "trance";
	_partyPos = 3;

	return S_OK;
}
void player3::release()
{

}
void player3::update() 
{
	player::update();
}
void player3::render()
{
	player::render();
}

void player3::levelUp(void)
{
	_maxHp += 8;
	_maxMp += 12;
	_str += 1;
	_int += 3;
	_agi += 4;

	player::levelUp();
}
