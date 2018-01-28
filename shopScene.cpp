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
	IMAGEMANAGER->addImage("������", ".\\userInterface\\Shop_Buy.bmp", 1024, 760, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("���Ǹ�", ".\\userInterface\\Shop_UI.bmp", 1024, 760, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("���Ŵ���ư", ".\\userInterface\\noselButton.bmp", 300, 49, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("���Ŵ�����", ".\\userInterface\\selButton.bmp", 300, 49, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�ǸŹ�ư", ".\\SceneImage\\button1.bmp", 205, 44, true, RGB(255, 0, 255));

	seltype = false;

	selX = 65;
	selY = 125;
	selnum = 0;

	itemsize = 0;
	equipsize = 0;

	//�κ��丮 ù ��ǥ 72, 240
	//�κ��丮 ���� ��ǥ 224, 52
	return S_OK;
}

void shopScene::release(void)
{

}

void shopScene::update(void) 
{
	if (!seltype)//�Ŵ� ���� ������ ��
	{
		if (KEYMANAGER->isOnceKeyDown('1'))//�ӽ÷� ������ �ø���
		{
			_Item->addItem("����");
			_Item->addItem("��������");
			_Item->addItem("��������");
			_Item->addItem("���װ���");
			_Item->addItem("����ź");
			_Item->addItem("����");
			_Item->addItem("���׸�");
			_Item->addItem("������");
			_Item->addItem("�ް�����");
			_Item->addItem("�ĵ�");
			_Item->addItem("ö����");
			_Item->addItem("��հ�");
			_Item->addItem("�ܰ�(��)");
			_Item->addItem("�ܰ�(�)");
			_Item->addItem("���� �����");
			_Item->addItem("ü���� �����");
			_Item->addItem("������ �����");
		}
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
		//����� ���� ����
		waitselnum = selnum;
		waitX = selX + selnum * 320;
		waitY = selY;

		if (KEYMANAGER->isOnceKeyDown(VK_RETURN))
		{
			if (waitselnum)//�Һ��� �̿��� �Ŵ� ���ý�
			{
				selX = 85;
				selY = 250;
			}
			else//�Һ��� ���ý�
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
			selX = 65;
			selY = 125;
			selnum = waitselnum;
			seltype = false;
		}

		if (waitselnum == 1)//�Ǹ� ���ý�
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
		else if (waitselnum == 0)//���� ���ý�
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
		else//DLC���ý�
		{

		}
	}
}

void shopScene::render(void)
{
	SetTextColor(getMemDC(), RGB(255, 255, 255));
	SetBkMode(getMemDC(), 0);
	if (waitselnum)//������ �Ǹ�, DLC ��
	{
		IMAGEMANAGER->findImage("���Ǹ�")->render(getMemDC(), (WINSIZEX - 1024) / 2, (WINSIZEY - 760) / 2);
		char str[128];
		sprintf(str, "%d", _Item->getMoney());
		TextOut(getMemDC(), 920 - strlen(str) * 7, 185, str, strlen(str));
	}
	else//������ ���Ž�
	{
		IMAGEMANAGER->findImage("������")->render(getMemDC(), (WINSIZEX - 1024) / 2, (WINSIZEY - 760) / 2);
		char str[128];
		sprintf(str, "%d", _Item->getMoney());
		TextOut(getMemDC(), 925 - strlen(str) * 7, 224, str, strlen(str));
	}
	for (int i = 0; i < 3; ++i)
	{
		IMAGEMANAGER->findImage("���Ŵ���ư")->render(getMemDC(), WINSIZEX / 2 - 470 + i * 320, 113);
		if (PtInRect(&RectMake(WINSIZEX / 2 - 470 + i * 320, 113, 300, 49), PointMake(waitX, waitY)))
		{
			IMAGEMANAGER->findImage("���Ŵ�����")->render(getMemDC(), WINSIZEX / 2 - 470 + i * 320, 113);
		}
	}
	char* str = "����";
	TextOut(getMemDC(), 174, 131, str, strlen(str));
	str = "�Ǹ�";
	TextOut(getMemDC(), 174 + 320, 131, str, strlen(str));
	str = "DLC";
	TextOut(getMemDC(), 174 + 640, 131, str, strlen(str));
	IMAGEMANAGER->findImage("����")->alphaRender(getMemDC(), waitX, waitY, 255 - seltype * 125);

	if (seltype)
	{
		if (waitselnum == 1)//�Ǹ� ���� ��
		{
			for (int i = 0; i < itemsize; ++i)
			{
				IMAGEMANAGER->findImage("�ǸŹ�ư")->render(getMemDC(), 72 + (int)(i % 4) * 224, 240 + (int)(i / 4) * 52);
				char str[128];
				sprintf(str, "%s", _Item->getiteminventory()[i].c_str());
				TextOut(getMemDC(), 120 + (int)(i % 4) * 224, 243 + (int)(i / 4) * 52, str, strlen(str));
				sprintf(str, "%d", _Item->findItem(_Item->getiteminventory()[i]).count);
				TextOut(getMemDC(), 240 + (int)(i % 4) * 224, 262 + (int)(i / 4) * 52, str, strlen(str));
			}
			for (int i = 0; i < equipsize; ++i)
			{
				IMAGEMANAGER->findImage("�ǸŹ�ư")->render(getMemDC(), 72 + (int)((i + itemsize) % 4) * 224, 240 + (int)((i + itemsize) / 4) * 52);
				char str[128];
				sprintf(str, "%s", _Item->getequipinventory()[i].c_str());
				TextOut(getMemDC(), 120 + (int)((i + itemsize) % 4) * 224, 243 + (int)((i + itemsize) / 4) * 52, str, strlen(str));
				sprintf(str, "%d", _Item->findItem(_Item->getequipinventory()[i]).count);
				TextOut(getMemDC(), 240 + (int)((i + itemsize) % 4) * 224, 262 + (int)((i + itemsize) / 4) * 52, str, strlen(str));
			}
			IMAGEMANAGER->findImage("����")->render(getMemDC(), selX + selnum % 4 * 224, selY + selnum / 4 * 52);
		}
		else if (waitselnum == 0)//���� ���� ��
		{
			char item_count[128];
			sprintf(item_count, "%d", _Item->getitemlist()[selnum + 1].count);
			TextOut(getMemDC(), 500, 197, item_count, strlen(item_count));
			for (int i = 0; i < 7; ++i)
			{
				IMAGEMANAGER->findImage("�����۹�ư")->render(getMemDC(), 390 + (int)(i % 2) * 320, 278 + (int)(i / 2) * 70);
				char str[128];
				sprintf(str, "%s", _Item->getitemlist()[i + 1].name.c_str());
				TextOut(getMemDC(), 445 + (int)(i % 2) * 320, 287 + (int)(i / 2) * 70, str, strlen(str));
				sprintf(str, "%d", _Item->getitemlist()[i + 1].price);
				TextOut(getMemDC(), 600 + (int)(i % 2) * 293, 313 + (int)(i / 2) * 70, str, strlen(str));
			}
			IMAGEMANAGER->findImage("����")->render(getMemDC(), selX + selnum % 2 * 320, selY + selnum / 2 * 70);
		}
		else//DLC ���� ��
		{

		}
	}
}