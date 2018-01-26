#include "stdafx.h"
#include "shopScene.h"
#include "Item.h"


shopScene::shopScene()
{
}


shopScene::~shopScene()
{

}

HRESULT shopScene::init(void)
{
	IMAGEMANAGER->addImage("샵구매", ".\\userInterface\\Shop_Buy.bmp", 1024, 760, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("샵판매", ".\\userInterface\\shop_Sell_Image.bmp", 1024, 760, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("판매버튼", ".\\SceneImage\\button1.bmp", 205, 44, true, RGB(255, 0, 255));

	seltype = false;

	selX = 150;
	selY = 125;
	selnum = 0;

	itemsize = 0;
	equipsize = 0;

	//인벤토리 첫 좌표 72, 240
	//인벤토리 길이 좌표 224, 52
	return S_OK;
}

void shopScene::release(void)
{

}

void shopScene::update(void) 
{
	if (!seltype)
	{
		if (KEYMANAGER->isOnceKeyDown('1'))
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
		waitselnum = selnum;
		waitX = selX + selnum * 422;
		waitY = selY;
		if (KEYMANAGER->isOnceKeyDown(VK_RETURN))
		{
			if (waitselnum)
			{
				selX = 85;
				selY = 250;
			}
			else
			{
				selX = 405;
				selY = 294;
			}
			selnum = 0;
			seltype = true;
		}
		if (KEYMANAGER->isOnceKeyDown(VK_BACK))
		{
			SCENEMANAGER->changeScene("townScene", false);
		}
	}
	else
	{
		itemsize = _Item->getiteminventory().size();
		equipsize = _Item->getequipinventory().size();
		if (KEYMANAGER->isOnceKeyDown(VK_BACK) || (!equipsize && !itemsize && waitselnum))
		{
			selX = 150;
			selY = 125;
			selnum = waitselnum;
			seltype = false;
		}

		if (waitselnum)
		{
			if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
			{
				++selnum;
				selnum = selnum % (itemsize + equipsize);
			}
			if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
			{
				--selnum;
				if (selnum < 0)selnum += itemsize + equipsize;
			}
			if (KEYMANAGER->isOnceKeyDown(VK_UP))
			{
				selnum -= 4;
				if (selnum < 0)selnum += ((itemsize + equipsize - 2) / 4 + 1) * 4;
				if (selnum >= itemsize + equipsize)selnum -= 4;
				if (selnum < 0)selnum += 4;
			}
			if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
			{
				selnum += 4;
				if (selnum >= itemsize + equipsize)selnum -= ((itemsize + equipsize - 2) / 4 + 1) * 4;
				if (selnum >= itemsize + equipsize)selnum -= 4;
				if (selnum < 0)selnum += 4;
			}
			if (KEYMANAGER->isOnceKeyDown(VK_RETURN))
			{
				if (selnum < itemsize)
				{
					_Item->setMoney(_Item->getMoney() + _Item->findItem(_Item->getiteminventory()[selnum]).price);
					_Item->delItem(_Item->getiteminventory()[selnum]);
				}
				else
				{
					selnum -= itemsize;
					_Item->setMoney(_Item->getMoney() + _Item->findItem(_Item->getequipinventory()[selnum]).price);
					_Item->delItem(_Item->getequipinventory()[selnum]);
					selnum += itemsize;
				}
				itemsize = _Item->getiteminventory().size();
				equipsize = _Item->getequipinventory().size();
				if (selnum >= itemsize + equipsize)--selnum;
			}
		}
		else
		{
			if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
			{
				++selnum;
				selnum = selnum % 7;
			}
			if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
			{
				--selnum;
				if (selnum < 0)selnum += 7;
			}
			if (KEYMANAGER->isOnceKeyDown(VK_UP))
			{
				selnum -= 2;
				if (selnum < 0)selnum += (7 / 2 + 1) * 2;
				if (selnum >= 7)selnum -= 2;
				if (selnum < 0)selnum += 2;
			}
			if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
			{
				selnum += 2;
				if (selnum >= 7)selnum -= (7 / 2 + 1) * 2;
				if (selnum >= 7)selnum -= 2;
				if (selnum < 0)selnum += 2;
			}
			if (KEYMANAGER->isOnceKeyDown(VK_RETURN))
			{
				if (_Item->getitemlist()[selnum + 1].price < _Item->getMoney())
				{
					_Item->setMoney(_Item->getMoney() - _Item->getitemlist()[selnum + 1].price);
					_Item->addItem(_Item->getitemlist()[selnum + 1].name);
				}
			}
		}

	}
}

void shopScene::render(void) 
{
	SetTextColor(getMemDC(), RGB(255, 255, 255));
	SetBkMode(getMemDC(), 0);
	if (waitselnum)
	{
		IMAGEMANAGER->findImage("샵판매")->render(getMemDC(), (WINSIZEX - 1024) / 2, (WINSIZEY - 760) / 2);
		char str[128];
		sprintf(str, "%d", _Item->getMoney());
		TextOut(getMemDC(), 920 - strlen(str) * 7, 185, str, strlen(str));
	}
	else
	{
		IMAGEMANAGER->findImage("샵구매")->render(getMemDC(), (WINSIZEX - 1024) / 2, (WINSIZEY - 760) / 2);
		char str[128];
		sprintf(str, "%d", _Item->getMoney());
		TextOut(getMemDC(), 925 - strlen(str) * 7, 224, str, strlen(str));
	}
	IMAGEMANAGER->findImage("선택")->alphaRender(getMemDC(), waitX, waitY, 255 - seltype * 125);

	if (seltype)
	{
		if (waitselnum)
		{
			for (int i = 0; i < itemsize; ++i)
			{
				IMAGEMANAGER->findImage("판매버튼")->render(getMemDC(), 72 + (int)(i % 4) * 224, 240 + (int)(i / 4) * 52);
				char str[128];
				sprintf(str, "%s", _Item->getiteminventory()[i].c_str());
				TextOut(getMemDC(), 120 + (int)(i % 4) * 224, 243 + (int)(i / 4) * 52, str, strlen(str));
				sprintf(str, "%d", _Item->findItem(_Item->getiteminventory()[i]).count);
				TextOut(getMemDC(), 240 + (int)(i % 4) * 224, 262 + (int)(i / 4) * 52, str, strlen(str));
			}
			for (int i = 0; i < equipsize; ++i)
			{
				IMAGEMANAGER->findImage("판매버튼")->render(getMemDC(), 72 + (int)((i + itemsize) % 4) * 224, 240 + (int)((i + itemsize) / 4) * 52);
				char str[128];
				sprintf(str, "%s", _Item->getequipinventory()[i].c_str());
				TextOut(getMemDC(), 120 + (int)((i + itemsize) % 4) * 224, 243 + (int)((i + itemsize) / 4) * 52, str, strlen(str));
				sprintf(str, "%d", _Item->findItem(_Item->getequipinventory()[i]).count);
				TextOut(getMemDC(), 240 + (int)((i + itemsize) % 4) * 224, 262 + (int)((i + itemsize) / 4) * 52, str, strlen(str));
			}
			IMAGEMANAGER->findImage("선택")->render(getMemDC(), selX + selnum % 4 * 224, selY + selnum / 4 * 52);
		}
		else
		{
			for (int i = 0; i < 7; ++i)
			{
				IMAGEMANAGER->findImage("아이템버튼")->render(getMemDC(), 390 + (int)(i % 2) * 320, 278 + (int)(i / 2) * 70);
				char str[128];
				sprintf(str, "%s", _Item->getitemlist()[i + 1].name.c_str());
				TextOut(getMemDC(), 445 + (int)(i % 2) * 320, 287 + (int)(i / 2) * 70, str, strlen(str));
				sprintf(str, "%d", _Item->getitemlist()[i + 1].price);
				TextOut(getMemDC(), 600 + (int)(i % 2) * 293, 313 + (int)(i / 2) * 70, str, strlen(str));
			}
			IMAGEMANAGER->findImage("선택")->render(getMemDC(), selX + selnum % 2 * 320, selY + selnum / 2 * 70);
		}
	}
}