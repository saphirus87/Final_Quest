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


void enemyManager::set_wolf(int x,int y,int nameX,int nameY)
{
	//셋팅값
	enemy* _wolf;
	_wolf = new wolf;
	_wolf->init();
	_wolf->SetPosition(x, y);
	_wolf->SetNamePosition(nameX, nameY);
	venemy.push_back(_wolf);

}

void enemyManager::set_knight(int x,int y,int nameX,int nameY)
{
	//셋팅값
	enemy* _knight;
	_knight = new knight;
	_knight->init();
	_knight->SetPosition(x, y);
	_knight->SetNamePosition(nameX, nameY);
	venemy.push_back(_knight);

}

void enemyManager::set_mammos(int x,int y,int nameX,int nameY)
{
	//셋팅값
	enemy* _mammos;
	_mammos = new mammos;
	_mammos->init();
	_mammos->SetPosition(x, y);
	_mammos->SetNamePosition(nameX,nameY);
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

void enemyManager::enemyErase(int arr)
{
	venemy.erase(venemy.begin() + arr);
}
