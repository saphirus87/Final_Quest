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
	IMAGEMANAGER->addImage("���޴���", ".\\SceneImage\\equipMenu.bmp", 1024, 760, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("����", ".\\SceneImage\\selectPoint.bmp", 27, 27, true, RGB(255, 0, 255));

	_cursorMenuNum = 0;

	_isCharater = false;

	return S_OK;
}

void equipMenu::release()
{

}

void equipMenu::update() 
{
	keyControl();
	//�׻� ���� ������ Ȯ��
	equipsize = _Item->getequipinventory().size();
}

void equipMenu::render() 
{
	//���� �� �ʱ�ȭ
	SetTextColor(getMemDC(), RGB(255, 255, 255));
	SetBkMode(getMemDC(), 0);
	//��� �Ѹ���
	IMAGEMANAGER->findImage("���޴���")->render(getMemDC(), 0, 0);
	//�Ŵ� ��ư �Ѹ���
	for (int i = 0; i < 3; ++i)
	{
		if (_waitplayersel == i)
		{
			IMAGEMANAGER->findImage("�����۸Ŵ�����")->render(getMemDC(), 40 + i * 240, 56);
		}
		else
		{
			IMAGEMANAGER->findImage("�����۸Ŵ���ư")->render(getMemDC(), 40 + i * 240, 56);
		}
		char str[128];
		sprintf(str, "%s", _pm->getvplayer()[i]->getName().c_str());
		TextOut(getMemDC(), 133 + (int)(i % 3) * 237, 69, str, strlen(str));
	}
	IMAGEMANAGER->findImage("����")->alphaRender(getMemDC(), 50 + _waitplayersel * 240, 64, 255 - _isCharater * 125);

	if (_isCharater)
	{
		char str[128];
		sprintf(str, "player%dface", _waitplayersel + 1);
		IMAGEMANAGER->findImage(str)->render(getMemDC(), 85, 160);

		for (int i = 0; i < 5; ++i)
		{
			IMAGEMANAGER->findImage("�����۹�ư")->render(getMemDC(), 300 + i % 2 * 380, 115 + i / 2 * 63);
		}
		for (int i = 0; i < equipsize; ++i)
		{
			IMAGEMANAGER->findImage("�ǸŹ�ư")->render(getMemDC(), 50 + i % 4 * 240, 325 + i / 4 * 65);
		}

		IMAGEMANAGER->findImage("����")->render(getMemDC(), 50 + _cursorMenuNum * 240, 64);
	}

}

void equipMenu::keyControl()
{
	if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
	{
		SOUNDMANAGER->play("�޴�����", 1.0f); //�޴����� �Ҹ�

		++_cursorMenuNum;
		_cursorMenuNum = _cursorMenuNum % 3;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
	{
		SOUNDMANAGER->play("�޴�����", 1.0f); //�޴����� �Ҹ�

		--_cursorMenuNum;
		if (_cursorMenuNum < 0)_cursorMenuNum += 3;
	}
	if (_isCharater)
	{
		if (KEYMANAGER->isOnceKeyDown(VK_BACK))
		{
			_cursorMenuNum = _waitplayersel;
			SOUNDMANAGER->play("�޴�����", 1.0f); //�޴����� �Ҹ�
			
			_isCharater = false;
		}

	}
	else
	{
		_waitplayersel = _cursorMenuNum;
		if (KEYMANAGER->isOnceKeyDown(VK_RETURN))
		{
			SOUNDMANAGER->play("�޴�����", 1.0f); //�޴����� �Ҹ�

			_isCharater = true;
			_cursorMenuNum = 0;
		}
		if (KEYMANAGER->isOnceKeyDown(VK_BACK))
		{
			SOUNDMANAGER->play("�޴�����", 1.0f); //�޴����� �Ҹ�

			SCENEMANAGER->changeScene("�޴���", FALSE);
		}
	}
}
