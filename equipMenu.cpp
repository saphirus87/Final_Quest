#include "stdafx.h"
#include "equipMenu.h"


equipMenu::equipMenu()
{
}


equipMenu::~equipMenu()
{

}

HRESULT equipMenu::init()
{
	IMAGEMANAGER->addImage("Àåºñ¸Þ´º¾À", ".\\SceneImage\\equipMenu.bmp", 1024, 760, true, RGB(255, 0, 255));

	return S_OK;
}

void equipMenu::release()
{

}

void equipMenu::update() 
{
	if (KEYMANAGER->isOnceKeyDown(VK_BACK))
	{
		SCENEMANAGER->changeScene("¸Þ´º¾À");
	}
}

void equipMenu::render() 
{
	IMAGEMANAGER->findImage("Àåºñ¸Þ´º¾À")->render(getMemDC(), WINSIZEX / 2 - IMAGEMANAGER->findImage("Àåºñ¸Þ´º¾À")->getWidth() / 2, WINSIZEY / 2 - IMAGEMANAGER->findImage("Àåºñ¸Þ´º¾À")->getHeight() / 2);
}
