#include "stdafx.h"
#include "playGround.h"



//�뷡 �߰��� ���� cpp����
//playGround�� ���ӵ�
//map�� �ڵ����� Ư����
//01,02���� ��ȣ�� ����Ͽ� ���� ����
void playGround::soundInit()
{
	SOUNDMANAGER->addSound("01.������", ".//musicSound//openingThema.mp3", true, true);
	SOUNDMANAGER->addSound("02.����", ".//musicSound//selectScene.mp3", true, true);

	//���ʹ� ����
	SOUNDMANAGER->addSound("70.basic", ".//enemySound//basic.mp3", true, true);
	SOUNDMANAGER->addSound("71.boss_reflex", ".//enemySound//boss_reflex", true, true);
}