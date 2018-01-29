#include "stdafx.h"
#include "playGround.h"



//노래 추가를 위한 cpp파일
//playGround에 종속됨

//노래를 추가할때 위에 주석으로 BGM인지 Effect인지 구분해주세요
void playGround::soundInit()
{

	//BGM류
	SOUNDMANAGER->addSound("오프닝", ".//musicSound//openingThema.mp3", true, true);
	SOUNDMANAGER->addSound("선택", ".//musicSound//selectScene.mp3", true, true);
	SOUNDMANAGER->addSound("배틀", ".//musicSound//battleThema.mp3",true, true);
	SOUNDMANAGER->addSound("배틀승리", ".//musicSound//battleEnding.mp3", true, false);
	SOUNDMANAGER->addSound("파라다이스", ".//musicSound//Finding Paradise.mp3", true, true);


	
	SOUNDMANAGER->addSound("티나", ".//musicSound//tinaThema.mp3", true, true);




	//EffectSound
	
	SOUNDMANAGER->addSound("메뉴선택", ".//effectSound//MenuSelectSound.MP3", false, false);
	SOUNDMANAGER->addSound("배틀입장", ".//effectSound//BattleEncounter.mp3", false, false);

	//에너미 사운드
	SOUNDMANAGER->addSound("70.basic", ".//enemySound//basic.mp3", false, false);
	SOUNDMANAGER->addSound("71.boss_reflex", ".//enemySound//boss_reflex.mp3", false, false);
}