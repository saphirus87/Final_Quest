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
	SOUNDMANAGER->play("02.선택", 0.75);
	IMAGEMANAGER->addImage("스타트씬", ".\\SceneImage\\startBackground.bmp", 1024, 665, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("선택", ".\\SceneImage\\selectPoint.bmp", 27, 27, true, RGB(255, 0, 255));

	_cursorMenuNum = 1;

	_alpha = 5;
	_isStart = true;

	CAMERAMANAGER->addImage("스타트", WINSIZEX, WINSIZEY);

	return S_OK;
}

void gameStartScene::release()
{

}

void gameStartScene::update() 
{
	alphaPlusMinus(_isStart, &_alpha);
	keyControl();
}

void gameStartScene::render() 
{
	//_startBackground->render(getMemDC(), WINSIZEX / 2 - _startBackground->getWidth() / 2, WINSIZEY / 2 - _startBackground->getHeight() / 2);

	IMAGEMANAGER->findImage("스타트씬")->render(CAMERAMANAGER->findImage("스타트")->getMemDC(), 0, 47);
	
	if (_alpha == 255)
	{
		if (_cursorMenuNum == 1)
		{
			IMAGEMANAGER->findImage("선택")->render(CAMERAMANAGER->findImage("스타트")->getMemDC(), WINSIZEX / 2 - 150, WINSIZEY / 2 + 120);
		}
		if (_cursorMenuNum == 2)
		{
			IMAGEMANAGER->findImage("선택")->render(CAMERAMANAGER->findImage("스타트")->getMemDC(), WINSIZEX / 2 - 150, WINSIZEY / 2 + 180);
		}
		if (_cursorMenuNum == 3)
		{
			IMAGEMANAGER->findImage("선택")->render(CAMERAMANAGER->findImage("스타트")->getMemDC(), WINSIZEX / 2 - 150, WINSIZEY / 2 + 240);
		}
	}

	CAMERAMANAGER->findImage("스타트")->alphaCameraRender(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, 0, 0, 1, _alpha);
}

void gameStartScene::keyControl()
{
	if (_alpha == 255)
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
	}

	if (KEYMANAGER->isOnceKeyDown(VK_RETURN))
	{
		if (_cursorMenuNum == 1)
		{
			if (_isStart == true && _alpha == 255)
			{
				_isStart = false;
			}
		}
		else if (_cursorMenuNum == 2)
		{
			SCENEMANAGER->changeScene("세이브로드메뉴씬");
		}
		else if (_cursorMenuNum == 3)
		{
			PostQuitMessage(0);
		}
	}

	if (_alpha == 0)
	{
		SCENEMANAGER->changeScene("fieldScene");

		_isStart = true;
	}
}
