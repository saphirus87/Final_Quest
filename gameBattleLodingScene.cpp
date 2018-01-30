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
	_image = IMAGEMANAGER->addFrameImage("��Ʋ���Ծ�", ".\\SceneImage\\battleLodingScene.bmp", 0, 0, 9216, 760, 9, 1, true, RGB(255, 0, 255));

	int battleLoading[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };
	KEYANIMANAGER->addArrayFrameAnimation("start", "��Ʋ���Ծ�", battleLoading, 9, 8, false);

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

	//IMAGEMANAGER->findImage("��Ʋ���Ծ�")->frameRender(getMemDC(), 0, 0);
}
