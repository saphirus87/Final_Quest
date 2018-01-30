#include "stdafx.h"
#include "gameBattleLodingScene.h"


gameBattleLodingScene::gameBattleLodingScene()
{
}


gameBattleLodingScene::~gameBattleLodingScene()
{

}

HRESULT gameBattleLodingScene::init()
{
	_image = IMAGEMANAGER->addFrameImage("¹èÆ²ÁøÀÔ¾À", ".\\SceneImage\\battleLodingScene.bmp", 0, 0, 9216, 760, 9, 1, true, RGB(255, 0, 255));

	int battleLoading[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };
	KEYANIMANAGER->addArrayFrameAnimation("start", "¹èÆ²ÁøÀÔ¾À", battleLoading, 9, 8, false);

	_battleLoading = KEYANIMANAGER->findAnimation("start");

	_battleLoading->start();

	return S_OK;
}

void gameBattleLodingScene::release()
{

}

void gameBattleLodingScene::update() 
{
	if (!_battleLoading->isPlay())
	{ 
		SCENEMANAGER->changeScene("battleScene");
	}

	KEYANIMANAGER->update();
}

void gameBattleLodingScene::render() 
{
	_image->aniRender(getMemDC(), 0, 0, _battleLoading);

	//IMAGEMANAGER->findImage("¹èÆ²ÁøÀÔ¾À")->frameRender(getMemDC(), 0, 0);
}
