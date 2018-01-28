#include "stdafx.h"
#include "abilitiesMenu.h"
#include "playerManager.h"


abilitiesMenu::abilitiesMenu()
{
}


abilitiesMenu::~abilitiesMenu()
{

}

HRESULT abilitiesMenu::init()
{
	IMAGEMANAGER->addImage("��ų�޴���", ".\\SceneImage\\abilitiesMenu.bmp", 1024, 760, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("����", ".\\SceneImage\\selectPoint.bmp", 27, 27, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�󱼹��", "D:\\GitHub\\�ӽ�\\SceneImage\\faceBackground.bmp", 108, 108, true, RGB(255, 0, 255));

	_cursorMenuNum = 0;

	return S_OK;
}

void abilitiesMenu::release()
{

}

void abilitiesMenu::update() 
{
	keyControl();
}

void abilitiesMenu::render() 
{
	IMAGEMANAGER->findImage("��ų�޴���")->render(getMemDC(), 0, 0);

	for (int i = 0; i < 3; ++i)
	{
		IMAGEMANAGER->findImage("�����۸Ŵ���ư")->render(getMemDC(), 40 + i * 240, 56);
		if (PtInRect(&RectMake(40 + i * 240, 57, 220, 40), PointMake(50 + _cursorMenuNum * 240, 64)))
		{
			IMAGEMANAGER->findImage("�����۸Ŵ�����")->render(getMemDC(), 40 + i * 240, 56);
		}
	}
	for (int i = 0; i < 3; ++i)
	{
		if (_pm->getvplayer()[i]->getCurrentHp())
		{
			SetTextColor(getMemDC(), RGB(255, 255, 255));
		}
		else
		{
			SetTextColor(getMemDC(), RGB(255, 0, 0));
		}
		char str[128];
		sprintf(str, "%s", _pm->getvplayer()[i]->getName().c_str());
		TextOut(getMemDC(), 133 + 240 * i, 69, str, strlen(str));
	}
	//���� �հ��� �Ѹ���
	IMAGEMANAGER->findImage("����")->alphaRender(getMemDC(), 50 + _cursorMenuNum * 240, 64, 255);

	IMAGEMANAGER->findImage("�󱼹��")->render(getMemDC(), 152, 127);
	char str[128];
	sprintf(str, "player%dface", _cursorMenuNum + 1);
	IMAGEMANAGER->render(str, getMemDC(), 155, 130);
}

void abilitiesMenu::keyControl()
{
	if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
	{
		++_cursorMenuNum;
		_cursorMenuNum = _cursorMenuNum % 3;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
	{
		--_cursorMenuNum;
		if (_cursorMenuNum < 0)_cursorMenuNum = 2;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_BACK))
	{
		SCENEMANAGER->changeScene("�޴���", FALSE);
	}
}
