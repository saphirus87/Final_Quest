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
	IMAGEMANAGER->addImage("��ŸƮ��", ".\\SceneImage\\startBackground.bmp", 1024, 665, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("����", ".\\SceneImage\\selectPoint.bmp", 27, 27, true, RGB(255, 0, 255));

	_cursorMenuNum = 1;

	_alpha = 5;
	_isStart = true;

	CAMERAMANAGER->addImage("��ŸƮ", WINSIZEX, WINSIZEY);

	return S_OK;
}

void gameStartScene::release()
{

}

void gameStartScene::update() 
{
	if (!SOUNDMANAGER->isPlaySound("����"))
	{
		SOUNDMANAGER->play("����", 0.75);
	}

	alphaPlusMinus(_isStart, &_alpha);
	keyControl();
}

void gameStartScene::render() 
{
	//_startBackground->render(getMemDC(), WINSIZEX / 2 - _startBackground->getWidth() / 2, WINSIZEY / 2 - _startBackground->getHeight() / 2);

	IMAGEMANAGER->findImage("��ŸƮ��")->render(CAMERAMANAGER->findImage("��ŸƮ")->getMemDC(), 0, 47);
	
	if (_alpha == 255)
	{
		if (_cursorMenuNum == 1)
		{
			IMAGEMANAGER->findImage("����")->render(CAMERAMANAGER->findImage("��ŸƮ")->getMemDC(), WINSIZEX / 2 - 150, WINSIZEY / 2 + 120);
		}
		if (_cursorMenuNum == 2)
		{
			IMAGEMANAGER->findImage("����")->render(CAMERAMANAGER->findImage("��ŸƮ")->getMemDC(), WINSIZEX / 2 - 150, WINSIZEY / 2 + 180);
		}
		if (_cursorMenuNum == 3)
		{
			IMAGEMANAGER->findImage("����")->render(CAMERAMANAGER->findImage("��ŸƮ")->getMemDC(), WINSIZEX / 2 - 150, WINSIZEY / 2 + 240);
		}
	}

	CAMERAMANAGER->findImage("��ŸƮ")->alphaCameraRender(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, 0, 0, 1, _alpha);
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
			SOUNDMANAGER->play("�޴�����",1.0f);
		}
		if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
		{
			if (_cursorMenuNum == 1) _cursorMenuNum = 2;
			else if (_cursorMenuNum == 2) _cursorMenuNum = 3;
			else if (_cursorMenuNum == 3) _cursorMenuNum = 1;
			SOUNDMANAGER->play("�޴�����", 1.0f);
		}
	}

	if (KEYMANAGER->isOnceKeyDown(VK_RETURN))
	{
		if (_cursorMenuNum == 1)
		{
			if (_isStart == true && _alpha == 255)
			{
				SOUNDMANAGER->setMusicVolume(0.0f);
				SOUNDMANAGER->setEffectVolume(0.0f);
				SOUNDMANAGER->setPan(2);
				_isStart = false;
			}
		}
		else if (_cursorMenuNum == 2)
		{
			SCENEMANAGER->changeScene("��ŸƮ���̺�ε�޴���");
		}
		else if (_cursorMenuNum == 3)
		{
			PostQuitMessage(0);
		}
		SOUNDMANAGER->play("�޴�����", 1.0f);


			
	
	}

	if (_alpha == 0)
	{
		SOUNDMANAGER->stop("����");
		SCENEMANAGER->changeScene("fieldScene");
		SOUNDMANAGER->play("Ƽ��", 0.75f, true);
		_isStart = true;
	}
}
