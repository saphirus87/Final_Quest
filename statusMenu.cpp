#include "stdafx.h"
#include "statusMenu.h"


statusMenu::statusMenu()
{
}


statusMenu::~statusMenu()
{

}

HRESULT statusMenu::init()
{
	IMAGEMANAGER->addImage("�������ͽ��޴���", ".\\SceneImage\\statusMenu.bmp", 1024, 760, true, RGB(255, 0, 255));

	return S_OK;
}

void statusMenu::release()
{

}

void statusMenu::update() 
{
	if (KEYMANAGER->isOnceKeyDown(VK_BACK))
	{
		SCENEMANAGER->changeScene("�޴���");
	}
}

void statusMenu::render() 
{
	IMAGEMANAGER->findImage("�������ͽ��޴���")->render(getMemDC(), 0, 0);
}
