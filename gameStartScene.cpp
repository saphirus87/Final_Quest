#include "stdafx.h"
#include "gameStartScene.h"


gameStartScene::gameStartScene()
{
}


gameStartScene::~gameStartScene()
{

}

HRESULT gameStartScene::init()
{
	_startBackground = IMAGEMANAGER->addImage("스타트씬", ".\\SceneImage\\startBackground.bmp", 1024, 665, true, RGB(255, 0, 255));
	_selectCursor = IMAGEMANAGER->addImage("스타트선택", ".\\SceneImage\\selectPoint.bmp", 27, 27, true, RGB(255, 0, 255));

	_cursorMenuNum = 1;

	return S_OK;
}

void gameStartScene::release()
{

}

void gameStartScene::update() 
{
	if (KEYMANAGER->isOnceKeyDown(VK_UP))
	{
		if (_cursorMenuNum == 1) _cursorMenuNum = 3;
		else if (_cursorMenuNum == 2) _cursorMenuNum = 1;
		else if (_cursorMenuNum == 3) _cursorMenuNum = 2;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
	{
		if (_cursorMenuNum == 1) _cursorMenuNum = 2;
		else if (_cursorMenuNum == 2) _cursorMenuNum = 3;
		else if (_cursorMenuNum == 3) _cursorMenuNum = 1;
	}

	if (KEYMANAGER->isOnceKeyDown(VK_RETURN))
	{
		if (_cursorMenuNum == 1)
		{
			SCENEMANAGER->changeScene("메뉴씬");
		}
		else if (_cursorMenuNum == 3)
		{
			PostQuitMessage(0);
		}
	}
}

void gameStartScene::render() 
{
	_startBackground->render(getMemDC(), WINSIZEX / 2 - _startBackground->getWidth() / 2, WINSIZEY / 2 - _startBackground->getHeight() / 2);

	if (_cursorMenuNum == 1)
	{
		_selectCursor->render(getMemDC(), WINSIZEX / 2 - 150, WINSIZEY / 2 + 120);
	}
	if (_cursorMenuNum == 2)
	{
		_selectCursor->render(getMemDC(), WINSIZEX / 2 - 150, WINSIZEY / 2 + 180);
	}
	if (_cursorMenuNum == 3)
	{
		_selectCursor->render(getMemDC(), WINSIZEX / 2 - 150, WINSIZEY / 2 + 240);
	}
}