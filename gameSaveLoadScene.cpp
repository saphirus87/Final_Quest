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
	IMAGEMANAGER->addImage("��ŸƮ���̺�ε�޴���", ".\\SceneImage\\saveLoadMenu.bmp", 1024, 760, true, RGB(255, 0, 255));

	return S_OK;
}

void gameSaveLoadScene::release()
{

}

void gameSaveLoadScene::update() 
{
	if (KEYMANAGER->isOnceKeyDown(VK_BACK))
	{
		SCENEMANAGER->changeScene("��ŸƮ��");
	}
}

void gameSaveLoadScene::render() 
{
	IMAGEMANAGER->findImage("��ŸƮ���̺�ε�޴���")->render(getMemDC(), 0, 0);
}
