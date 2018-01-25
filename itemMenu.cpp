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
	IMAGEMANAGER->addImage("�����۸޴���", ".\\SceneImage\\itemMenu.bmp", 1024, 760, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�����۹�ư", ".\\SceneImage\\button.bmp", 273, 59, true, RGB(255, 0, 255));
	
	_Item = new Item;
	_Item->init();

	seltype = false;

	waitX = 25;
	waitY = 64;

	selX = 25;
	selY = 64;
	selnum = 0;

	itemsize = 0;
	equipsize = 0;

	//�κ��丮 ù ��ǥ 82, 163
	//�κ��丮 ���� ��ǥ 293, 79

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
			SCENEMANAGER->changeScene("�޴���");
		}
	}
	else
	{
		itemsize = _Item->iteminventory()->size();
		equipsize = _Item->equipinventory()->size();
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
		_Item->addItem("����");
		_Item->addItem("��������");
	}
	if (KEYMANAGER->isOnceKeyDown('2'))
	{
		_Item->addItem("��������");
		_Item->addItem("���װ���");
	}
	if (KEYMANAGER->isOnceKeyDown('3'))
	{
		_Item->addItem("����ź");
		_Item->addItem("����");
	}
	if (KEYMANAGER->isOnceKeyDown('4'))
	{
		_Item->addItem("���׸�");
		_Item->addItem("������");
	}
	if (KEYMANAGER->isOnceKeyDown('5'))
	{
		_Item->addItem("�ް�����");
		_Item->addItem("�ĵ�");
	}
}

void itemMenu::render()	
{
	IMAGEMANAGER->findImage("�����۸޴���")->render(getMemDC(), (WINSIZEX - 1024) / 2, (WINSIZEY - 760) / 2);
	IMAGEMANAGER->findImage("����")->alphaRender(getMemDC(), waitX, waitY, 255 - seltype * 125);
	if (seltype)
	{
		if (waitselnum)
		{
			for (int i = 0; i < equipsize; ++i)
			{
				IMAGEMANAGER->findImage("�����۹�ư")->render(getMemDC(), 82 + (int)(i % 3) * 293, 163 + (int)(i / 3) * 79);
				char str[128];
				sprintf(str, "%s", _Item->vequipstring(i).c_str());
				TextOut(getMemDC(), 160 + (int)(i % 3) * 293, 175 + (int)(i / 3) * 79, str, strlen(str));
				sprintf(str, "%d", _Item->findItem(_Item->vequipstring(i)).count);
				TextOut(getMemDC(), 300 + (int)(i % 3) * 293, 175 + (int)(i / 3) * 79, str, strlen(str));
			}
		}
		else
		{
			for (int i = 0; i < itemsize; ++i)
			{
				IMAGEMANAGER->findImage("�����۹�ư")->render(getMemDC(), 82 + (int)(i % 3) * 293, 163 + (int)(i / 3) * 79);
				char str[128];
				sprintf(str, "%s", _Item->vitemstring(i).c_str());
				TextOut(getMemDC(), 160 + (int)(i % 3) * 293, 175 + (int)(i / 3) * 79, str, strlen(str));
				sprintf(str, "%d", _Item->findItem(_Item->vitemstring(i)).count);
				TextOut(getMemDC(), 300 + (int)(i % 3) * 293, 175 + (int)(i / 3) * 79, str, strlen(str));
			}
		}

		IMAGEMANAGER->findImage("����")->render(getMemDC(), selX + selnum % 3 * 293, selY + selnum / 3 * 79);
	}
}
