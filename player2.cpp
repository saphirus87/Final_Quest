#include "stdafx.h"
#include "player2.h"


player2::player2()
{
}


player2::~player2()
{

}

HRESULT player2::init()
{

	player::init();

	// 플레이어2 능력치 초기화
	_currentHp = _maxHp = 120;
	_currentMp = _maxMp = 80;
	_str = 12;
	_int = 8;
	_agi = 8;
	_def = 0;
	_m_def = 4;

	_name = "Moogle";
	_partyPos = 2;

	return S_OK;
}
void player2::release()
{

}
void player2::update() 
{
	player::update();
}
void player2::render()
{
	player::render();
}

void player2::levelUp(void)
{
	_maxHp += 12;
	_maxMp += 8;
	_str += 3;
	_int += 1;
	_agi += 3;

	player::levelUp();
}
