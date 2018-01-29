#include "stdafx.h"
#include "equipMenu.h"
#include "playerManager.h"
#include "Item.h"


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

	_cursorMenuNum = 0;

	_isCharater = false;

	return S_OK;
}

void equipMenu::release()
{

}

void equipMenu::update() 
{
	for (int i = 0; i < 3; ++i)
	{
		if (_waitplayersel == _pm->getvplayer()[i]->getpartyPos() - 1)
		{
			playerposition = i;
		}
	}
	keyControl();
	//항상 현재 소지템 확인
	equipsize = _Item->getequipinventory().size();
}

void equipMenu::render() 
{
	//글자 색 초기화
	SetTextColor(getMemDC(), RGB(255, 255, 255));
	SetBkMode(getMemDC(), 0);
	//배경 뿌리기
	IMAGEMANAGER->findImage("장비메뉴씬")->render(getMemDC(), 0, 0);
	//매뉴 버튼 뿌리기
	for (int i = 0; i < 3; ++i)
	{
		if (_pm->getvplayer()[(_pm->getvplayer()[i]->getpartyPos() - 1)]->getCurrentHp())
		{
			SetTextColor(getMemDC(), RGB(255, 255, 255));
		}
		else
		{
			SetTextColor(getMemDC(), RGB(255, 0, 0));
		}

		if (_waitplayersel == _pm->getvplayer()[i]->getpartyPos() - 1)
		{
			IMAGEMANAGER->findImage("아이템매뉴선택")->render(getMemDC(), 40 + (_pm->getvplayer()[i]->getpartyPos() - 1) * 240, 56);
		}
		else
		{
			IMAGEMANAGER->findImage("아이템매뉴버튼")->render(getMemDC(), 40 + (_pm->getvplayer()[i]->getpartyPos() - 1) * 240, 56);
		}
		char str[128];
		sprintf(str, "%s", _pm->getvplayer()[i]->getName().c_str());
		TextOut(getMemDC(), 133 + (int)(_pm->getvplayer()[i]->getpartyPos() - 1) * 237, 69, str, strlen(str));
	}
	SetTextColor(getMemDC(), RGB(255, 255, 255));
	IMAGEMANAGER->findImage("선택")->alphaRender(getMemDC(), 50 + _waitplayersel * 240, 64, 255 - _isCharater * 125);

	if (_isCharater)
	{
		char str[128];
		sprintf(str, "player%dface", playerposition + 1);
		IMAGEMANAGER->findImage(str)->render(getMemDC(), 85, 160);

		for (int i = 0; i < 5; ++i)
		{
			IMAGEMANAGER->findImage("아이템버튼")->render(getMemDC(), 300 + i % 2 * 380, 115 + i / 2 * 63);
			
			char str[128];
			sprintf(str, "%s", _pm->getvplayer()[playerposition]->getplayerEquip(i).name.c_str());
			TextOut(getMemDC(), 330 + i % 2 * 380, 125 + i / 2 * 63, str, strlen(str));
		}

		if (equipsize)
		{
			for (int i = 0; i < equipsize; ++i)
			{
				IMAGEMANAGER->findImage("판매버튼")->render(getMemDC(), 50 + i % 4 * 240, 325 + i / 4 * 65);

				char str[128];
				sprintf(str, "%s", _Item->getequipinventory()[i].c_str());
				TextOut(getMemDC(), 100 + i % 4 * 240, 329 + i / 4 * 65, str, strlen(str));
				str[128];
				sprintf(str, "%d", _Item->findItem(_Item->getequipinventory()[i]).count);
				TextOut(getMemDC(), 200 + i % 4 * 240, 349 + i / 4 * 65, str, strlen(str));
			}

			IMAGEMANAGER->findImage("선택")->render(getMemDC(), 60 + _cursorMenuNum % 4 * 240, 335 + _cursorMenuNum / 4 * 65);
		}
	}
}

void equipMenu::keyControl()
{
	if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
	{
		SOUNDMANAGER->play("메뉴선택", 1.0f); //메뉴선택 소리

		++_cursorMenuNum;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
	{
		SOUNDMANAGER->play("메뉴선택", 1.0f); //메뉴선택 소리

		--_cursorMenuNum;
	}
	if (_isCharater)
	{
		if (KEYMANAGER->isOnceKeyDown(VK_BACK))
		{
			_cursorMenuNum = _waitplayersel;
			SOUNDMANAGER->play("메뉴선택", 1.0f); //메뉴선택 소리

			_isCharater = false;
		}
		if (equipsize)
		{
			if (KEYMANAGER->isOnceKeyDown(VK_UP))
			{
				SOUNDMANAGER->play("메뉴선택", 1.0f); //메뉴선택 소리

				_cursorMenuNum -= 4;
				if (_cursorMenuNum < 0)_cursorMenuNum += ((equipsize - 1) / 4 + 1) * 4;
				if (_cursorMenuNum >= equipsize)_cursorMenuNum -= 4;
				if (_cursorMenuNum < 0)_cursorMenuNum += 4;
			}
			if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
			{
				SOUNDMANAGER->play("메뉴선택", 1.0f); //메뉴선택 소리

				_cursorMenuNum += 4;
				if (_cursorMenuNum >= equipsize)_cursorMenuNum -= ((equipsize - 1) / 4 + 1) * 4;
				if (_cursorMenuNum >= equipsize)_cursorMenuNum -= 4;
				if (_cursorMenuNum < 0)_cursorMenuNum += 4;
			}
			_cursorMenuNum = _cursorMenuNum % equipsize;
			if (_cursorMenuNum < 0)_cursorMenuNum += equipsize;

			if (KEYMANAGER->isOnceKeyDown(VK_RETURN))
			{
				SOUNDMANAGER->play("메뉴선택", 1.0f); //메뉴선택 소리
				string str = "없음";
				if (_pm->getvplayer()[playerposition]->getplayerEquip(_Item->findItem(_Item->getequipinventory()[_cursorMenuNum]).code / 100 - 1).name != str)
				{
					str = _pm->getvplayer()[playerposition]->getplayerEquip(_Item->findItem(_Item->getequipinventory()[_cursorMenuNum]).code / 100 - 1).name;
				}

				_pm->getvplayer()[playerposition]->setplayerEquip(_Item->findItem(_Item->getequipinventory()[_cursorMenuNum]), _Item->findItem(_Item->getequipinventory()[_cursorMenuNum]).code / 100 - 1);

				_Item->delItem(_Item->getequipinventory()[_cursorMenuNum]);
				if (str != "없음")
				{
					_Item->addItem(str.c_str());
				}
			}
		}
	}
	else
	{
		_cursorMenuNum = _cursorMenuNum % 3;
		if (_cursorMenuNum < 0)_cursorMenuNum += 3;
		_waitplayersel = _cursorMenuNum;
		if (KEYMANAGER->isOnceKeyDown(VK_RETURN))
		{
			SOUNDMANAGER->play("메뉴선택", 1.0f); //메뉴선택 소리

			_isCharater = true;
			_cursorMenuNum = 0;
		}
		if (KEYMANAGER->isOnceKeyDown(VK_BACK))
		{
			SOUNDMANAGER->play("메뉴선택", 1.0f); //메뉴선택 소리

			SCENEMANAGER->changeScene("메뉴씬", FALSE);
		}
	}
}

void equipMenu::player1Information()
{
	//char str[128];
	//
	//sprintf(str, "%s", _pm->getvplayer()[0]->getplayerEquip(0).name.c_str());
	//TextOut(getMemDC(), 145, 127, str, strlen(str));
}

void equipMenu::player2Information()
{

}

void equipMenu::player3Information()
{

}