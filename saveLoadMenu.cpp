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
	IMAGEMANAGER->addImage("���̺�ε�޴���", ".\\SceneImage\\saveLoadMenu.bmp", 1024, 760, true, RGB(255, 0, 255));


	return S_OK;
}

void saveLoadMenu::release()
{

}

void saveLoadMenu::update()	
{
	if (KEYMANAGER->isOnceKeyDown(VK_BACK))
	{
		SCENEMANAGER->changeScene("�޴���");
	}
}

void saveLoadMenu::render()	
{
	IMAGEMANAGER->findImage("���̺�ε�޴���")->render(getMemDC(), WINSIZEX / 2 - IMAGEMANAGER->findImage("���̺�ε�޴���")->getWidth() / 2, WINSIZEY / 2 - IMAGEMANAGER->findImage("���̺�ε�޴���")->getHeight() / 2);
}
