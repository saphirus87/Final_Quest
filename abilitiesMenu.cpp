#include "stdafx.h"
#include "abilitiesMenu.h"


abilitiesMenu::abilitiesMenu()
{
}


abilitiesMenu::~abilitiesMenu()
{

}

HRESULT abilitiesMenu::init()
{
	IMAGEMANAGER->addImage("½ºÅ³¸Ş´º¾À", ".\\SceneImage\\abilitiesMenu.bmp", 1024, 760, true, RGB(255, 0, 255));

	return S_OK;
}

void abilitiesMenu::release()
{

}

void abilitiesMenu::update() 
{
	if (KEYMANAGER->isOnceKeyDown(VK_BACK))
	{
		SCENEMANAGER->changeScene("¸Ş´º¾À", FALSE);
	}
}

void abilitiesMenu::render() 
{
	IMAGEMANAGER->findImage("½ºÅ³¸Ş´º¾À")->render(getMemDC(), 0, 0);
}
