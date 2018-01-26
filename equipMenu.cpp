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
	IMAGEMANAGER->addImage("Àåºñ¸Ş´º¾À", ".\\SceneImage\\equipMenu.bmp", 1024, 760, true, RGB(255, 0, 255));

	return S_OK;
}

void equipMenu::release()
{

}

void equipMenu::update() 
{
	if (KEYMANAGER->isOnceKeyDown(VK_BACK))
	{
		SCENEMANAGER->changeScene("¸Ş´º¾À", FALSE);
	}
}

void equipMenu::render() 
{
	IMAGEMANAGER->findImage("Àåºñ¸Ş´º¾À")->render(getMemDC(), 0, 0);
}
