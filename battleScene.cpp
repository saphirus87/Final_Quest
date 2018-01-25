#include "stdafx.h"
#include "battleScene.h"


battleScene::battleScene()
{
}


battleScene::~battleScene()
{
}

HRESULT battleScene::init(void) 
{

	/////배틀씬 임시 이미지///
	IMAGEMANAGER->addImage("battleBackground","mapImage/battleBackground.bmp", 1136, 640, true, RGB(255, 0, 255));

	em = new enemyManager;
	em->set_wolf();
	em->set_knight();
	em->set_mammos();
	return S_OK;
}

void battleScene::release(void) 
{
}

void battleScene::update(void)
{
	if (KEYMANAGER->isOnceKeyDown(VK_F10))
	{
		SCENEMANAGER->changeScene("fieldScene", false);
	}
	em->update();
}

void battleScene::render(void)
{
	IMAGEMANAGER->findImage("battleBackground")->render(getMemDC(),0,0);
	em->render();
	//if(적두명일때)

	//if(적세마리일때)
}