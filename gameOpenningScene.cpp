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

	return S_OK;
}

void gameOpenningScene::release()
{

}

void gameOpenningScene::update() 
{

}

void gameOpenningScene::render() 
{
	SetTextColor(getMemDC(), RGB(255, 0, 0));
	TextOut(getMemDC(), WINSIZEX / 2, WINSIZEY / 2, "¿ÀÇÁ´× ¾¯ºü!!!!!", strlen("¿ÀÇÁ´× ¾¯ºü!!!!!"));
}