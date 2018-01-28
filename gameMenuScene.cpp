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
	IMAGEMANAGER->addImage("�޴���", ".\\SceneImage\\mainMenu.bmp", 1024, 760, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("����", ".\\SceneImage\\selectPoint.bmp", 27, 27, true, RGB(255, 0, 255));

	_cursorMenuNum = 1;

	_alpha = 0;
	_isMenu = true;

	CAMERAMANAGER->addImage("�޴�", WINSIZEX, WINSIZEY);

	return S_OK;
}

void gameMenuScene::release()
{

}

void gameMenuScene::update()
{
	alphaPlusMinus(_isMenu, &_alpha);
	keyControl();
}

void gameMenuScene::render()
{
	IMAGEMANAGER->findImage("�޴���")->render(CAMERAMANAGER->findImage("�޴�")->getMemDC(), 0, 0);

	if (_alpha == 255)
	{
		if (_cursorMenuNum == 1)
		{
			IMAGEMANAGER->findImage("����")->render(CAMERAMANAGER->findImage("�޴�")->getMemDC(), WINSIZEX / 2 + 250, 85);
		}
		if (_cursorMenuNum == 2)
		{
			IMAGEMANAGER->findImage("����")->render(CAMERAMANAGER->findImage("�޴�")->getMemDC(), WINSIZEX / 2 + 250, 165);
		}
		if (_cursorMenuNum == 3)
		{
			IMAGEMANAGER->findImage("����")->render(CAMERAMANAGER->findImage("�޴�")->getMemDC(), WINSIZEX / 2 + 250, 245);
		}
		if (_cursorMenuNum == 4)
		{
			IMAGEMANAGER->findImage("����")->render(CAMERAMANAGER->findImage("�޴�")->getMemDC(), WINSIZEX / 2 + 250, 325);
		}
		if (_cursorMenuNum == 5)
		{
			IMAGEMANAGER->findImage("����")->render(CAMERAMANAGER->findImage("�޴�")->getMemDC(), WINSIZEX / 2 + 250, 405);
		}
		if (_cursorMenuNum == 6)
		{
			IMAGEMANAGER->findImage("����")->render(CAMERAMANAGER->findImage("�޴�")->getMemDC(), WINSIZEX / 2 + 250, 485);
		}

		if (_cursorMenuNum == 7)
		{
			IMAGEMANAGER->findImage("����")->render(CAMERAMANAGER->findImage("�޴�")->getMemDC(), 40, 115);
		}
		if (_cursorMenuNum == 8)
		{
			IMAGEMANAGER->findImage("����")->render(CAMERAMANAGER->findImage("�޴�")->getMemDC(), 40, 265);
		}
		if (_cursorMenuNum == 9)
		{
			IMAGEMANAGER->findImage("����")->render(CAMERAMANAGER->findImage("�޴�")->getMemDC(), 40, 415);
		}
		if (_cursorMenuNum == 10)
		{
			IMAGEMANAGER->findImage("����")->render(CAMERAMANAGER->findImage("�޴�")->getMemDC(), 40, 565);
		}
	}

	CAMERAMANAGER->findImage("�޴�")->alphaCameraRender(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, 0, 0, 1, _alpha);
}

void gameMenuScene::keyControl()
{
	if (_alpha == 255)
	{
		if (KEYMANAGER->isOnceKeyDown(VK_UP))
		{
			SOUNDMANAGER->play("�޴�����", 1.0f); //�޴����� �Ҹ�

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
			SOUNDMANAGER->play("�޴�����", 1.0f); //�޴����� �Ҹ�

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
			SOUNDMANAGER->play("�޴�����", 1.0f); //�޴����� �Ҹ�

			if (_cursorMenuNum < 7) _cursorMenuNum = 7;
		}
		if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
		{
			SOUNDMANAGER->play("�޴�����", 1.0f); //�޴����� �Ҹ�

			if (_cursorMenuNum > 6) _cursorMenuNum = 1;
		}
		if (KEYMANAGER->isOnceKeyDown(VK_RETURN))
		{
			SOUNDMANAGER->play("�޴�����", 1.0f); //�޴����� �Ҹ�

			if (_cursorMenuNum == 1)
			{
				SCENEMANAGER->changeScene("�����۸޴���");
			}
			else if (_cursorMenuNum == 2)
			{
				SCENEMANAGER->changeScene("��ų�޴���");
			}
			else if (_cursorMenuNum == 3)
			{
				SCENEMANAGER->changeScene("���޴���");
			}
			else if (_cursorMenuNum == 4)
			{
				SCENEMANAGER->changeScene("�������ͽ��޴���");
			}
			else if (_cursorMenuNum == 5)
			{
				SCENEMANAGER->changeScene("���̺�ε�޴���");
			}
			else if (_cursorMenuNum == 6)
			{
				SCENEMANAGER->changeScene("�ɼǾ�", FALSE);
			}
		}
		if (KEYMANAGER->isOnceKeyDown(VK_BACK))
		{
			SOUNDMANAGER->play("�޴�����", 1.0f); //�޴����� �Ҹ�

			_isMenu = false;
		}
	}
	
	if (_alpha == 0)
	{
		SCENEMANAGER->changeScene(_iswhere, FALSE);

		_isMenu = true;
	}
}
