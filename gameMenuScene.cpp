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
	IMAGEMANAGER->addImage("�÷��̾�1��", ".\\playerImage\\player1face.bmp", 100, 100, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�÷��̾�2��", ".\\playerImage\\player2face.bmp", 100, 100, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�÷��̾�3��", ".\\playerImage\\player3face.bmp", 100, 100, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�÷��̾�󱼹��", ".\\SceneImage\\faceBackground.bmp", 108, 108, true, RGB(255, 0, 255));

	_cursorMenuNum = 1;

	_selectNum = 1;
	_currentNum = 1;

	_alpha = 0;
	_isMenu = true;
	_isCharater1 = true;
	_isCharater2 = true;
	_isCharater3 = true;

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
			_currentNum = 1;
			IMAGEMANAGER->findImage("����")->render(CAMERAMANAGER->findImage("�޴�")->getMemDC(), 40, 115);
		}
		if (_cursorMenuNum == 8)
		{
			_currentNum = 2;
			IMAGEMANAGER->findImage("����")->render(CAMERAMANAGER->findImage("�޴�")->getMemDC(), 40, 265);
		}
		if (_cursorMenuNum == 9)
		{
			_currentNum = 3;
			IMAGEMANAGER->findImage("����")->render(CAMERAMANAGER->findImage("�޴�")->getMemDC(), 40, 415);
		}
		if (_cursorMenuNum == 10)
		{
			_currentNum = 4;
			IMAGEMANAGER->findImage("����")->render(CAMERAMANAGER->findImage("�޴�")->getMemDC(), 40, 565);
		}

		if (_pm->getvplayer()[0]->getpartyPos())
		{
			if (_isCharater1 == true)
			{
				_selectNum = 1;

				IMAGEMANAGER->findImage("�÷��̾�󱼹��")->render(CAMERAMANAGER->findImage("�޴�")->getMemDC(), 100, 72);
				IMAGEMANAGER->findImage("�÷��̾�1��")->render(CAMERAMANAGER->findImage("�޴�")->getMemDC(), 103, 75);
				player1Information();
			}
		}
		if (_pm->getvplayer()[1]->getpartyPos())
		{
			if (_isCharater2 == true)
			{
				_selectNum = 2;

				IMAGEMANAGER->findImage("�÷��̾�󱼹��")->render(CAMERAMANAGER->findImage("�޴�")->getMemDC(), 100, 72 + 150);
				IMAGEMANAGER->findImage("�÷��̾�2��")->render(CAMERAMANAGER->findImage("�޴�")->getMemDC(), 103, 75 + 150);
				player2Information();
			}
		}
		if (_pm->getvplayer()[2]->getpartyPos())
		{
			if (_isCharater3 == true)
			{
				_selectNum = 3;

				IMAGEMANAGER->findImage("�÷��̾�󱼹��")->render(CAMERAMANAGER->findImage("�޴�")->getMemDC(), 100, 72 + 300);
				IMAGEMANAGER->findImage("�÷��̾�3��")->render(CAMERAMANAGER->findImage("�޴�")->getMemDC(), 103, 75 + 300);
				player3Information();
			}
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

			if (_cursorMenuNum == 7 && _selectNum == 1)
			{
				if (_selectNum == 1 && (_currentNum == 1 || _currentNum == 2 || _currentNum == 3 || _currentNum == 4))
				{
					_selectNum = 2;
				}
			}
			if (_cursorMenuNum == 8)
			{
				//_isCharater1 = false;
				//_isCharater2 = true;
				//_isCharater3 = false;
			}
			if (_cursorMenuNum == 9)
			{
				//_isCharater1 = false;
				//_isCharater2 = false;
				//_isCharater3 = true;
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

void gameMenuScene::player1Information()
{
	if (_pm->getvplayer()[0]->getCurrentHp())
	{
		SetTextColor(CAMERAMANAGER->findImage("�޴�")->getMemDC(), RGB(255, 255, 255));
	}
	else
	{
		SetTextColor(CAMERAMANAGER->findImage("�޴�")->getMemDC(), RGB(255, 0, 0));
	}

	char str2[128];
	sprintf(str2, "%s", _pm->getvplayer()[0]->getName().c_str());
	TextOut(CAMERAMANAGER->findImage("�޴�")->getMemDC(), 400, 60, str2, strlen(str2));

	char str[128];

	sprintf(str, "%d", _pm->getvplayer()[0]->getLevel());
	TextOut(CAMERAMANAGER->findImage("�޴�")->getMemDC(), 550 - strlen(str) * 10, 89, str, strlen(str));

	sprintf(str, "%d / %d", _pm->getvplayer()[0]->getCurrentHp(), _pm->getvplayer()[0]->getMaxHp());
	TextOut(CAMERAMANAGER->findImage("�޴�")->getMemDC(), 550 - strlen(str) * 10, 117, str, strlen(str));

	sprintf(str, "%d / %d", _pm->getvplayer()[0]->getCurrentMp(), _pm->getvplayer()[0]->getMaxMp());
	TextOut(CAMERAMANAGER->findImage("�޴�")->getMemDC(), 550 - strlen(str) * 10, 145, str, strlen(str));

	sprintf(str, "%d", _pm->getvplayer()[0]->getMaxExp() - _pm->getvplayer()[0]->getCurrentExp());
	TextOut(CAMERAMANAGER->findImage("�޴�")->getMemDC(), 550 - strlen(str) * 10, 173, str, strlen(str));
}

void gameMenuScene::player2Information()
{
	if (_pm->getvplayer()[1]->getCurrentHp())
	{
		SetTextColor(CAMERAMANAGER->findImage("�޴�")->getMemDC(), RGB(255, 255, 255));
	}
	else
	{
		SetTextColor(CAMERAMANAGER->findImage("�޴�")->getMemDC(), RGB(255, 0, 0));
	}

	char str2[128];
	sprintf(str2, "%s", _pm->getvplayer()[1]->getName().c_str());
	TextOut(CAMERAMANAGER->findImage("�޴�")->getMemDC(), 400, 60 + 150, str2, strlen(str2));

	char str[128];

	sprintf(str, "%d", _pm->getvplayer()[1]->getLevel());
	TextOut(CAMERAMANAGER->findImage("�޴�")->getMemDC(), 550 - strlen(str) * 10, 89 + 150, str, strlen(str));

	sprintf(str, "%d / %d", _pm->getvplayer()[1]->getCurrentHp(), _pm->getvplayer()[1]->getMaxHp());
	TextOut(CAMERAMANAGER->findImage("�޴�")->getMemDC(), 550 - strlen(str) * 10, 117 + 150, str, strlen(str));

	sprintf(str, "%d / %d", _pm->getvplayer()[1]->getCurrentMp(), _pm->getvplayer()[1]->getMaxMp());
	TextOut(CAMERAMANAGER->findImage("�޴�")->getMemDC(), 550 - strlen(str) * 10, 145 + 150, str, strlen(str));

	sprintf(str, "%d", _pm->getvplayer()[1]->getMaxExp() - _pm->getvplayer()[1]->getCurrentExp());
	TextOut(CAMERAMANAGER->findImage("�޴�")->getMemDC(), 550 - strlen(str) * 10, 173 + 150, str, strlen(str));
}

void gameMenuScene::player3Information()
{
	if (_pm->getvplayer()[2]->getCurrentHp())
	{
		SetTextColor(CAMERAMANAGER->findImage("�޴�")->getMemDC(), RGB(255, 255, 255));
	}
	else
	{
		SetTextColor(CAMERAMANAGER->findImage("�޴�")->getMemDC(), RGB(255, 0, 0));
	}

	char str2[128];
	sprintf(str2, "%s", _pm->getvplayer()[2]->getName().c_str());
	TextOut(CAMERAMANAGER->findImage("�޴�")->getMemDC(), 400, 60 + 300, str2, strlen(str2));

	char str[128];

	sprintf(str, "%d", _pm->getvplayer()[2]->getLevel());
	TextOut(CAMERAMANAGER->findImage("�޴�")->getMemDC(), 550 - strlen(str) * 10, 90 + 300, str, strlen(str));

	sprintf(str, "%d / %d", _pm->getvplayer()[2]->getCurrentHp(), _pm->getvplayer()[2]->getMaxHp());
	TextOut(CAMERAMANAGER->findImage("�޴�")->getMemDC(), 550 - strlen(str) * 10, 118 + 300, str, strlen(str));

	sprintf(str, "%d / %d", _pm->getvplayer()[2]->getCurrentMp(), _pm->getvplayer()[2]->getMaxMp());
	TextOut(CAMERAMANAGER->findImage("�޴�")->getMemDC(), 550 - strlen(str) * 10, 146 + 300, str, strlen(str));

	sprintf(str, "%d", _pm->getvplayer()[2]->getMaxExp() - _pm->getvplayer()[2]->getCurrentExp());
	TextOut(CAMERAMANAGER->findImage("�޴�")->getMemDC(), 550 - strlen(str) * 10, 174 + 300, str, strlen(str));
}