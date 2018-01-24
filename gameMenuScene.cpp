#include "stdafx.h"
#include "gameMenuScene.h"

gameMenuScene::gameMenuScene()
{
}


gameMenuScene::~gameMenuScene()
{

}

HRESULT gameMenuScene::init()
{
	_menuScene = IMAGEMANAGER->addImage("메뉴씬", ".\\SceneImage\\mainMenu.bmp", 1024, 760, true, RGB(255, 0, 255));
	_selectCursor = IMAGEMANAGER->addImage("메뉴씬선택", ".\\SceneImage\\selectPoint.bmp", 27, 27, true, RGB(255, 0, 255));

	_cursorMenuNum = 1;

	return S_OK;
}

void gameMenuScene::release()
{

}

void gameMenuScene::update()
{
	selectMove();
}

void gameMenuScene::render()
{
	_menuScene->render(getMemDC(), WINSIZEX / 2 - _menuScene->getWidth() / 2, WINSIZEY / 2 - _menuScene->getHeight() / 2);

	if (_cursorMenuNum == 1)
	{
		_selectCursor->render(getMemDC(), WINSIZEX / 2 + 250, 85);
	}
	if (_cursorMenuNum == 2)
	{
		_selectCursor->render(getMemDC(), WINSIZEX / 2 + 250, 165);
	}
	if (_cursorMenuNum == 3)
	{
		_selectCursor->render(getMemDC(), WINSIZEX / 2 + 250, 245);
	}
	if (_cursorMenuNum == 4)
	{
		_selectCursor->render(getMemDC(), WINSIZEX / 2 + 250, 325);
	}
	if (_cursorMenuNum == 5)
	{
		_selectCursor->render(getMemDC(), WINSIZEX / 2 + 250, 405);
	}
	if (_cursorMenuNum == 6)
	{
		_selectCursor->render(getMemDC(), WINSIZEX / 2 + 250, 485);
	}

	if (_cursorMenuNum == 7)
	{
		_selectCursor->render(getMemDC(), 40, 115);
	}
	if (_cursorMenuNum == 8)
	{
		_selectCursor->render(getMemDC(), 40, 265);
	}
	if (_cursorMenuNum == 9)
	{
		_selectCursor->render(getMemDC(), 40, 415);
	}
	if (_cursorMenuNum == 10)
	{
		_selectCursor->render(getMemDC(), 40, 565);
	}
}

void gameMenuScene::selectMove()
{
	if (KEYMANAGER->isOnceKeyDown(VK_UP))
	{
		if (_cursorMenuNum == 1) _cursorMenuNum = 6;
		else if (_cursorMenuNum == 2) _cursorMenuNum = 1;
		else if (_cursorMenuNum == 3) _cursorMenuNum = 2;
		else if (_cursorMenuNum == 4) _cursorMenuNum = 3;
		else if (_cursorMenuNum == 5) _cursorMenuNum = 4;
		else if (_cursorMenuNum == 6) _cursorMenuNum = 5;
		else if (_cursorMenuNum == 7) _cursorMenuNum = 10;
		else if (_cursorMenuNum == 8) _cursorMenuNum = 7;
		else if (_cursorMenuNum == 9) _cursorMenuNum = 8;
		else if (_cursorMenuNum == 10) _cursorMenuNum = 9;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
	{
		if (_cursorMenuNum == 1) _cursorMenuNum = 2;
		else if (_cursorMenuNum == 2) _cursorMenuNum = 3;
		else if (_cursorMenuNum == 3) _cursorMenuNum = 4;
		else if (_cursorMenuNum == 4) _cursorMenuNum = 5;
		else if (_cursorMenuNum == 5) _cursorMenuNum = 6;
		else if (_cursorMenuNum == 6) _cursorMenuNum = 1;
		else if (_cursorMenuNum == 7) _cursorMenuNum = 8;
		else if (_cursorMenuNum == 8) _cursorMenuNum = 9;
		else if (_cursorMenuNum == 9) _cursorMenuNum = 10;
		else if (_cursorMenuNum == 10) _cursorMenuNum = 7;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
	{
		if (_cursorMenuNum < 7) _cursorMenuNum = 7;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
	{
		if (_cursorMenuNum > 6) _cursorMenuNum = 1;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_RETURN))
	{
		if (_cursorMenuNum == 1)
		{
			SCENEMANAGER->changeScene("아이템메뉴씬");
		}
		else if (_cursorMenuNum == 2)
		{
			SCENEMANAGER->changeScene("스킬메뉴씬");
		}
		else if (_cursorMenuNum == 3)
		{
			PostQuitMessage(0);
		}
		else if (_cursorMenuNum == 4)
		{
			PostQuitMessage(0);
		}
		else if (_cursorMenuNum == 5)
		{
			SCENEMANAGER->changeScene("세이브로드메뉴씬");
		}
		else if (_cursorMenuNum == 6)
		{
			PostQuitMessage(0);
		}
	}
	else if (KEYMANAGER->isOnceKeyDown(VK_BACK))
	{
		SCENEMANAGER->changeScene("fieldScene");
	}
}