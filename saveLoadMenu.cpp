#include "stdafx.h"
#include "saveLoadMenu.h"


saveLoadMenu::saveLoadMenu()
{
}


saveLoadMenu::~saveLoadMenu()
{

}

HRESULT saveLoadMenu::init()
{
	IMAGEMANAGER->addImage("세이브로드메뉴씬", ".\\SceneImage\\saveLoadMenu.bmp", 1024, 760, true, RGB(255, 0, 255));


	return S_OK;
}

void saveLoadMenu::release()
{

}

void saveLoadMenu::update()	
{
	if (KEYMANAGER->isOnceKeyDown(VK_BACK))
	{
		SCENEMANAGER->changeScene("메뉴씬", FALSE);
	}
}

void saveLoadMenu::render()	
{
	IMAGEMANAGER->findImage("세이브로드메뉴씬")->render(getMemDC(), 0, 0);
}
