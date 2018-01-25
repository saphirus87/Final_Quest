#pragma once
#include <vector>
#include "player1.h"
class playerManager
{

private:
	typedef vector<player&> vPlayer;

	vPlayer* _vPlayer;

public:
	playerManager();
	~playerManager();

	HRESULT init();
	void release();
	void update();
	void render();
};

