#include "stdafx.h"
#include "playGround.h"



//�뷡 �߰��� ���� cpp����
//playGround�� ���ӵ�

//�뷡�� �߰��Ҷ� ���� �ּ����� BGM���� Effect���� �������ּ���
void playGround::soundInit()
{

	//BGM��
	SOUNDMANAGER->addSound("������", ".//musicSound//openingThema.mp3", true, true);
	SOUNDMANAGER->addSound("����", ".//musicSound//selectScene.mp3", true, true);
	SOUNDMANAGER->addSound("��Ʋ", ".//musicSound//battleThema.mp3",true, true);
	SOUNDMANAGER->addSound("��Ʋ�¸�", ".//musicSound//battleEnding.mp3", true, false);
	
	
	SOUNDMANAGER->addSound("Ƽ��", ".//musicSound//tinaThema.mp3", true, true);

	//EffectSound
	
	SOUNDMANAGER->addSound("�޴�����", ".//effectSound//MenuSelectSound.MP3", false, false);
	SOUNDMANAGER->addSound("��Ʋ����", ".//effectSound//BattleEncounter.wav", false, false);

	//���ʹ� ����
	SOUNDMANAGER->addSound("70.basic", ".//enemySound//basic.wav", false, false);
	SOUNDMANAGER->addSound("71.boss_reflex", ".//enemySound//boss_reflex.wav", false, false);
}