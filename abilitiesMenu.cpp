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
	IMAGEMANAGER->addImage("스킬메뉴씬", ".\\SceneImage\\abilitiesMenu.bmp", 1024, 760, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("선택", ".\\SceneImage\\selectPoint.bmp", 27, 27, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("플레이어1얼굴", ".\\playerImage\\player1face.bmp", 100, 100, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("플레이어2얼굴", ".\\playerImage\\player2face.bmp", 100, 100, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("플레이어3얼굴", ".\\playerImage\\player3face.bmp", 100, 100, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("플레이어얼굴배경", ".\\SceneImage\\faceBackground.bmp", 108, 108, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("플레이어버튼", ".\\userInterface\\noselButton.bmp", 220, 40, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("플레이어버튼선택", ".\\userInterface\\selButton.bmp", 220, 40, true, RGB(255, 0, 255));

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

	IMAGEMANAGER->findImage("스킬메뉴씬")->render(getMemDC(), 0, 0);

	for (int i = 0; i < 3; ++i)
	{
		IMAGEMANAGER->findImage("플레이어버튼")->render(getMemDC(), 40 + i * 240, 56);
		if ((_cursorMenuNum - 1) == i)
		{
			IMAGEMANAGER->findImage("플레이어버튼선택")->render(getMemDC(), 40 + i * 240, 56);
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
	
	IMAGEMANAGER->findImage("선택")->render(getMemDC(), 50 + (_cursorMenuNum - 1) * 240, 64);

	if (_isCharater1 == true)
	{
		IMAGEMANAGER->findImage("플레이어얼굴배경")->render(getMemDC(), 145, 127);
		IMAGEMANAGER->findImage("플레이어1얼굴")->render(getMemDC(), 148, 130);
		player1Information();
	}
	if (_isCharater2 == true)
	{
		IMAGEMANAGER->findImage("플레이어얼굴배경")->render(getMemDC(), 145, 127);
		IMAGEMANAGER->findImage("플레이어2얼굴")->render(getMemDC(), 148, 130);
		player2Information();
	}
	if (_isCharater3 == true)
	{
		IMAGEMANAGER->findImage("플레이어얼굴배경")->render(getMemDC(), 145, 127);
		IMAGEMANAGER->findImage("플레이어3얼굴")->render(getMemDC(), 148, 130);
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
		SOUNDMANAGER->play("메뉴선택", 1.0f); //메뉴선택 소리

		if (_cursorMenuNum == 1) _cursorMenuNum = 2;
		else if (_cursorMenuNum == 2) _cursorMenuNum = 3;
		else if (_cursorMenuNum == 3) _cursorMenuNum = 3;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
	{
		SOUNDMANAGER->play("메뉴선택", 1.0f); //메뉴선택 소리

		if (_cursorMenuNum == 1) _cursorMenuNum = 1;
		else if (_cursorMenuNum == 2) _cursorMenuNum = 1;
		else if (_cursorMenuNum == 3) _cursorMenuNum = 2;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_RETURN))
	{
		SOUNDMANAGER->play("메뉴선택", 1.0f); //메뉴선택 소리

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
		SOUNDMANAGER->play("메뉴선택", 1.0f); //메뉴선택 소리

		SCENEMANAGER->changeScene("메뉴씬", FALSE);
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