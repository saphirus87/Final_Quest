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
	IMAGEMANAGER->addImage("½ºÅ³¸Þ´º¾À", ".\\SceneImage\\abilitiesMenu.bmp", 1024, 760, true, RGB(255, 0, 255));

	return S_OK;
}

void abilitiesMenu::release()
{

}

void abilitiesMenu::update() 
{
	if (KEYMANAGER->isOnceKeyDown(VK_BACK))
	{
		SCENEMANAGER->changeScene("¸Þ´º¾À");
	}
}

void abilitiesMenu::render() 
{
	IMAGEMANAGER->findImage("½ºÅ³¸Þ´º¾À")->render(getMemDC(), WINSIZEX / 2 - IMAGEMANAGER->findImage("½ºÅ³¸Þ´º¾À")->getWidth() / 2, WINSIZEY / 2 - IMAGEMANAGER->findImage("½ºÅ³¸Þ´º¾À")->getHeight() / 2);
}
