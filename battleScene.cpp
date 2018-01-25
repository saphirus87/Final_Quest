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
}

void battleScene::render(void)
{
}