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
	IMAGEMANAGER->addImage("���޴���", ".\\SceneImage\\equipMenu.bmp", 1024, 760, true, RGB(255, 0, 255));

	return S_OK;
}

void equipMenu::release()
{

}

void equipMenu::update() 
{
	if (KEYMANAGER->isOnceKeyDown(VK_BACK))
	{
		SCENEMANAGER->changeScene("�޴���");
	}
}

void equipMenu::render() 
{
	IMAGEMANAGER->findImage("���޴���")->render(getMemDC(), WINSIZEX / 2 - IMAGEMANAGER->findImage("���޴���")->getWidth() / 2, WINSIZEY / 2 - IMAGEMANAGER->findImage("���޴���")->getHeight() / 2);
}
