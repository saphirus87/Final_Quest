#include "stdafx.h"
#include "playGround.h"



//�뷡 �߰��� ���� cpp����
//playGround�� ���ӵ�
//map�� �ڵ����� Ư����
//01,02���� ��ȣ�� ����Ͽ� ���� ����
void playGround::soundInit()
{
	SOUNDMANAGER->addSound("������", ".//musicSound//openingThema.mp3", true, true);
	SOUNDMANAGER->addSound("����", ".//musicSound//selectScene.mp3", true, true);
	SOUNDMANAGER->addSound("��Ʋ", ".//musicSound//battleThema.mp3",true, true);
	SOUNDMANAGER->addSound("��Ʋ�¸�", ".//musicSound//battleEnding.mp3", true, false);




	//���ʹ� ����
	SOUNDMANAGER->addSound("70.basic", ".//enemySound//basic.wav", false, false);
	SOUNDMANAGER->addSound("71.boss_reflex", ".//enemySound//boss_reflex.wav", false, false);
}