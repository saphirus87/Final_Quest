#include "stdafx.h"
#include "playGround.h"



//노래 추가를 위한 cpp파일
//playGround에 종속됨
//map의 자동정렬 특성상
//01,02등의 번호를 사용하여 정렬 방지
void playGround::soundInit()
{
	SOUNDMANAGER->addSound("01.오프닝", ".//musicSound//openingThema.mp3", true, true);
	SOUNDMANAGER->addSound("02.선택", ".//musicSound//selectScene.mp3", true, true);

	//에너미 사운드
	SOUNDMANAGER->addSound("70.basic", ".//enemySound//basic.mp3", true, true);
	SOUNDMANAGER->addSound("71.boss_reflex", ".//enemySound//boss_reflex", true, true);
}