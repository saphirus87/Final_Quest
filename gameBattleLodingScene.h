#pragma once
#include "gameNode.h"

class playerManager;

class gameBattleLodingScene : public gameNode
{
private:
	playerManager* _pm;

	image* _image;

	animation* _battleLoading;

public:
	HRESULT init();
	void release();
	void update();
	void render();

	inline void setPlayerManagerAddressLink(playerManager* pm) { _pm = pm; }

	gameBattleLodingScene();
	~gameBattleLodingScene();
};

