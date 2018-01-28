#include "stdafx.h"
#include "itemMenu.h"
#include "playerManager.h"
#include "Item.h"


itemMenu::itemMenu()
{
}


itemMenu::~itemMenu()
{

}

HRESULT itemMenu::init()
{
	IMAGEMANAGER->addImage("아이템메뉴씬", ".\\SceneImage\\itemMenu.bmp", 1024, 760, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("아이템버튼", ".\\SceneImage\\button.bmp", 273, 59, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("아이템매뉴버튼", ".\\userInterface\\noselButton.bmp", 220, 40, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("아이템매뉴선택", ".\\userInterface\\selButton.bmp", 220, 40, true, RGB(255, 0, 255));
	
	seltype = false;
	selItem = false;

	selX = 50;
	selY = 64;
	selnum = 0;

	itemsize = 0;
	equipsize = 0;
	playersel = 0;

	//인벤토리 첫 좌표 82, 163
	//인벤토리 길이 좌표 293, 79

	return S_OK;
}

void itemMenu::release()
{

}

void itemMenu::update()	
{
	if (KEYMANAGER->isOnceKeyDown('1'))//임시로 소지템 늘리기
	{
		_Item->addItem("포션");
		_Item->addItem("밀집모자");
		_Item->addItem("하이포션");
		_Item->addItem("가죽갑옷");
		_Item->addItem("연막탄");
		_Item->addItem("방패");
		_Item->addItem("에테르");
		_Item->addItem("지팡이");
		_Item->addItem("메가포션");
		_Item->addItem("후드");
		_Item->addItem("철투구");
		_Item->addItem("양손검");
		_Item->addItem("단검(右)");
		_Item->addItem("단검(左)");
		_Item->addItem("힘의 목걸이");
		_Item->addItem("체력의 목걸이");
		_Item->addItem("마력의 목걸이");
	}

	if (!seltype) // 매뉴 선택 안했을 때
	{
		if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
		{
			++selnum;
		}
		if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
		{
			--selnum;
		}

		if (selnum < 0)selnum += 3;
		selnum = selnum % 3;
		waitX = selX + selnum * 240;
		waitY = selY;
		waitselnum = selnum;

		if (KEYMANAGER->isOnceKeyDown(VK_RETURN) && ((itemsize && waitselnum == 0) || (equipsize && waitselnum == 1)))
		{
			selX = 100;
			selY = 180;
			selnum = 0;
			seltype = true;
		}
		if (KEYMANAGER->isOnceKeyDown(VK_BACK))
		{
			SCENEMANAGER->changeScene("메뉴씬");
		}
	}
	else if (selItem) // 아이템 선택했을 때
	{
		if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
		{
			++selnum;
		}
		if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
		{
			--selnum;
			if (selnum < 0)selnum += 3;
		}
		selnum = selnum % 3;

		if (KEYMANAGER->isOnceKeyDown(VK_RETURN))
		{
			if (_Item->findItem(_Item->getiteminventory()[waitselItem]).code == 4)
			{
				_pm->getvplayer()[selnum]->setCurrentMp(_pm->getvplayer()[selnum]->getCurrentMp() + _Item->findItem(_Item->getiteminventory()[waitselItem]).value);
				if (_pm->getvplayer()[selnum]->getCurrentMp() > _pm->getvplayer()[selnum]->getMaxMp())
				{
					_pm->getvplayer()[selnum]->setCurrentMp(_pm->getvplayer()[selnum]->getMaxMp());
				}
			}
			else if (_Item->findItem(_Item->getiteminventory()[waitselItem]).code == 5)
			{
				if (_pm->getvplayer()[selnum]->getCurrentMp());
				else
				{
					_pm->getvplayer()[selnum]->setCurrentMp(_pm->getvplayer()[selnum]->getCurrentMp() + _Item->findItem(_Item->getiteminventory()[waitselItem]).value);
					if (_pm->getvplayer()[selnum]->getCurrentMp() > _pm->getvplayer()[selnum]->getMaxMp())
					{
						_pm->getvplayer()[selnum]->setCurrentMp(_pm->getvplayer()[selnum]->getMaxMp());
					}
				}
			}
			else if (_Item->findItem(_Item->getiteminventory()[waitselItem]).code == 6)
			{
				for (int i = 0; i < 3; i++)
				{
					if (_pm->getvplayer()[i]->getCurrentMp())continue;
					else
					{
						_pm->getvplayer()[i]->setCurrentMp(_pm->getvplayer()[i]->getCurrentMp() + _Item->findItem(_Item->getiteminventory()[waitselItem]).value);
						if (_pm->getvplayer()[i]->getCurrentMp() > _pm->getvplayer()[i]->getMaxMp())
						{
							_pm->getvplayer()[i]->setCurrentMp(_pm->getvplayer()[i]->getMaxMp());
						}
					}
				}
			}
			else if (_Item->findItem(_Item->getiteminventory()[waitselItem]).code == 7);
			else
			{
				_pm->getvplayer()[selnum]->setCurrentHp(_pm->getvplayer()[selnum]->getCurrentHp() + _Item->findItem(_Item->getiteminventory()[waitselItem]).value);
				if (_pm->getvplayer()[selnum]->getCurrentHp() > _pm->getvplayer()[selnum]->getMaxHp())
				{
					_pm->getvplayer()[selnum]->setCurrentHp(_pm->getvplayer()[selnum]->getMaxHp());
				}
			}

			_Item->delItem(_Item->findItem(_Item->getiteminventory()[waitselItem]).name);

			selX = 100;
			selY = 180;
			selnum = waitselItem;
			selItem = false;
		}

		if (KEYMANAGER->isOnceKeyDown(VK_BACK))
		{
			selX = 100;
			selY = 180;
			selnum = waitselItem;
			selItem = false;
		}
	}
	else // 매뉴 선택하고 아이템 선택 안했을 때
	{
		if (KEYMANAGER->isOnceKeyDown(VK_BACK))
		{
			selX = 50;
			selY = 64;
			selnum = waitselnum;
			seltype = false;
		}

		waitItemX = selX + selnum % 3 * 293;
		waitItemY = selY + selnum / 3 * 79;
		waitselItem = selnum;

		if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
		{
			++selnum;
			if (waitselnum)
			{
				selnum = selnum % equipsize;
			}
			else
			{
				selnum = selnum % itemsize;
			}
		}
		if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
		{
			--selnum;
			if (waitselnum)
			{
				if (selnum < 0)selnum += equipsize;
			}
			else
			{
				if (selnum < 0)selnum += itemsize;
			}
		}
		if (KEYMANAGER->isOnceKeyDown(VK_UP))
		{
			selnum -= 3;
			if (waitselnum)
			{
				if (selnum < 0)selnum += ((equipsize - 1) / 3 + 1) * 3;
				if (selnum >= equipsize)selnum -= 3;
				if (selnum < 0)selnum += 3;
			}
			else
			{
				if (selnum < 0)selnum += ((itemsize - 1) / 3 + 1) * 3;
				if (selnum >= itemsize)selnum -= 3;
				if (selnum < 0)selnum += 3;
			}
		}
		if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
		{
			selnum += 3;
			if (waitselnum)
			{
				if (selnum >= equipsize)selnum -= ((equipsize - 1) / 3 + 1) * 3;
				if (selnum >= equipsize)selnum -= 3;
				if (selnum < 0)selnum += 3;
			}
			else
			{
				if (selnum >= itemsize)selnum -= ((itemsize - 1) / 3 + 1) * 3;
				if (selnum >= itemsize)selnum -= 3;
				if (selnum < 0)selnum += 3;
			}
		}

		if (KEYMANAGER->isOnceKeyDown(VK_RETURN) && !waitselnum && _Item->findItem(_Item->getiteminventory()[waitselItem]).code != 7)
		{
			selItem = true;
			selX = 100;
			selY = 700;
			selnum = 0;
		}
	}
	//항상 현재 소지템 확인
	itemsize = _Item->getiteminventory().size();
	equipsize = _Item->getequipinventory().size();
}

void itemMenu::render()	
{
	//글자 색 초기화
	SetTextColor(getMemDC(), RGB(255, 255, 255));
	SetBkMode(getMemDC(), 0);
	//배경 뿌리기
	IMAGEMANAGER->findImage("아이템메뉴씬")->render(getMemDC(), (WINSIZEX - 1024) / 2, (WINSIZEY - 760) / 2);
	//매뉴버튼 뿌리기
	for (int i = 0; i < 3; ++i)
	{
		IMAGEMANAGER->findImage("아이템매뉴버튼")->render(getMemDC(), 40 + i * 240, 56);
		if (PtInRect(&RectMake(40 + i * 240, 57, 220, 40), PointMake(waitX, waitY)))
		{
			IMAGEMANAGER->findImage("아이템매뉴선택")->render(getMemDC(), 40 + i * 240, 56);
		}
	}
	char* str = "소비";
	TextOut(getMemDC(), 133 , 69, str, strlen(str));
	str = "장비";
	TextOut(getMemDC(), 133 + 240, 69, str, strlen(str));
	str = "DLC";
	TextOut(getMemDC(), 133 + 480, 69, str, strlen(str));
	//선택 손가락 뿌리기
	IMAGEMANAGER->findImage("선택")->alphaRender(getMemDC(), waitX, waitY, 255 - seltype * 125);

	if (seltype)//매뉴 선택했다면
	{
		if (waitselnum)//대기하는 매뉴가 0이 아닐 때(소비템 제외 나머지)
		{
			for (int i = 0; i < equipsize; ++i)
			{
				IMAGEMANAGER->findImage("아이템버튼")->render(getMemDC(), 82 + (int)(i % 3) * 293, 163 + (int)(i / 3) * 79);
				char str[128];
				sprintf(str, "%s", _Item->getequipinventory()[i].c_str());
				TextOut(getMemDC(), 160 + (int)(i % 3) * 293, 175 + (int)(i / 3) * 79, str, strlen(str));
				sprintf(str, "%d", _Item->findItem(_Item->getequipinventory()[i]).count);
				TextOut(getMemDC(), 300 + (int)(i % 3) * 293, 197 + (int)(i / 3) * 79, str, strlen(str));
			}
			IMAGEMANAGER->findImage("선택")->render(getMemDC(), waitItemX, waitItemY);
		}
		else//매뉴 소비템 선택시
		{
			for (int i = 0; i < itemsize; ++i)
			{
				IMAGEMANAGER->findImage("아이템버튼")->render(getMemDC(), 82 + (int)(i % 3) * 293, 163 + (int)(i / 3) * 79);
				char str[128];
				sprintf(str, "%s", _Item->getiteminventory()[i].c_str());
				TextOut(getMemDC(), 160 + (int)(i % 3) * 293, 175 + (int)(i / 3) * 79, str, strlen(str));
				sprintf(str, "%d", _Item->findItem(_Item->getiteminventory()[i]).count);
				TextOut(getMemDC(), 300 + (int)(i % 3) * 293, 197 + (int)(i / 3) * 79, str, strlen(str));
			}
			if (selItem)//만약 아이템 선택했을 시
			{
				for (int i = 0; i < 3; ++i)
				{
					IMAGEMANAGER->findImage("아이템버튼")->render(getMemDC(), 82 + i * 293, 575);
					char str[128];
					sprintf(str, "%s", _pm->getvplayer()[i]->getName().c_str());
					TextOut(getMemDC(), 160 + (int)(i % 3) * 293, 583, str, strlen(str));
				}
				if (_Item->findItem(_Item->getiteminventory()[waitselItem]).code == 6)
				{
					for (int j = 0; j < 3; j++)
					{
						IMAGEMANAGER->findImage("선택")->render(getMemDC(), selX + j % 3 * 293, 590);
					}
				}
				IMAGEMANAGER->findImage("선택")->render(getMemDC(), selX + selnum % 3 * 293, 590);
			}
			IMAGEMANAGER->findImage("선택")->alphaRender(getMemDC(), waitItemX, waitItemY, 255 - selItem * 125);
		}

	}
}
