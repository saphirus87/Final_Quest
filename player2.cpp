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
	//===================================== 플레이어 1 이미지 추가 =====================================

	IMAGEMANAGER->addFrameImage("player2Move", ".//playerImage//player2Move.bmp", 78, 172, 3, 4, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("player2Battle_Idle", ".//playerImage//player2_attack_idle.bmp", 25, 38, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("player2Die", ".//playerImage//player2_die.bmp", 42, 22, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("player2Hurt", ".//playerImage//player2_hurt.bmp", 25, 41, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("player2Skill", ".//playerImage//player2_skill.bmp", 50, 40, 2, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("player2Win", ".//playerImage//player2_win_motion.bmp", 100, 46, 4, 1, true, RGB(255, 0, 255));


	IMAGEMANAGER->addImage("player2face", ".//playerImage//player2face.bmp", 100, 100, true, RGB(255, 0, 255));

	//===================================== 플레이어 1 이미지 추가 =====================================

	//===================================== 플레이어 1 애니메이션 추가 =====================================

	//===================================== 플레이어 1 애니메이션 추가 =====================================
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
	IMAGEMANAGER->render("player2Battle_Idle", getMemDC(), 910, 330);
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
