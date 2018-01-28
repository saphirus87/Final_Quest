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
	//===================================== �÷��̾� 1 �̹��� �߰� =====================================
	IMAGEMANAGER->addFrameImage("player1Move", ".//playerImage//player1Move.bmp", 84, 184, 3, 4, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("player1Battle_Idle", ".//playerImage//player1_attack_idle.bmp", 28, 43, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("player1Die", ".//playerImage//player1_die.bmp", 47, 24, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("player1Hurt", ".//playerImage//player1_hurt.bmp", 36, 45, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("player1Skill", ".//playerImage//player1_skill.bmp", 54, 45, 2, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("player1Win", ".//playerImage//player1_win_motion.bmp", 446, 46, 4, 1, true, RGB(255, 0, 255));
	//===================================== �÷��̾� 1 �̹��� �߰� =====================================
	IMAGEMANAGER->addImage("player1face", ".//playerImage//player1face.bmp", 100, 100, true, RGB(255, 0, 255));

	//===================================== �÷��̾� 1 �ִϸ��̼� �߰� =====================================

	//===================================== �÷��̾� 1 �ִϸ��̼� �߰� =====================================


	player::init();

	// �÷��̾�1 �ɷ�ġ �ʱ�ȭ
	_currentHp = _maxHp = 100;
	_currentMp = _maxMp = 100;
	_str = 10;
	_int = 10;
	_agi = 10;
	_def = 2;
	_m_def = 2;

	_name = "Tina";
	_partyPos = 1;

	return S_OK;
}
void player1::release()
{


}
void player1::update()
{
	player::update();



}
void player1::render(void)
{
	player::render();
}

void player1::levelUp(void)
{
	_maxHp += 10;
	_maxMp += 10;
	_str += 2;
	_int += 2;
	_agi += 2;

	player::levelUp();
}
