#include "stdafx.h"
#include "abilitiesMenu.h"
#include "playerManager.h"

abilitiesMenu::abilitiesMenu()
{
}


abilitiesMenu::~abilitiesMenu()
{

}

HRESULT abilitiesMenu::init()
{
	IMAGEMANAGER->addImage("��ų�޴���", ".\\SceneImage\\abilitiesMenu.bmp", 1024, 760, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("����", ".\\SceneImage\\selectPoint.bmp", 27, 27, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�÷��̾�1��", ".\\playerImage\\player1face.bmp", 100, 100, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�÷��̾�2��", ".\\playerImage\\player2face.bmp", 100, 100, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�÷��̾�3��", ".\\playerImage\\player3face.bmp", 100, 100, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�÷��̾�󱼹��", ".\\SceneImage\\faceBackground.bmp", 108, 108, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�÷��̾��ư", ".\\userInterface\\noselButton.bmp", 220, 40, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�÷��̾��ư����", ".\\userInterface\\selButton.bmp", 220, 40, true, RGB(255, 0, 255));

	_cursorMenuNum = 1;

	_isCharater1 = false;
	_isCharater2 = false;
	_isCharater3 = false;

	return S_OK;
}

void abilitiesMenu::release()
{

}

void abilitiesMenu::update() 
{
	keyControl();
}

void abilitiesMenu::render() 
{
	HFONT hFont = CreateFont(20, 0, 0, 0, 600, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, VARIABLE_PITCH | FF_ROMAN, TEXT("consolas"));
	HFONT oFont = (HFONT)SelectObject(getMemDC(), hFont);

	SetBkMode(getMemDC(), TRANSPARENT);
	SetTextColor(getMemDC(), RGB(220, 220, 220));

	IMAGEMANAGER->findImage("��ų�޴���")->render(getMemDC(), 0, 0);

	for (int i = 0; i < 3; ++i)
	{
		IMAGEMANAGER->findImage("�÷��̾��ư")->render(getMemDC(), 40 + i * 240, 56);
		if ((_cursorMenuNum - 1) == i)
		{
			IMAGEMANAGER->findImage("�÷��̾��ư����")->render(getMemDC(), 40 + i * 240, 56);
		}
	}

	for (int i = 0; i < 3; ++i)
	{
		if (_pm->getvplayer()[i]->getCurrentHp())
		{
			SetTextColor(getMemDC(), RGB(255, 255, 255));
		}
		else
		{
			SetTextColor(getMemDC(), RGB(255, 0, 0));
		}

		char str[128];
		sprintf(str, "%s", _pm->getvplayer()[i]->getName().c_str());
		TextOut(getMemDC(), 125 + 235 * i, 65, str, strlen(str));
	}
	
	IMAGEMANAGER->findImage("����")->render(getMemDC(), 50 + (_cursorMenuNum - 1) * 240, 64);

	if (_isCharater1 == true)
	{
		IMAGEMANAGER->findImage("�÷��̾�󱼹��")->render(getMemDC(), 145, 127);
		IMAGEMANAGER->findImage("�÷��̾�1��")->render(getMemDC(), 148, 130);
		player1Information();
	}
	if (_isCharater2 == true)
	{
		IMAGEMANAGER->findImage("�÷��̾�󱼹��")->render(getMemDC(), 145, 127);
		IMAGEMANAGER->findImage("�÷��̾�2��")->render(getMemDC(), 148, 130);
		player2Information();
	}
	if (_isCharater3 == true)
	{
		IMAGEMANAGER->findImage("�÷��̾�󱼹��")->render(getMemDC(), 145, 127);
		IMAGEMANAGER->findImage("�÷��̾�3��")->render(getMemDC(), 148, 130);
		player3Information();
	}

	SelectObject(getMemDC(), oFont);
	DeleteObject(hFont);
	DeleteObject(oFont);
}

void abilitiesMenu::keyControl()
{
	if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
	{
		SOUNDMANAGER->play("�޴�����", 1.0f); //�޴����� �Ҹ�

		if (_cursorMenuNum == 1) _cursorMenuNum = 2;
		else if (_cursorMenuNum == 2) _cursorMenuNum = 3;
		else if (_cursorMenuNum == 3) _cursorMenuNum = 3;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
	{
		SOUNDMANAGER->play("�޴�����", 1.0f); //�޴����� �Ҹ�

		if (_cursorMenuNum == 1) _cursorMenuNum = 1;
		else if (_cursorMenuNum == 2) _cursorMenuNum = 1;
		else if (_cursorMenuNum == 3) _cursorMenuNum = 2;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_RETURN))
	{
		SOUNDMANAGER->play("�޴�����", 1.0f); //�޴����� �Ҹ�

		if (_cursorMenuNum == 1)
		{
			_isCharater1 = true;
			_isCharater2 = false;
			_isCharater3 = false;
		}
		if (_cursorMenuNum == 2)
		{
			_isCharater1 = false;
			_isCharater2 = true;
			_isCharater3 = false;
		}
		if (_cursorMenuNum == 3)
		{
			_isCharater1 = false;
			_isCharater2 = false;
			_isCharater3 = true;
		}
	}

	if (KEYMANAGER->isOnceKeyDown(VK_BACK))
	{
		SOUNDMANAGER->play("�޴�����", 1.0f); //�޴����� �Ҹ�

		SCENEMANAGER->changeScene("�޴���", FALSE);
	}
}

void abilitiesMenu::player1Information()
{
	char str[128];

	sprintf(str, "%d", _pm->getvplayer()[0]->getLevel());
	TextOut(getMemDC(), 600 - strlen(str) * 10, 156, str, strlen(str));

	sprintf(str, "%d / %d", _pm->getvplayer()[0]->getCurrentHp(), _pm->getvplayer()[0]->getMaxHp());
	TextOut(getMemDC(), 600 - strlen(str) * 10, 183, str, strlen(str));

	sprintf(str, "%d / %d", _pm->getvplayer()[0]->getCurrentMp(), _pm->getvplayer()[0]->getMaxMp());
	TextOut(getMemDC(), 600 - strlen(str) * 10, 210, str, strlen(str));
}

void abilitiesMenu::player2Information()
{
	char str[128];

	sprintf(str, "%d", _pm->getvplayer()[1]->getLevel());
	TextOut(getMemDC(), 600 - strlen(str) * 10, 156, str, strlen(str));

	sprintf(str, "%d / %d", _pm->getvplayer()[1]->getCurrentHp(), _pm->getvplayer()[0]->getMaxHp());
	TextOut(getMemDC(), 600 - strlen(str) * 10, 183, str, strlen(str));

	sprintf(str, "%d / %d", _pm->getvplayer()[1]->getCurrentMp(), _pm->getvplayer()[0]->getMaxMp());
	TextOut(getMemDC(), 600 - strlen(str) * 10, 210, str, strlen(str));
}

void abilitiesMenu::player3Information()
{
	char str[128];

	sprintf(str, "%d", _pm->getvplayer()[2]->getLevel());
	TextOut(getMemDC(), 600 - strlen(str) * 10, 156, str, strlen(str));

	sprintf(str, "%d / %d", _pm->getvplayer()[2]->getCurrentHp(), _pm->getvplayer()[0]->getMaxHp());
	TextOut(getMemDC(), 600 - strlen(str) * 10, 183, str, strlen(str));

	sprintf(str, "%d / %d", _pm->getvplayer()[2]->getCurrentMp(), _pm->getvplayer()[0]->getMaxMp());
	TextOut(getMemDC(), 600 - strlen(str) * 10, 210, str, strlen(str));
}