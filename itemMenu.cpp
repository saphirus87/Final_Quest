#include "stdafx.h"
#include "itemMenu.h"


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
	
	seltype = false;

	waitX = 25;
	waitY = 64;

	selX = 25;
	selY = 64;
	selnum = 0;

	itemsize = 0;
	equipsize = 0;

	//인벤토리 첫 좌표 82, 163
	//인벤토리 길이 좌표 293, 79

	return S_OK;
}

void itemMenu::release()
{

}

void itemMenu::update()	
{
	if (!seltype)
	{
		if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
		{
			++selnum;
		}
		if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
		{
			--selnum;
		}
		if (selnum < 0)selnum += 2;
		selnum = selnum % 2;
		waitX = selX + selnum * 252;
		waitY = selY;
		if (KEYMANAGER->isOnceKeyDown(VK_RETURN))
		{
			selX = 100;
			selY = 180;
			waitselnum = selnum;
			selnum = 0;
			seltype = true;
		}
		if (KEYMANAGER->isOnceKeyDown(VK_BACK))
		{
			SCENEMANAGER->changeScene("메뉴씬");
		}
	}
	else
	{
		itemsize = ITEMMANAGER->getiteminventory()->size();
		equipsize = ITEMMANAGER->getequipinventory()->size();
		if (KEYMANAGER->isOnceKeyDown(VK_BACK) || (!itemsize && !waitselnum) || (!equipsize && waitselnum))
		{
			selX = 25;
			selY = 64;
			selnum = waitselnum;
			seltype = false;
		}
		if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
		{
			++selnum;
			if (itemsize)
			{
				selnum = selnum % itemsize;
			}
			if (equipsize)
			{
				selnum = selnum % equipsize;
			}
		}
		if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
		{
			--selnum;
			if (itemsize)
			{
				if (selnum < 0)selnum += itemsize;
			}
			if (equipsize)
			{
				if (selnum < 0)selnum += equipsize;
			}
		}
		if (KEYMANAGER->isOnceKeyDown(VK_UP))
		{
			selnum -= 3;
			if (itemsize)
			{
				if (selnum < 0)selnum += (itemsize / 3 + 1) * 3;
				if (selnum >= itemsize)selnum -= 3;
				if (selnum < 0)selnum += 3;
			}
			if (equipsize)
			{
				if (selnum < 0)selnum += (equipsize / 3 + 1) * 3;
				if (selnum >= equipsize)selnum -= 3;
				if (selnum < 0)selnum += 3;
			}
		}
		if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
		{
			selnum += 3;
			if (itemsize)
			{
				if (selnum > itemsize)selnum -= (itemsize / 3 + 1) * 3;
				if (selnum >= itemsize)selnum -= 3;
				if (selnum < 0)selnum += 3;
			}
			if (equipsize)
			{
				if (selnum > equipsize)selnum -= (equipsize / 3 + 1) * 3;
				if (selnum > equipsize)selnum -= 3;
				if (selnum < 0)selnum += 3;
			}
		}
	}
	if (KEYMANAGER->isOnceKeyDown('1'))
	{
		ITEMMANAGER->addItem("포션");
		ITEMMANAGER->addItem("밀집모자");
	}
	if (KEYMANAGER->isOnceKeyDown('2'))
	{
		ITEMMANAGER->addItem("하이포션");
		ITEMMANAGER->addItem("가죽갑옷");
	}
	if (KEYMANAGER->isOnceKeyDown('3'))
	{
		ITEMMANAGER->addItem("연막탄");
		ITEMMANAGER->addItem("방패");
	}
	if (KEYMANAGER->isOnceKeyDown('4'))
	{
		ITEMMANAGER->addItem("에테르");
		ITEMMANAGER->addItem("지팡이");
	}
	if (KEYMANAGER->isOnceKeyDown('5'))
	{
		ITEMMANAGER->addItem("메가포션");
		ITEMMANAGER->addItem("후드");
	}
}

void itemMenu::render()	
{
	SetTextColor(getMemDC(), RGB(255, 255, 255));
	SetBkMode(getMemDC(), 0);
	IMAGEMANAGER->findImage("아이템메뉴씬")->render(getMemDC(), (WINSIZEX - 1024) / 2, (WINSIZEY - 760) / 2);
	IMAGEMANAGER->findImage("선택")->alphaRender(getMemDC(), waitX, waitY, 255 - seltype * 125);
	if (seltype)
	{
		if (waitselnum)
		{
			for (int i = 0; i < equipsize; ++i)
			{
				IMAGEMANAGER->findImage("아이템버튼")->render(getMemDC(), 82 + (int)(i % 3) * 293, 163 + (int)(i / 3) * 79);
				char str[128];
				sprintf(str, "%s", ITEMMANAGER->getvequipstring(i).c_str());
				TextOut(getMemDC(), 160 + (int)(i % 3) * 293, 175 + (int)(i / 3) * 79, str, strlen(str));
				sprintf(str, "%d", ITEMMANAGER->findItem(ITEMMANAGER->getvequipstring(i)).count);
				TextOut(getMemDC(), 300 + (int)(i % 3) * 293, 175 + (int)(i / 3) * 79, str, strlen(str));
			}
		}
		else
		{
			for (int i = 0; i < itemsize; ++i)
			{
				IMAGEMANAGER->findImage("아이템버튼")->render(getMemDC(), 82 + (int)(i % 3) * 293, 163 + (int)(i / 3) * 79);
				char str[128];
				sprintf(str, "%s", ITEMMANAGER->getvitemstring(i).c_str());
				TextOut(getMemDC(), 160 + (int)(i % 3) * 293, 175 + (int)(i / 3) * 79, str, strlen(str));
				sprintf(str, "%d", ITEMMANAGER->findItem(ITEMMANAGER->getvitemstring(i)).count);
				TextOut(getMemDC(), 300 + (int)(i % 3) * 293, 175 + (int)(i / 3) * 79, str, strlen(str));
			}
		}

		IMAGEMANAGER->findImage("선택")->render(getMemDC(), selX + selnum % 3 * 293, selY + selnum / 3 * 79);
	}
}
