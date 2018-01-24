#include "stdafx.h"
#include "itemMenu.h"


itemMenu::itemMenu()
{
}


itemMenu::~itemMenu()
{

}

HRESULT itemMenu::init()
{
	_itemScene = IMAGEMANAGER->addImage("¾ÆÀÌÅÛ¸Þ´º¾À", ".\\SceneImage\\itemMenu.bmp", 1024, 760, true, RGB(255, 0, 255));


	return S_OK;
}

void itemMenu::release()
{

}

void itemMenu::update()	
{
	if (KEYMANAGER->isOnceKeyDown(VK_BACK))
	{
		SCENEMANAGER->changeScene("¸Þ´º¾À");
	}
}

void itemMenu::render()	
{
	_itemScene->render(getMemDC(), WINSIZEX / 2 - _itemScene->getWidth() / 2, WINSIZEY / 2 - _itemScene->getHeight() / 2);
}
