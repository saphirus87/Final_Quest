#include "stdafx.h"
#include "gameMenuScene.h"
#include "playerManager.h"

gameMenuScene::gameMenuScene()
{
}


gameMenuScene::~gameMenuScene()
{

}

HRESULT gameMenuScene::init()
{
	IMAGEMANAGER->addImage("�޴���", ".\\SceneImage\\mainMenu1.bmp", 1024, 760, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("����", ".\\SceneImage\\selectPoint.bmp", 27, 27, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("����2", ".\\SceneImage\\selectPoint.bmp", 27, 27, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�÷��̾�1��", ".\\playerImage\\player1face.bmp", 100, 100, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�÷��̾�2��", ".\\playerImage\\player2face.bmp", 100, 100, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�÷��̾�3��", ".\\playerImage\\player3face.bmp", 100, 100, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�÷��̾�󱼹��", ".\\SceneImage\\faceBackground.bmp", 108, 108, true, RGB(255, 0, 255));

	_cursorMenuNum = 1;

	_selectNum = 7;

	_alpha = 0;
	_isMenu = true;
	_isCharater = false;

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
	HFONT hFont = CreateFont(20, 0, 0, 0, 600, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, VARIABLE_PITCH | FF_ROMAN, TEXT("consolas"));
	HFONT oFont = (HFONT)SelectObject(CAMERAMANAGER->findImage("�޴�")->getMemDC(), hFont);

	SetBkMode(CAMERAMANAGER->findImage("�޴�")->getMemDC(), TRANSPARENT);
	SetTextColor(CAMERAMANAGER->findImage("�޴�")->getMemDC(), RGB(220, 220, 220));

	IMAGEMANAGER->findImage("�޴���")->render(CAMERAMANAGER->findImage("�޴�")->getMemDC(), 0, 0);

	for (int i = 0; i < 3; ++i)
	{
		playerInformation(i);
	}

	if (_alpha == 255)
	{
		if (_cursorMenuNum == 1)
		{
			IMAGEMANAGER->findImage("����")->render(CAMERAMANAGER->findImage("�޴�")->getMemDC(), WINSIZEX / 2 + 250, 85);
		}
		else if (_cursorMenuNum == 2)
		{
			IMAGEMANAGER->findImage("����")->render(CAMERAMANAGER->findImage("�޴�")->getMemDC(), WINSIZEX / 2 + 250, 165);
		}
		else if (_cursorMenuNum == 3)
		{
			IMAGEMANAGER->findImage("����")->render(CAMERAMANAGER->findImage("�޴�")->getMemDC(), WINSIZEX / 2 + 250, 245);
		}
		else if (_cursorMenuNum == 4)
		{
			IMAGEMANAGER->findImage("����")->render(CAMERAMANAGER->findImage("�޴�")->getMemDC(), WINSIZEX / 2 + 250, 325);
		}
		else if (_cursorMenuNum == 5)
		{
			IMAGEMANAGER->findImage("����")->render(CAMERAMANAGER->findImage("�޴�")->getMemDC(), WINSIZEX / 2 + 250, 405);
		}
		else if (_cursorMenuNum == 6)
		{
			IMAGEMANAGER->findImage("����")->render(CAMERAMANAGER->findImage("�޴�")->getMemDC(), WINSIZEX / 2 + 250, 485);
		}
		else
		{
			IMAGEMANAGER->findImage("����")->alphaRender(CAMERAMANAGER->findImage("�޴�")->getMemDC(), 20, 115 + (_selectNum - 1) * 150, _isCharater * 125);
			IMAGEMANAGER->findImage("����")->alphaRender(CAMERAMANAGER->findImage("�޴�")->getMemDC(), 20 + _isCharater * 20, 115 + (_cursorMenuNum - 7) * 150, 255);
		}
	}

	CAMERAMANAGER->findImage("�޴�")->alphaCameraRender(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, 0, 0, 1, _alpha);

	SelectObject(CAMERAMANAGER->findImage("�޴�")->getMemDC(), oFont);
	DeleteObject(hFont);
	DeleteObject(oFont);
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
			else if (_cursorMenuNum < 10)
			{
				playerposchange(_cursorMenuNum);
			}
		}
		
		if (KEYMANAGER->isOnceKeyDown(VK_UP))
		{
			SOUNDMANAGER->play("�޴�����", 1.0f); //�޴����� �Ҹ�

			if (_cursorMenuNum == 7) _cursorMenuNum = 10;
			else if (_cursorMenuNum == 8) _cursorMenuNum = 7;
			else if (_cursorMenuNum == 9) _cursorMenuNum = 8;
			else if (_cursorMenuNum == 10) _cursorMenuNum = 9;
		}

		if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
		{
			SOUNDMANAGER->play("�޴�����", 1.0f); //�޴����� �Ҹ�

			if (_cursorMenuNum == 7) _cursorMenuNum = 8;
			else if (_cursorMenuNum == 8) _cursorMenuNum = 9;
			else if (_cursorMenuNum == 9) _cursorMenuNum = 10;
			else if (_cursorMenuNum == 10) _cursorMenuNum = 7;
		}
		
		if (KEYMANAGER->isOnceKeyDown(VK_BACK))
		{
			SOUNDMANAGER->play("�޴�����", 1.0f); //�޴����� �Ҹ�
			if (_isCharater)
			{
				_isCharater = false;
			}
			else
			{
				_isMenu = false;
			}
		}
	}
	
	if (_alpha == 0)
	{
		SCENEMANAGER->changeScene(_iswhere, FALSE);

		_isMenu = true;
	}
}

void gameMenuScene::playerInformation(int playerv)
{
	IMAGEMANAGER->findImage("�÷��̾�󱼹��")->render(CAMERAMANAGER->findImage("�޴�")->getMemDC(), 100, 72 + (_pm->getvplayer()[playerv]->getpartyPos() - 1) * 150);

	char facename[128];
	sprintf(facename, "player%dface", playerv + 1);
	IMAGEMANAGER->findImage(facename)->render(CAMERAMANAGER->findImage("�޴�")->getMemDC(), 103, 75 + (_pm->getvplayer()[playerv]->getpartyPos() - 1) * 150);

	if (_pm->getvplayer()[playerv]->getCurrentHp())
	{
		SetTextColor(CAMERAMANAGER->findImage("�޴�")->getMemDC(), RGB(255, 255, 255));
	}
	else
	{
		SetTextColor(CAMERAMANAGER->findImage("�޴�")->getMemDC(), RGB(255, 0, 0));
	}

	char str2[128];
	sprintf(str2, "%s", _pm->getvplayer()[playerv]->getName().c_str());
	TextOut(CAMERAMANAGER->findImage("�޴�")->getMemDC(), 400, 60 + (_pm->getvplayer()[playerv]->getpartyPos() - 1) * 150, str2, strlen(str2));

	char str[128];

	sprintf(str, "%d", _pm->getvplayer()[playerv]->getLevel());
	TextOut(CAMERAMANAGER->findImage("�޴�")->getMemDC(), 550 - strlen(str) * 10, 89 + (_pm->getvplayer()[playerv]->getpartyPos() - 1) * 150, str, strlen(str));

	sprintf(str, "%d / %d", _pm->getvplayer()[playerv]->getCurrentHp(), _pm->getvplayer()[playerv]->getMaxHp());
	TextOut(CAMERAMANAGER->findImage("�޴�")->getMemDC(), 550 - strlen(str) * 10, 117 + (_pm->getvplayer()[playerv]->getpartyPos() - 1) * 150, str, strlen(str));

	sprintf(str, "%d / %d", _pm->getvplayer()[playerv]->getCurrentMp(), _pm->getvplayer()[playerv]->getMaxMp());
	TextOut(CAMERAMANAGER->findImage("�޴�")->getMemDC(), 550 - strlen(str) * 10, 145 + (_pm->getvplayer()[playerv]->getpartyPos() - 1) * 150, str, strlen(str));

	sprintf(str, "%d", _pm->getvplayer()[playerv]->getMaxExp() - _pm->getvplayer()[playerv]->getCurrentExp());
	TextOut(CAMERAMANAGER->findImage("�޴�")->getMemDC(), 550 - strlen(str) * 10, 173 + (_pm->getvplayer()[playerv]->getpartyPos() - 1) * 150, str, strlen(str));
}

void gameMenuScene::playerposchange(int key)
{
	if (_isCharater)
	{
		for (int i = 0; i < 3; ++i)
		{
			if (_pm->getvplayer()[i]->getpartyPos() == key - 6)
			{
				positiontemp = i;
			}
		}
		for (int i = 0; i < 3; ++i)
		{
			if (_pm->getvplayer()[i]->getpartyPos() == _selectNum)
			{
				positiontemp1 = i;
			}
		}
		_pm->getvplayer()[positiontemp1]->setpartyPos(_pm->getvplayer()[positiontemp]->getpartyPos());
		_pm->getvplayer()[positiontemp]->setpartyPos(_selectNum);
		_isCharater = false;
	}
	else
	{
		_isCharater = true;
		_selectNum = key - 6;
	}
}