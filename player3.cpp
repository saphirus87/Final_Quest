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
	//===================================== 플레이어 1 이미지 추가 =====================================
	IMAGEMANAGER->addFrameImage("player3Move", ".//playerImage//player3Move.bmp", 90, 192, 3, 4, true, RGB(255, 0, 255));
	_img = IMAGEMANAGER->addImage("player3Battle_Idle", ".//playerImage//player3_attack_idle.bmp", 33, 43, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("player3Die", ".//playerImage//player3_die.bmp", 39, 25, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("player3Hurt", ".//playerImage//player3_hurt.bmp", 39, 47, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("player3Skill", ".//playerImage//player3_skill.bmp", 72, 45, 2, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("player3Win", ".//playerImage//player3_win_motion.bmp", 108, 47, 4, 1, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("player3face", ".//playerImage//player3face.bmp", 100, 100, true, RGB(255, 0, 255));

	//===================================== 플레이어 1 이미지 추가 =====================================

	//===================================== 플레이어 1 애니메이션 추가 =====================================

	//===================================== 플레이어 1 애니메이션 추가 =====================================
	player::init();

	// 플레이어2 능력치 초기화
	_currentHp = _maxHp = 80;
	_currentMp = _maxMp = 120;
	_str = 8;
	_int = 12;
	_agi = 12;
	_def = 2;
	_m_def = 3;

	_x = 960;
	_y = 480;

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
	IMAGEMANAGER->render("player3Battle_Idle", getMemDC(), _x, _y, 50, 65);
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
