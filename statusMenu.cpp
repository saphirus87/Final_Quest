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
	IMAGEMANAGER->addImage("스테이터스메뉴씬", ".\\SceneImage\\statusMenu.bmp", 1024, 760, true, RGB(255, 0, 255));

	return S_OK;
}

void statusMenu::release()
{

}

void statusMenu::update() 
{
	if (KEYMANAGER->isOnceKeyDown(VK_BACK))
	{
		SCENEMANAGER->changeScene("메뉴씬");
	}
}

void statusMenu::render() 
{
	IMAGEMANAGER->findImage("스테이터스메뉴씬")->render(getMemDC(), 0, 0);
}
