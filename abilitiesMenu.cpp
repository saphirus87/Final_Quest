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
	_abilitiesScene = IMAGEMANAGER->addImage("��ų�޴���", ".\\SceneImage\\abilitiesMenu.bmp", 1024, 760, true, RGB(255, 0, 255));

	return S_OK;
}

void abilitiesMenu::release()
{

}

void abilitiesMenu::update() 
{
	if (KEYMANAGER->isOnceKeyDown(VK_BACK))
	{
		SCENEMANAGER->changeScene("�޴���");
	}
}

void abilitiesMenu::render() 
{
	_abilitiesScene->render(getMemDC(), WINSIZEX / 2 - _abilitiesScene->getWidth() / 2, WINSIZEY / 2 - _abilitiesScene->getHeight() / 2);
}
