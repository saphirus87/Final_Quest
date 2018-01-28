#include "stdafx.h"
#include "statusMenu.h"
#include "playerManager.h"


statusMenu::statusMenu()
{
}


statusMenu::~statusMenu()
{

}

HRESULT statusMenu::init()
{
	IMAGEMANAGER->addImage("스테이터스메뉴씬", ".\\SceneImage\\statusMenu.bmp", 1024, 760, true, RGB(255, 0, 255));
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

void statusMenu::release()
{

}

void statusMenu::update() 
{
	keyControl();
}

void statusMenu::render() 
{
	HFONT hFont = CreateFont(20, 0, 0, 0, 600, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, VARIABLE_PITCH | FF_ROMAN, TEXT("consolas"));
	HFONT oFont = (HFONT)SelectObject(getMemDC(), hFont);

	SetBkMode(getMemDC(), TRANSPARENT);
	SetTextColor(getMemDC(), RGB(220, 220, 220));

	IMAGEMANAGER->findImage("스테이터스메뉴씬")->render(getMemDC(), 0, 0);

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
		IMAGEMANAGER->findImage("플레이어얼굴배경")->render(getMemDC(), 152, 155);
		IMAGEMANAGER->findImage("플레이어1얼굴")->render(getMemDC(), 155, 158);
		player1Information();
	}
	if (_isCharater2 == true)
	{
		IMAGEMANAGER->findImage("플레이어얼굴배경")->render(getMemDC(), 152, 155);
		IMAGEMANAGER->findImage("플레이어2얼굴")->render(getMemDC(), 155, 158);
		player2Information();
	}
	if (_isCharater3 == true)
	{
		IMAGEMANAGER->findImage("플레이어얼굴배경")->render(getMemDC(), 152, 155);
		IMAGEMANAGER->findImage("플레이어3얼굴")->render(getMemDC(), 155, 158);
		player3Information();
	}

	SelectObject(getMemDC(), oFont);
	DeleteObject(hFont);
	DeleteObject(oFont);
}

void statusMenu::keyControl()
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
		SCENEMANAGER->changeScene("메뉴씬", FALSE);
	}
}

void statusMenu::player1Information()
{
	//스텟 부분 /////////////////////////////////////////////////////
	char str[128];
	int kkk = 340;
	int lll = 0;
	float nnn = 27.5;

	sprintf(str, "%d", _pm->getvplayer()[0]->getStr());
	TextOut(getMemDC(), 230, kkk + lll * nnn, str, strlen(str));
	++lll;

	sprintf(str, "%d", _pm->getvplayer()[0]->getAgi());
	TextOut(getMemDC(), 230, kkk + lll * nnn, str, strlen(str));
	++lll;

	sprintf(str, "%d", _pm->getvplayer()[0]->getAgi());
	TextOut(getMemDC(), 230, kkk + lll * nnn, str, strlen(str));
	++lll;

	char* str1 = "ㅡ";
	//sprintf(str, "%d", _pm->getvplayer()[0]->getAgi());
	TextOut(getMemDC(), 230, kkk + lll * nnn, str1, strlen(str1));
	++lll;

	str1 = "ㅡ";
	//sprintf(str, "%d", _pm->getvplayer()[0]->getAgi());
	TextOut(getMemDC(), 230, kkk + lll * nnn, str1, strlen(str1));
	++lll;

	sprintf(str, "%d", _pm->getvplayer()[0]->getAgi());
	TextOut(getMemDC(), 230, kkk + lll * nnn, str, strlen(str));
	++lll;

	str1 = "ㅡ";
	//sprintf(str, "%d", _pm->getvplayer()[0]->getAgi());
	TextOut(getMemDC(), 230, kkk + lll * nnn, str1, strlen(str1));
	++lll;

	sprintf(str, "%d", _pm->getvplayer()[0]->getAgi());
	TextOut(getMemDC(), 230, kkk + lll * nnn, str, strlen(str));
	++lll;

	str1 = "ㅡ";
	sprintf(str, "%d", _pm->getvplayer()[0]->getAgi());
	TextOut(getMemDC(), 230, kkk + lll * nnn, str1, strlen(str1));
	//////////////////////////////////////////////////////////////////

	char str2[128];

	//sprintf(str2, "%s", _pm->getvplayer()[0]->getName().c_str());
	//TextOut(getMemDC(), 650, 130, str2, strlen(str2));

	sprintf(str2, "%d", _pm->getvplayer()[0]->getLevel());
	TextOut(getMemDC(), 700 - strlen(str2) * 10, 156, str2, strlen(str2));

	sprintf(str2, "%d / %d", _pm->getvplayer()[0]->getCurrentHp(), _pm->getvplayer()[0]->getMaxHp());
	TextOut(getMemDC(), 700 - strlen(str2) * 10, 183, str2, strlen(str2));

	sprintf(str2, "%d / %d", _pm->getvplayer()[0]->getCurrentMp(), _pm->getvplayer()[0]->getMaxMp());
	TextOut(getMemDC(), 700 - strlen(str2) * 10, 210, str2, strlen(str2));

	sprintf(str2, "%d", _pm->getvplayer()[0]->getCurrentExp());
	TextOut(getMemDC(), 700 - strlen(str2) * 10, 237, str2, strlen(str2));

	sprintf(str2, "%d", _pm->getvplayer()[0]->getMaxExp() - _pm->getvplayer()[0]->getCurrentExp());
	TextOut(getMemDC(), 700 - strlen(str2) * 10, 264, str2, strlen(str2));

	char str3[128];

	sprintf(str3, "%s", _pm->getvplayer()[0]->getplayerEquip(0).name.c_str());
	TextOut(getMemDC(), 525, 515, str3, strlen(str3));
}

void statusMenu::player2Information()
{
	//스텟 부분 /////////////////////////////////////////////////////
	char str[128];
	int kkk = 340;
	int lll = 0;
	float nnn = 27.5;

	sprintf(str, "%d", _pm->getvplayer()[1]->getStr());
	TextOut(getMemDC(), 230, kkk + lll * nnn, str, strlen(str));
	++lll;

	sprintf(str, "%d", _pm->getvplayer()[1]->getAgi());
	TextOut(getMemDC(), 230, kkk + lll * nnn, str, strlen(str));
	++lll;

	sprintf(str, "%d", _pm->getvplayer()[1]->getAgi());
	TextOut(getMemDC(), 230, kkk + lll * nnn, str, strlen(str));
	++lll;

	char* str1 = "ㅡ";
	//sprintf(str, "%d", _pm->getvplayer()[1]->getAgi());
	TextOut(getMemDC(), 230, kkk + lll * nnn, str1, strlen(str1));
	++lll;

	str1 = "ㅡ";
	//sprintf(str, "%d", _pm->getvplayer()[1]->getAgi());
	TextOut(getMemDC(), 230, kkk + lll * nnn, str1, strlen(str1));
	++lll;

	sprintf(str, "%d", _pm->getvplayer()[1]->getAgi());
	TextOut(getMemDC(), 230, kkk + lll * nnn, str, strlen(str));
	++lll;

	str1 = "ㅡ";
	//sprintf(str, "%d", _pm->getvplayer()[1]->getAgi());
	TextOut(getMemDC(), 230, kkk + lll * nnn, str1, strlen(str1));
	++lll;

	sprintf(str, "%d", _pm->getvplayer()[1]->getAgi());
	TextOut(getMemDC(), 230, kkk + lll * nnn, str, strlen(str));
	++lll;

	str1 = "ㅡ";
	sprintf(str, "%d", _pm->getvplayer()[1]->getAgi());
	TextOut(getMemDC(), 230, kkk + lll * nnn, str1, strlen(str1));
	//////////////////////////////////////////////////////////////////

	char str2[128];

	//sprintf(str2, "%s", _pm->getvplayer()[1]->getName().c_str());
	//TextOut(getMemDC(), 650, 130, str2, strlen(str2));

	sprintf(str2, "%d", _pm->getvplayer()[1]->getLevel());
	TextOut(getMemDC(), 700 - strlen(str2) * 10, 156, str2, strlen(str2));

	sprintf(str2, "%d / %d", _pm->getvplayer()[1]->getCurrentHp(), _pm->getvplayer()[1]->getMaxHp());
	TextOut(getMemDC(), 700 - strlen(str2) * 10, 183, str2, strlen(str2));

	sprintf(str2, "%d / %d", _pm->getvplayer()[1]->getCurrentMp(), _pm->getvplayer()[1]->getMaxMp());
	TextOut(getMemDC(), 700 - strlen(str2) * 10, 210, str2, strlen(str2));

	sprintf(str2, "%d", _pm->getvplayer()[1]->getCurrentExp());
	TextOut(getMemDC(), 700 - strlen(str2) * 10, 237, str2, strlen(str2));

	sprintf(str2, "%d", _pm->getvplayer()[1]->getMaxExp() - _pm->getvplayer()[1]->getCurrentExp());
	TextOut(getMemDC(), 700 - strlen(str2) * 10, 264, str2, strlen(str2));
}

void statusMenu::player3Information()
{
	//스텟 부분 /////////////////////////////////////////////////////
	char str[128];
	int kkk = 340;
	int lll = 0;
	float nnn = 27.5;

	sprintf(str, "%d", _pm->getvplayer()[2]->getStr());
	TextOut(getMemDC(), 230, kkk + lll * nnn, str, strlen(str));
	++lll;

	sprintf(str, "%d", _pm->getvplayer()[2]->getAgi());
	TextOut(getMemDC(), 230, kkk + lll * nnn, str, strlen(str));
	++lll;

	sprintf(str, "%d", _pm->getvplayer()[2]->getAgi());
	TextOut(getMemDC(), 230, kkk + lll * nnn, str, strlen(str));
	++lll;

	char* str1 = "ㅡ";
	//sprintf(str, "%d", _pm->getvplayer()[2]->getAgi());
	TextOut(getMemDC(), 230, kkk + lll * nnn, str1, strlen(str1));
	++lll;

	str1 = "ㅡ";
	//sprintf(str, "%d", _pm->getvplayer()[2]->getAgi());
	TextOut(getMemDC(), 230, kkk + lll * nnn, str1, strlen(str1));
	++lll;

	sprintf(str, "%d", _pm->getvplayer()[2]->getAgi());
	TextOut(getMemDC(), 230, kkk + lll * nnn, str, strlen(str));
	++lll;

	str1 = "ㅡ";
	//sprintf(str, "%d", _pm->getvplayer()[2]->getAgi());
	TextOut(getMemDC(), 230, kkk + lll * nnn, str1, strlen(str1));
	++lll;

	sprintf(str, "%d", _pm->getvplayer()[2]->getAgi());
	TextOut(getMemDC(), 230, kkk + lll * nnn, str, strlen(str));
	++lll;

	str1 = "ㅡ";
	sprintf(str, "%d", _pm->getvplayer()[2]->getAgi());
	TextOut(getMemDC(), 230, kkk + lll * nnn, str1, strlen(str1));
	//////////////////////////////////////////////////////////////////

	char str2[128];

	//sprintf(str2, "%s", _pm->getvplayer()[2]->getName().c_str());
	//TextOut(getMemDC(), 650, 130, str2, strlen(str2));

	sprintf(str2, "%d", _pm->getvplayer()[2]->getLevel());
	TextOut(getMemDC(), 700 - strlen(str2) * 10, 156, str2, strlen(str2));

	sprintf(str2, "%d / %d", _pm->getvplayer()[2]->getCurrentHp(), _pm->getvplayer()[2]->getMaxHp());
	TextOut(getMemDC(), 700 - strlen(str2) * 10, 183, str2, strlen(str2));

	sprintf(str2, "%d / %d", _pm->getvplayer()[2]->getCurrentMp(), _pm->getvplayer()[2]->getMaxMp());
	TextOut(getMemDC(), 700 - strlen(str2) * 10, 210, str2, strlen(str2));

	sprintf(str2, "%d", _pm->getvplayer()[2]->getCurrentExp());
	TextOut(getMemDC(), 700 - strlen(str2) * 10, 237, str2, strlen(str2));

	sprintf(str2, "%d", _pm->getvplayer()[2]->getMaxExp() - _pm->getvplayer()[2]->getCurrentExp());
	TextOut(getMemDC(), 700 - strlen(str2) * 10, 264, str2, strlen(str2));
}
