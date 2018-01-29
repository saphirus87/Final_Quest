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
	IMAGEMANAGER->addImage("�����۸޴���", ".\\SceneImage\\itemMenu.bmp", 1024, 760, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�����۹�ư", ".\\SceneImage\\button.bmp", 273, 59, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�����۸Ŵ���ư", ".\\userInterface\\noselButton.bmp", 220, 40, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�����۸Ŵ�����", ".\\userInterface\\selButton.bmp", 220, 40, true, RGB(255, 0, 255));
	int ia;
	seltype = false;
	selItem = false;

	selX = 50;
	selY = 64;
	selnum = 0;

	itemsize = 0;
	equipsize = 0;
	playersel = 0;

	//�κ��丮 ù ��ǥ 82, 163
	//�κ��丮 ���� ��ǥ 293, 79

	return S_OK;
}

void itemMenu::release()
{

}

void itemMenu::update()	
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
		_Item->addItem("ö����");
		_Item->addItem("��հ�");
		_Item->addItem("�ܰ�(��)");
		_Item->addItem("�ܰ�(�)");
		_Item->addItem("���� �����");
		_Item->addItem("�Ǵн��� ����");
		_Item->addItem("������ �����");
	}

	if (!seltype) // �Ŵ� ���� ������ ��
	{
		if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
		{
			SOUNDMANAGER->play("�޴�����", 1.0f); //�޴����� �Ҹ�

			++selnum;
		}
		if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
		{
			SOUNDMANAGER->play("�޴�����", 1.0f); //�޴����� �Ҹ�

			--selnum;
		}

		if (selnum < 0)selnum += 3;
		selnum = selnum % 3;
		waitX = selX + selnum * 240;
		waitY = selY;
		waitselnum = selnum;

		if (KEYMANAGER->isOnceKeyDown(VK_RETURN) && ((itemsize && waitselnum == 0) || (equipsize && waitselnum == 1)))
		{
			SOUNDMANAGER->play("�޴�����", 1.0f); //�޴����� �Ҹ�

			selX = 100;
			selY = 180;
			selnum = 0;
			seltype = true;
		}
		if (KEYMANAGER->isOnceKeyDown(VK_BACK))
		{
			SOUNDMANAGER->play("�޴�����", 1.0f); //�޴����� �Ҹ�

			SCENEMANAGER->changeScene("�޴���", FALSE);
		}
	}
	else if (selItem) // ������ �������� ��
	{
		if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
		{
			SOUNDMANAGER->play("�޴�����", 1.0f); //�޴����� �Ҹ�

			++selnum;
		}
		if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
		{
			SOUNDMANAGER->play("�޴�����", 1.0f); //�޴����� �Ҹ�

			--selnum;
			if (selnum < 0)selnum += 3;
		}
		selnum = selnum % 3;

		if (KEYMANAGER->isOnceKeyDown(VK_RETURN))
		{
			SOUNDMANAGER->play("�޴�����", 1.0f); //�޴����� �Ҹ�
			int playerposition;
			for (int i = 0; i < 3; ++i)
			{
				if (selnum == _pm->getvplayer()[i]->getpartyPos() - 1)
				{
					playerposition = i;
				}
			}
			if (_Item->findItem(_Item->getiteminventory()[waitselItem]).code == 4)
			{
				_pm->getvplayer()[playerposition]->setCurrentMp(_pm->getvplayer()[playerposition]->getCurrentMp() + _Item->findItem(_Item->getiteminventory()[waitselItem]).value);
				if (_pm->getvplayer()[playerposition]->getCurrentMp() > _pm->getvplayer()[playerposition]->getMaxMp())
				{
					_pm->getvplayer()[playerposition]->setCurrentMp(_pm->getvplayer()[playerposition]->getMaxMp());
				}
			}
			else if (_Item->findItem(_Item->getiteminventory()[waitselItem]).code == 5)
			{
				if (_pm->getvplayer()[playerposition]->getCurrentHp());
				else
				{
					_pm->getvplayer()[playerposition]->setCurrentHp(_pm->getvplayer()[playerposition]->getCurrentHp() + _Item->findItem(_Item->getiteminventory()[waitselItem]).value);
					if (_pm->getvplayer()[playerposition]->getCurrentHp() > _pm->getvplayer()[playerposition]->getMaxHp())
					{
						_pm->getvplayer()[playerposition]->setCurrentHp(_pm->getvplayer()[playerposition]->getMaxHp());
					}
				}
			}
			else if (_Item->findItem(_Item->getiteminventory()[waitselItem]).code == 6)
			{
				for (int i = 0; i < 3; i++)
				{
					if (_pm->getvplayer()[i]->getCurrentHp())continue;
					else
					{
						_pm->getvplayer()[i]->setCurrentHp(_pm->getvplayer()[i]->getCurrentHp() + _Item->findItem(_Item->getiteminventory()[waitselItem]).value);
						if (_pm->getvplayer()[i]->getCurrentHp() > _pm->getvplayer()[i]->getMaxHp())
						{
							_pm->getvplayer()[i]->setCurrentHp(_pm->getvplayer()[i]->getMaxHp());
						}
					}
				}
			}
			else if (_Item->findItem(_Item->getiteminventory()[waitselItem]).code == 7);
			else
			{
				if (_pm->getvplayer()[playerposition]->getCurrentHp())
				{
					_pm->getvplayer()[playerposition]->setCurrentHp(_pm->getvplayer()[playerposition]->getCurrentHp() + _Item->findItem(_Item->getiteminventory()[waitselItem]).value);
					if (_pm->getvplayer()[playerposition]->getCurrentHp() > _pm->getvplayer()[playerposition]->getMaxHp())
					{
						_pm->getvplayer()[playerposition]->setCurrentHp(_pm->getvplayer()[playerposition]->getMaxHp());
					}
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
			SOUNDMANAGER->play("�޴�����", 1.0f); //�޴����� �Ҹ�

			selX = 100;
			selY = 180;
			selnum = waitselItem;
			selItem = false;
		}
	}
	else // �Ŵ� �����ϰ� ������ ���� ������ ��
	{
		if (KEYMANAGER->isOnceKeyDown(VK_BACK))
		{
			SOUNDMANAGER->play("�޴�����", 1.0f); //�޴����� �Ҹ�

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
			SOUNDMANAGER->play("�޴�����", 1.0f); //�޴����� �Ҹ�

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
			SOUNDMANAGER->play("�޴�����", 1.0f); //�޴����� �Ҹ�

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
			SOUNDMANAGER->play("�޴�����", 1.0f); //�޴����� �Ҹ�

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
			SOUNDMANAGER->play("�޴�����", 1.0f); //�޴����� �Ҹ�

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
			SOUNDMANAGER->play("�޴�����", 1.0f); //�޴����� �Ҹ�

			selItem = true;
			selX = 100;
			selY = 700;
			selnum = 0;
		}
	}
	//�׻� ���� ������ Ȯ��
	itemsize = _Item->getiteminventory().size();
	equipsize = _Item->getequipinventory().size();
}

void itemMenu::render()	
{
	//���� �� �ʱ�ȭ
	SetTextColor(getMemDC(), RGB(255, 255, 255));
	SetBkMode(getMemDC(), 0);
	//��� �Ѹ���
	IMAGEMANAGER->findImage("�����۸޴���")->render(getMemDC(), (WINSIZEX - 1024) / 2, (WINSIZEY - 760) / 2);
	//�Ŵ���ư �Ѹ���
	for (int i = 0; i < 3; ++i)
	{
		IMAGEMANAGER->findImage("�����۸Ŵ���ư")->render(getMemDC(), 40 + i * 240, 56);
		if (PtInRect(&RectMake(40 + i * 240, 57, 220, 40), PointMake(waitX, waitY)))
		{
			IMAGEMANAGER->findImage("�����۸Ŵ�����")->render(getMemDC(), 40 + i * 240, 56);
		}
	}
	char* str = "�Һ�";
	TextOut(getMemDC(), 133 , 69, str, strlen(str));
	str = "���";
	TextOut(getMemDC(), 133 + 240, 69, str, strlen(str));
	str = "DLC";
	TextOut(getMemDC(), 133 + 480, 69, str, strlen(str));
	//���� �հ��� �Ѹ���
	IMAGEMANAGER->findImage("����")->alphaRender(getMemDC(), waitX, waitY, 255 - seltype * 125);

	if (seltype)//�Ŵ� �����ߴٸ�
	{
		if (waitselnum)//����ϴ� �Ŵ��� 0�� �ƴ� ��(�Һ��� ���� ������)
		{
			for (int i = 0; i < equipsize; ++i)
			{
				IMAGEMANAGER->findImage("�����۹�ư")->render(getMemDC(), 82 + (int)(i % 3) * 293, 163 + (int)(i / 3) * 79);
				char str[128];
				sprintf(str, "%s", _Item->getequipinventory()[i].c_str());
				TextOut(getMemDC(), 160 + (int)(i % 3) * 293, 175 + (int)(i / 3) * 79, str, strlen(str));
				sprintf(str, "%d", _Item->findItem(_Item->getequipinventory()[i]).count);
				TextOut(getMemDC(), 300 + (int)(i % 3) * 293, 197 + (int)(i / 3) * 79, str, strlen(str));
			}
			IMAGEMANAGER->findImage("����")->render(getMemDC(), waitItemX, waitItemY);
		}
		else//�Ŵ� �Һ��� ���ý�
		{
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

				IMAGEMANAGER->findImage("�����۹�ư")->render(getMemDC(), 82 + (_pm->getvplayer()[i]->getpartyPos() - 1) * 293, 575);
				char str[128];
				sprintf(str, "%s", _pm->getvplayer()[i]->getName().c_str());
				TextOut(getMemDC(), 160 + (_pm->getvplayer()[i]->getpartyPos() - 1) % 3 * 293, 583, str, strlen(str));

				str[128];
				sprintf(str, "HP : %d / %d", _pm->getvplayer()[i]->getCurrentHp(), _pm->getvplayer()[i]->getMaxHp());
				TextOut(getMemDC(), 115 + (int)(_pm->getvplayer()[i]->getpartyPos() - 1) * 293, 611, str, strlen(str));

				str[128];
				sprintf(str, "MP : %d / %d", _pm->getvplayer()[i]->getCurrentMp(), _pm->getvplayer()[i]->getMaxMp());
				TextOut(getMemDC(), 230 + (int)(_pm->getvplayer()[i]->getpartyPos() - 1) * 293, 611, str, strlen(str));
			}
			SetTextColor(getMemDC(), RGB(255, 255, 255));
			for (int i = 0; i < itemsize; ++i)
			{
				IMAGEMANAGER->findImage("�����۹�ư")->render(getMemDC(), 82 + (int)(i % 3) * 293, 163 + (int)(i / 3) * 79);
				char str[128];
				sprintf(str, "%s", _Item->getiteminventory()[i].c_str());
				TextOut(getMemDC(), 160 + (int)(i % 3) * 293, 175 + (int)(i / 3) * 79, str, strlen(str));
				sprintf(str, "%d", _Item->findItem(_Item->getiteminventory()[i]).count);
				TextOut(getMemDC(), 300 + (int)(i % 3) * 293, 197 + (int)(i / 3) * 79, str, strlen(str));
			}
			if (selItem)//���� ������ �������� ��
			{
				if (_Item->findItem(_Item->getiteminventory()[waitselItem]).code == 6)
				{
					for (int j = 0; j < 3; j++)
					{
						IMAGEMANAGER->findImage("����")->render(getMemDC(), selX + j % 3 * 293, 590);
					}
				}
				IMAGEMANAGER->findImage("����")->render(getMemDC(), selX + selnum % 3 * 293, 590);
			}
			IMAGEMANAGER->findImage("����")->alphaRender(getMemDC(), waitItemX, waitItemY, 255 - selItem * 125);
		}

	}
	else if (waitselnum == 2)
	{
		for (int i = 0; i < DLCMANAGER->getDLCinven().size(); ++i)
		{
			IMAGEMANAGER->findImage("�����۹�ư")->render(getMemDC(), 82 + (int)(i % 3) * 293, 163 + (int)(i / 3) * 79);
			char str[128];
			sprintf(str, "%s", DLCMANAGER->getDLCinven()[i].c_str());
			TextOut(getMemDC(), 160 + (int)(i % 3) * 293, 175 + (int)(i / 3) * 79, str, strlen(str));
		}
	}
}
