#include "stdafx.h"
#include "abilitiesMenu.h"


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
	IMAGEMANAGER->findImage("��ų�޴���")->render(getMemDC(), 0, 0);

	if (_cursorMenuNum == 1)
	{
		IMAGEMANAGER->findImage("����")->render(getMemDC(), 25, 65);
	}
	if (_cursorMenuNum == 2)
	{
		IMAGEMANAGER->findImage("����")->render(getMemDC(), 280, 65);
	}
	if (_cursorMenuNum == 3)
	{
		IMAGEMANAGER->findImage("����")->render(getMemDC(), 535, 65);
	}
	if (_isCharater1 == true)
	{
		IMAGEMANAGER->findImage("�÷��̾�1��")->render(getMemDC(), 155, 130);
	}
	if (_isCharater2 == true)
	{
		IMAGEMANAGER->findImage("�÷��̾�2��")->render(getMemDC(), 155, 130);
	}
	if (_isCharater3 == true)
	{
		//IMAGEMANAGER->findImage("�÷��̾�2��")->render(getMemDC(), 155, 130);
	}
}

void abilitiesMenu::keyControl()
{
	if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
	{
		if (_cursorMenuNum == 1) _cursorMenuNum = 2;
		else if (_cursorMenuNum == 2) _cursorMenuNum = 3;
		else if (_cursorMenuNum == 3) _cursorMenuNum = 3;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
	{
		if (_cursorMenuNum == 1) _cursorMenuNum = 1;
		else if (_cursorMenuNum == 2) _cursorMenuNum = 1;
		else if (_cursorMenuNum == 3) _cursorMenuNum = 2;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_RETURN))
	{
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
		SCENEMANAGER->changeScene("�޴���", FALSE);
	}
}
