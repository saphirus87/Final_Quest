#include "stdafx.h"
#include "equipMenu.h"


equipMenu::equipMenu()
{
}


equipMenu::~equipMenu()
{

}

HRESULT equipMenu::init()
{
	IMAGEMANAGER->addImage("장비메뉴씬", ".\\SceneImage\\equipMenu.bmp", 1024, 760, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("선택", ".\\SceneImage\\selectPoint.bmp", 27, 27, true, RGB(255, 0, 255));

	_cursorMenuNum = 1;

	_isCharater1 = false;
	_isCharater2 = false;
	_isCharater3 = false;

	return S_OK;
}

void equipMenu::release()
{

}

void equipMenu::update() 
{
	keyControl();
}

void equipMenu::render() 
{
	//배경 뿌리기
	IMAGEMANAGER->findImage("장비메뉴씬")->render(getMemDC(), 0, 0);
	//매뉴 버튼 뿌리기
	for (int i = 0; i < 3; ++i)
	{
		if (_cursorMenuNum == i + 1)
		{
			IMAGEMANAGER->findImage("아이템매뉴선택")->render(getMemDC(), 40 + i * 240, 56);
		}
		else
		{
			IMAGEMANAGER->findImage("아이템매뉴버튼")->render(getMemDC(), 40 + i * 240, 56);
		}
	}
	IMAGEMANAGER->findImage("선택")->render(getMemDC(), 50 + (_cursorMenuNum - 1) * 240, 64);

	if (_isCharater1 == true)
	{
		IMAGEMANAGER->findImage("플레이어1얼굴")->render(getMemDC(), 90, 160);
	}
	if (_isCharater2 == true)
	{
		IMAGEMANAGER->findImage("플레이어2얼굴")->render(getMemDC(), 90, 160);
	}
	if (_isCharater3 == true)
	{
		//IMAGEMANAGER->findImage("플레이어2얼굴")->render(getMemDC(), 90, 160);
	}
}

void equipMenu::keyControl()
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
		SCENEMANAGER->changeScene("메뉴씬", FALSE);
	}
}
