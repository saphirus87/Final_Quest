#include "stdafx.h"
#include "gameOpenningScene.h"


gameOpenningScene::gameOpenningScene()
{
}


gameOpenningScene::~gameOpenningScene()
{

}

HRESULT gameOpenningScene::init()
{
	IMAGEMANAGER->addImage("openningBackGround", ".\\SceneImage\\OpenningBackGround.bmp", 1024, 2048, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("openningFrontGround", ".\\SceneImage\\OpenningFrontGround.bmp", 1024, 760, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("fire", ".\\SceneImage\\fire.bmp", 1024, 256, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("burn", ".\\SceneImage\\firBurn.bmp", 1024, 256, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Knight", ".\\SceneImage\\OpeningNight.bmp", 376, 300, true, RGB(255, 0, 255));

	CAMERAMANAGER->addImage("������", WINSIZEX, WINSIZEY);


	OpeningCameraY = 0;
	knihgtAlpha = 0;
	_alpha = 0;
	return S_OK;
}

void gameOpenningScene::release()
{

}

void gameOpenningScene::update()
{


	if (!SOUNDMANAGER->isPlaySound("������"))
	{
		SOUNDMANAGER->play("������");
	}
	if (OpeningCameraY + 750 < 2000)
	{
		OpeningCameraY++;
	}
	else
	{
		if (knihgtAlpha < 255)
			knihgtAlpha += 5;
		else if (knihgtAlpha >= 255)
		{
			knihgtAlpha = 255;
		}
	}

	if (KEYMANAGER->isStayKeyDown(VK_RETURN))
	{
		SCENEMANAGER->changeScene("��ŸƮ��");
		if (SOUNDMANAGER->isPlaySound("������"))
		{
			SOUNDMANAGER->stop("������");
		}
	}



	_alpha += 150;


}

void gameOpenningScene::render()
{
	IMAGEMANAGER->findImage("fire")->render(CAMERAMANAGER->findImage("������")->getMemDC(), 0, 200);
	IMAGEMANAGER->findImage("burn")->alphaRender(CAMERAMANAGER->findImage("������")->getMemDC(), 0, 200, _alpha);
	IMAGEMANAGER->findImage("openningBackGround")->render(CAMERAMANAGER->findImage("������")->getMemDC(), 0, 0, 0, OpeningCameraY, 1024, 760);

	IMAGEMANAGER->findImage("Knight")->alphaRender(CAMERAMANAGER->findImage("������")->getMemDC(), 259, 155, knihgtAlpha);



	CAMERAMANAGER->findImage("������")->render(getMemDC());
}