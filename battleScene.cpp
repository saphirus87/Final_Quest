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
		
	int rnd1 = RND->getFromIntTo(2, 3);

	for (int i = 0; i < rnd1; i++)
	{
		int rnd2 = RND->getFromFloatTo(1, 4);
	//cout << rnd2 << endl;
		int x, y;
		if (i == 0)
		{
			x = 200;
			y = 150;
		}
		else if (i == 1)
		{
			x = 200;
			y = 300;
		}
		else if (i == 2)
		{
			x = 200;
			y = 450;
		}
		switch (rnd2)
		{
		case 1:
			em->set_wolf(x,y);
			break;
		case 2:
			em->set_knight(x,y);
			break;
		case 3:
			em->set_mammos(x,y);
		default:
			break;
		}

	}
	return S_OK;
}

void battleScene::release(void) 
{

}

void battleScene::update(void)
{
	if (KEYMANAGER->isOnceKeyDown(VK_F10))
	{
		SCENEMANAGER->changeScene("fieldScene",false);
	}
	em->update();
}

void battleScene::render(void)
{
	IMAGEMANAGER->findImage("battleBackground")->render(getMemDC(),0,0);

	em->render();
}