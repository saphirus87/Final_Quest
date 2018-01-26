#include "stdafx.h"
#include "gameSaveLoadScene.h"


gameSaveLoadScene::gameSaveLoadScene()
{
}


gameSaveLoadScene::~gameSaveLoadScene()
{

}

HRESULT gameSaveLoadScene::init()
{
	IMAGEMANAGER->addImage("스타트세이브로드메뉴씬", ".\\SceneImage\\saveLoadMenu.bmp", 1024, 760, true, RGB(255, 0, 255));

	return S_OK;
}

void gameSaveLoadScene::release()
{

}

void gameSaveLoadScene::update() 
{
	if (KEYMANAGER->isOnceKeyDown(VK_BACK))
	{
		SCENEMANAGER->changeScene("스타트씬");
	}
}

void gameSaveLoadScene::render() 
{
	IMAGEMANAGER->findImage("스타트세이브로드메뉴씬")->render(getMemDC(), 0, 0);
}
