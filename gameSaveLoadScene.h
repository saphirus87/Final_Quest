#pragma once
#include "gameNode.h"

class playerManager;

class gameSaveLoadScene : public gameNode
{
private:
	playerManager* _pm;

public:
	HRESULT init();
	void release();
	void update();
	void render();

	inline void setPlayerManagerAddressLink(playerManager* pm) { _pm = pm; }

	gameSaveLoadScene();
	~gameSaveLoadScene();
};

