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
		SCENEMANAGER->changeScene("�޴���", FALSE);
	}
}

void saveLoadMenu::render()	
{
	IMAGEMANAGER->findImage("���̺�ε�޴���")->render(getMemDC(), 0, 0);
}
