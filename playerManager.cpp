#include "stdafx.h"
#include "playerManager.h"


playerManager::playerManager()
{
}


playerManager::~playerManager()
{
}

HRESULT playerManager::init()
{
	player* player1Obj;
	player1Obj = new player1;
	player* player2Obj;
	player2Obj = new player2;
	player* player3Obj;
	player3Obj = new player3;

	_vPlayer.push_back(player1Obj);
	_vPlayer.push_back(player2Obj);
	_vPlayer.push_back(player3Obj);

	for (int i = 0; i < _vPlayer.size(); i++)
	{
		_vPlayer[i]->init();
	}

	return S_OK;
}
void playerManager::release()
{

}
void playerManager::update()
{
	for (int i = 0; i < _vPlayer.size(); i++)
	{
		_vPlayer[i]->update();
	}
}
void playerManager::render()
{
	for (int i = 0; i < _vPlayer.size(); i++)
	{
		_vPlayer[i]->render();
	}
}
