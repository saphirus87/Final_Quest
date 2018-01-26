#include "stdafx.h"
#include "enemyManager.h"
//

enemyManager::enemyManager()
{
}


enemyManager::~enemyManager()
{
}

HRESULT enemyManager::init()
{
	return S_OK;
}

void enemyManager::release()
{
}

void enemyManager::update()
{
	for (vienemy = venemy.begin(); vienemy != venemy.end(); vienemy++)
	{
		//내가 플레이어 때려서 플레이어 피다르는 함수
		//
		(*vienemy)->update();
	}
}

void enemyManager::render()
{
	for (vienemy = venemy.begin(); vienemy != venemy.end(); vienemy++)
	{
		(*vienemy)->render(getMemDC());
	}
}


void enemyManager::set_wolf(int x,int y)
{
	//셋팅값
	enemy* _wolf;
	_wolf = new wolf;
	_wolf->init();
	_wolf->SetPosition(x, y);
	venemy.push_back(_wolf);

}

void enemyManager::set_knight(int x,int y)
{
	//셋팅값
	enemy* _knight;
	_knight = new knight;
	_knight->init();
	_knight->SetPosition(x, y);
	venemy.push_back(_knight);

}

void enemyManager::set_mammos(int x,int y)
{
	//셋팅값
	enemy* _mammos;
	_mammos = new mammos;
	_mammos->init();
	_mammos->SetPosition(x, y);
	venemy.push_back(_mammos);
}

void enemyManager::set_boss(int x,int y)
{
	enemy* _boss;
	_boss = new Boss;
	_boss->init();
	_boss->SetPosition(x, y);
	venemy.push_back(_boss);
}


void enemyManager::Hit()
{

}

void enemyManager::enemyErase()
{
	//venemy.erase()
}
