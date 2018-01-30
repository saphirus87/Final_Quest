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
		_vPlayer[i]->setnowenemycount(_nowenemycount);
		_vPlayer[i]->update();

		if (_vPlayer[i]->getCommand()->selectCommand == RUN_COMMAND)
		{
			SCENEMANAGER->changeScene("fieldScene", FALSE);
			_vPlayer[i]->getCommand()->selectCommand = NO_COMMAND;
		}
	}
}
void playerManager::render()
{
	for (int i = 0; i < _vPlayer.size(); i++)
	{
		_vPlayer[i]->render();

		playerAction(i);
	}
}

void playerManager::playerAction(int playerIndex)
{
	if (_vPlayer[playerIndex]->getCommand()->selectCommand == RUN_COMMAND)
	{
		SCENEMANAGER->changeScene("fieldScene", FALSE);
		_vPlayer[playerIndex]->commandReset();
	}
}

void playerManager::updateActGauge(void)
{
	for (int i = 0; i < _vPlayer.size(); i++)
	{
		_vPlayer[i]->increaseActGauge();
	}
}

BOOL playerManager::isCommandReady(void)
{
	BOOL playerReady = false;

	for (int i = 0; i < _vPlayer.size(); i++)
	{
		playerReady |= _vPlayer[i]->getIsCommandReady();
	}

	return playerReady;
}

void playerManager::resetActGauge(void)
{
	for (int i = 0; i < _vPlayer.size(); i++)
	{
		_vPlayer[i]->setCurActGauge(0);
		_vPlayer[i]->setIsCommandReady(false);
		_vPlayer[i]->setSelectCommand(NO_COMMAND);
		_vPlayer[i]->setCurCommand(ATTACK_COMMAND);
	}
}
