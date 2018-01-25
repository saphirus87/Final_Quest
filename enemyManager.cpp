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
		(*vienemy)->render();
	}
}


void enemyManager::set_wolf()
{
	//���ð�
	enemy* _wolf;
	_wolf = new wolf;
	_wolf->init();
	
	venemy.push_back(_wolf);

}

void enemyManager::set_knight()
{
	//���ð�
	enemy* _knight;
	_knight = new knight;
	_knight->init();

	venemy.push_back(_knight);

}

void enemyManager::set_mammos()
{
	//���ð�
	enemy* _mammos;
	_mammos = new mammos;
	_mammos->init();

	venemy.push_back(_mammos);
}
